/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QPushButton *releaseButton;
    QPushButton *takePicture;
    QLabel *WE_ARE;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *lcdAltitude;
    QLabel *altitudeUnits;
    QHBoxLayout *horizontalLayout_2;
    QLCDNumber *lcdTemperature;
    QLabel *temperatureUnits;
    QHBoxLayout *horizontalLayout_3;
    QLCDNumber *lcdPressure;
    QLabel *pressureUnits;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *beginMission;
    QPushButton *endMission;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLCDNumber *lcdLatitude;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLCDNumber *lcdLongitude;
    QMenuBar *menuBar;
    QMenu *menuSettings;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 400, 400));
        releaseButton = new QPushButton(centralWidget);
        releaseButton->setObjectName(QStringLiteral("releaseButton"));
        releaseButton->setGeometry(QRect(560, 10, 251, 91));
        releaseButton->setFlat(false);
        takePicture = new QPushButton(centralWidget);
        takePicture->setObjectName(QStringLiteral("takePicture"));
        takePicture->setGeometry(QRect(130, 410, 141, 51));
        WE_ARE = new QLabel(centralWidget);
        WE_ARE->setObjectName(QStringLiteral("WE_ARE"));
        WE_ARE->setGeometry(QRect(430, 430, 541, 131));
        QFont font;
        font.setPointSize(28);
        WE_ARE->setFont(font);
        WE_ARE->setPixmap(QPixmap(QString::fromUtf8("../AERSP-header.png")));
        WE_ARE->setScaledContents(true);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(480, 110, 401, 191));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lcdAltitude = new QLCDNumber(widget);
        lcdAltitude->setObjectName(QStringLiteral("lcdAltitude"));

        horizontalLayout->addWidget(lcdAltitude);

        altitudeUnits = new QLabel(widget);
        altitudeUnits->setObjectName(QStringLiteral("altitudeUnits"));

        horizontalLayout->addWidget(altitudeUnits);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lcdTemperature = new QLCDNumber(widget);
        lcdTemperature->setObjectName(QStringLiteral("lcdTemperature"));

        horizontalLayout_2->addWidget(lcdTemperature);

        temperatureUnits = new QLabel(widget);
        temperatureUnits->setObjectName(QStringLiteral("temperatureUnits"));

        horizontalLayout_2->addWidget(temperatureUnits);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lcdPressure = new QLCDNumber(widget);
        lcdPressure->setObjectName(QStringLiteral("lcdPressure"));

        horizontalLayout_3->addWidget(lcdPressure);

        pressureUnits = new QLabel(widget);
        pressureUnits->setObjectName(QStringLiteral("pressureUnits"));

        horizontalLayout_3->addWidget(pressureUnits);


        verticalLayout->addLayout(horizontalLayout_3);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(560, 350, 247, 32));
        horizontalLayout_4 = new QHBoxLayout(widget1);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        beginMission = new QPushButton(widget1);
        beginMission->setObjectName(QStringLiteral("beginMission"));
        QFont font1;
        font1.setPointSize(14);
        beginMission->setFont(font1);

        horizontalLayout_4->addWidget(beginMission);

        endMission = new QPushButton(widget1);
        endMission->setObjectName(QStringLiteral("endMission"));
        endMission->setFont(font1);

        horizontalLayout_4->addWidget(endMission);

        widget2 = new QWidget(centralWidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(10, 470, 291, 61));
        verticalLayout_2 = new QVBoxLayout(widget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label = new QLabel(widget2);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setPointSize(16);
        label->setFont(font2);

        horizontalLayout_6->addWidget(label);

        lcdLatitude = new QLCDNumber(widget2);
        lcdLatitude->setObjectName(QStringLiteral("lcdLatitude"));

        horizontalLayout_6->addWidget(lcdLatitude);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(widget2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font2);

        horizontalLayout_5->addWidget(label_2);

        lcdLongitude = new QLCDNumber(widget2);
        lcdLongitude->setObjectName(QStringLiteral("lcdLongitude"));

        horizontalLayout_5->addWidget(lcdLongitude);


        verticalLayout_2->addLayout(horizontalLayout_5);

        MainWindow->setCentralWidget(centralWidget);
        lcdTemperature->raise();
        temperatureUnits->raise();
        lcdPressure->raise();
        pressureUnits->raise();
        graphicsView->raise();
        lcdAltitude->raise();
        altitudeUnits->raise();
        label->raise();
        label_2->raise();
        lcdLatitude->raise();
        lcdLongitude->raise();
        beginMission->raise();
        endMission->raise();
        releaseButton->raise();
        takePicture->raise();
        WE_ARE->raise();
        altitudeUnits->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 22));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSettings->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RPi Weather Client", Q_NULLPTR));
        releaseButton->setText(QApplication::translate("MainWindow", "PARACHUTE EMERGENCY RELEASE", Q_NULLPTR));
        takePicture->setText(QApplication::translate("MainWindow", "Capture Image", Q_NULLPTR));
        WE_ARE->setText(QString());
        altitudeUnits->setText(QApplication::translate("MainWindow", "Altitude (feet)", Q_NULLPTR));
        temperatureUnits->setText(QApplication::translate("MainWindow", "Temperature (deg C)", Q_NULLPTR));
        pressureUnits->setText(QApplication::translate("MainWindow", "Pressure (Pa)", Q_NULLPTR));
        beginMission->setText(QApplication::translate("MainWindow", "Begin Mission", Q_NULLPTR));
        endMission->setText(QApplication::translate("MainWindow", "End Mission", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Latitude", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Longititude", Q_NULLPTR));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
