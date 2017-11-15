#ifndef FORMCREATETYPERESOURCE_H
#define FORMCREATETYPERESOURCE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QList>
#include <string>

namespace Ui {

class FormCreateTypeResource;
}

class FormCreateTypeResource : public QWidget
{
    Q_OBJECT

public:
    explicit FormCreateTypeResource(QWidget *parent = 0);
    ~FormCreateTypeResource();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::FormCreateTypeResource *ui;


};

#endif // FORMCREATETYPERESOURCE_H
