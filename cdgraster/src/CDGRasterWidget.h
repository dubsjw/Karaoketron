#pragma once

#include <cdgdecode/Screen.h>
#include <QColor>
#include <QWidget>
#include <cstdint>
#include <functional>
#include <vector>

namespace cdgraster
{

class CDGRasterWidget : public QWidget
{
	Q_OBJECT
	public:

		CDGRasterWidget();

		void SetNextListener(std::function<void()> next);

		/**
		 * The following method is required by the MemoryPreset 
		 * instruction.
		 */
		void Clear(std::int8_t color);
		void ClearBorder(std::int8_t color);
		void DrawTile( std::int8_t row, std::int8_t column
			     , std::int8_t const* tile);


	protected:
		void paintEvent(QPaintEvent* evt);
		void mousePressEvent(QMouseEvent* evt);
	

	private:
		QHash<std::int8_t, QColor> m_colors;
		std::vector<std::vector<std::int8_t> > m_screen;
		std::function<void()> m_next;
};

}


