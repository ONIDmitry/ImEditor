#ifndef FORMCREATERESOURCE2_H
#define FORMCREATERESOURCE2_H

#include <QWidget>

namespace Ui {
class FormCreateResource2;
}

class FormCreateResource2 : public QWidget
{
    Q_OBJECT

public:
    explicit FormCreateResource2(QWidget *parent = 0);
    ~FormCreateResource2();

private:
    Ui::FormCreateResource2 *ui;
};

#endif // FORMCREATERESOURCE2_H
