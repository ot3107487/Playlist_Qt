/********************************************************************************
** Form generated from reading UI file 'melodii.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MELODII_H
#define UI_MELODII_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_melodiiClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *melodiiClass)
    {
        if (melodiiClass->objectName().isEmpty())
            melodiiClass->setObjectName(QStringLiteral("melodiiClass"));
        melodiiClass->resize(600, 400);
        menuBar = new QMenuBar(melodiiClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        melodiiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(melodiiClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        melodiiClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(melodiiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        melodiiClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(melodiiClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        melodiiClass->setStatusBar(statusBar);

        retranslateUi(melodiiClass);

        QMetaObject::connectSlotsByName(melodiiClass);
    } // setupUi

    void retranslateUi(QMainWindow *melodiiClass)
    {
        melodiiClass->setWindowTitle(QApplication::translate("melodiiClass", "melodii", 0));
    } // retranslateUi

};

namespace Ui {
    class melodiiClass: public Ui_melodiiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MELODII_H
