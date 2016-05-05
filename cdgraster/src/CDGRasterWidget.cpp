#include "src/CDGRasterWidget.h"
#include <cdgdecode/Tile.h>
#include <QBrush>
#include <QMouseEvent>
#include <QPainter>
#include <cstdlib>
#include <iostream>

namespace cdgraster
{

CDGRasterWidget::CDGRasterWidget()
: QWidget(nullptr)
{
	QObject::connect(&m_timer, SIGNAL(timeout()), this, SLOT(OnTimeout()));

	using namespace cdgdecode;
	setMinimumSize( screen::Width, screen::Height );
	setMaximumSize( screen::Width, screen::Height );

	m_colors[0] = QColor(0,0,0);
	m_colors[1] = QColor(128, 0, 0);
	m_colors[2] = QColor(255, 0, 0);
	m_colors[3] = QColor(255, 0, 255);
	m_colors[4] = QColor(0, 128, 128);
	m_colors[5] = QColor(0, 128, 0);
	m_colors[6] = QColor(0, 255, 0);
	m_colors[7] = QColor(0, 255, 255);
	m_colors[8] = QColor(0, 0, 128);
	m_colors[9] = QColor(128, 0, 128);
	m_colors[10] = QColor(0, 0, 255);
	m_colors[11] = QColor(192, 192, 192);
	m_colors[12] = QColor(128, 128, 128);
	m_colors[13] = QColor(128, 128, 0);
	m_colors[14] = QColor(255, 255, 0);
	m_colors[15] = QColor(255, 255, 255);

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

	int x = row * screen::TileWidth;	
	int y = column * screen::TileHeight;	

	for(int tileX = 0; tileX < cdgdecode::screen::TileWidth; ++tileX)
	{
		for(int tileY = 0; tileY < cdgdecode::screen::TileHeight; ++tileY)
		{
			m_screen[tileX + x][tileY + y] = tile[tileX][tileY];
			//std::cout << "m_screen[" << (tileX + x) << "," << (tileY + y) << "] = tile[" << tileX << "," <<tileY << "] = " << static_cast<int>(tile[tileX][tileY]) << "\n";
		}
	}

	repaint();
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
			if (m_colors.contains(pixelColor))
			{
				c = m_colors[pixelColor];	
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

}


