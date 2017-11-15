#ifndef FORMEDITOPERATION_H
#define FORMEDITOPERATION_H

#include <QWidget>

namespace Ui {
class FormEditOperation;
}

class FormEditOperation : public QWidget
{
    Q_OBJECT

public:
    explicit FormEditOperation(QWidget *parent = 0);
    ~FormEditOperation();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::FormEditOperation *ui;
};

#endif // FORMEDITOPERATION_H
