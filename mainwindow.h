#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <typeresource.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_3_triggered();

    void on_pushButton_clicked();

    void on_action_5_triggered();

    void on_action_4_triggered();

    void on_action_6_triggered();

    void on_action_7_triggered();

    void on_action_triggered();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_label_linkActivated(const QString &link);

private:
    Ui::MainWindow *ui;

};






#endif // MAINWINDOW_H
