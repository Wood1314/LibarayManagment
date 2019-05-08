#include "management.h"
#include "ui_management.h"
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QSqlQuery>
#include <QPainter>
#include <QMessageBox>
#include <QTabWidget>
#include <QDebug>

Management::Management(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Management)
{
    QFont ft;
    ui->setupUi(this);


     this->setWindowIcon(QIcon(":/image/icon.png"));
    this->setWindowTitle("管理模块");
//创建一个label并隐藏，点击查询按钮后触发show
    serchLabel = new QLabel(this);
    serchLabel->setText("查询模块（请至少输入一个查询信息）");
    serchLabel->move(250,50);
    ft.setPointSize(16);
    serchLabel->setFont(ft);
//创建第一个查询Label
    serchLabel_name = new QLabel(this);
    serchLabel_name->setText("图书名称:");
    serchLabel_name->move(255,107);
    ft.setPointSize(10);
    serchLabel_name->setFont(ft);
//创建第二个查询Label
    serchLabel_author = new QLabel(this);
    serchLabel_author->setText("作者:");
    serchLabel_author->move(255,157);
    ft.setPointSize(10);
    serchLabel_author->setFont(ft);
//创建第三个查询Label
    serchLabel_out = new QLabel(this);
    serchLabel_out->setText("出版社:");
    serchLabel_out->move(255,207);
    ft.setPointSize(10);
    serchLabel_out->setFont(ft);
//创建第四个查询Label
    serchLabel_isbn = new QLabel(this);
    serchLabel_isbn->setText("ISBN号:");
    serchLabel_isbn->move(255,257);
    ft.setPointSize(10);
    serchLabel_isbn->setFont(ft);
//创建Edit
    serchEdit_name = new QLineEdit(this);
    serchEdit_name->move(355,105);

    serchEdit_author = new QLineEdit(this);
    serchEdit_author->move(355,155);

    serchEdit_out = new QLineEdit(this);
    serchEdit_out->move(355,205);

    serchEdit_isbn = new QLineEdit(this);
    serchEdit_isbn->move(355,255);

    serSer_btn = new QPushButton(this);
    serSer_btn->move(420,337);
    serSer_btn->setText("查询");
    serSer_btn->setStyleSheet("background-image: url(:/image/btn7.png);");

    response = new QTableWidget(this);
    response->move(220,80);
    response->setFixedSize(450,300);
    response->setColumnCount(8);
    response->setHorizontalHeaderLabels(QStringList() << "ISBN"<< "书名"<< "作者"<< "出版社"<< "进书日期"<< "库存量"<< "批发价"<<"零售价");

    //添加模块
    addLabel_name = new QLabel(this);
    addLabel_name->move(255,107);
    addLabel_name->setText("图书名称:");
    addLabel_name->setFont(ft);

    addLabel_isbn = new QLabel(this);
    addLabel_isbn->move(255,137);
    addLabel_isbn->setText("ISBN号:");
    addLabel_isbn->setFont(ft);

    addLabel_author = new QLabel(this);
    addLabel_author->move(255,167);
    addLabel_author->setText("作者:");
    addLabel_author->setFont(ft);

    addLabel_out = new QLabel(this);
    addLabel_out->move(255,197);
    addLabel_out->setText("出版社:");
    addLabel_out->setFont(ft);

    addLabel_time = new QLabel(this);
    addLabel_time->move(255,227);
    addLabel_time->setText("入库时间:");
    addLabel_time->setFont(ft);

    addLabel_num = new QLabel(this);
    addLabel_num->move(255,257);
    addLabel_num->setText("库存量:");
    addLabel_num->setFont(ft);


    addLabel_or = new QLabel(this);
    addLabel_or->move(255,287);
    addLabel_or->setText("批发价:");
    addLabel_or->setFont(ft);

    addLabel_re = new QLabel(this);
    addLabel_re->move(255,317);
    addLabel_re->setText("零售价:");
    addLabel_re->setFont(ft);

    addLabel = new QLabel(this);
    addLabel->setText("增添模块");
    addLabel->move(300,50);
    ft.setPointSize(16);
    addLabel->setFont(ft);
    addLabel->show();

    addEdit_name = new QLineEdit(this);
    addEdit_name->move(355,105);

    addEdit_isbn = new QLineEdit(this);
    addEdit_isbn->move(355,135);

    addEdit_author = new QLineEdit(this);
    addEdit_author->move(355,165);

    addEdit_out = new QLineEdit(this);
    addEdit_out->move(355,195);

    addEdit_date = new QDateEdit(this);
    addEdit_date->move(355,225);

    addEdit_num = new QLineEdit(this);
    addEdit_num->move(355,255);

    addEdit_or = new QLineEdit(this);
    addEdit_or->move(355,285);

    addEdit_re = new QLineEdit(this);
    addEdit_re->move(355,315);

    addSer_btn = new QPushButton(this);
    addSer_btn->move(400,357);
    addSer_btn->setText("增加");
    addSer_btn->setStyleSheet("background-image: url(:/image/btn7.png);");
//修改模块
    changeLabel = new QLabel(this);
    changeLabel->setText("修改模块（请至少输入一个查询信息）");
    changeLabel->move(250,50);
    ft.setPointSize(16);
    changeLabel->setFont(ft);

    changeLabel_name = new QLabel(this);
    changeLabel_name->move(255,157);
    changeLabel_name->setText("图书名称:");
    ft.setPointSize(10);
    changeLabel_name->setFont(ft);

    changeLabel_isbn = new QLabel(this);
    changeLabel_isbn->move(255,257);
    changeLabel_isbn->setText("ISBN:");
    changeLabel_isbn->setFont(ft);

    changeEdit_name = new QLineEdit(this);
    changeEdit_name->move(355,157);

    changeEdit_isbn = new QLineEdit(this);
    changeEdit_isbn->move(355,257);

    chagSer_btn = new QPushButton(this);
    chagSer_btn->move(400,337);
    chagSer_btn->setText("修改");
    chagSer_btn->setStyleSheet("background-image: url(:/image/btn7.png);");

    add1Label_name = new QLabel(this);
    add1Label_name->move(255,107);
    add1Label_name->setText("图书名称:");
    add1Label_name->setFont(ft);

    add1Label_isbn = new QLabel(this);
    add1Label_isbn->move(255,137);
    add1Label_isbn->setText("ISBN号:");
    add1Label_isbn->setFont(ft);

    add1Label_author = new QLabel(this);
    add1Label_author->move(255,167);
    add1Label_author->setText("作者:");
    add1Label_author->setFont(ft);

    add1Label_out = new QLabel(this);
    add1Label_out->move(255,197);
    add1Label_out->setText("出版社:");
    add1Label_out->setFont(ft);

    add1Label_time = new QLabel(this);
    add1Label_time->move(255,227);
    add1Label_time->setText("入库时间:");
    add1Label_time->setFont(ft);

    add1Label_num = new QLabel(this);
    add1Label_num->move(255,257);
    add1Label_num->setText("库存量:");
    add1Label_num->setFont(ft);


    add1Label_or = new QLabel(this);
    add1Label_or->move(255,287);
    add1Label_or->setText("批发价:");
    add1Label_or->setFont(ft);

    add1Label_re = new QLabel(this);
    add1Label_re->move(255,317);
    add1Label_re->setText("零售价:");
    add1Label_re->setFont(ft);

    add1Label = new QLabel(this);
    add1Label->setText("增添模块");
    add1Label->move(300,50);
    ft.setPointSize(16);
    add1Label->setFont(ft);
    add1Label->show();

    add1Edit_name = new QLineEdit(this);
    add1Edit_name->move(355,105);

    add1Edit_isbn = new QLineEdit(this);
    add1Edit_isbn->move(355,135);

    add1Edit_author = new QLineEdit(this);
    add1Edit_author->move(355,165);

    add1Edit_out = new QLineEdit(this);
    add1Edit_out->move(355,195);

    add1Edit_date = new QDateEdit(this);
    add1Edit_date->move(355,225);

    add1Edit_num = new QLineEdit(this);
    add1Edit_num->move(355,255);

    add1Edit_or = new QLineEdit(this);
    add1Edit_or->move(355,285);

    add1Edit_re = new QLineEdit(this);
    add1Edit_re->move(355,315);

    add1Ser_btn = new QPushButton(this);
    add1Ser_btn->move(400,357);
    add1Ser_btn->setText("修改");
    add1Ser_btn->setStyleSheet("background-image: url(:/image/btn7.png);");
//删除模块
    delLabel = new QLabel(this);
    delLabel->setText("删除模块（请至少输入一个查询信息）");
    delLabel->move(250,50);
    ft.setPointSize(16);
    delLabel->setFont(ft);

    delLabel_name = new QLabel(this);
    delLabel_name->move(255,157);
    delLabel_name->setText("图书名称:");
    ft.setPointSize(10);
    delLabel_name->setFont(ft);

    delLabel_isbn = new QLabel(this);
    delLabel_isbn->move(255,257);
    delLabel_isbn->setText("ISBN:");
    delLabel_isbn->setFont(ft);

    delEdit_name = new QLineEdit(this);
    delEdit_name->move(355,157);

    delEdit_isbn = new QLineEdit(this);
    delEdit_isbn->move(355,257);

    delSer_btn = new QPushButton(this);
    delSer_btn->move(400,337);
    delSer_btn->setText("删除");
    delSer_btn->setStyleSheet("background-image: url(:/image/btn7.png);");
//将所有ui隐藏
    hide_all();
    //连接函数
    connect(this->delSer_btn,SIGNAL(clicked(bool)),this,SLOT(del_book()));
    connect(this->serSer_btn,SIGNAL(clicked(bool)),this,SLOT(ser_book()));
    connect(this->chagSer_btn,SIGNAL(clicked(bool)),this,SLOT(chag_book()));
    connect(this->addSer_btn,SIGNAL(clicked(bool)),this,SLOT(chag_book()));
    connect(this->add1Ser_btn,SIGNAL(clicked(bool)),this,SLOT(add1_book()));
}

Management::~Management()
{
    delete ui;
}


void Management::on_serch_btn_clicked()
{
    //把之前所有的都隐藏
    hide_all();
    //触发标签头的label
    serchLabel->show();
    serchLabel_out->show();
    serchLabel_isbn->show();
    serchLabel_name->show();
    serchLabel_author->show();
    serchEdit_out->show();
    serchEdit_isbn->show();
    serchEdit_name->show();
    serchLabel_isbn->show();
    serchEdit_author->show();
    serSer_btn->show();
}

void Management::hide_all()
{
    serchLabel->hide();
    serchLabel_out->hide();
    serchLabel_isbn->hide();
    serchLabel_name->hide();
    serchLabel_author->hide();
    serchEdit_out->hide();
    serchEdit_isbn->hide();
    serchEdit_name->hide();
    serchLabel_isbn->hide();
    serchEdit_author->hide();
    serSer_btn->hide();
    response->hide();

    addLabel->hide();
    addLabel_name->hide();
    addLabel_author->hide();
    addLabel_isbn->hide();
    addLabel_out->hide();
    addLabel_time->hide();
    addLabel_num->hide();
    addLabel_or->hide();
    addLabel_re->hide();
    addEdit_name->hide();
    addEdit_author->hide();
    addEdit_isbn->hide();
    addEdit_out->hide();
    addEdit_date->hide();
    addEdit_or->hide();
    addEdit_num->hide();
    addEdit_re->hide();
    addSer_btn->hide();

    changeLabel->hide();
    changeLabel_name->hide();
    changeLabel_isbn->hide();
    changeEdit_name->hide();
    changeEdit_isbn->hide();
    chagSer_btn->hide();
    add1Label->hide();
    add1Label_name->hide();
    add1Label_author->hide();
    add1Label_isbn->hide();
    add1Label_out->hide();
    add1Label_time->hide();
    add1Label_num->hide();
    add1Label_or->hide();
    add1Label_re->hide();
    add1Edit_name->hide();
    add1Edit_author->hide();
    add1Edit_isbn->hide();
    add1Edit_out->hide();
    add1Edit_date->hide();
    add1Edit_or->hide();
    add1Edit_num->hide();
    add1Edit_re->hide();
    add1Ser_btn->hide();

    delLabel->hide();
    delLabel_name->hide();
    delLabel_isbn->hide();
    delEdit_name->hide();
    delEdit_isbn->hide();
    delSer_btn->hide();
}
void Management::on_add_btn_clicked()
{
    hide_all();
    addLabel->show();
    addLabel_name->show();
    addLabel_author->show();
    addLabel_isbn->show();
    addLabel_out->show();
    addLabel_time->show();
    addLabel_num->show();
    addLabel_or->show();
    addLabel_re->show();
    addEdit_name->show();
    addEdit_author->show();
    addEdit_isbn->show();
    addEdit_out->show();
    addEdit_date->show();
    addEdit_or->show();
    addEdit_num->show();
    addEdit_re->show();
    addSer_btn->show();
}

void Management::on_chag_btn_clicked()
{
    hide_all();
    changeLabel->show();
    changeLabel_name->show();
    changeLabel_isbn->show();
    changeEdit_name->show();
    changeEdit_isbn->show();
    chagSer_btn->show();
}

void Management::on_del_btn_clicked()
{
    hide_all();
    delLabel->show();
    delLabel_name->show();
    delLabel_isbn->show();
    delEdit_name->show();
    delEdit_isbn->show();
    delSer_btn->show();
}
void Management::paintEvent(QPaintEvent *)
{
    //背景
    QPainter painter(this);
    QPixmap pix(":/image/beg.png");
    painter.drawPixmap(0,0,900,600,pix);
}
//删除功能实现
void Management::del_book()
{
    if(QMessageBox::Yes == QMessageBox::question(this,"确认","确定删除吗？",QMessageBox::Yes | QMessageBox::No,QMessageBox::No))
    {
        QString a;
        if(delEdit_name->text() == "")
        {
            if(delEdit_isbn->text() == "")
            {
                QMessageBox::critical(this,"error","请输入删除内容!");
                return;
            }
            else
            {
                 a = QString("delete from Book where isbn = '%1").arg(delEdit_isbn->text());
            }
        }
        else
        {
            if(delEdit_isbn->text() == "")
            {
                a = QString("delete from Book where name = '%1").arg((delEdit_name->text()));
            }
            else
            {
                a = QString("delete from Book where name = '%1' and isbn = '%2'").arg(delEdit_name->text()).arg(delEdit_isbn->text());//这句可能有问题
            }
        }
        QSqlQuery sqlquery;
        if(sqlquery.exec(a))
        {
            QMessageBox::information(this,"成功","删除完成");
        }
        else {
            QMessageBox::information(this,"失败","未找到此书");
        }
    }
}
//查询功能实现
void Management::ser_book()
{
    QString a;
    if(serchEdit_name->text()=="")
    {
        if(serchEdit_author->text()=="")
        {
            if(serchEdit_out->text()=="")
            {
                if(serchEdit_isbn->text()=="")
                {
                    QMessageBox::critical(this,"error","请输入查询内容！");
                    return;
                }
                else {
                    a = QString("select * from Book where isbn like '%%1%'").arg(serchEdit_isbn->text());
                }
            }
            else {
                if(serchEdit_isbn->text()=="")
                {
                    a = QString("select * from Book where press like '%%1%'").arg(serchEdit_out->text());
                }
                else {
                    a = QString("select * from Book where isbn like '%%1%' and press like '%%2%'").arg(serchEdit_isbn->text()).arg(serchEdit_out->text());
                }
            }
        }
        else{
            if(serchEdit_out->text()=="")
            {
                if(serchEdit_isbn->text()=="")
                {
                    a = QString("select * from Book where author like '%%1%'").arg(serchEdit_author->text());
                }
                else {
                    a = QString("select * from Book where isbn like '%%1%' and author like '%%2%'").arg(serchEdit_isbn->text()).arg(serchEdit_author->text());
                }
            }
            else {
                if(serchEdit_isbn->text()=="")
                {
                    a = QString("select * from Book where press like '%%1%' and author like '%%2%'").arg(serchEdit_out->text()).arg(serchEdit_author->text());
                }
                else {
                    a = QString("select * from Book where isbn like '%%1%' and press like '%%2%' and author like '%%3%'").arg(serchEdit_author->text()).arg(serchEdit_out->text()).arg(serchEdit_author->text());
                }
            }
        }
    }
    else {
        if(serchEdit_author->text()=="")
        {
            if(serchEdit_out->text()=="")
            {
                if(serchEdit_isbn->text()=="")
                {
                    a = QString("select * from Book where name like '%%1%'").arg(serchEdit_name->text());
                }
                else {
                    a = QString("select * from Book where name like '%%1%' and isbn like '%%2%'").arg(serchEdit_name->text()).arg(serchEdit_isbn->text());
                }
            }
            else {
                if(serchEdit_isbn->text()=="")
                {
                     a = QString("select * from Book where name like '%%1%' and press like '%%2%' ").arg(serchEdit_name->text()).arg(serchLabel_out->text());
                }
                else {
                     a = QString("select * from Book where name like '%%1%' and isbn like '%%2%' and press like '%%3%'").arg(serchEdit_name->text()).arg(serchEdit_isbn->text()).arg(serchEdit_out->text());
                }
            }
        }
        else{
            if(serchEdit_out->text()=="")
            {
                if(serchEdit_out->text()=="")
                {
                     a = QString("select * from Book where name like '%%1%' and author like '%%2%'").arg(serchEdit_name->text()).arg(serchEdit_author->text());
                }
                else {
                     a = QString("select * from Book where name like '%%1%' and isbn like '%%2%' and author like '%%3%'").arg(serchEdit_name->text()).arg(serchEdit_isbn->text()).arg(serchEdit_author->text());
                }
            }
            else {
                if(serchLabel_isbn->text()=="")
                {
                     a = QString("select * from Book where name like '%%1%' and press like '%%2%' and author like '%%3%'").arg(serchEdit_name->text()).arg(serchEdit_out->text()).arg(serchEdit_author->text());
                }
                else {
                    a = QString("select * from Book where isbn like '%%1%' and press like '%%2%' and author like '%%3%'").arg(serchEdit_isbn->text()).arg(serchEdit_out->text()).arg(serchEdit_author->text());
                }
            }
        }

    }
    QSqlQuery sqlquery;
    sqlquery.exec(a);
    int i=0;
    if(!sqlquery.next())
    {
        QMessageBox::information(this,"error","未找到指定图书");
        return;
    }
    sqlquery.previous();
    while(sqlquery.next())
    {
       response->setRowCount(i+1);
       response->setItem(i,0,new QTableWidgetItem(sqlquery.value(2).toString()));
       response->setItem(i,1,new QTableWidgetItem(sqlquery.value(1).toString()));
       response->setItem(i,2,new QTableWidgetItem(sqlquery.value(3).toString()));
       response->setItem(i,3,new QTableWidgetItem(sqlquery.value(4).toString()));
       response->setItem(i,4,new QTableWidgetItem(sqlquery.value(5).toString()));
       response->setItem(i,5,new QTableWidgetItem(sqlquery.value(6).toString()));
       response->setItem(i,6,new QTableWidgetItem(sqlquery.value(7).toString()));
       response->setItem(i,7,new QTableWidgetItem(sqlquery.value(8).toString()));
       i++;
    }
    hide_all();
    response->show();
    //back_button->hide();
    //back_button2->show();
}
//修改操作
void Management::chag_book()
{   //查询部分
    QString a;
    if(changeEdit_name->text()=="")
    {
        if(changeEdit_isbn->text()=="")
        {
            QMessageBox::critical(this,"error","请输入查询内容！");
            return;
        }
        else{
            a = QString("select * from Book where isbn = '%1'").arg(changeEdit_isbn->text());
        }
    }
    else {
        if(changeEdit_isbn->text()=="")
        {
            a = QString("select * from Book where name = '%1'").arg(changeEdit_name->text());

        }
        else {
           a = QString("select * from Book where name = '%1' and isbn = '%2'").arg(changeEdit_name->text()).arg(changeEdit_isbn->text());
        }
    }
    QSqlQuery sqlquery;
    sqlquery.exec(a);
    if(!sqlquery.next())
    {
        QMessageBox::information(this,"error","未找到指定图书");
        return;
    }
    else{
        hide_all();
        this->add1Label->show();
        add1Label->show();
        add1Label_name->show();
        add1Label_author->show();
        add1Label_isbn->show();
        add1Label_out->show();
        add1Label_time->show();
        add1Label_num->show();
        add1Label_or->show();
        add1Label_re->show();
        add1Edit_name->show();
        add1Edit_author->show();
        add1Edit_isbn->show();
        add1Edit_out->show();
        add1Edit_date->show();
        add1Edit_or->show();
        add1Edit_num->show();
        add1Edit_re->show();
        add1Ser_btn->show();
        add1Edit_name->setText(sqlquery.value(1).toString());
        add1Edit_isbn->setText(sqlquery.value(2).toString());
        add1Edit_author->setText(sqlquery.value(3).toString());
        add1Edit_out->setText(sqlquery.value(4).toString());
        add1Edit_date->setDate(sqlquery.value(5).toDate());
        add1Edit_num->setText(sqlquery.value(6).toString());
        add1Edit_or->setText(sqlquery.value(7).toString());
        add1Edit_re->setText(sqlquery.value(8).toString());
    }
}
//添加操作
void Management::add_book()
{
    QString a;
    if(QMessageBox::Yes == QMessageBox::question(this,"确认","确定修改吗?",QMessageBox::Yes | QMessageBox::No,QMessageBox::No))
    {
            if(addEdit_name->text()==""||addEdit_isbn->text()==""||addEdit_or->text()==""||addEdit_re->text()==""||addEdit_num->text()=="")
            {
                QMessageBox::critical(this,"错误","书名，ISBN，库存，批发价，销售价请勿为空！");
                return;
            }
            if(addEdit_or->text().toDouble()<0||addEdit_re->text().toDouble()<0||addEdit_num->text().toInt()<0)
            {
                QMessageBox::critical(this,"错误","价格或库存量不能为负");
                return;
            }
            if(addEdit_or->text().toDouble()>addEdit_re->text().toDouble())
            {
                QMessageBox::critical(this,"错误","批发价不能小于零售价");
                return;
            }
            if(addEdit_isbn->text().toULongLong()==0)
            {
                QMessageBox::critical(this,"错误","isbn填写出错");
                return;
            }
            QString d=addEdit_date->text();
            for(int i=0;i<d.length();i++)
            {
                if(d[i]=="/")
                    d.replace(i,1,"-");
            }
            //执行sql
            a = QString("insert into Book values(0,'%1','%2','%3','%4','%5',%6,%7,%8,%9)").arg(addEdit_name->text()).arg(addEdit_isbn->text()).arg(addEdit_author->text()).arg(addEdit_out->text()).arg(d).arg(addEdit_num->text()).arg(addEdit_or->text()).arg(addEdit_re->text()).arg(addEdit_or->text().toDouble()*addEdit_num->text().toInt());
            QSqlQuery sqlquery;
            if(sqlquery.exec(a))
            {
                QMessageBox::information(this,"成功","添加成功！");
            }
            else{
                QMessageBox::information(this,"失败","添加失败！");
            }
    }
}
void Management::add1_book()
{
   //修改部分
    QString a;
    if(QMessageBox::Yes == QMessageBox::question(this,"确认","确认修改书籍？",QMessageBox::Yes | QMessageBox::No,QMessageBox::No))
    {
        //一些输入判断
        if(add1Edit_name->text()==""||add1Edit_isbn->text()==""||add1Edit_num->text()==""||add1Edit_or->text()==""||add1Edit_re->text()=="")
        {
            QMessageBox::critical(this,"错误","书名，ISBN，库存，批发价，销售价请勿为空！");
            return;
        }
        if(add1Edit_or->text().toDouble()<0||add1Edit_re->text().toDouble()<0||add1Edit_num->text().toInt()<0)
        {
            QMessageBox::critical(this,"错误","价格或库存量不能为负");
            return;
        }
        if(add1Edit_or->text().toDouble()>add1Edit_re->text().toDouble())
        {
            QMessageBox::critical(this,"错误","批发价不能小于零售价");
            return;
        }
        if(add1Edit_isbn->text().toULongLong()==0)
        {
            QMessageBox::critical(this,"错误","isbn填写出错");
            return;
        }
        QString d=add1Edit_date->text();
        for(int i=0;i<d.length();i++)
        {
            if(d[i]=="/")
                d.replace(i,1,"-");
        }
        //执行sql
        if(add1Edit_name->text()=="")
        {
            if(add1Edit_isbn->text()=="")
            {
                QMessageBox::critical(this,"error","请输入查询内容！");
                return;
            }
            else{
                a = QString("update Book set name = '%2',isbn = '%3',author = '%4',press = '%5',date = '%6',stock = '%7',price_1 = '%8',price_2 = '%9',price_1cnt = '%10' where isbn = '%1'").arg(add1Edit_isbn->text()).arg(add1Edit_name->text()).arg(add1Edit_isbn->text()).arg(add1Edit_author->text()).arg(add1Edit_out->text()).arg(d).arg(add1Edit_num->text()).arg(add1Edit_or->text()).arg(add1Edit_re->text()).arg(add1Edit_or->text().toDouble()*add1Edit_num->text().toInt());
            }
        }
        else {
            if(add1Edit_isbn->text()=="")
            {
                a = QString("update Book set name = '%2',isbn = '%3',author = '%4',press = '%5',date = '%6',stock = '%7',price_1 = '%8',price_2 = '%9',price_1cnt = '%10' where name = '%1'").arg(add1Edit_name->text()).arg(addEdit_name->text()).arg(add1Edit_isbn->text()).arg(add1Edit_author->text()).arg(add1Edit_out->text()).arg(d).arg(add1Edit_num->text()).arg(add1Edit_or->text()).arg(add1Edit_re->text()).arg(add1Edit_or->text().toDouble()*add1Edit_num->text().toInt());

            }
            else {
               a = QString("update Book set name = '%3',isbn = '%4',author = '%5',press = '%6',date = '%7',stock = '%8',price_1 = '%9',price_2 = '%10',price_1cnt = %11 where name = '%1' and isbn = '%2'").arg(add1Edit_name->text()).arg(add1Edit_isbn->text()).arg(add1Edit_name->text()).arg(add1Edit_isbn->text()).arg(add1Edit_author->text()).arg(add1Edit_out->text()).arg(d).arg(add1Edit_num->text()).arg(add1Edit_or->text()).arg(add1Edit_re->text()).arg(add1Edit_or->text().toDouble()*add1Edit_num->text().toInt());
            }
        }
        QSqlQuery sqlquery;
        if(sqlquery.exec(a))
        {
            QMessageBox::information(this,"成功","修改成功！");
        }
        else{
            QMessageBox::information(this,"失败","修改失败！");
        }
    }
}
