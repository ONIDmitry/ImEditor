#include "formedittyperesource.h"
#include "ui_formedittyperesource.h"
#include "immodel.h"
#include <QMessageBox>

int colTxtBox5 = 1;
QList<QLineEdit*> listtxt11;
QList<QLineEdit*> listtxt12;
QList<QLineEdit*> listtxt13;
QList<QComboBox*> listcmb10;

FormEditTypeResource::FormEditTypeResource(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormEditTypeResource)
{
    ui->setupUi(this);

    extern QList<TypeResource> ListTypeResources;
    extern QString ChosenTypeResource;
    extern int NumberChosenTypeResource;
    colTxtBox5 = 1;

    listtxt11.clear();
    listtxt12.clear();
    listtxt13.clear();
    listcmb10.clear();

    ui->cmbTrase->addItems(QStringList()<<"Да"<<"Нет");
    ui->cmbTime->addItems(QStringList()<<"Временные"<<"Постоянные");

    ui->fldTypeName->setText(ChosenTypeResource);
    ui->cmbTrase->setCurrentText(ListTypeResources.at(NumberChosenTypeResource).TraseValue);
    ui->cmbTime->setCurrentText(ListTypeResources.at(NumberChosenTypeResource).TempValue);

    for (int i=0; i<ListTypeResources.at(NumberChosenTypeResource).ParamName.count(); i++)
    {
        QLineEdit *txt1 = new QLineEdit(this);
        QLineEdit *txt2 = new QLineEdit(this);
        QLineEdit *txt3 = new QLineEdit(this);
        QComboBox *cmb = new QComboBox(this);

        cmb->addItems(QStringList()<<"int"<<"bool"<<"Enum");

        try
        {
            txt1->setText(ListTypeResources.at(NumberChosenTypeResource).ParamName.at(i));
        }
        catch (exception)
        {
            QMessageBox::warning(this, "Предупреждение","Ошибка определения имени параметра типа ресурсов");
        }

        try
        {
            txt2->setText(ListTypeResources.at(NumberChosenTypeResource).ParamVariant.at(i));
        }
        catch (exception)
        {
            QMessageBox::warning(this, "Предупреждение","Ошибка определения вариантов значений для типа Enum");
        }

        try
        {
            txt3->setText(ListTypeResources.at(NumberChosenTypeResource).ParamDefault.at(i));
        }
        catch (exception)
        {
            QMessageBox::warning(this, "Предупреждение","Ошибка определения начального значения одного из параметров типа ресурсов");
        }


        try
        {
            cmb->setCurrentText(ListTypeResources.at(NumberChosenTypeResource).ParamType.at(i));
        }
        catch (exception)
        {
            QMessageBox::warning(this, "Предупреждение","Ошибка определения типа одного из параметров типа ресурсов");
        }

        txt1->setGeometry(10, 200 + (colTxtBox5 - 1) * (20 + 10), 113, 20);
        txt2->setGeometry(292, 200 + (colTxtBox5 - 1) * (20 + 10), 191, 20);
        txt3->setGeometry(510, 200 + (colTxtBox5 - 1) * (20 + 10), 113, 20);
        cmb->setGeometry(150, 200 + (colTxtBox5 - 1) * (21 + 9), 111, 21);

        txt1->show();
        txt2->show();
        txt3->show();
        cmb->show();

        listtxt11.append(txt1);
        listtxt12.append(txt2);
        listtxt13.append(txt3);
        listcmb10.append(cmb);

        colTxtBox5+=1;
    }

}

FormEditTypeResource::~FormEditTypeResource()
{
    delete ui;
}

void FormEditTypeResource::on_pushButton_2_clicked()
{
    extern QList<TypeResource> ListTypeResources;
    extern QString ChosenTypeResource;
    extern int NumberChosenTypeResource;

    ListTypeResources.removeAt(NumberChosenTypeResource);

    QString s = "Тип ресурса \"";
    s+=ChosenTypeResource;
    s+="\" успешно удален!";
    QMessageBox::warning(this, "Предупреждение", s);

    ChosenTypeResource = "";
    NumberChosenTypeResource = -1;
    listtxt11.clear();
    listtxt12.clear();
    listtxt13.clear();
    listcmb10.clear();
    close();
}

void FormEditTypeResource::on_pushButton_3_clicked()
{
    extern QString ChosenTypeResource;
    extern int NumberChosenTypeResource;

    ChosenTypeResource = "";
    NumberChosenTypeResource = -1;
    listtxt11.clear();
    listtxt12.clear();
    listtxt13.clear();
    listcmb10.clear();
    close();
}

void FormEditTypeResource::on_pushButton_4_clicked()
{
    QLineEdit *newtxt = new QLineEdit(this);
    QLineEdit *newtxt2 = new QLineEdit(this);
    QLineEdit *newtxt3 = new QLineEdit(this);
    QComboBox *newcmb = new QComboBox(this);
    newcmb->addItems(QStringList()<<"int"<<"bool"<<"Enum");

    newtxt->setGeometry(10, 200 + (colTxtBox5 - 1) * (20 + 10), 113, 20);
    newtxt2->setGeometry(292, 200 + (colTxtBox5 - 1) * (20 + 10), 191, 20);
    newtxt3->setGeometry(510, 200 + (colTxtBox5 - 1) * (20+ 10), 113, 20);
    newcmb->setGeometry(150, 200 + (colTxtBox5 - 1) * (21 + 9), 111, 21);

    newcmb->show();
    newtxt->show();
    newtxt2->show();
    newtxt3->show();

    listtxt11.append(newtxt);
    listcmb10.append(newcmb);
    listtxt12.append(newtxt2);
    listtxt13.append(newtxt3);

    colTxtBox5 = colTxtBox5 + 1;
}

void FormEditTypeResource::on_pushButton_5_clicked()
{
    if (listtxt11.count() > 1)
    {

        delete listcmb10.at(listcmb10.count() - 1);
        delete listtxt11.at(listtxt11.count() - 1);
        delete listtxt12.at(listtxt12.count() - 1);
        delete listtxt13.at(listtxt13.count() - 1);

        listcmb10.removeAt(listcmb10.count() - 1);
        listtxt11.removeAt(listtxt11.count() - 1);
        listtxt12.removeAt(listtxt12.count() - 1);
        listtxt13.removeAt(listtxt13.count() - 1);
        colTxtBox5--;
    }
}

void FormEditTypeResource::on_pushButton_clicked()
{
    extern QList<TypeResource> ListTypeResources;
    extern QString ChosenTypeResource;
    extern int NumberChosenTypeResource;
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

    for (int i=0; i<listtxt11.count(); i++)
    {
        if (listtxt11.at(i)->text() == "")
        {
            QString s = "Hе выбрано значение имени параметра типа ресурсов № ";
            s+=QString::number(i+1);
            s+="!";
            QMessageBox::warning(this, "Предупреждение", s);
            check2 = false;
        }
    }

    for (int i = 0; i<listtxt11.count(); i ++)
    {
        //string hex = ui->cmbTrase->currentText();
        //int go = hex.ToDouble(&isNumber);
        //if (!isNumber)
        double d = listtxt13.at(i)->text().toDouble(&isNumber);
        if ((isNumber==false) && (listcmb10.at(i)->currentText() == "int") && (listtxt13.at(i)->text() != ""))
        {
            QString s = "Введеное начальное значение для параметра № ";
            s+=QString::number(i+1);
            s+=" типа int не является числом!";
            QMessageBox::warning(this, "Предупреждение", s);
            check3 = false;
        }
    }

    for (int i = 0; i<listtxt11.count(); i ++)
    {
        if ((listcmb10.at(i)->currentText() == "bool") && (listtxt13.at(i)->text() != "false") && (listtxt13.at(i)->text() != "true") && (listtxt13.at(i)->text() != "True") && (listtxt13.at(i)->text() != "False") && (listtxt13.at(i)->text() != ""))
        {
            QString s = "Введеное начальное значение для параметра № ";
            s+=QString::number(i+1);
            s+=" типа bool задано неверно!";
            QMessageBox::warning(this, "Предупреждение", s);
            check3 = false;
        }
    }

    for (int i=0; i<listtxt11.count(); i++)
    {
        if ((listcmb10.at(i)->currentText() == "int") && (listtxt12.at(i)->text() != ""))
        {
            QString s = "Возможные значения выбираются только для типа параметра Enum! Введены возможные значения для типа int в параметре № ";
            s+=QString::number(i+1);
            s+="!";
            QMessageBox::warning(this, "Предупреждение", s);
            check4 = false;
        }
    }

    for (int i=0; i<listtxt11.count(); i++)
    {
        if ((listcmb10.at(i)->currentText() == "bool") && (listtxt12.at(i)->text() != ""))
        {
            QString s = "Возможные значения выбираются только для типа параметра Enum! Введены возможные значения для типа bool в параметре № ";
            s+=QString::number(i+1);
            s+="!";
            QMessageBox::warning(this, "Предупреждение", s);
            check4 = false;
        }
    }

    for (int i=0; i<listtxt11.count(); i++)
    {
        if ((listcmb10.at(i)->currentText() == "Enum") && (listtxt12.at(i)->text() == ""))
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

       for (int i=0; i<listtxt11.count(); i++)
       {
           ParamName.append(listtxt11.at(i)->text());
           ParamType.append(listcmb10.at(i)->currentText());
           ParamVariant.append(listtxt12.at(i)->text());
           ParamDefault.append(listtxt13.at(i)->text());
       }

       TypeResource tprss(ui->fldTypeName->text(), ui->cmbTrase->currentText(), ui->cmbTime->currentText(),ParamName, ParamType, ParamVariant, ParamDefault);
       ListTypeResources.removeAt(NumberChosenTypeResource);
       ListTypeResources.insert(NumberChosenTypeResource, tprss);
       QString s = "Тип ресурсов '";
       s+=ChosenTypeResource;
       s+="' успешно изменен!";
       ChosenTypeResource = "";
       NumberChosenTypeResource = -1;
       listtxt11.clear();
       listtxt12.clear();
       listtxt13.clear();
       listcmb10.clear();
       QMessageBox::warning(this, "Предупреждение", s);

       close();
   }
}
