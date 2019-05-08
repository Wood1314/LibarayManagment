#ifndef SALE_H
#define SALE_H

#include <QDialog>

namespace Ui {
class Sale;
}

class Sale : public QDialog
{
    Q_OBJECT

public:
    explicit Sale(QWidget *parent = nullptr);
    ~Sale();
    void set_money();//设置消费总额和应付总额；
    void set_taxRate();//设置税率
    double get_tax();//返回税率
    double get_sale();//返回消费总额
    double get_total();//返回消费数
    void paintEvent(QPaintEvent *);

private slots:
    void on_ser_btn_clicked();

    void on_cagtax_btn_clicked();

    void on_check_btn_clicked();

private:
    Ui::Sale *ui;
    double tax=0;
    double sale=0;
    double total=0;
    double tax_rate = 0;
    int i=0;
};

#endif // SALE_H
