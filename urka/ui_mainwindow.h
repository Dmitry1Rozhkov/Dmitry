/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QCustomPlot *widget;
    QPushButton *pushButton;
    QCustomPlot *widget_2;
    QCustomPlot *widget_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1148, 661);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QCustomPlot(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 50, 491, 251));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setTabletTracking(false);
        widget->setAutoFillBackground(false);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 10, 111, 31));
        pushButton->setLayoutDirection(Qt::LeftToRight);
        pushButton->setAutoFillBackground(false);
        widget_2 = new QCustomPlot(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(570, 50, 511, 251));
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setTabletTracking(false);
        widget_3 = new QCustomPlot(centralWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(20, 310, 491, 271));
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        widget_3->setTabletTracking(false);
        widget_3->setFocusPolicy(Qt::NoFocus);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1148, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
