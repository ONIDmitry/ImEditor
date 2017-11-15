#ifndef FORMCREATEPATTERNOPERATION_H
#define FORMCREATEPATTERNOPERATION_H

#include <QWidget>
#include <QGridLayout>

namespace Ui {

class FormCreatePatternOperation;
}

class FormCreatePatternOperation : public QWidget
{
    Q_OBJECT

public:
    explicit FormCreatePatternOperation(QWidget *parent = 0);
    ~FormCreatePatternOperation();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::FormCreatePatternOperation *ui;


};

#endif // FORMCREATEPATTERNOPERATION_H
