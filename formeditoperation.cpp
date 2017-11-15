#include "formeditoperation.h"
#include "ui_formeditoperation.h"
#include "immodel.h"
#include <QComboBox>
#include <QMessageBox>


int colTxtBox9 = 1;
QList<QComboBox*> listcmb31;
FormEditOperation::FormEditOperation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormEditOperation)
{
    ui->setupUi(this);

    extern QList<Operation> ListOperations;
    extern QList<PatternOperation> ListPatternOperations;
    extern QList<Resource> ListResources;
    extern QString ChosenOperation;
    extern int NumberChosenOperation;

    colTxtBox9 = 1;

    for (int i =0; i< ListOperations.count(); i ++)
    {
        ui->cmbPatternName->addItem(ListPatternOperations.at(i).PatternName);
    }

    ui->fldOperationName->setText(ListOperations.at(NumberChosenOperation).OperationName);
    ui->cmbPatternName->setCurrentText(ListOperations.at(NumberChosenOperation).PatternName);

    for (int i=0; i< ListOperations.at(NumberChosenOperation).ResourceNames.count(); i++)
    {
        QComboBox *cmb1 = new QComboBox(this);


        for (int j=0; j<ListResources.count(); j++)
        {
            cmb1->addItem(ListResources.at(j).ResourceName);
        }
        try
        {
            cmb1->setCurrentText(ListOperations.at(NumberChosenOperation).ResourceNames.at(i));
        }
        catch (exception)
        {
            QString s = "Ошибка определения одного из ресурсов для операции ";
            QMessageBox::warning(this, "Предупреждение", s);
        }

        cmb1->setGeometry(colTxtBox9* (110), 185, 100, 21);
        cmb1->show();
        listcmb31.append(cmb1);

        colTxtBox9+=1;
    }
}

FormEditOperation::~FormEditOperation()
{
    delete ui;
}

void FormEditOperation::on_pushButton_4_clicked()
{
    QComboBox *cmb2 = new QComboBox(this);
    extern QList<Resource> ListResources;

    for (int i=0; i<ListResources.count(); i++)
    {
        cmb2->addItem(ListResources.at(i).ResourceName);
    }

    cmb2->setGeometry(colTxtBox9* (110), 185, 100, 21);

    cmb2->show();
    listcmb31.append(cmb2);
    colTxtBox9+=1;
}

void FormEditOperation::on_pushButton_5_clicked()
{
    if (colTxtBox9 > 2)
    {
        delete listcmb31.at(listcmb31.count() - 1);
        listcmb31.removeAt(listcmb31.count() - 1);

        colTxtBox9--;
    }
}

void FormEditOperation::on_pushButton_2_clicked()
{
    extern QList<Operation> ListOperations;
    extern QString ChosenOperation;
    extern int NumberChosenOperation;

    ListOperations.removeAt(NumberChosenOperation);

    QString s = "Операция \"";
    s+=ChosenOperation;
    s+="\" успешно удалена!";
    QMessageBox::warning(this, "Предупреждение", s);

    ChosenOperation = "";
    NumberChosenOperation = -1;
    listcmb31.clear();
    close();
}

void FormEditOperation::on_pushButton_3_clicked()
{

    extern QString ChosenOperation;
    extern int NumberChosenOperation;
    ChosenOperation = "";
    NumberChosenOperation = -1;
    listcmb31.clear();
    close();
}

void FormEditOperation::on_pushButton_clicked()
{
    bool check1 = true;
    extern QList<Operation> ListOperations;
    extern QString ChosenOperation;
    extern int NumberChosenOperation;


    if (ui->fldOperationName->text() == "")
    {
        QString s = "Введите имя операции!";
        QMessageBox::warning(this, "Предупреждение", s);
        check1 = false;
    }

    if (check1 == true)
    {
        QList<QString> ResourceNames;

        for (int i=0; i<listcmb31.count(); i++)
        {
            ResourceNames.append(listcmb31.at(i)->currentText());
        }

        Operation opr(ui->fldOperationName->text(),ui->cmbPatternName->currentText(), ResourceNames);
        ListOperations.removeAt(NumberChosenOperation);
        ListOperations.insert(NumberChosenOperation, opr);

        QString s = "Операция '";
        s+=ChosenOperation;
        s+="' успешно изменена!";
        ChosenOperation = "";
        NumberChosenOperation = -1;
        listcmb31.clear();
        QMessageBox::warning(this, "Предупреждение", s);

        close();
    }
}
