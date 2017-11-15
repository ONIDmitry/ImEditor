#ifndef FORMEDITPATTERNOPERATION_H
#define FORMEDITPATTERNOPERATION_H

#include <QWidget>

namespace Ui {
class FormEditPatternOperation;
}

class FormEditPatternOperation : public QWidget
{
    Q_OBJECT

public:
    explicit FormEditPatternOperation(QWidget *parent = 0);
    ~FormEditPatternOperation();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::FormEditPatternOperation *ui;
};

#endif // FORMEDITPATTERNOPERATION_H
