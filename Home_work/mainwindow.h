#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "sale.h"
#include <QMainWindow>
#include "management.h"
#include "report.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_actionhelp_triggered();

    void on_actionadd_triggered();

    void on_actionthanks_triggered();

private:
    Ui::MainWindow *ui;
    Sale *custom;
    Management *manboss;
    Report *reboss;
};

#endif // MAINWINDOW_H
