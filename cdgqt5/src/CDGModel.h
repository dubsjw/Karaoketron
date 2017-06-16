#pragma once

// cdgqt5 dependencies
#include <cdgqt5/Globals.h>

// qt dependencies
#include <QObject>

namespace cdgdecode { class ColorTable; }
namespace cdgdecode { class Tile; }

namespace cdgqt5
{

struct CDGModelPrivate;

class CDGQT5_EXPORT CDGModel : public QObject
{
	Q_OBJECT

	public:
		CDGModel(QObject* parent=nullptr);
		~CDGModel();
		CDGModel(CDGModel const&) = delete;
		CDGModel& operator=(CDGModel const&) = delete;


		void Load(QString const& filename);	
		

	public: // Engine stuff.
		
		void Clear(std::int8_t color);	
		void ClearBorder(std::int8_t color);	
		void DrawTile( std::int8_t row, std::int8_t column, cdgdecode::Tile const& tile );
		void DrawXORTile( std::int8_t row, std::int8_t column, cdgdecode::Tile const& tile );
		cdgdecode::ColorTable& Palette();


	private:
		//! 
		CDGModelPrivate* d_ptr;
};

}


