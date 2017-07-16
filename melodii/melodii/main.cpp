#include "melodii.h"
#include <QtWidgets/QApplication>
#include "Music.h"
#include "Repo.h"
#include "GUI.h"
int main(int argc, char *argv[])
{
	Music::testDomain();
	Repo::testeRepo();
	QApplication a(argc, argv);
	Repo r{ "test.txt" };
	Controller c{ r };
	iPod i{ c };
	i.show();
	return a.exec();
}
