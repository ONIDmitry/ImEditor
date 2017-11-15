#include "formcreateresource2.h"
#include "ui_formcreateresource2.h"

FormCreateResource2::FormCreateResource2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCreateResource2)
{
    ui->setupUi(this);
}

FormCreateResource2::~FormCreateResource2()
{
    delete ui;
}
