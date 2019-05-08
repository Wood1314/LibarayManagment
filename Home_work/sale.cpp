#include "sale.h"
#include "ui_sale.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QtDebug>
#include <QSqlQuery>
#include <QTableWidget>
#include <QInputDialog>
#include <QPainter>

Sale::Sale(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sale)
{
    ui->setupUi(this);
    this->setWindowTitle("销售模块");
    this->setWindowIcon(QIcon(":/image/icon.png"));
    set_taxRate();
    set_money();
}
Sale::~Sale()
{
    delete ui;
}
void Sale::set_taxRate()
{
    QSqlQuery sqlquery;
    QString sql;
    sql = "select rate from tax";
    sqlquery.exec(sql);
    sqlquery.first();
    tax_rate = sqlquery.value(0).toDouble();
}
double Sale::get_tax()
{
    return tax;
}
double Sale::get_sale()
{
    return sale;
}
double Sale::get_total()
{
    return total;
}
void Sale::set_money()
{
    ui->tax_label->setText(QString::number(get_tax(), 10, 2) + "RMB");
    ui->sale_label->setText(QString::number(get_sale(), 10, 2) + "RMB");
    ui->total_label->setText(QString::number(get_total(), 10, 2) + "RMB");
}

//void Sale:


//查询操作
void Sale::on_ser_btn_clicked()
{
    ui->buy_vi->setColumnCount(4);
    ui->buy_vi->setRowCount(i+1);
    if(QMessageBox::Yes == QMessageBox::question(this,"确认","确定购买吗?确认后无法取消购买操作。",QMessageBox::Yes | QMessageBox::No,QMessageBox::No))
    {
        QString a;
        if(ui->name_txt->text() == "")
        {
            QMessageBox::critical(this,"error","请输入书籍名称！");
            return;
        }
        else
        {
            a = QString("select * from Book where name = '%1'").arg(ui->name_txt->text());
        }
        QSqlQuery sqlquery2;
        sqlquery2.exec(a);
        if(!sqlquery2.next())
        {
            QMessageBox::information(this,"error","未找到指定图书");
            return;
        }
        else {
            if(sqlquery2.value(6).toInt()<1)
            {
                QMessageBox::information(this,"不足",QString("库存不足。当前此书库存为%1本").arg(sqlquery2.value(6).toString()));
            }
            else
            {
                QMessageBox::information(this,"成功","购买成功");
                sale+=sqlquery2.value(8).toDouble();
                tax = tax_rate * sale;
                total = sale + tax;
                ui->tax_label->setText(QString::number(get_tax(), 10, 2) + "RMB");
                ui->sale_label->setText(QString::number(get_sale(), 10, 2) + "RMB");
                ui->total_label->setText(QString::number(get_total(), 10, 2) + "RMB");
                ui->buy_vi->setItem(i,0,new QTableWidgetItem(sqlquery2.value(2).toString()));
                ui->buy_vi->setItem(i,1,new QTableWidgetItem(sqlquery2.value(1).toString()));
                ui->buy_vi->setItem(i,2,new QTableWidgetItem(sqlquery2.value(8).toString()));
                ui->buy_vi->setItem(i,3,new QTableWidgetItem(QString("%1").arg(sqlquery2.value(8).toDouble())));
                i++;
            }

        }
    }
}
//修改税率
void Sale::on_cagtax_btn_clicked()
{
    bool isok;
    QString taxrare1;
    QString tax_rate1= QInputDialog::getText(this,"改变税率","请输入税率",QLineEdit::Normal,taxrare1,&isok);
    if(isok)
    {
        if(tax_rate1.toDouble()>0)
        {
            QSqlQuery sqlquery1;
            QString a;
            tax = sale*tax_rate1.toDouble();
            total = tax + sale;
            set_money();
            QMessageBox::information(this,"成功","修改税率成功");
            a = QString("update tax set rate = %1 where id = 1").arg(tax_rate1.toDouble());
            sqlquery1.exec(a);
        }
        else {
            QMessageBox::information(this,"失败","修改税率失败");
        }
    }
}
//收银
void Sale::on_check_btn_clicked()
{
    tax = 0;
    sale = 0;
    total = 0;
    QMessageBox::question(this,"确认","确定收银吗?",QMessageBox::Yes | QMessageBox::No,QMessageBox::No);
    QMessageBox::information(this,"成功","收银成功");
    this->close();
}
void Sale::paintEvent(QPaintEvent *)
{
    //背景
    QPainter painter(this);
    QPixmap pix(":/image/beg.png");
    painter.drawPixmap(0,0,900,600,pix);
}
