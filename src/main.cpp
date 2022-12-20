#include <QApplication>
#include "GraphicScene.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GraphicScene window;
	window.show();
	return a.exec();
}
