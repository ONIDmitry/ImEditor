#include "formcreateoperation.h"
#include "ui_formcreateoperation.h"
#include <QList>
#include "immodel.h"
#include <QList>
#include <QString>
#include <QMessageBox>

using namespace std;

int colTxtBox2 = 1;
QList<QComboBox*> listcmb;

FormCreateOperation::FormCreateOperation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCreateOperation)
{
    ui->setupUi(this);

    extern QList<PatternOperation> ListPatternOperations;
    extern QList<Resource> ListResources;

    listcmb.clear();

    for (int i=0; i< ListPatternOperations.count(); i++)
    {
        ui->cmbPatternName->addItem(ListPatternOperations.at(i).PatternName);
    }

    for (int i=0; i< ListResources.count(); i++)
    {
        ui->cmbResourceName->addItem(ListResources.at(i).ResourceName);
    }

    listcmb.append(ui->cmbResourceName);


}

FormCreateOperation::~FormCreateOperation()
{
    delete ui;
}

void FormCreateOperation::on_pushButton_2_clicked()
{
    QComboBox *cmb = new QComboBox(this);
    extern QList<Resource> ListResources;
    colTxtBox2+=1;

    for (int i=0; i<ListResources.count(); i++)
    {
        cmb->addItem(ListResources.at(i).ResourceName);
    }

    cmb->setGeometry(ui->cmbResourceName->x() + (colTxtBox2 - 1)* (ui->cmbResourceName->width() + 10), ui->cmbResourceName->y(), ui->cmbResourceName->width(), ui->cmbResourceName->height());

    cmb->show();
    listcmb.append(cmb);
}

void FormCreateOperation::on_pushButton_3_clicked()
{
    if (colTxtBox2 > 1)
    {
        delete listcmb.at(listcmb.count() - 1);
        listcmb.removeAt(listcmb.count() - 1);

        colTxtBox2--;
    }
}

void FormCreateOperation::on_pushButton_clicked()
{
    bool check1 = true;
    extern QList<Operation> ListOperations;

    if (ui->fldOperationName->text() == "")
    {
        QString s = "Введите имя операции!";
        QMessageBox::warning(this, "Предупреждение", s);
        check1 = false;
    }

    if (check1 == true)
    {
        QList<QString> ResourceNames;

        for (int i=0; i<listcmb.count(); i++)
        {
            ResourceNames.append(listcmb.at(i)->currentText());
        }

        Operation opr(ui->fldOperationName->text(),ui->cmbPatternName->currentText(), ResourceNames);
        ListOperations.append(opr);

        QString s = "Операция '";
        s+=ui->fldOperationName->text();
        s+="' успешно создана!";
        listcmb.clear();
        QMessageBox::warning(this, "Предупреждение", s);

        close();
    }
}
