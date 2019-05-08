#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <QLineEdit>
#include <QLabel>
#include <QDateEdit>
#include <QDialog>
#include <QPushButton>
#include <QTableWidget>

namespace Ui {
class Management;
}

class Management : public QDialog
{
    Q_OBJECT

public:
    explicit Management(QWidget *parent = nullptr);
    ~Management();
    void hide_all();//把所有ui隐藏
    void paintEvent(QPaintEvent *);

private slots:

    void on_serch_btn_clicked();

    void on_add_btn_clicked();

    void on_chag_btn_clicked();

    void on_del_btn_clicked();

    void del_book();

    void ser_book();

    void chag_book();

    void add_book();

    void add1_book();

private:
    Ui::Management *ui;
    //查询模块
    QLabel *serchLabel, *serchLabel_name, *serchLabel_author, *serchLabel_out, *serchLabel_isbn;
    QLineEdit *serchEdit_name, *serchEdit_author, *serchEdit_out, *serchEdit_isbn;
    //增加模块
    QLabel *addLabel, *addLabel_name, *addLabel_isbn, *addLabel_author, *addLabel_out, *addLabel_time,
    *addLabel_num,*addLabel_or, *addLabel_re,*add1Label, *add1Label_name, *add1Label_isbn, *add1Label_author, *add1Label_out, *add1Label_time,
    *add1Label_num,*add1Label_or, *add1Label_re;
    QLineEdit *addEdit_name, *addEdit_isbn, *addEdit_author, *addEdit_out,
    *addEdit_num, *addEdit_or, *addEdit_re,*add1Edit_name, *add1Edit_isbn, *add1Edit_author, *add1Edit_out,
    *add1Edit_num, *add1Edit_or, *add1Edit_re;
    QDateEdit *addEdit_date,*add1Edit_date;
    //修改
    QLabel *changeLabel,*changeLabel_name,*changeLabel_isbn;
    QLineEdit *changeEdit_name, *changeEdit_isbn;
    QPushButton *chagSer_btn,*add1Ser_btn;
    //删除
    QLabel *delLabel, *delLabel_name, *delLabel_isbn;
    QLineEdit *delEdit_name,*delEdit_isbn;
    QPushButton *delSer_btn,*addSer_btn,*serSer_btn;
    QTableWidget *response;
};
#endif // MANAGEMENT_H
