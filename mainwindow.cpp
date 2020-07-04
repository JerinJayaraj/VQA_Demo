#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QProcess>
#include "sockettest.h"

QString fileName;
QString question;

SocketTest::SocketTest(QObject *parent) : QObject(parent)
{

}

QString SocketTest::Connect()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1",6000);
    QString p;

    if(socket->waitForConnected(5000))
    {
        qDebug() <<"Connected";
        qDebug() <<fileName;
        qDebug() <<question;
        socket->write(QString(fileName + "\n" + question).toUtf8());
        //socket->write(QString(question + "\n").toUtf8());


        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(150000);
        qDebug() << "Reading" <<socket->bytesAvailable();
        p = socket->readAll();
        //qDebug() << socket->readAll();

        qDebug() <<p;
    }

    else
    {
        qDebug() <<"Not Connected";
    }

    return p;
    socket->close();
    qDebug() << "Closed";
}


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

    this->centralWidget()->setStyleSheet("background-image:url(\"bg2.png\");" );

	canDraw = false;
	pix = new QPixmap;

    //Display image 1
    ui->img1->setIcon(QIcon("test2.jpg"));
    ui->img1->setIconSize(QSize(224 , 224));

    //Display image 2
    ui->img2->setIcon(QIcon("test3.jpg"));
    ui->img2->setIconSize(QSize(224 , 224));

    //Display image 3
    ui->img3->setIcon(QIcon("test4.jpg"));
    ui->img3->setIconSize(QSize(224 , 224));

    //Display image 4
    ui->img4->setIcon(QIcon("test5.jpg"));
    ui->img4->setIconSize(QSize(224 , 224));

}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_browseButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::currentPath(), tr("Image Files (*.jpg *.jpeg)"));
    qDebug() << fileName;

    if (fileName != "")
    {
        QPixmap pixmap(fileName);
        ui->productImage->setPixmap(pixmap);
    }

}

// On clicking clear button -> clear selected image and question
void MainWindow::on_clear_clicked()
{
    ui->productImage->clear();
    canDraw = false;
    ui->lineEdit->setText("");
    ui->userInput->setText("");
}

void MainWindow::on_submit_clicked()
{
    question = ui->userInput->text();
    qDebug() << question;

    SocketTest cTest;
    QString p;
    p=cTest.Connect();
    qDebug() << p;

    //output display in lineEdit -> answer from program
    ui->lineEdit->setText(p);

}

// Image 1 button on clicking -> storing filename test2
void MainWindow::on_img1_clicked()
{
    fileName = "test2.jpg";
    qDebug() << fileName;

    if (fileName != "")
    {
        QPixmap pixmap("test2.jpg");
        ui->productImage->setPixmap(pixmap);
    }
}

// Image 2 button on clicking -> storing filename test3
void MainWindow::on_img2_clicked()
{
    fileName = "test3.jpg";
    qDebug() << fileName;

    if (fileName != "")
    {
        QPixmap pixmap("test3.jpg");
        ui->productImage->setPixmap(pixmap);
    }
}

// Image 3 button on clicking -> storing filename test4
void MainWindow::on_img3_clicked()
{
    fileName = "test4.jpg";
    qDebug() << fileName;

    if (fileName != "")
    {
        QPixmap pixmap("test4.jpg");
        ui->productImage->setPixmap(pixmap);
    }

}


// Image 4 button on clicking -> storing filename test5
void MainWindow::on_img4_clicked()
{
    fileName = "test5.jpg";
    qDebug() << fileName;

    if (fileName != "")
    {
        QPixmap pixmap("test5.jpg");
        ui->productImage->setPixmap(pixmap);
    }

}





