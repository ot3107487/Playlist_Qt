#include "GUI.h"

void iPod::construiesteFereasta()
{
	mainLayout = new QVBoxLayout(this);
	first = new QHBoxLayout();
	tabel = new QTableView();
	tabel->setSelectionBehavior(QAbstractItemView::SelectRows);
	tabel->resizeColumnsToContents();
	tabel->setModel(&this->model);
	tabel->setMaximumHeight(height() / 3);
	first->addWidget(tabel);
	first->setContentsMargins(0, 0, 0, height()/3);
	second = new QFormLayout();
	titluTxt = new QLineEdit();
	titluTxt->setPlaceholderText("Introduceti titlul");
	rankTxt = new QLineEdit();
	rankTxt->setPlaceholderText("Introduceti rank-ul");
	second->addRow(titluTxt);
	second->addRow(rankTxt);
	sterge = new QPushButton("&Sterge");
	modifica = new QPushButton("&Modifica");
	second->addRow(sterge, modifica);
	first->addLayout(second);
	mainLayout->addLayout(first);
	mainLayout->addSpacing(height()/3);
}

void iPod::conectare()
{
	QObject::connect(tabel, &QTableView::clicked, [&]() {
		if (tabel->selectionModel()->selection().indexes().size() > 0)
		{
			mSelectata = ctr.getAll()[tabel->selectionModel()->selection().indexes().at(0).row()];
			titluTxt->setText(QString::fromStdString(mSelectata.getTitlu()));
			rankTxt->setText(QString::fromStdString(to_string(mSelectata.getRank())));
			tabel->reset();
			repaint();
		}
	});
	QObject::connect(sterge, &QPushButton::clicked, [&]() {
		ctr.dilit(mSelectata.getId());
		tabel->reset();
	});
	QObject::connect(modifica, &QPushButton::clicked, [&]() {
		ctr.update(Music{ mSelectata.getId(),mSelectata.getTitlu(),titluTxt->text().toStdString(),rankTxt->text().toInt() });
		tabel->reset();
		repaint();
	});

}
