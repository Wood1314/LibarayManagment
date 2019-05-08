#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIcon>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QPainter>
#include <QTimer>
#include <QBitmap>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("图书管理系统");
    //链接数据库
    //使用sql odbc插件
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //远程连接
    db.setHostName("******");
    db.setPort(3306);
    db.setDatabaseName("******");
    db.setUserName("******");
    db.setPassword("******");

    if(db.open()==false){
        QMessageBox::critical(this,"warning","it cannot open datebase \nPlease check the network connection");
    }
    //设置图片
    this->setWindowIcon(QIcon(":/image/icon.png"));
    //时间显示的实现
    //启用计时器 1s更新1次
    QTimer *timer = new QTimer(this);
    timer->start(1000);
    connect(timer,&QTimer::timeout,[=](){
        QDateTime time = QDateTime::currentDateTime();
        QString timeStr = time.toString("yyyy-MM-dd hh:mm:ss");
        ui->time_label->setText(timeStr);
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    custom = new Sale;
    custom ->exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    manboss = new Management;
    manboss->exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    reboss = new Report;
    reboss->exec();
}

void MainWindow::on_actionhelp_triggered()
{
    QMessageBox::information(this, tr("图书管理系统"),
                                     tr("详情请见帮助文档"));

}

void MainWindow::on_actionadd_triggered()
{
    QMessageBox::information(this, tr("图书管理系统"),
                                     tr("161820323刘嘉木\n"
                                        "id wood"));
}
void MainWindow::paintEvent(QPaintEvent *)
{
    //背景
    QPainter painter(this);
    QPixmap pix(":/image/beg.png");
    painter.drawPixmap(0,0,900,600,pix);
    //logo显示
    QPainter painter_logo(this);
    painter_logo.drawPixmap(20,708,QPixmap(":/image/logo.png"));

}

void MainWindow::on_actionthanks_triggered()
{
    QMessageBox::information(this, tr("特别感谢"),
                                     tr("网易云课堂qt入门精讲\n"
                                        "陈楚燚 id:desperado 给予的技术上的支持\n"
                                        "刘志赞 id:Kitty 给予的服务器支持"));
}
