#include "formcreatepatternoperation.h"
#include "ui_formcreatepatternoperation.h"
#include "QVBoxLayout"
#include "QList"
#include "QLabel"
#include "immodel.h"
#include <QGridLayout>
#include <QMessageBox>
#include <patternoperation.h>

using namespace std;

int colTxtBox1 = 1;
QList<QLabel*> listlbl1;
QList<QLabel*> listlbl2;
QList<QLabel*> listlbl3;
QList<QLabel*> listlbl4;
QList<QLabel*> listlbl5;
QList<QLabel*> listlbl6;
QList<QLabel*> listlbl7;
QList<QLabel*> listlbl8;
QList<QLabel*> listlbl9;
QList<QLabel*> listlbl10;

QList<QLineEdit*> listtxt1;
QList<QLineEdit*> listtxt2;
QList<QLineEdit*> listtxt3;
QList<QLineEdit*> listtxt4;
QList<QLineEdit*> listtxt5;
QList<QLineEdit*> listtxt6;

QList<QComboBox*> listcmb1;
QList<QComboBox*> listcmb2;
QList<QComboBox*> listcmb3;
QList<QComboBox*> listcmb4;

QList<QFrame*> listfrm;

QGridLayout *lay = new QGridLayout;
FormCreatePatternOperation::FormCreatePatternOperation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCreatePatternOperation)
{
    ui->setupUi(this);
  // QGridLayout *lay = new QGridLayout;

   //lay->addWidget();

    listlbl1.clear();
    listlbl2.clear();
    listlbl3.clear();
    listlbl4.clear();
    listlbl5.clear();
    listlbl6.clear();
    listlbl7.clear();
    listlbl8.clear();
    listlbl9.clear();
    listlbl10.clear();

    listtxt1.clear();
    listtxt2.clear();
    listtxt3.clear();
    listtxt4.clear();
    listtxt5.clear();
    listtxt6.clear();

    listcmb1.clear();
    listcmb2.clear();
    listcmb3.clear();
    listcmb4.clear();

    listfrm.clear();

    QLabel *l1 = new QLabel;
    QLabel *l2 = new QLabel;
    QLabel *l3 = new QLabel;
    QLabel *l4 = new QLabel;
    QLabel *l5 = new QLabel;
    QLabel *l6 = new QLabel;
    QLabel *l7 = new QLabel;
    QLabel *l8 = new QLabel;
    QLabel *l9 = new QLabel;
    QLabel *l10 = new QLabel;
    QLineEdit *t1 = new QLineEdit;
    QLineEdit *t2 = new QLineEdit;
    QLineEdit *t3 = new QLineEdit;
    QLineEdit *t4 = new QLineEdit;
    QLineEdit *t5 = new QLineEdit;
    QLineEdit *t6 = new QLineEdit;
    QComboBox *c1 = new QComboBox;
    QComboBox *c2 = new QComboBox;
    QComboBox *c3 = new QComboBox;
    QComboBox *c4 = new QComboBox;
    QLabel *exl1 = new QLabel;
    exl1->setText("______________________");



    l1->setText("Релевантный ресурс");
    l2->setText("Описатель");
    l3->setText("Статус конвертора");
    l4->setText("Статус конвертора начала");
    l5->setText("Статус конвертора конца");
    l6->setText("Предусловие");
    l7->setText("Convert Event");
    l8->setText("Convert Rule");
    l9->setText("Convert Begin");
    l10->setText("Convert End");

    //extern QGridLayout *lay;

    lay->addWidget(l1,0,0);
    lay->addWidget(l2,1,0);
    lay->addWidget(l3,2,0);
    lay->addWidget(l4,3,0);
    lay->addWidget(l5,4,0);
    lay->addWidget(exl1, 5,0);
    lay->addWidget(t1,0, 1);
    lay->addWidget(c1,1,1);
    lay->addWidget(c2,2,1);
    lay->addWidget(c3,3,1);
    lay->addWidget(c4,4,1);

    lay->addWidget(l6,0,3);
    lay->addWidget(l7,1,3);
    lay->addWidget(l8,2,3);
    lay->addWidget(l9,3,3);
    lay->addWidget(l10,4,3);

    lay->addWidget(t2,0,4);
    lay->addWidget(t3,1,4);
    lay->addWidget(t4,2,4);
    lay->addWidget(t5,3,4);
    lay->addWidget(t6,4,4);

    lay->setColumnMinimumWidth(4,650);

    ui->scrollContents->setLayout(lay);

    extern QList<TypeResource> ListTypeResources;

    for (int i=0; i < ListTypeResources.count(); i++)
    {
         c1->addItem(ListTypeResources.at(i).TypeName);
    }

    ui->cmbPatternType->addItems(QStringList()<<"Нерегулярное_событие"<<"Правило"<<"Операция");
    ui->cmbTrase->addItems(QStringList()<<"Да"<<"Нет");
    ui->cmbTypeTime->addItems(QStringList()<<"Точное"<<"Случайное");
    ui->cmbLaw->addItems(QStringList()<<"@normal@"<<"@exponential@"<<"@uniform@"<<"Отсутствует");
    c2->addItems(QStringList()<<"Не_изменять"<<"Сохранить"<<"Отсутствует");
    c3->addItems(QStringList()<<"Не_изменять"<<"Сохранить"<<"Отсутствует");
    c4->addItems(QStringList()<<"Не_изменять"<<"Сохранить"<<"Отсутствует");

    listlbl1.append(l1);
    listlbl2.append(l2);
    listlbl3.append(l3);
    listlbl4.append(l4);
    listlbl5.append(l5);
    listlbl6.append(l6);
    listlbl7.append(l7);
    listlbl8.append(l8);
    listlbl9.append(l9);
    listlbl10.append(l10);

    listtxt1.append(t1);
    listtxt2.append(t2);
    listtxt3.append(t3);
    listtxt4.append(t4);
    listtxt5.append(t5);
    listtxt6.append(t6);

    listcmb1.append(c1);
    listcmb2.append(c2);
    listcmb3.append(c3);
    listcmb4.append(c4);

    listfrm.append(exl1);


}

FormCreatePatternOperation::~FormCreatePatternOperation()
{
    delete ui;
}

void FormCreatePatternOperation::on_pushButton_clicked()
{
    QLabel *l1 = new QLabel;
    QLabel *l2 = new QLabel;
    QLabel *l3 = new QLabel;
    QLabel *l4 = new QLabel;
    QLabel *l5 = new QLabel;
    QLabel *l6 = new QLabel;
    QLabel *l7 = new QLabel;
    QLabel *l8 = new QLabel;
    QLabel *l9 = new QLabel;
    QLabel *l10 = new QLabel;
    QLineEdit *t1 = new QLineEdit;
    QLineEdit *t2 = new QLineEdit;
    QLineEdit *t3 = new QLineEdit;
    QLineEdit *t4 = new QLineEdit;
    QLineEdit *t5 = new QLineEdit;
    QLineEdit *t6 = new QLineEdit;
    QComboBox *c1 = new QComboBox;
    QComboBox *c2 = new QComboBox;
    QComboBox *c3 = new QComboBox;
    QComboBox *c4 = new QComboBox;

    QLabel *exl1 = new QLabel;
    exl1->setText("_______________");

    colTxtBox1+=1;

    l1->setText("Релевантный ресурс");
    l2->setText("Описатель");
    l3->setText("Статус конвертора");
    l4->setText("Статус конвертора начала");
    l5->setText("Статус конвертора конца");
    l6->setText("Предусловие");
    l7->setText("Convert Event");
    l8->setText("Convert Rule");
    l9->setText("Convert Begin");
    l10->setText("Convert End");

   // extern QGridLayout *lay1 = new QGridLayout;
    lay->addWidget(exl1,((colTxtBox1-1)*6) + 5,0);
    lay->addWidget(l1,((colTxtBox1-1)*6),0);
    lay->addWidget(l2,((colTxtBox1-1)*6) +1,0);
    lay->addWidget(l3,((colTxtBox1-1)*6) +2,0);
    lay->addWidget(l4,((colTxtBox1-1)*6) +3,0);
    lay->addWidget(l5,((colTxtBox1-1)*6) +4,0);
    lay->addWidget(t1,((colTxtBox1-1)*6), 1);
    lay->addWidget(c1,((colTxtBox1-1)*6) +1,1);
    lay->addWidget(c2,((colTxtBox1-1)*6) +2,1);
    lay->addWidget(c3,((colTxtBox1-1)*6) +3,1);
    lay->addWidget(c4,((colTxtBox1-1)*6) +4,1);

    lay->addWidget(l6,((colTxtBox1-1)*6) ,3);
    lay->addWidget(l7,((colTxtBox1-1)*6) +1,3);
    lay->addWidget(l8,((colTxtBox1-1)*6) +2,3);
    lay->addWidget(l9,((colTxtBox1-1)*6) +3,3);
    lay->addWidget(l10,((colTxtBox1-1)*6) +4,3);

    lay->addWidget(t2,((colTxtBox1-1)*6) ,4);
    lay->addWidget(t3,((colTxtBox1-1)*6) +1,4);
    lay->addWidget(t4,((colTxtBox1-1)*6) +2,4);
    lay->addWidget(t5,((colTxtBox1-1)*6) +3,4);
    lay->addWidget(t6,((colTxtBox1-1)*6) +4,4);
     lay->setColumnMinimumWidth(4,650);

     ui->scrollContents->setLayout(lay);

     extern QList<TypeResource> ListTypeResources;

     for (int i=0; i < ListTypeResources.count(); i++)
     {
          c1->addItem(ListTypeResources.at(i).TypeName);
     }


     c2->addItems(QStringList()<<"Не_изменять"<<"Сохранить"<<"Отсутствует");
     c3->addItems(QStringList()<<"Не_изменять"<<"Сохранить"<<"Отсутствует");
     c4->addItems(QStringList()<<"Не_изменять"<<"Сохранить"<<"Отсутствует");

     listlbl1.append(l1);
     listlbl2.append(l2);
     listlbl3.append(l3);
     listlbl4.append(l4);
     listlbl5.append(l5);
     listlbl6.append(l6);
     listlbl7.append(l7);
     listlbl8.append(l8);
     listlbl9.append(l9);
     listlbl10.append(l10);

     listtxt1.append(t1);
     listtxt2.append(t2);
     listtxt3.append(t3);
     listtxt4.append(t4);
     listtxt5.append(t5);
     listtxt6.append(t6);

     listcmb1.append(c1);
     listcmb2.append(c2);
     listcmb3.append(c3);
     listcmb4.append(c4);

     listfrm.append(exl1);

}

void FormCreatePatternOperation::on_pushButton_2_clicked()
{
    if (colTxtBox1 > 1)
    {
        delete listlbl1.at(listlbl1.count() - 1);
        delete listlbl2.at(listlbl2.count() - 1);
        delete listlbl3.at(listlbl3.count() - 1);
        delete listlbl4.at(listlbl4.count() - 1);
        delete listlbl5.at(listlbl5.count() - 1);
        delete listlbl6.at(listlbl6.count() - 1);
        delete listlbl7.at(listlbl7.count() - 1);
        delete listlbl8.at(listlbl8.count() - 1);
        delete listlbl9.at(listlbl9.count() - 1);
        delete listlbl10.at(listlbl10.count() - 1);

        delete listtxt1.at(listtxt1.count() - 1);
        delete listtxt2.at(listtxt2.count() - 1);
        delete listtxt3.at(listtxt3.count() - 1);
        delete listtxt4.at(listtxt4.count() - 1);
        delete listtxt5.at(listtxt5.count() - 1);
        delete listtxt6.at(listtxt6.count() - 1);

        delete listcmb1.at(listcmb1.count() - 1);
        delete listcmb2.at(listcmb2.count() - 1);
        delete listcmb3.at(listcmb3.count() - 1);
        delete listcmb4.at(listcmb4.count() - 1);

        delete listfrm.at(listfrm.count() - 1);

        listlbl1.removeAt(listlbl1.count() - 1);
        listlbl2.removeAt(listlbl2.count() - 1);
        listlbl3.removeAt(listlbl3.count() - 1);
        listlbl4.removeAt(listlbl4.count() - 1);
        listlbl5.removeAt(listlbl5.count() - 1);
        listlbl6.removeAt(listlbl6.count() - 1);
        listlbl7.removeAt(listlbl7.count() - 1);
        listlbl8.removeAt(listlbl8.count() - 1);
        listlbl9.removeAt(listlbl9.count() - 1);
        listlbl10.removeAt(listlbl10.count() - 1);

        listtxt1.removeAt(listtxt1.count() - 1);
        listtxt2.removeAt(listtxt2.count() - 1);
        listtxt3.removeAt(listtxt3.count() - 1);
        listtxt4.removeAt(listtxt4.count() - 1);
        listtxt5.removeAt(listtxt5.count() - 1);
        listtxt6.removeAt(listtxt6.count() - 1);

        listcmb1.removeAt(listcmb1.count() - 1);
        listcmb2.removeAt(listcmb2.count() - 1);
        listcmb3.removeAt(listcmb3.count() - 1);
        listcmb4.removeAt(listcmb4.count() - 1);

        listfrm.removeAt(listfrm.count() - 1);


        colTxtBox1--;
    }
}

void FormCreatePatternOperation::on_pushButton_3_clicked()
{
    bool check1 = true;
    bool check2 = true;
    bool check3 = true;
    bool check4 = true;
    bool check5 = true;
    bool isNumber1 = false;
    bool isNumber2 = false;
    bool isNumber3 = false;

    int n = 0;

    if (ui->fldPatternName->text() == "")
    {
        QString s = "Вы не ввели имя образца операции! ";
        QMessageBox::warning(this, "Предупреждение", s);
        check1 = false;
    }

    for (int i=0; i<listtxt1.count(); i++)
    {
        if (listtxt1.at(i)->text() == "")
        {
            QString s = "Не введено имя релевантного ресурса № ";
            s+=QString::number(i+1);
            s+=" !";
            QMessageBox::warning(this, "Предупреждение", s);
            check1 = false;
        }
    }

    if ((ui->cmbTypeTime->currentText() == "Точное") && (ui->fldTimeValue->text() == ""))
    {
        QString s = "Для точного типа времени не может быть задано пустое значение времени! ";
        QMessageBox::warning(this, "Предупреждение", s);
        check3 = false;
    }

    double d = ui->fldTimeValue->text().toDouble(&isNumber1);

    if ((ui->cmbTypeTime->currentText() == "Точное") && (ui->fldTimeValue->text() != "") && (isNumber1 == false))
    {
        QString s = "Для точного типа времени заданное значение времени не является числом! ";
        QMessageBox::warning(this, "Предупреждение", s);
        check3 = false;
    }

    if ((ui->cmbTypeTime->currentText() == "Точное") && ((ui->cmbLaw->currentText() != "Отсутствует") || (ui->fldBeginInt->text() != "") || (ui->fldEndInt->text() != "")))
    {
        QString s = "Для точного типа времени нельзя указывать закон, начало и конец интервала! ";
        QMessageBox::warning(this, "Предупреждение", s);
        check3 = false;
    }

    if ((ui->cmbTypeTime->currentText() == "Случайное") && (ui->cmbLaw->currentText() == "Отсутствует"))
    {
        QString s = "Для случайного типа времени не задан закон! ";
        QMessageBox::warning(this, "Предупреждение", s);
        check3 = false;
    }

    if ((ui->cmbTypeTime->currentText() == "Случайное") && (ui->fldBeginInt->text() == ""))
    {
        QString s = "Для случайного типа времени не задано начало интервала! ";
        QMessageBox::warning(this, "Предупреждение", s);
        check3 = false;
    }

    if ((ui->cmbTypeTime->currentText() == "Случайное") && (ui->fldEndInt->text() == ""))
    {
        QString s = "Для случайного типа времени не задан конец интервала! ";
        QMessageBox::warning(this, "Предупреждение", s);
        check3 = false;
    }

     double x = ui->fldBeginInt->text().toDouble(&isNumber2);
     double z = ui->fldEndInt->text().toDouble(&isNumber3);

     if ((ui->cmbTypeTime->currentText() == "Случайное") && (ui->fldBeginInt->text() != "") && (isNumber2 == false))
     {
         QString s = "Для случайного типа времени заданное значение начала интервала не является числом! ";
         QMessageBox::warning(this, "Предупреждение", s);
         check3 = false;
     }

     if ((ui->cmbTypeTime->currentText() == "Случайное") && (ui->fldEndInt->text() != "") && (isNumber3 == false))
     {
         QString s = "Для случайного типа времени заданное значение конца интервала не является числом! ";
         QMessageBox::warning(this, "Предупреждение", s);
         check3 = false;
     }

     if ((ui->cmbTypeTime->currentText() == "Случайное") && (ui->fldTimeValue->text() != ""))
     {
         QString s = "Для случайного типа времени нельзя задавать конкретное значение времени! ";
         QMessageBox::warning(this, "Предупреждение", s);
         check3 = false;
     }

     for (int i=0; i<listcmb2.count();i++)
     {
         if ((ui->cmbPatternType->currentText() == "Нерегулярное_событие") && (listcmb2.at(i)->currentText() == "Отсутствует"))
         {
             QString s = "Для нерегулярного события необходимо задать статус конвертора! Не задан для релевантного ресурса №  ";
             s+=QString::number(i+1);
             s+=" !";
             QMessageBox::warning(this, "Предупреждение", s);
             check4 = false;
         }
     }

     for (int i=0; i<listcmb2.count(); i++)
     {
         if ((ui->cmbPatternType->currentText() == "Нерегулярное_событие") && (listcmb3.at(i)->currentText() != "Отсутствует" || listcmb4.at(i)->currentText() != "Отсутствует"))
         {
             QString s = "Для нерегулярного события нельзя задавать статус конвертора начала или конца (релевантный ресурс №  ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check4 = false;
         }
     }

     for (int i=0; i<listcmb2.count();i++)
     {
         if ((ui->cmbPatternType->currentText() == "Правило") && (listcmb2.at(i)->currentText() == "Отсутствует"))
         {
             QString s = "Для правила необходимо задать статус конвертора! Не задан для релевантного ресурса №  ";
             s+=QString::number(i+1);
             s+=" !";
             QMessageBox::warning(this, "Предупреждение", s);
             check4 = false;
         }
     }

     for (int i=0; i<listcmb2.count(); i++)
     {
         if ((ui->cmbPatternType->currentText() == "Правило") && (listcmb3.at(i)->currentText() != "Отсутствует" || listcmb4.at(i)->currentText() != "Отсутствует"))
         {
             QString s = "Для правила нельзя задавать статус конвертора начала или конца (релевантный ресурс №  ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check4 = false;
         }
     }

     for (int i=0; i<listcmb3.count(); i++)
     {
         if ((ui->cmbPatternType->currentText() == "Операция") && (listcmb3.at(i)->currentText() == "Отсутствует"))
         {
             QString s = "Для операции необходимо задать статус конвертора начала! Не задан для релевантного ресурса № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check4 = false;
         }
     }

     for (int i=0; i<listcmb4.count(); i++)
     {
         if ((ui->cmbPatternType->currentText() == "Операция") && (listcmb4.at(i)->currentText() == "Отсутствует"))
         {
             QString s = "Для операции необходимо задать статус конвертора конца! Не задан для релевантного ресурса № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check4 = false;
         }
     }


     for (int i=0; i<listcmb2.count(); i++)
     {
         if ((ui->cmbPatternType->currentText() == "Операция") && (listcmb2.at(i)->currentText() != "Отсутствует"))
         {
             QString s = "Для операции нельзя задавать статус конвертора (релевантный ресурс № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check4 = false;
         }
     }

     for (int i=0; i<listtxt2.count(); i++)
     {
         if ((ui->cmbPatternType->currentText() == "Нерегулярное_событие") && (listtxt2.at(i)->text() != ""))
         {
             QString s = "Для нерегулярного события нельзя задавать предусловие! (релевантный ресурс № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check5 = false;
         }

         if ((ui->cmbPatternType->currentText() == "Правило") && (listtxt2.at(i)->text() == ""))
         {
             QString s = "Для правила необходимо задать предусловие! (релевантный ресурс № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check5 = false;
         }

         if ((ui->cmbPatternType->currentText() == "Операция") && (listtxt2.at(i)->text() == ""))
         {
             QString s = "Для операции необходимо задать предусловие! (релевантный ресурс № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check5 = false;
         }
     }

     for (int i=0; i<listtxt3.count(); i++)
     {
         if ((ui->cmbPatternType->currentText() == "Нерегулярное_событие") && (listtxt3.at(i)->text() == ""))
         {
             QString s = "Для нерегулярного события необходимо описать действия в convert Event! (релевантный ресурс № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check5 = false;
         }

         if ((ui->cmbPatternType->currentText() == "Правило") && (listtxt3.at(i)->text() != ""))
         {
             QString s = "Для правила нельзя описывать действия в Convert Event! (релевантный ресурс № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check5 = false;
         }

         if ((ui->cmbPatternType->currentText() == "Операция") && (listtxt3.at(i)->text() != ""))
         {
             QString s = "Для операции нельзя описывать действия в Convert Event! (релевантный ресурс № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check5 = false;
         }

     }

     for (int i=0; i<listtxt4.count(); i++)
     {
         if ((ui->cmbPatternType->currentText() == "Нерегулярное_событие") && (listtxt4.at(i)->text() != ""))
         {
             QString s = "Для нерегулярного события нельзя задавать действия в Convert Rule! (релевантный ресурс № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check5 = false;
         }

         if ((ui->cmbPatternType->currentText() == "Правило") && (listtxt4.at(i)->text() == ""))
         {
             QString s = "Для правила необходимо задать действия в Convert Rule! (релевантный ресурс № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check5 = false;
         }

         if ((ui->cmbPatternType->currentText() == "Операция") && (listtxt4.at(i)->text() != ""))
         {
             QString s = "Для операции нельзя задавать действия в Convert Rule! (релевантный ресурс № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check5 = false;
         }
     }

    for (int i=0; i<listtxt5.count(); i++)
    {
        if ((ui->cmbPatternType->currentText() == "Нерегулярное_событие") && (listtxt5.at(i)->text() != ""))
        {
            QString s = "Для нерегулярного события нельзя задавать действия в Convert Begin! (релевантный ресурс № ";
            s+=QString::number(i+1);
            s+=") !";
            QMessageBox::warning(this, "Предупреждение", s);
            check5 = false;
        }

        if ((ui->cmbPatternType->currentText() == "Правило") && (listtxt5.at(i)->text() != ""))
        {
            QString s = "Для правила нельзя задавать действия в Convert Begin! (релевантный ресурс № ";
            s+=QString::number(i+1);
            s+=") !";
            QMessageBox::warning(this, "Предупреждение", s);
            check5 = false;
        }

        if ((ui->cmbPatternType->currentText() == "Операция") && (listtxt5.at(i)->text() == ""))
        {
            QString s = "Для операции необходимо задать действия в Convert Begin! (релевантный ресурс № ";
            s+=QString::number(i+1);
            s+=") !";
            QMessageBox::warning(this, "Предупреждение", s);
            check5 = false;
        }

    }


    for (int i=0; i<listtxt6.count(); i++)
    {
        if ((ui->cmbPatternType->currentText() == "Нерегулярное_событие") && (listtxt6.at(i)->text() != ""))
        {
            QString s = "Для нерегулярного события нельзя задавать действия в Convert End! (релевантный ресурс № ";
            s+=QString::number(i+1);
            s+=") !";
            QMessageBox::warning(this, "Предупреждение", s);
            check5 = false;
        }

        if ((ui->cmbPatternType->currentText() == "Правило") && (listtxt6.at(i)->text() != ""))
        {
            QString s = "Для правила нельзя задавать действия в Convert End! (релевантный ресурс № ";
            s+=QString::number(i+1);
            s+=") !";
            QMessageBox::warning(this, "Предупреждение", s);
            check5 = false;
        }

        if ((ui->cmbPatternType->currentText() == "Операция") && (listtxt6.at(i)->text() == ""))
        {
            QString s = "Для операции необходимо задать действия в Convert End! (релевантный ресурс № ";
            s+=QString::number(i+1);
            s+=") !";
            QMessageBox::warning(this, "Предупреждение", s);
            check5 = false;
        }

    }

    if ((check1 == true) && (check2 == true) && (check3 == true) && (check4 == true) && (check5 == true))
    {
        QList<QString> RelResName;
        QList<QString> TypeNameW;
        QList<QString> ConvStatus;
        QList<QString> ConvBegin ;
        QList<QString> ConvEnd;
        QList<QString> Condition;
        QList<QString> ConvertEvent;
        QList<QString> ConvertRule;
        QList<QString> ConvertBegin;
        QList<QString> ConvertEnd;
        extern QList<PatternOperation> ListPatternOperations;

        QString l;


        for (int i=0; i<listtxt1.count(); i++)
        {
            RelResName.append(listtxt1.at(i)->text());
            Condition.append(listtxt2.at(i)->text());
            ConvertEvent.append(listtxt3.at(i)->text());
            ConvertRule.append(listtxt4.at(i)->text());
            ConvertBegin.append(listtxt5.at(i)->text());
            ConvertEnd.append(listtxt6.at(i)->text());
            TypeNameW.append(listcmb1.at(i)->currentText());

            if (listcmb2.at(i)->currentText() == "Отсутствует")
            {
                ConvStatus.append("");
            }
            else
            {
                ConvStatus.append(listcmb2.at(i)->currentText());
            }

            if (listcmb3.at(i)->currentText() == "Отсутствует")
            {
                ConvBegin.append("");
            }
            else
            {
                ConvBegin.append(listcmb3.at(i)->currentText());
            }

            if (listcmb4.at(i)->currentText() == "Отсутствует")
            {
                ConvEnd.append("");
            }
            else
            {
                ConvEnd.append(listcmb4.at(i)->currentText());
            }

            if (ui->cmbLaw->currentText() == "Отсутствует")
            {
                l = "";
            }
            else
            {
                l = ui->cmbLaw->currentText();
            }

            PatternOperation ptr1(ui->fldPatternName->text(), ui->cmbPatternType->currentText(), ui->cmbTrase->currentText(), ui->cmbTypeTime->currentText(), ui->fldTimeValue->text(), l, ui->fldBeginInt->text(), ui->fldEndInt->text(), RelResName, TypeNameW, ConvStatus, ConvBegin, ConvEnd, Condition, ConvertEvent, ConvertRule, ConvertBegin, ConvertEnd);
            ListPatternOperations.append(ptr1);
            QString s = "Образец операции '";
            s+=ui->fldPatternName->text();
            s+="' успешно создан!";
            listtxt1.clear();
            listtxt2.clear();
            listtxt3.clear();
            listtxt4.clear();
            listtxt5.clear();
            listtxt6.clear();

            listlbl1.clear();
            listlbl2.clear();
            listlbl3.clear();
            listlbl4.clear();
            listlbl5.clear();
            listlbl6.clear();
            listlbl7.clear();
            listlbl8.clear();
            listlbl9.clear();
            listlbl10.clear();

            listcmb1.clear();
            listcmb2.clear();
            listcmb3.clear();
            listcmb4.clear();

            listfrm.clear();
            QMessageBox::warning(this, "Предупреждение", s);

            close();


        }
    }

}
