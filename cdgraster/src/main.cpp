#include <cdgdecode/CDGBuffer.h>
#include <cdgdecode/Packet.h>
#include <cdgdecode/PacketProcessor.h>

#include "src/CDGRasterWidget.h"
#include <QApplication>
#include <QLabel>
#include <iostream>

enum 
{
	StartOfPackets = 16 * 6 

};


int main(int argc, char** argv)
{
	cdgdecode::CDGBuffer buffer;
	buffer.Open("/tmp/MaryHadALittleLamb.cdg");


	QApplication app(argc, argv);
	cdgraster::CDGRasterWidget rw;	
	rw.setVisible(true);
	
	cdgdecode::PacketProcessor<cdgraster::CDGRasterWidget> pp(rw);

	cdgdecode::Packet packet(buffer, StartOfPackets);  

	rw.SetNextListener( [&packet, &pp]() 
	{ 
		++packet; 
		pp(packet);	
		std::cout << "NEXT PACKET!\n"; 
	} );

	return app.exec();
}
