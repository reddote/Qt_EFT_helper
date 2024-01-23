/********************************************************************************
** Form generated from reading UI file 'QtEftHelperHp9288.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef QTEFTHELPERHP9288_H
#define QTEFTHELPERHP9288_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtEftHelperClass
{
public:
    QWidget *centralWidget;
    QComboBox *weaponList;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtEftHelperClass)
    {
        if (QtEftHelperClass->objectName().isEmpty())
            QtEftHelperClass->setObjectName(QStringLiteral("QtEftHelperClass"));
        QtEftHelperClass->resize(608, 400);
        centralWidget = new QWidget(QtEftHelperClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        weaponList = new QComboBox(centralWidget);
        weaponList->setObjectName(QStringLiteral("weaponList"));
        weaponList->setGeometry(QRect(10, 20, 171, 22));
        QtEftHelperClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtEftHelperClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 608, 21));
        QtEftHelperClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtEftHelperClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtEftHelperClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtEftHelperClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtEftHelperClass->setStatusBar(statusBar);

        retranslateUi(QtEftHelperClass);

        QMetaObject::connectSlotsByName(QtEftHelperClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtEftHelperClass)
    {
        QtEftHelperClass->setWindowTitle(QApplication::translate("QtEftHelperClass", "QtEftHelper", 0));
        weaponList->clear();
        weaponList->insertItems(0, QStringList()
         << QApplication::translate("QtEftHelperClass", "M4A1", 0)
         << QApplication::translate("QtEftHelperClass", "Mp5", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class QtEftHelperClass: public Ui_QtEftHelperClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // QTEFTHELPERHP9288_H
