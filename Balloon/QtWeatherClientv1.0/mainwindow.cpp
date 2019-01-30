#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QHostAddress>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <unistd.h>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->dialog = new ServerSettingsDialog(this);
    statusBar()->showMessage("Sensor Application Started");
    this->temperature = 0.0f;
    this->updateDisplay();
    this->timer = new QTimer(this);
    //when the timer times out, call the on_timerUpdate() function
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timerUpdate()));
    this->timer->start(30000);             // time out after 5 sec
    this->createActions();
    if (startrec!=true){
        ui->lcdTemperature->display("---------");
        ui->lcdPressure->display("---------");
        ui->lcdLatitude->display("---------");
        ui->lcdLongitude->display("---------");
        ui->lcdAltitude->display("---------");
    }

}



void MainWindow::createActions(){
    QAction *exit = new QAction("&Exit", this);
    exit->setShortcut(QKeySequence(tr("Ctrl+X")));
    QAction *settings = new QAction("&Settings", this);
    settings->setShortcut(QKeySequence(tr("Ctrl+S")));
    QMenu *menu = menuBar()->addMenu("&Menu");
    menu->addAction(settings);
    menu->addAction(exit);
    connect(exit, SIGNAL(triggered()), qApp, SLOT(quit()));  //quit application
    connect(settings, SIGNAL(triggered()), this, SLOT(on_openSettings()));
}


void MainWindow::on_timerUpdate() {
    this->updateDisplay();
}

void MainWindow::updateDisplay() {
    getSensorReading();
    ui->lcdTemperature->display((double)temperature);
    ui->lcdPressure->display((double)pressure);
    ui->lcdLatitude->display((double)latitude);
    ui->lcdLongitude->display((double)longitude);
    ui->lcdAltitude->display((double)altitude);

}

void MainWindow::on_openSettings(){
    this->dialog->exec();                             // display the dialog box
    this->timer->start(1000*this->dialog->getTimeDelay()); //update timer delay
}

int MainWindow::getSensorReading(){
    // Get the server address and port from the settings dialog box
    serverPort = this->dialog->getServerPort();  // get from the dialog box
    serverAddr = this->dialog->getIPAddress();   // from the dialog box
    tcpSocket = new QTcpSocket(this);    // create socket
    tcpSocket->connectToHost(QHostAddress(serverAddr), serverPort); // connect
    if(!tcpSocket->waitForConnected(1000)){    //wait up to 1s for a connection
        statusBar()->showMessage("Failed to connect to server...");
        return 1;
    }
    // Send the message "getReading" to the server
    tcpSocket->write("getReading");
    if(!tcpSocket->waitForReadyRead(3000)){    // wait up to 3s for the server
        statusBar()->showMessage("Server did not respond...");
        return 1;
    }
    // If the server has sent bytes back to the client
    if(tcpSocket->bytesAvailable()>0){
        int size = tcpSocket->bytesAvailable(); // how many bytes are ready?
        char data[200];                         // upper limit of 200 chars
        tcpSocket->read(&data[0],(qint64)size); // read the number of bytes rec.
        data[size]='\0';                        // terminate the string
        cout << "Received the data [" << data << "]" << endl;
        this->parseJSONData(QString(data));

    }
    else{
        statusBar()->showMessage("No data available...");
    }
    return 0;    // the on_updateTemperature() slot will update the display
}

int MainWindow::parseJSONData(QString str){
    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject obj = doc.object();
    QJsonObject sample = obj["sample"].toObject();
    this->temperature = (float) sample["temperature"].toDouble();
    this->altitude = (float) sample["altitude"].toDouble();
    this->pressure = (float) sample["pressure"].toDouble();
    this->longitude= (float) sample["longitude"].toDouble();
    this->latitude = (float) sample["latitude"].toDouble();
    this->servo1_act = (float) sample["servo1_act"].toDouble();
    this->servo2_act= (float) sample["servo2_act"].toDouble();
    this->servo3_act= (float) sample["servo3_act"].toDouble();

    cout << "The temperature is " << temperature << " and altitude is " << altitude << " and pressure is "<<pressure<< endl;
    return 0;
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::successfulRelease()
{

    QMessageBox::information(this, "Release", "Parachute Released!");
    //if reply is yes then the system will tell you that the parachute has been released
    //or parachute has been released automatically
}

void MainWindow::ribbonRelease(QString color)
{

        QMessageBox::information(this, color + " Ribbon Release", "Ribbon Released!");

   //Display message showing that ribbon has been released
}


void MainWindow::autorelease( float altitude, float servo3_act)
{
    //upon reaching desired height send message saying parachute released
    if (altitude>=2990 && altitude <= 3010 && servo3_act==1)
    {
        successfulRelease();
    }

}


void MainWindow::ribbonConfirm(float altitude, float servo1_act, float servo2_act)
{
    if (altitude>=990 && altitude <= 1010 && servo1_act==1)
    {
        color="red";
        ribbonRelease(color);
    }
    if (altitude>=1990 && altitude <= 2010 && servo2_act==1)
    {
        color="black";
        ribbonRelease(color);
    }
}
void MainWindow::on_releaseButton_clicked()
{
    QMessageBox::StandardButton reply= QMessageBox::warning(this, "Confirmation", "Are you sure?",
                                                             QMessageBox::Yes | QMessageBox::No);
    //Makes variable for yes/no response to confirmation screen

    if (reply == QMessageBox::Yes)
    {
        // Get the server address and port from the settings dialog box
        serverPort = this->dialog->getServerPort();  // get from the dialog box
        serverAddr = this->dialog->getIPAddress();   // from the dialog box
        tcpSocket = new QTcpSocket(this);    // create socket
        tcpSocket->connectToHost(QHostAddress(serverAddr), serverPort); // connect
        if(!tcpSocket->waitForConnected(1000)){    //wait up to 1s for a connection
            statusBar()->showMessage("Failed to connect to server...");
        }
        // Send the message "manualRelease" to the server
        tcpSocket->write("manualRelease");
        if(!tcpSocket->waitForReadyRead(3000)){    // wait up to 3s for the server
            statusBar()->showMessage("Server did not respond...");
        }
        successfulRelease();

    }

}


//This fuction sends a command over the TCP socket to the Pi that it should call the raspistill single-image function
//The key for the raspistill function that the RPi is listening for is "getPicture"
void MainWindow::on_takePicture_clicked()
{
    // Get the server address and port from the settings dialog box
    serverPort = this->dialog->getServerPort();  // get from the dialog box
    serverAddr = this->dialog->getIPAddress();   // from the dialog box
    tcpSocket = new QTcpSocket(this);    // create socket
    tcpSocket->connectToHost(QHostAddress(serverAddr), serverPort); // connect
    if(!tcpSocket->waitForConnected(1000)){    //wait up to 1s for a connection
        statusBar()->showMessage("Failed to connect to server...");
    }
    // Send the message "getPicture" to the server
    tcpSocket->write("getPicture");
    if(!tcpSocket->waitForReadyRead(3000)){    // wait up to 3s for the server
        statusBar()->showMessage("Server did not respond...");
    }
    QMessageBox::about(this, "Picture Taken!", "Manual Picture has been Taken.");
    //tells user that picture has been taken
    //send signal to take picture
}

void MainWindow::on_beginMission_clicked()
{
    // Get the server address and port from the settings dialog box
    serverPort = this->dialog->getServerPort();  // get from the dialog box
    serverAddr = this->dialog->getIPAddress();   // from the dialog box
    tcpSocket = new QTcpSocket(this);    // create socket
    tcpSocket->connectToHost(QHostAddress(serverAddr), serverPort); // connect
    if(!tcpSocket->waitForConnected(1000)){    //wait up to 1s for a connection
        statusBar()->showMessage("Failed to connect to server...");
    }
    // Send the message "getPicture" to the server
    tcpSocket->write("startRecording");
    if(!tcpSocket->waitForReadyRead(3000)){    // wait up to 3s for the server
        statusBar()->showMessage("Server did not respond...");
    }
    startrec=true;
}

void MainWindow::on_endMission_clicked()
{
    // Get the server address and port from the settings dialog box
    serverPort = this->dialog->getServerPort();  // get from the dialog box
    serverAddr = this->dialog->getIPAddress();   // from the dialog box
    tcpSocket = new QTcpSocket(this);    // create socket
    tcpSocket->connectToHost(QHostAddress(serverAddr), serverPort); // connect
    if(!tcpSocket->waitForConnected(1000)){    //wait up to 1s for a connection
        statusBar()->showMessage("Failed to connect to server...");
    }
    // Send the message "getPicture" to the server
    tcpSocket->write("stopRecording");
    if(!tcpSocket->waitForReadyRead(3000)){    // wait up to 3s for the server
        statusBar()->showMessage("Server did not respond...");
    }

}
