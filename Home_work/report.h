#ifndef REPORT_H
#define REPORT_H

#include <QDialog>
#include <QTableWidget>

namespace Ui {
class Report;
}

class Report : public QDialog
{
    Q_OBJECT

public:
    explicit Report(QWidget *parent = nullptr);
    ~Report();
    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::Report *ui;
    QTableWidget *tableui;
};

#endif // REPORT_H
