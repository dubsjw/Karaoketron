#include "src/CDGRasterWidget.h"
#include <QBrush>
#include <QMouseEvent>
#include <QPainter>
#include <cstdlib>

namespace cdgraster
{

CDGRasterWidget::CDGRasterWidget()
: QWidget(nullptr)
{
	using namespace cdgdecode;
	setMinimumSize( screen::Width, screen::Height );
	setMaximumSize( screen::Width, screen::Height );

	for(int i=0; i<16; ++i)
	{
		m_colors[0] = QColor(rand() % 255, rand() % 255, rand() % 255);
	}

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


void CDGRasterWidget::DrawTile( std::int8_t row, std::int8_t column
	                      , std::int8_t const* tile)
{

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
	if (evt->button() == Qt::LeftButton)
	{
		m_next();
	}
}


void CDGRasterWidget::SetNextListener(std::function<void()> next)
{
	m_next = next;
}

}


