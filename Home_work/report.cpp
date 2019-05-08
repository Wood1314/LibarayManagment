#include "report.h"
#include "ui_report.h"
#include <QSqlQuery>
#include <QTableWidget>
#include <QPainter>

Report::Report(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Report)
{
    ui->setupUi(this);
    //设置标题
    this->setWindowTitle("报表模块");
    this->setWindowIcon(QIcon(":/image/icon.png"));
}

Report::~Report()
{
    delete ui;
}

void Report::on_pushButton_2_clicked()
{
    tableui = new QTableWidget(this);
    tableui->move(200,110);
    tableui->setFixedSize(600,280);
    tableui->setColumnCount(3);
    tableui->setHorizontalHeaderLabels(QStringList() << "书名"<< "ISBN"<< "库存量");
    QSqlQuery sqlquery;
    QString sql;
    sql = "select * from Book order by stock desc";
    sqlquery.exec(sql);
    int i=0;
    while(sqlquery.next())
    {
        tableui->setRowCount(i+1);
        tableui->setItem(i,0,new QTableWidgetItem(sqlquery.value(1).toString()));
        tableui->setItem(i,1,new QTableWidgetItem(sqlquery.value(2).toString()));
        tableui->setItem(i,2,new QTableWidgetItem(sqlquery.value(6).toString()));
        i++;
    }
    tableui->show();
}

void Report::on_pushButton_3_clicked()
{
    tableui = new QTableWidget(this);
    tableui->move(200,110);
    tableui->setFixedSize(600,280);
    tableui->setColumnCount(3);
    tableui->setHorizontalHeaderLabels(QStringList() << "书名"<< "ISBN"<< "入库日期");
    QSqlQuery sqlquery;
    QString sql;
    sql = "select * from Book order by date";
    sqlquery.exec(sql);
    int i=0;
    while(sqlquery.next())
    {
        tableui->setRowCount(i+1);
        tableui->setItem(i,0,new QTableWidgetItem(sqlquery.value(1).toString()));
        tableui->setItem(i,1,new QTableWidgetItem(sqlquery.value(2).toString()));
        tableui->setItem(i,2,new QTableWidgetItem(sqlquery.value(5).toString()));
        i++;
    }
    tableui->show();
}

void Report::on_pushButton_4_clicked()
{
    tableui = new QTableWidget(this);
    tableui->move(200,110);
    tableui->setFixedSize(600,280);
    tableui->setColumnCount(3);
    tableui->setHorizontalHeaderLabels(QStringList() << "书名"<< "ISBN"<< "库存量");
    QSqlQuery sqlquery;
    QString sql;
    sql = "select * from Book order by stock desc";
    sqlquery.exec(sql);
    int i=0;
    while(sqlquery.next())
    {
        tableui->setRowCount(i+1);
        tableui->setItem(i,0,new QTableWidgetItem(sqlquery.value(1).toString()));
        tableui->setItem(i,1,new QTableWidgetItem(sqlquery.value(2).toString()));
        tableui->setItem(i,2,new QTableWidgetItem(sqlquery.value(6).toString()));
        i++;
    }
    tableui->show();
}

void Report::on_pushButton_clicked()
{
    tableui = new QTableWidget(this);
    tableui->move(200,110);
    tableui->setFixedSize(600,280);
    tableui->setColumnCount(8);
    tableui->setHorizontalHeaderLabels(QStringList() << "ISBN"<< "书名"<< "作者"<< "出版社"<< "进书日期"<< "库存量"<< "批发价"<<"零售价");
    QSqlQuery sqlquery;
    QString sql;
    sql = "select * from Book";
    sqlquery.exec(sql);
    int i=0;
    while(sqlquery.next())
    {
       tableui->setRowCount(i+1);
       tableui->setItem(i,0,new QTableWidgetItem(sqlquery.value(2).toString()));
       tableui->setItem(i,1,new QTableWidgetItem(sqlquery.value(1).toString()));
       tableui->setItem(i,2,new QTableWidgetItem(sqlquery.value(3).toString()));
       tableui->setItem(i,3,new QTableWidgetItem(sqlquery.value(4).toString()));
       tableui->setItem(i,4,new QTableWidgetItem(sqlquery.value(5).toString()));
       tableui->setItem(i,5,new QTableWidgetItem(sqlquery.value(6).toString()));
       tableui->setItem(i,6,new QTableWidgetItem(sqlquery.value(7).toString()));
       tableui->setItem(i,7,new QTableWidgetItem(sqlquery.value(8).toString()));
       i++;
    }
    tableui->show();
}
void Report::paintEvent(QPaintEvent *)
{
    //背景
    QPainter painter(this);
    QPixmap pix(":/image/beg.png");
    painter.drawPixmap(0,0,900,600,pix);
}
