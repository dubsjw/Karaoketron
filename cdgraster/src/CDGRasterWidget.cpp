#include "src/CDGRasterWidget.h"
#include <cdgdecode/Tile.h>
#include <QBrush>
#include <QMouseEvent>
#include <QPainter>
#include <cstdlib>
#include <iostream>

namespace cdgraster
{
enum { THRESHOLD = 10 };

CDGRasterWidget::CDGRasterWidget()
: QWidget(nullptr)
{
	QObject::connect(&m_timer, SIGNAL(timeout()), this, SLOT(OnTimeout()));

	using namespace cdgdecode;
	setMinimumSize( screen::Width, screen::Height );
	setMaximumSize( screen::Width, screen::Height );


	m_colors[0] = Color(0,0,0);
	m_colors[1] = Color(128, 0, 0);
	m_colors[2] = Color(255, 0, 0);
	m_colors[3] = Color(255, 0, 255);
	m_colors[4] = Color(0, 128, 128);
	m_colors[5] = Color(0, 128, 0);
	m_colors[6] = Color(0, 255, 0);
	m_colors[7] = Color(0, 255, 255);
	m_colors[8] = Color(0, 0, 128);
	m_colors[9] = Color(128, 0, 128);
	m_colors[10] = Color(0, 0, 255);
	m_colors[11] = Color(192, 192, 192);
	m_colors[12] = Color(128, 128, 128);
	m_colors[13] = Color(128, 128, 0);
	m_colors[14] = Color(255, 255, 0);
	m_colors[15] = Color(255, 255, 255);

	m_screen.resize(screen::Width);
	for(int i=0; i<screen::Width; ++i)
	{
		// Initialize purposefully with garbage.
		m_screen[i].resize(screen::Height);
		for(int j=0; j<screen::Height; ++j)
		{
			m_screen[i][j] = static_cast<std::int8_t>(rand() % 100);
		}
	}
}


void CDGRasterWidget::Clear(std::int8_t color)
{
	using namespace cdgdecode;
	for(int i= screen::ViewX1; i<screen::ViewX2; ++i)
	{
		for(int j=screen::ViewY1; j<screen::ViewY2; ++j)
		{
			m_screen[i][j] = color;	
		}
	}
	repaint();
}


void CDGRasterWidget::ClearBorder(std::int8_t color)
{
	using namespace cdgdecode;
	for(int i=0; i<screen::Width; ++i)
	{
		for(int j=0; j<screen::ViewY1; ++j)
		{
			m_screen[i][j] = color;
		}

		for(int j=screen::ViewY2; j<screen::Height; ++j)
		{
			m_screen[i][j] = color;
		}
	}	

	for(int i=0; i<screen::ViewX1; ++i)
	{
		for(int j=screen::ViewY1; j<=screen::ViewY2; ++j)
		{
			m_screen[i][j] = color;
		}
	}
	for(int i=screen::ViewX2; i<screen::Width; ++i)
	{
		for(int j=screen::ViewY1; j<=screen::ViewY2; ++j)
		{
			m_screen[i][j] = color;
		}
	}

	repaint();
}


void CDGRasterWidget::DrawTile( std::int8_t row
                              , std::int8_t column
                              , cdgdecode::Tile const& tile )
{
	using namespace cdgdecode;
//	std::cout << "ROW: " << static_cast<int>(row) << ", COLUMN: " << static_cast<int>(column) << std::endl;

	int x = column * screen::TileWidth;	
	int y = row * screen::TileHeight;	

	for(unsigned int tileX = 0; tileX < cdgdecode::screen::TileWidth; ++tileX)
	{
		for(unsigned int tileY = 0; tileY < cdgdecode::screen::TileHeight; ++tileY)
		{
			if (tileX + x < m_screen.size() && tileY + y < m_screen[x+tileX].size())
			{
				m_screen[tileX + x][tileY + y] = tile[tileX][tileY];
			}
		}
	}

	static int counter = 0;
	++counter;
	if (counter >= THRESHOLD)
	{
		counter = 0;
		repaint();
	}

}


void CDGRasterWidget::DrawXORTile( std::int8_t row
                                 , std::int8_t column
                                 , cdgdecode::Tile const& tile )
{
	using namespace cdgdecode;

	int x = column * screen::TileWidth;	
	int y = row * screen::TileHeight;	

	for(unsigned int tileX = 0; tileX < cdgdecode::screen::TileWidth; ++tileX)
	{
		for(unsigned int tileY = 0; tileY < cdgdecode::screen::TileHeight; ++tileY)
		{
			if (tileX + x < m_screen.size() && tileY + y < m_screen[x+tileX].size())
			{
				auto originalValue = m_screen[tileX + x][tileY + y];
				auto xorValue = tile[tileX][tileY];
		
				m_screen[tileX + x][tileY + y] = originalValue ^ xorValue;
			}
		}
	}

	static int counter = 0;
	++counter;
	if (counter >= THRESHOLD)
	{
		counter = 0;
		repaint();
	}
}




void CDGRasterWidget::paintEvent(QPaintEvent* evt)
{
	using namespace cdgdecode;
	QPainter painter(this);
	for(int i=0; i<screen::Width; ++i)
	{
		for(int j=0; j<screen::Height; ++j)
		{
			auto pixelColor = m_screen[i][j];

			QColor c;
			if (pixelColor < 16)
			{
				Color& localColor = m_colors[pixelColor];
				
				c = QColor(localColor.Red(), localColor.Green(), localColor.Blue());
			}
			else
			{
				c = QColor(rand() % 255, rand() % 255, rand() % 255);
			}

			painter.setPen(c);
			painter.drawPoint(i, j);
		}
	}
}


void CDGRasterWidget::mousePressEvent(QMouseEvent* evt)
{
	if ( (evt->buttons() | Qt::LeftButton) && (evt->buttons() | Qt::RightButton))
	{
		m_timer.start(1);
	}
	else if (evt->button() == Qt::LeftButton)
	{
		m_next(1);
	}
	else if (evt->button() == Qt::RightButton)
	{
		m_next(20);
	}
	else if (evt->button() == Qt::MiddleButton)
	{
		m_timer.start(1);
	}
}


void CDGRasterWidget::SetNextListener(std::function<void(int)> next)
{
	m_next = next;
}


void CDGRasterWidget::OnTimeout()
{
	m_next(100);
}


cdgdecode::ColorTable& CDGRasterWidget::Palette()
{
	return m_colors;
}

}


