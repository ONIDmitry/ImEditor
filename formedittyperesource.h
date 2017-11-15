#ifndef FORMEDITTYPERESOURCE_H
#define FORMEDITTYPERESOURCE_H

#include <QWidget>

namespace Ui {
class FormEditTypeResource;
}

class FormEditTypeResource : public QWidget
{
    Q_OBJECT

public:
    explicit FormEditTypeResource(QWidget *parent = 0);
    ~FormEditTypeResource();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

private:
    Ui::FormEditTypeResource *ui;
};

#endif // FORMEDITTYPERESOURCE_H
