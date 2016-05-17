#include "src/Viewer.h"
#include <QApplication>


int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	Viewer V;
	V.setVisible(true);	

	return app.exec();
}


