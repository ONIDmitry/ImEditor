#include "formeditresource.h"
#include "ui_formeditresource.h"
#include "immodel.h"
#include <QMessageBox>

QList<QLineEdit*> listtxt;
QList<QLabel*> listlbl11;
QList<QLabel*> listlbl12;
QList<QLabel*> listlbl13;
QList<QLabel*> listlbl14;

FormEditResource::FormEditResource(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormEditResource)
{
    ui->setupUi(this);
    int n=0;
    extern QList<Resource> ListResources;
    extern QList<TypeResource> ListTypeResources;
    extern QString ChosenResource;
    extern int NumberChosenResource;

    listtxt.clear();
    listlbl11.clear();
    listlbl12.clear();
    listlbl13.clear();
    listlbl14.clear();

    for (int i=0; i<ListTypeResources.count(); i++)
    {
        ui->cmbTypes->addItem(ListTypeResources.at(i).TypeName);

        if (ListTypeResources.at(i).TypeName == ListResources.at(NumberChosenResource).TypeName)
        {
            n=i;
        }
    }

    ui->cmbTypes->setCurrentText(ListResources.at(NumberChosenResource).TypeName);
    ui->fldResName->setText(ListResources.at(NumberChosenResource).ResourceName);

    for (int i=0; i<ListTypeResources.at(n).ParamName.count(); i++)
    {
        QLabel *newl1 = new QLabel(this);
        QLabel *newl2 = new QLabel(this);
        QLabel *newl3 = new QLabel(this);
        QLabel *newl4 = new QLabel(this);
        QLineEdit *txt = new QLineEdit(this);

        try
        {
            newl1->setText(ListTypeResources.at(n).ParamName.at(i));
        }
        catch (exception)
        {
            QMessageBox::warning(this, "Предупреждение","Ошибка определения имени одного из параметров типа ресурсов");
        }

        try
        {
            newl2->setText(ListTypeResources.at(n).ParamType.at(i));
        }
        catch (exception)
        {
            QMessageBox::warning(this, "Предупреждение","Ошибка определения типа одного из параметров типа ресурсов");
        }

        try
        {
            newl3->setText(ListTypeResources.at(n).ParamVariant.at(i));
        }
        catch (exception)
        {
            QMessageBox::warning(this, "Предупреждение","Ошибка определения возможных вариантов типа Enum для одного из параметров типа ресурсов");
        }

        try
        {
            newl4->setText(ListTypeResources.at(n).ParamDefault.at(i));
        }
        catch (exception)
        {
            QMessageBox::warning(this, "Предупреждение","Ошибка определения начального значения для одного из параметров типа ресурсов");
        }

        try
        {
            txt->setText(ListResources.at(NumberChosenResource).ParamValue.at(i));
        }
        catch (exception)
        {
            QMessageBox::warning(this, "Предупреждение","Ошибка определения начального значения для одного из параметров ресурса");
        }

        newl1->setStyleSheet("QLabel {"
                                     "border-style: solid;"
                                     "border-width: 1px;"
                                     "border-color: black; "
                                     "}");

        newl2->setStyleSheet("QLabel {"
                                     "border-style: solid;"
                                     "border-width: 1px;"
                                     "border-color: black; "
                                     "}");
        newl3->setStyleSheet("QLabel {"
                                     "border-style: solid;"
                                     "border-width: 1px;"
                                     "border-color: black; "
                                     "}");
        newl4->setStyleSheet("QLabel {"
                                     "border-style: solid;"
                                     "border-width: 1px;"
                                     "border-color: black; "
                                     "}");

        newl1->setGeometry(15, 210 + (i+1)*(16 + 10), 100, 16);
        newl2->setGeometry(135, 210 + (i+1)*(16 + 10), 81, 16);
        newl3->setGeometry(260, 210 + (i+1)*(16 + 10), 201, 16);
        newl4->setGeometry(520, 210 + (i+1)*(16 + 10), 110, 16);
        txt->setGeometry(685, 210 + (i+1)*(16 + 10), 110, 16);

        newl1->show();
        newl2->show();
        newl3->show();
        newl4->show();
        txt->show();

        listlbl11.append(newl1);
        listlbl12.append(newl2);
        listlbl13.append(newl3);
        listlbl14.append(newl4);
        listtxt.append(txt);

    }
}

FormEditResource::~FormEditResource()
{
    delete ui;
}

void FormEditResource::on_pushButton_3_clicked()
{
    extern QString ChosenResource;
    extern int NumberChosenResource;

    ChosenResource = "";
    NumberChosenResource = -1;
    listlbl11.clear();
    listlbl12.clear();
    listlbl13.clear();
    listlbl14.clear();
    listtxt.clear();
    close();
}

void FormEditResource::on_pushButton_2_clicked()
{
    extern QList<Resource> ListResources;
    extern QString ChosenResource;
    extern int NumberChosenResource;

    ListResources.removeAt(NumberChosenResource);

    QString s = "Ресурс \"";
    s+=ChosenResource;
    s+="\" успешно удален!";
    QMessageBox::warning(this, "Предупреждение", s);

    ChosenResource = "";
    NumberChosenResource = -1;
    listlbl11.clear();
    listlbl12.clear();
    listlbl13.clear();
    listlbl14.clear();
    listtxt.clear();
    close();
}

void FormEditResource::on_pushButton_clicked()
{
    extern QList<TypeResource> ListTypeResources;
    extern QList<Resource> ListResources;
    extern QString ChosenResource;
    extern int NumberChosenResource;

    bool check1 = true;
    bool check2 = true;
    bool check3 = true;
    bool check4 = true;
    bool check5 = true;
    bool check6 = true;
    bool isNumber = false;
    int k = 0;
    int n = 0;
    int m = 0;


    for (int i=0; i<ListTypeResources.count();i++)
    {
        if (ui->cmbTypes->currentText() == ListTypeResources.at(i).TypeName)
        {
            k++;
            n=i;
        }
    }

    if (k==1)
    {
        if (listlbl11.count() == ListTypeResources.at(n).ParamName.count())
        {
            for (int j=0; j<ListTypeResources.at(n).ParamName.count(); j++)
            {
                if (ListTypeResources.at(n).ParamName.at(j) == listlbl11.at(j)->text())
                {
                    m++;
                }
            }

            if (m != ListTypeResources.at(n).ParamName.count())
            {
                QString s = "Тип ресурсов ";
                s+=ListTypeResources.at(n).TypeName;
                s+=" не содержит такие параметры!";
                QMessageBox::warning(this, "Предупреждение", s);
                check6 = false;
            }
        }
        else
        {
            QString s = "Тип ресурсов ";
            s+=ListTypeResources.at(n).TypeName;
            s+=" не содержит такие параметры!";
            QMessageBox::warning(this, "Предупреждение", s);
            check6 = false;
        }

    }

    if (k==0)
    {
        QString s = "Такого типа ресурсов нет!";
        QMessageBox::warning(this, "Предупреждение", s);
        check1 = false;
    }

    if (ui->fldResName->text() == "")
    {
        QString s = "Введите имя ресурса!";
        QMessageBox::warning(this, "Предупреждение", s);
        check2 = false;
    }

    for (int i=0; i<listlbl14.count(); i++)
    {
        if (listlbl14.at(i)->text() == "")
        {
            if (listtxt.at(i)->text() == "")
            {
                QString s = "В параметре № ";
                s+=QString::number(i+1);
                s+=" не задано начальное значение параметра ресурса, в то время, как начальное значение параметра в типе ресурсов также пустое!";
                QMessageBox::warning(this, "Предупреждение", s);
                check3 = false;
            }
            else if (listtxt.at(i)->text() == "*")
            {
                QString s = "В параметре № ";
                s+=QString::number(i+1);
                s+="  указано начальное значение параметра ресурса '*', в то время, как начальное значение параметра в типе ресурсов пустое!";
                QMessageBox::warning(this, "Предупреждение", s);
                check3 = false;
            }
        }
        else if (listtxt.at(i)->text() == "")
        {
            QString s = "В параметре № ";
            s+=QString::number(i+1);
            s+=" указано пустое начальное значение параметра ресурса! Поставьте '*' или конкретное значение!";
            QMessageBox::warning(this, "Предупреждение", s);
            check3 = false;
        }
    }

    for (int i=0;i<listtxt.count(); i++)
    {
        double d = listtxt.at(i)->text().toDouble(&isNumber);
        if ((listlbl12.at(i)->text() == "int") && (isNumber == false) && (listtxt.at(i)->text() != "") && (listtxt.at(i)->text() != "*"))
        {
            QString s = "Введенное начальное значение для типа int в параметре № ";
            s+=QString::number(i+1);
            s+=" не является числом! ";
            QMessageBox::warning(this, "Предупреждение", s);
            check4 = false;
        }
        else if ((listlbl12.at(i)->text() == "bool") && (listtxt.at(i)->text() != "false") && (listtxt.at(i)->text() != "False") && (listtxt.at(i)->text() != "true") && (listtxt.at(i)->text() != "True") && (listtxt.at(i)->text() != "") && (listtxt.at(i)->text() != "*"))
        {
            QString s = "Введенное начальное значение для типа bool в параметре № ";
            s+=QString::number(i+1);
            s+=" задано неверно!";
            QMessageBox::warning(this, "Предупреждение", s);
            check4 = false;
        }
    }

    if ((check1 == true) && (check2 == true) && (check3 == true) && (check4 == true) && (check5 == true) && (check6 == true))
    {
        QList<QString> ParamValue;

        for (int i=0; i<listtxt.count(); i++)
        {
            ParamValue.append(listtxt.at(i)->text());
        }

        QString p = "";

        for (int i=0; i< ListTypeResources.count(); i++)
        {
            if (ListTypeResources.at(i).TypeName == ui->cmbTypes->currentText())
            {
                p = ListTypeResources.at(i).TraseValue;
            }
        }

        Resource rss(ui->cmbTypes->currentText(), ui->fldResName->text(), ParamValue, p);
        ListResources.removeAt(NumberChosenResource);
        ListResources.insert(NumberChosenResource, rss);

        QString s = "Ресурс '";
        s+=ChosenResource;
        s+="' успешно изменен!";
        ChosenResource = "";
        NumberChosenResource = -1;

        listlbl11.clear();
        listlbl12.clear();
        listlbl13.clear();
        listlbl14.clear();
        listtxt.clear();
        QMessageBox::warning(this, "Предупреждение", s);

        close();
    }
}
