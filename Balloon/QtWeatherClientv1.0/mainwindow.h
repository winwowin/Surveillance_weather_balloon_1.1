#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTcpSocket>
#include <QMessageBox>
#include "serversettingsdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_timerUpdate();
    void on_openSettings();          // opens the server settings window

    void on_releaseButton_clicked();
    void on_takePicture_clicked();

    void on_beginMission_clicked();

    void on_endMission_clicked();

private:
    float temperature, altitude, pressure, latitude, longitude;
    QTimer *timer;                    // The timer that updates
    ServerSettingsDialog *dialog;     // The Server settings dialog
    float servo1_act, servo2_act, servo3_act; //serrvo actuation
    QString color; //ribbon color
    int serverPort;   // get from the dialog box
    quint32 serverAddr;   // from the dialog box
    QTcpSocket *tcpSocket;
    int getSensorReading();
    void updateDisplay();
    float celsiusToFahrenheit(float valueCelsius);
    int parseJSONData(QString str);
    Ui::MainWindow *ui;
    bool startrec;
    void createActions();             // sets up the menu for the window

    void successfulRelease();//Displays successful release box

    void ribbonRelease(QString color); //Display message showing that ribbon has been released, needs to take in color

    void autorelease(float altitude, float servo3_act); //release message for auto release

    void ribbonConfirm(float altitude, float servo1_act, float servo2_act); //notifies upon colored riboon release
};

#endif // MAINWINDOW_H
