#ifndef FORMCREATERESOURCE_H
#define FORMCREATERESOURCE_H

#include <QWidget>

namespace Ui {
class formcreateresource;
}

class formcreateresource : public QWidget
{
    Q_OBJECT

public:
    explicit formcreateresource(QWidget *parent = 0);
    ~formcreateresource();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



private:
    Ui::formcreateresource *ui;
};

#endif // FORMCREATERESOURCE_H
