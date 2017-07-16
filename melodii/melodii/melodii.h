#ifndef MELODII_H
#define MELODII_H

#include <QtWidgets/QMainWindow>
#include "ui_melodii.h"

class melodii : public QMainWindow
{
	Q_OBJECT

public:
	melodii(QWidget *parent = 0);
	~melodii();

private:
	Ui::melodiiClass ui;
};

#endif // MELODII_H
