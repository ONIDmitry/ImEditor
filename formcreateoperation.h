#ifndef FORMCREATEOPERATION_H
#define FORMCREATEOPERATION_H

#include <QWidget>

namespace Ui {
class FormCreateOperation;
}

class FormCreateOperation : public QWidget
{
    Q_OBJECT

public:
    explicit FormCreateOperation(QWidget *parent = 0);
    ~FormCreateOperation();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::FormCreateOperation *ui;
};

#endif // FORMCREATEOPERATION_H
