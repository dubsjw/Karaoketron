#pragma once

#include <cdgdecode/ColorTable.h>
#include <cdgdecode/Screen.h>
#include <QColor>
#include <QTimer>
#include <QWidget>
#include <cstdint>
#include <functional>
#include <vector>

namespace cdgdecode { struct Tile; }

namespace cdgraster
{

class CDGRasterWidget : public QWidget
{
	Q_OBJECT
	public:

		CDGRasterWidget();

		void SetNextListener(std::function<void(int increment)> next);

		/**
		 * The following method is required by the MemoryPreset 
		 * instruction.
		 */
		void Clear(std::int8_t color);
		void ClearBorder(std::int8_t color);
		void DrawTile( std::int8_t row, std::int8_t column
			     , cdgdecode::Tile const& tile );

		void DrawXORTile( std::int8_t row, std::int8_t column
			        , cdgdecode::Tile const& tile );
		cdgdecode::ColorTable& Palette();

	public Q_SLOTS:
		void OnTimeout();

	protected:
		void paintEvent(QPaintEvent* evt);
		void mousePressEvent(QMouseEvent* evt);
	

	private:
		cdgdecode::ColorTable m_colors;
		std::vector<std::vector<std::int8_t> > m_screen;
		std::function<void(int increment)> m_next;
		QTimer m_timer;
};

}


