#include "formcreatetyperesource.h"
#include "ui_formcreatetyperesource.h"
#include <string>
#include <QList>
#include <QString>
#include <QMessageBox>
#include <QVBoxLayout>
#include <immodel.h>
#include <mainwindow.h>

using namespace std;

int colTxtBox = 1;
QList<QLineEdit*> txtbxes1;
QList<QComboBox*> cmbbxes;
QList<QLineEdit*> txtbxes2;
QList<QLineEdit*> txtbxes3;

FormCreateTypeResource::FormCreateTypeResource(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCreateTypeResource)
{
    ui->setupUi(this);



    ui->cmbTrase->addItems(QStringList()<<"Да"<<"Нет");
    ui->cmbTime->addItems(QStringList()<<"Временные"<<"Постоянные");
    ui->cmbParam1->addItems(QStringList()<<"int"<<"bool"<<"Enum");
    txtbxes1.clear();
    txtbxes2.clear();
    txtbxes3.clear();
    cmbbxes.clear();
    txtbxes1.append(ui->fldParam1);
    cmbbxes.append(ui->cmbParam1);
    txtbxes2.append(ui->fldVariants1);
    txtbxes3.append(ui->fldDefault1);

    //ui->cmbTrase->setGeometry(150,199,111,22);
}




FormCreateTypeResource::~FormCreateTypeResource()
{
    delete ui;
}

void FormCreateTypeResource::on_pushButton_2_clicked()
{
    QLineEdit *newtxtbx = new QLineEdit(this);
    QLineEdit *newtxtbx2 = new QLineEdit(this);
    QLineEdit *newtxtbx3 = new QLineEdit(this);
    QComboBox *newcmbbx = new QComboBox(this);
    colTxtBox = colTxtBox + 1;
    newcmbbx->addItems(QStringList()<<"int"<<"bool"<<"Enum");


    newtxtbx->setGeometry(ui->fldParam1->x(), ui->fldParam1->y() + (colTxtBox - 1) * (ui->fldParam1->height() + 10), ui->fldParam1->width(), ui->fldParam1->height());
    newtxtbx2->setGeometry(ui->fldVariants1->x(), ui->fldVariants1->y() + (colTxtBox - 1) * (ui->fldVariants1->height() + 10), ui->fldVariants1->width(), ui->fldVariants1->height());
    newtxtbx3->setGeometry(ui->fldDefault1->x(), ui->fldDefault1->y() + (colTxtBox - 1) * (ui->fldDefault1->height() + 10), ui->fldDefault1->width(), ui->fldDefault1->height());
    newcmbbx->setGeometry(ui->cmbParam1->x(), ui->cmbParam1->y() + (colTxtBox - 1) * (ui->cmbParam1->height() + 9), ui->cmbParam1->width(), ui->cmbParam1->height());


    newcmbbx->show();
    newtxtbx->show();
    newtxtbx2->show();
    newtxtbx3->show();



    txtbxes1.append(newtxtbx);
    cmbbxes.append(newcmbbx);
    txtbxes2.append(newtxtbx2);
    txtbxes3.append(newtxtbx3);
}

void FormCreateTypeResource::on_pushButton_3_clicked()
{
    if (colTxtBox > 1)
    {

        delete cmbbxes.at(cmbbxes.count() - 1);
        delete txtbxes1.at(txtbxes1.count() - 1);
        delete txtbxes2.at(txtbxes2.count() - 1);
        delete txtbxes3.at(txtbxes3.count() - 1);

        cmbbxes.removeAt(cmbbxes.count() - 1);
        txtbxes1.removeAt(txtbxes1.count() - 1);
        txtbxes2.removeAt(txtbxes2.count() - 1);
        txtbxes3.removeAt(txtbxes3.count() - 1);
        colTxtBox--;
    }
}

void FormCreateTypeResource::on_pushButton_clicked()
{
    extern QList<TypeResource> ListTypeResources;
    bool check1 = true;
    bool check2 = true;
    bool isNumber = false;
    bool check3 = true;
    bool check4 = true;
    bool check5 = true;
    bool check6 = true;

    int value;

    //ImModel im;

    if (ui->fldTypeName->text() == "")
    {
        QMessageBox::warning(this, "Предупреждение","Вы не выбрали имя типа ресурсов!");
        check1 = false;
    }

    for (int i=0; i<txtbxes1.count(); i++)
    {
        if (txtbxes1.at(i)->text() == "")
        {
            QString s = "Hе выбрано значение имени параметра типа ресурсов № ";
            s+=QString::number(i+1);
            s+="!";
            QMessageBox::warning(this, "Предупреждение", s);
            check2 = false;
        }
    }

    for (int i = 0; i<txtbxes1.count(); i ++)
    {
        //string hex = ui->cmbTrase->currentText();
        //int go = hex.ToDouble(&isNumber);
        //if (!isNumber)
        double d = txtbxes3.at(i)->text().toDouble(&isNumber);
        if ((isNumber==false) && (cmbbxes.at(i)->currentText() == "int") && (txtbxes3.at(i)->text() != ""))
        {
            QString s = "Введеное начальное значение для параметра № ";
            s+=QString::number(i+1);
            s+=" типа int не является числом!";
            QMessageBox::warning(this, "Предупреждение", s);
            check3 = false;
        }
    }

    for (int i = 0; i<txtbxes1.count(); i ++)
    {
        if ((cmbbxes.at(i)->currentText() == "bool") && (txtbxes3.at(i)->text() != "false") && (txtbxes3.at(i)->text() != "true") && (txtbxes3.at(i)->text() != "True") && (txtbxes3.at(i)->text() != "False") && (txtbxes3.at(i)->text() != ""))
        {
            QString s = "Введеное начальное значение для параметра № ";
            s+=QString::number(i+1);
            s+=" типа bool задано неверно!";
            QMessageBox::warning(this, "Предупреждение", s);
            check3 = false;
        }
    }

    for (int i=0; i<txtbxes1.count(); i++)
    {
        if ((cmbbxes.at(i)->currentText() == "int") && (txtbxes2.at(i)->text() != ""))
        {
            QString s = "Возможные значения выбираются только для типа параметра Enum! Введены возможные значения для типа int в параметре № ";
            s+=QString::number(i+1);
            s+="!";
            QMessageBox::warning(this, "Предупреждение", s);
            check4 = false;
        }
    }

    for (int i=0; i<txtbxes1.count(); i++)
    {
        if ((cmbbxes.at(i)->currentText() == "bool") && (txtbxes2.at(i)->text() != ""))
        {
            QString s = "Возможные значения выбираются только для типа параметра Enum! Введены возможные значения для типа bool в параметре № ";
            s+=QString::number(i+1);
            s+="!";
            QMessageBox::warning(this, "Предупреждение", s);
            check4 = false;
        }

    }


    for (int i =0; i<ListTypeResources.count();i++)
    {
        if (check5 == true)
        {
            if (ListTypeResources.at(i).TypeName == ui->fldTypeName->text())
            {
            QString s = "Тип ресурсов ";
            s+=ui->fldTypeName->text();
            s+=" уже существует!";
            QMessageBox::warning(this, "Предупреждение", s);
            check5 = false;
            }
        }
    }

    for (int i=0; i<txtbxes1.count(); i++)
    {
        if ((cmbbxes.at(i)->currentText() == "Enum") && (txtbxes2.at(i)->text() == ""))
        {
            QString s = "В параметре № ";
            s+=QString::number(i+1);
            s+=" не указаны возможные значения для типа Enum!";
            QMessageBox::warning(this, "Предупреждение", s);
            check6 = false;
        }
    }

   if ((check1 == true) && (check2 == true) && (check3 == true) && (check4 == true) && (check5 == true) && (check6 == true))
   {
       QList<QString> ParamName;
       QList<QString> ParamType;
       QList<QString> ParamVariant;
       QList<QString> ParamDefault;

       for (int i=0; i<txtbxes1.count(); i++)
       {
           ParamName.append(txtbxes1.at(i)->text());
           ParamType.append(cmbbxes.at(i)->currentText());
           ParamVariant.append(txtbxes2.at(i)->text());
           ParamDefault.append(txtbxes3.at(i)->text());
       }

       TypeResource tprss(ui->fldTypeName->text(), ui->cmbTrase->currentText(), ui->cmbTime->currentText(),ParamName, ParamType, ParamVariant, ParamDefault);
       ListTypeResources.append(tprss);
       QString s = "Тип ресурсов '";
       s+=ui->fldTypeName->text();
       s+="' успешно создан!";
       txtbxes1.clear();
       txtbxes2.clear();
       txtbxes3.clear();
       cmbbxes.clear();
       QMessageBox::warning(this, "Предупреждение", s);

       close();
   }


}
