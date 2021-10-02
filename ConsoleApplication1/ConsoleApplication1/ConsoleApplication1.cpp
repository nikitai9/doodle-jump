#include <iostream>
#include "MainWindow.h"

int main()
{
	MainWindow * window = new MainWindow(500, 700, "Doodle Jump");
	window->setBgColor(255, 255, 255);
	window->show();

	delete window;
	return 0;
}