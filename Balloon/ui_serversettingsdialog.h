/********************************************************************************
** Form generated from reading UI file 'serversettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERSETTINGSDIALOG_H
#define UI_SERVERSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ServerSettingsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *serverSettingsGroup;
    QLabel *portnumberLabel;
    QSpinBox *addrBox1;
    QSpinBox *addrBox2;
    QSpinBox *addrBox3;
    QSpinBox *addrBox4;
    QSpinBox *portSpinBox;
    QGroupBox *clientSettingsGroup;
    QLabel *timeSampleLabel;
    QLabel *secondsLabel;
    QSpinBox *timeSampleSpinBox;

    void setupUi(QDialog *ServerSettingsDialog)
    {
        if (ServerSettingsDialog->objectName().isEmpty())
            ServerSettingsDialog->setObjectName(QStringLiteral("ServerSettingsDialog"));
        ServerSettingsDialog->resize(292, 209);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ServerSettingsDialog->sizePolicy().hasHeightForWidth());
        ServerSettingsDialog->setSizePolicy(sizePolicy);
        ServerSettingsDialog->setMinimumSize(QSize(292, 209));
        ServerSettingsDialog->setMaximumSize(QSize(292, 209));
        buttonBox = new QDialogButtonBox(ServerSettingsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(80, 170, 201, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        serverSettingsGroup = new QGroupBox(ServerSettingsDialog);
        serverSettingsGroup->setObjectName(QStringLiteral("serverSettingsGroup"));
        serverSettingsGroup->setGeometry(QRect(10, 10, 271, 91));
        portnumberLabel = new QLabel(serverSettingsGroup);
        portnumberLabel->setObjectName(QStringLiteral("portnumberLabel"));
        portnumberLabel->setGeometry(QRect(20, 60, 91, 16));
        addrBox1 = new QSpinBox(serverSettingsGroup);
        addrBox1->setObjectName(QStringLiteral("addrBox1"));
        addrBox1->setGeometry(QRect(20, 30, 51, 22));
        addrBox1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        addrBox1->setMaximum(255);
        addrBox1->setValue(192);
        addrBox2 = new QSpinBox(serverSettingsGroup);
        addrBox2->setObjectName(QStringLiteral("addrBox2"));
        addrBox2->setGeometry(QRect(80, 30, 51, 22));
        addrBox2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        addrBox2->setMaximum(255);
        addrBox2->setValue(168);
        addrBox3 = new QSpinBox(serverSettingsGroup);
        addrBox3->setObjectName(QStringLiteral("addrBox3"));
        addrBox3->setGeometry(QRect(140, 30, 51, 22));
        addrBox3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        addrBox3->setMaximum(255);
        addrBox3->setValue(1);
        addrBox4 = new QSpinBox(serverSettingsGroup);
        addrBox4->setObjectName(QStringLiteral("addrBox4"));
        addrBox4->setGeometry(QRect(200, 30, 51, 22));
        addrBox4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        addrBox4->setMaximum(255);
        addrBox4->setValue(1);
        portSpinBox = new QSpinBox(serverSettingsGroup);
        portSpinBox->setObjectName(QStringLiteral("portSpinBox"));
        portSpinBox->setGeometry(QRect(100, 60, 71, 22));
        portSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        portSpinBox->setMaximum(65535);
        portSpinBox->setValue(5555);
        clientSettingsGroup = new QGroupBox(ServerSettingsDialog);
        clientSettingsGroup->setObjectName(QStringLiteral("clientSettingsGroup"));
        clientSettingsGroup->setGeometry(QRect(10, 110, 271, 51));
        timeSampleLabel = new QLabel(clientSettingsGroup);
        timeSampleLabel->setObjectName(QStringLiteral("timeSampleLabel"));
        timeSampleLabel->setGeometry(QRect(10, 20, 101, 16));
        secondsLabel = new QLabel(clientSettingsGroup);
        secondsLabel->setObjectName(QStringLiteral("secondsLabel"));
        secondsLabel->setGeometry(QRect(200, 20, 46, 21));
        timeSampleSpinBox = new QSpinBox(clientSettingsGroup);
        timeSampleSpinBox->setObjectName(QStringLiteral("timeSampleSpinBox"));
        timeSampleSpinBox->setGeometry(QRect(130, 20, 61, 22));
        timeSampleSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        timeSampleSpinBox->setMaximum(50000);
        timeSampleSpinBox->setValue(30);
        serverSettingsGroup->raise();
        buttonBox->raise();
        clientSettingsGroup->raise();

        retranslateUi(ServerSettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ServerSettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ServerSettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ServerSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *ServerSettingsDialog)
    {
        ServerSettingsDialog->setWindowTitle(QApplication::translate("ServerSettingsDialog", "RPi Server Settings", Q_NULLPTR));
        serverSettingsGroup->setTitle(QApplication::translate("ServerSettingsDialog", "Server IP Address:", Q_NULLPTR));
        portnumberLabel->setText(QApplication::translate("ServerSettingsDialog", "Port Number:", Q_NULLPTR));
        clientSettingsGroup->setTitle(QApplication::translate("ServerSettingsDialog", "Client Settings:", Q_NULLPTR));
        timeSampleLabel->setText(QApplication::translate("ServerSettingsDialog", "Time Sample Period:", Q_NULLPTR));
        secondsLabel->setText(QApplication::translate("ServerSettingsDialog", "Seconds", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ServerSettingsDialog: public Ui_ServerSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERSETTINGSDIALOG_H
