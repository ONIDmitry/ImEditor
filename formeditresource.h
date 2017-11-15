#ifndef FORMEDITRESOURCE_H
#define FORMEDITRESOURCE_H

#include <QWidget>

namespace Ui {
class FormEditResource;
}

class FormEditResource : public QWidget
{
    Q_OBJECT

public:
    explicit FormEditResource(QWidget *parent = 0);
    ~FormEditResource();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::FormEditResource *ui;
};

#endif // FORMEDITRESOURCE_H
