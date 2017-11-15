#include "formcreateresource.h"
#include "ui_formcreateresource.h"
#include <immodel.h>
#include <QMessageBox>
#include <QLabel>
#include <mainwindow.h>


using namespace std;

QList<QLineEdit*> txtbxes4;
QList<QLabel*> lbl1;
QList<QLabel*> lbl2;
QList<QLabel*> lbl3;
QList<QLabel*> lbl4;


formcreateresource::formcreateresource(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::formcreateresource)
{
    ui->setupUi(this);

    extern QList<TypeResource> ListTypeResources;

    lbl1.clear();
    lbl2.clear();
    lbl3.clear();
    lbl4.clear();
    txtbxes4.clear();

    ui->pushButton_2->setVisible(false);
    ui->fldResName->setVisible(false);

    for (int i=0; i< ListTypeResources.count(); i++)
    {
        ui->cmbTypes->addItem(ListTypeResources.at(i).TypeName);
    }
}

formcreateresource::~formcreateresource()
{
    delete ui;
}

void formcreateresource::on_pushButton_clicked()
{
    extern QList<TypeResource> ListTypeResources;
    int n=0;

    for (int i=0; i<txtbxes4.count();i++)
    {
        delete txtbxes4.at(i);
        delete lbl1.at(i);
        delete lbl2.at(i);
        delete lbl3.at(i);
        delete lbl4.at(i);

        txtbxes4.removeAt(i);
        lbl1.removeAt(i);
        lbl2.removeAt(i);
        lbl3.removeAt(i);
        lbl4.removeAt(i);
    }

    qDeleteAll(txtbxes4.begin(), txtbxes4.end());
    qDeleteAll(lbl1.begin(), lbl1.end());
    qDeleteAll(lbl2.begin(), lbl2.end());
    qDeleteAll(lbl3.begin(), lbl3.end());
    qDeleteAll(lbl4.begin(), lbl4.end());

    txtbxes4.clear();
    lbl1.clear();
    lbl2.clear();
    lbl3.clear();
    lbl4.clear();


    for (int i=0; i<ListTypeResources.count(); i++)
    {
        if (ui->cmbTypes->currentText() != ListTypeResources.at(i).TypeName)
        {
            n++;
        }
        else
        {
            break;
        }
    }

    QLabel *l1 = new QLabel(this);
    QLabel *l2 = new QLabel(this);
    QLabel *l3 = new QLabel(this);
    QLabel *l4 = new QLabel(this);
    QLabel *l5 = new QLabel(this);
    QLabel *l6 = new QLabel(this);

    ui->pushButton_2->setVisible(true);
    ui->fldResName->setVisible(true);
    l1->setText("Имя параметра");
    l2->setText("Тип параметра");
    l3->setText("Возможные значения (только для типа Enum)");
    l4->setText("Значение по умолчанию");
    l5->setText("Начальное значение параметра ресурсов");
    l6->setText("Введите имя ресурса");

    l1->setGeometry(25,170,81,16);
    l2->setGeometry(140,170,81,16);
    l3->setGeometry(250,170,250,16);
    l4->setGeometry(510,170,131,16);
    l5->setGeometry(650,170,250,16);
    l6->setGeometry(100,100,150,16);

    l1->show();
    l2->show();
    l3->show();
    l4->show();
    l5->show();
    l6->show();


    for (int i=0; i<ListTypeResources.at(n).ParamName.count();i++)
    {
        QLabel *newl1 = new QLabel(this);
        QLabel *newl2 = new QLabel(this);
        QLabel *newl3 = new QLabel(this);
        QLabel *newl4 = new QLabel(this);
        QLineEdit *newtxt = new QLineEdit(this);

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

        newl1->setText(ListTypeResources.at(n).ParamName.at(i));
        newl2->setText(ListTypeResources.at(n).ParamType.at(i));
        newl3->setText(ListTypeResources.at(n).ParamVariant.at(i));
        newl4->setText(ListTypeResources.at(n).ParamDefault.at(i));

        newl1->setGeometry(15,170+(i+1)*(l1->height() + 10), 100, 16);
        newl2->setGeometry(135,170+(i+1)*(l2->height() + 10), 81, 16);
        newl3->setGeometry(260,170+(i+1)*(l3->height() + 10), 201, 16);
        newl4->setGeometry(520,170+(i+1)*(l4->height() + 10), 110, 16);

        newl1->show();
        newl2->show();
        newl3->show();
        newl4->show();

        newtxt->setGeometry(685,170+(i+1)*(l5->height() + 10), 110, 16);
        newtxt->show();
        txtbxes4.append(newtxt);
        lbl1.append(newl1);
        lbl2.append(newl2);
        lbl3.append(newl3);
        lbl4.append(newl4);
    }

}


void formcreateresource::on_pushButton_2_clicked()
{
    extern QList<TypeResource> ListTypeResources;
    extern QList<Resource> ListResources;
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
        if (lbl1.count() == ListTypeResources.at(n).ParamName.count())
        {
            for (int j=0; j<ListTypeResources.at(n).ParamName.count(); j++)
            {
                if (ListTypeResources.at(n).ParamName.at(j) == lbl1.at(j)->text())
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

    for (int i=0; i<lbl4.count(); i++)
    {
        if (lbl4.at(i)->text() == "")
        {
            if (txtbxes4.at(i)->text() == "")
            {
                QString s = "В параметре № ";
                s+=QString::number(i+1);
                s+=" не задано начальное значение параметра ресурса, в то время, как начальное значение параметра в типе ресурсов также пустое!";
                QMessageBox::warning(this, "Предупреждение", s);
                check3 = false;
            }
            else if (txtbxes4.at(i)->text() == "*")
            {
                QString s = "В параметре № ";
                s+=QString::number(i+1);
                s+="  указано начальное значение параметра ресурса '*', в то время, как начальное значение параметра в типе ресурсов пустое!";
                QMessageBox::warning(this, "Предупреждение", s);
                check3 = false;
            }
        }
        else if (txtbxes4.at(i)->text() == "")
        {
            QString s = "В параметре № ";
            s+=QString::number(i+1);
            s+=" указано пустое начальное значение параметра ресурса! Поставьте '*' или конкретное значение!";
            QMessageBox::warning(this, "Предупреждение", s);
            check3 = false;
        }
    }

    for (int i=0;i<txtbxes4.count(); i++)
    {
        double d = txtbxes4.at(i)->text().toDouble(&isNumber);
        if ((lbl2.at(i)->text() == "int") && (isNumber == false) && (txtbxes4.at(i)->text() != "") && (txtbxes4.at(i)->text() != "*"))
        {
            QString s = "Введенное начальное значение для типа int в параметре № ";
            s+=QString::number(i+1);
            s+=" не является числом! ";
            QMessageBox::warning(this, "Предупреждение", s);
            check4 = false;
        }
        else if ((lbl2.at(i)->text() == "bool") && (txtbxes4.at(i)->text() != "false") && (txtbxes4.at(i)->text() != "False") && (txtbxes4.at(i)->text() != "true") && (txtbxes4.at(i)->text() != "True") && (txtbxes4.at(i)->text() != "") && (txtbxes4.at(i)->text() != "*"))
        {
            QString s = "Введенное начальное значение для типа bool в параметре № ";
            s+=QString::number(i+1);
            s+=" задано неверно!";
            QMessageBox::warning(this, "Предупреждение", s);
            check4 = false;
        }
    }

    for (int i=0; i<ListResources.count(); i++)
    {
        if (check5 == true)
        {
            if (ListResources.at(i).ResourceName == ui->fldResName->text())
            {
                QString s = "Ресурс ";
                s+=ui->fldResName->text();
                s+=" уже существует!";
                QMessageBox::warning(this, "Предупреждение", s);
                check5 = false;
            }
        }
    }

    if ((check1 == true) && (check2 == true) && (check3 == true) && (check4 == true) && (check5 == true) && (check6 == true))
    {
        QList<QString> ParamValue;

        for (int i=0; i<txtbxes4.count(); i++)
        {
            ParamValue.append(txtbxes4.at(i)->text());
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
        ListResources.append(rss);
        QString s = "Ресурс '";
        s+=ui->fldResName->text();
        s+="' успешно создан!";
        txtbxes4.clear();
        lbl1.clear();
        lbl2.clear();
        lbl3.clear();
        lbl4.clear();
        QMessageBox::warning(this, "Предупреждение", s);

        close();
    }


}
