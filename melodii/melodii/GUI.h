#pragma once
#include "controller.h"
#include <QAbstractTableModel>
#include <QPainter>
#include <qwidget.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qtableview.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qvariant.h>
#include <QPainter>
#include <QFormLayout>
class GUI : public QAbstractTableModel {
private:
	Controller& ctr;
public:
	GUI(Controller& ctr, QObject *parent = {}) :ctr{ ctr }, QAbstractTableModel{ parent } {};
	int rowCount(const QModelIndex &parent) const override {
		return this->ctr.getAll().size();
	}
	int columnCount(const QModelIndex &parent) const override {
		return 5;
	}
	QVariant data(const QModelIndex &index, int role /* = Qt::DisplayRole */) const override {
		if (role != Qt::DisplayRole&&role != Qt::EditRole)
			return{};
		const auto& music = this->ctr.getAll()[index.row()];
		switch (index.column()) {
		case 0:
			return music.getId();
		case 1:
			return QString::fromStdString(music.getTitlu());
		case 2:
			return QString::fromStdString(music.getArtist());
		case 3:
			return music.getRank();
		case 4:
			return this->ctr.rankNumber(music.getRank());
		default:
			return{};
		}
	}
	QVariant headerData(int section, Qt::Orientation orientation, int role /* = Qt::DisplayRole */) const override {
		if (orientation != Qt::Vertical&&role != Qt::DisplayRole)
			return{};
		switch (section) {
		case 0:
			return "id";
		case 1:
			return "titlu";
		case 2:
			return "autor";
		case 3:
			return "rank";
		case 4:
			return "frecventa";
		default:
			return{};
		}
	}

};


class iPod : public QWidget {
Q_OBJECT
private:
	Controller ctr;
	QHBoxLayout *first, *buttonLayout;
	QFormLayout  *second;
	QVBoxLayout  *mainLayout;
	QTableView *tabel;
	QLineEdit *titluTxt, *rankTxt;
	QPushButton *sterge, *modifica;
	Music mSelectata;
	int idSelectat;
	GUI model{ ctr };
protected:
	void paintEvent(QPaintEvent *ev)override {
		QPainter paint(this);
		for (int i = 0; i < 10; i++) {
			paint.fillRect(width()/10*i,height()-ctr.rankNumber(i)*20-20, width()/10-10, ctr.rankNumber(i) * 20, Qt::red);
		}
	}
public:
	iPod(Controller& c) :ctr{ c } { construiesteFereasta(); conectare(); };
	void construiesteFereasta();
	void conectare();
};
