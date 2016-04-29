#define CATCH_CONFIG_RUNNER

#include "catch.hpp"

#if defined QT_TEST_APP
	#include <QApplication>
#endif 

int main(int argc, char** argv)
{
	#if defined QT_TEST_APP
	QApplication app(argc, argv, false);
	#endif

	int result = Catch::Session().run(argc, argv);

	return result;
}

