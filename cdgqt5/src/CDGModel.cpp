#include "src/CDGModel.h"

// cdgdecode dependencies
#include <cdgdecode/ColorTable.h>
#include <cdgdecode/Packet.h>
#include <cdgdecode/PacketProcessor.h>
#include <cdgdecode/Screen.h>

namespace cdgqt5
{


struct CDGModelPrivate
{
	//! The palette, gets set up through the file.
	cdgdecode::ColorTable m_palette;

	//! The file to load from.
	QString m_file;

	//! The packet processor.
	cdgdecode::PacketProcessor<CDGModel> m_packetProcessor;

	//! The local packet.
	//cdgdecode::Packet m_packet;


	CDGModelPrivate(CDGModel* api)
	: m_palette()
	, m_file()
	, m_packetProcessor(*api)
	//, m_packet()
	{
	}
};


CDGModel::CDGModel(QObject* parent)
: QObject(parent)
, d_ptr(new CDGModelPrivate(this))
{
}


CDGModel::~CDGModel()
{
	delete d_ptr;
}


void CDGModel::Load(QString const& filename)
{
	
}


cdgdecode::ColorTable& CDGModel::Palette()
{
	return d_ptr->m_palette;
}


void CDGModel::Clear(std::int8_t color)
{
}


void CDGModel::ClearBorder(std::int8_t color)
{
}


void CDGModel::DrawTile( std::int8_t row, std::int8_t column, cdgdecode::Tile const& tile )
{
}


void CDGModel::DrawXORTile( std::int8_t row, std::int8_t column, cdgdecode::Tile const& tile )
{
}



}
