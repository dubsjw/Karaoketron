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
	#if defined _WIN32 || defined _WIN64
	buffer.Open("C:/MaryHadALittleLamb.cdg");
	#else
	buffer.Open("/tmp/MaryHadALittleLamb.cdg");
	#endif


	QApplication app(argc, argv);
	cdgraster::CDGRasterWidget rw;	
	rw.setVisible(true);
	
	cdgdecode::PacketProcessor<cdgraster::CDGRasterWidget> pp(rw);

	cdgdecode::Packet packet(buffer, StartOfPackets);  
	int counter = 0;
	rw.SetNextListener( [&packet, &pp, &counter](int num) 
	{ 
		for(int i=0; i<num; ++i, ++counter)
		{
			++packet; 
			pp(packet);	
			//std::cout << "PACKET(" << counter << ")\n";
		}
	} );

	return app.exec();
}
