#include "formeditpatternoperation.h"
#include "ui_formeditpatternoperation.h"
#include "immodel.h"
#include <QMessageBox>
#include <QGridLayout>


int colTxtBox7 = 0;
QList<QLabel*> listlbl21;
QList<QLabel*> listlbl22;
QList<QLabel*> listlbl23;
QList<QLabel*> listlbl24;
QList<QLabel*> listlbl25;
QList<QLabel*> listlbl26;
QList<QLabel*> listlbl27;
QList<QLabel*> listlbl28;
QList<QLabel*> listlbl29;
QList<QLabel*> listlbl30;

QList<QLineEdit*> listtxt21;
QList<QLineEdit*> listtxt22;
QList<QLineEdit*> listtxt23;
QList<QLineEdit*> listtxt24;
QList<QLineEdit*> listtxt25;
QList<QLineEdit*> listtxt26;

QList<QComboBox*> listcmb21;
QList<QComboBox*> listcmb22;
QList<QComboBox*> listcmb23;
QList<QComboBox*> listcmb24;
QList<QFrame*> listfrm1;

QGridLayout *lay1 = new QGridLayout;
FormEditPatternOperation::FormEditPatternOperation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormEditPatternOperation)
{
    ui->setupUi(this);
    extern QList<PatternOperation> ListPatternOperations;
    extern QList<TypeResource> ListTypeResources;
    extern QString ChosenPatternOperation;
    extern int NumberChosenPatternOperation;

    colTxtBox7 = 0;
    listlbl21.clear();
    listlbl22.clear();
    listlbl23.clear();
    listlbl24.clear();
    listlbl25.clear();
    listlbl26.clear();
    listlbl27.clear();
    listlbl28.clear();
    listlbl29.clear();
    listlbl30.clear();

    listtxt21.clear();
    listtxt22.clear();
    listtxt23.clear();
    listtxt24.clear();
    listtxt25.clear();
    listtxt26.clear();

    listcmb21.clear();
    listcmb22.clear();
    listcmb23.clear();
    listcmb24.clear();

    listfrm1.clear();

    ui->cmbPatternType->addItems(QStringList()<<"Нерегулярное_событие"<<"Правило"<<"Операция");
    ui->cmbTrase->addItems(QStringList()<<"Да"<<"Нет");
    ui->cmbTypeTime->addItems(QStringList()<<"Точное"<<"Случайное");
    ui->cmbLaw->addItems(QStringList()<<"@normal@"<<"@exponential@"<<"@uniform@"<<"Отсутствует");

    ui->cmbPatternType->setCurrentText(ListPatternOperations.at(NumberChosenPatternOperation).PatternType);
    ui->cmbTrase->setCurrentText(ListPatternOperations.at(NumberChosenPatternOperation).PatternTrace);
    ui->cmbTypeTime->setCurrentText(ListPatternOperations.at(NumberChosenPatternOperation).TypeTime);

    if (ListPatternOperations.at(NumberChosenPatternOperation).TimeLaw == "")
    {
        ui->cmbLaw->setCurrentText("Отсутствует");
    }
    else
    {
        ui->cmbLaw->setCurrentText(ListPatternOperations.at(NumberChosenPatternOperation).TimeLaw);
    }

    ui->fldPatternName->setText(ListPatternOperations.at(NumberChosenPatternOperation).PatternName);
    ui->fldTimeValue->setText(ListPatternOperations.at(NumberChosenPatternOperation).TimeValue);
    ui->fldBeginInt->setText(ListPatternOperations.at(NumberChosenPatternOperation).StartInt);
    ui->fldEndInt->setText(ListPatternOperations.at(NumberChosenPatternOperation).EndInt);

    for (int i=0; i<ListPatternOperations.at(NumberChosenPatternOperation).RelResName.count(); i++)
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
        exl1->setText("______________________");

        colTxtBox7+=1;

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

        lay1->addWidget(exl1,((colTxtBox7-1)*6) + 5,0);
        lay1->addWidget(l1,((colTxtBox7-1)*6),0);
        lay1->addWidget(l2,((colTxtBox7-1)*6) +1,0);
        lay1->addWidget(l3,((colTxtBox7-1)*6) +2,0);
        lay1->addWidget(l4,((colTxtBox7-1)*6) +3,0);
        lay1->addWidget(l5,((colTxtBox7-1)*6) +4,0);
        lay1->addWidget(t1,((colTxtBox7-1)*6), 1);
        lay1->addWidget(c1,((colTxtBox7-1)*6) +1,1);
        lay1->addWidget(c2,((colTxtBox7-1)*6) +2,1);
        lay1->addWidget(c3,((colTxtBox7-1)*6) +3,1);
        lay1->addWidget(c4,((colTxtBox7-1)*6) +4,1);

        lay1->addWidget(l6,((colTxtBox7-1)*6) ,3);
        lay1->addWidget(l7,((colTxtBox7-1)*6) +1,3);
        lay1->addWidget(l8,((colTxtBox7-1)*6) +2,3);
        lay1->addWidget(l9,((colTxtBox7-1)*6) +3,3);
        lay1->addWidget(l10,((colTxtBox7-1)*6) +4,3);

        lay1->addWidget(t2,((colTxtBox7-1)*6) ,4);
        lay1->addWidget(t3,((colTxtBox7-1)*6) +1,4);
        lay1->addWidget(t4,((colTxtBox7-1)*6) +2,4);
        lay1->addWidget(t5,((colTxtBox7-1)*6) +3,4);
        lay1->addWidget(t6,((colTxtBox7-1)*6) +4,4);
        lay1->setColumnMinimumWidth(4,650);


        ui->scrollContents->setLayout(lay1);

        extern QList<TypeResource> ListTypeResources;

        for (int i=0; i < ListTypeResources.count(); i++)
        {
             c1->addItem(ListTypeResources.at(i).TypeName);
        }

        c2->addItems(QStringList()<<"Не_изменять"<<"Сохранить"<<"Отсутствует");
        c3->addItems(QStringList()<<"Не_изменять"<<"Сохранить"<<"Отсутствует");
        c4->addItems(QStringList()<<"Не_изменять"<<"Сохранить"<<"Отсутствует");

        try
        {
            t1->setText(ListPatternOperations.at(NumberChosenPatternOperation).RelResName.at(i));
        }
        catch (exception)
        {
            QString s = "Ошибка определения имени релевантного ресурса № ";
            s+=QString::number(i+1);
            QMessageBox::warning(this, "Предупреждение", s);
        }

        try
        {
            t2->setText(ListPatternOperations.at(NumberChosenPatternOperation).Condition.at(i));
        }
        catch (exception)
        {
            QString s = "Ошибка определения действий в предусловии для релевантного ресурса № ";
            s+=QString::number(i+1);
            QMessageBox::warning(this, "Предупреждение", s);
        }

        try
        {
            t3->setText(ListPatternOperations.at(NumberChosenPatternOperation).ConvertEvent.at(i));
        }
        catch (exception)
        {
            QString s = "Ошибка определения действий в ConvertEvent для релевантного ресурса № ";
            s+=QString::number(i+1);
            QMessageBox::warning(this, "Предупреждение", s);
        }

        try
        {
            t4->setText(ListPatternOperations.at(NumberChosenPatternOperation).ConvertRule.at(i));
        }
        catch (exception)
        {
            QString s = "Ошибка определения действий в ConvertRule для релевантного ресурса № ";
            s+=QString::number(i+1);
            QMessageBox::warning(this, "Предупреждение", s);
        }

        try
        {
            t5->setText(ListPatternOperations.at(NumberChosenPatternOperation).ConvertBegin.at(i));
        }
        catch (exception)
        {
            QString s = "Ошибка определения действий в ConvertBegin для релевантного ресурса № ";
            s+=QString::number(i+1);
            QMessageBox::warning(this, "Предупреждение", s);
        }

        try
        {
            t6->setText(ListPatternOperations.at(NumberChosenPatternOperation).ConvertEnd.at(i));
        }
        catch (exception)
        {
            QString s = "Ошибка определения действий в ConvertEnd для релевантного ресурса № ";
            s+=QString::number(i+1);
            QMessageBox::warning(this, "Предупреждение", s);
        }

        try
        {
            c1->setCurrentText(ListPatternOperations.at(NumberChosenPatternOperation).TypeNameW.at(i));
        }
        catch (exception)
        {
            QString s = "Ошибка определения описателя для для релевантного ресурса № ";
            s+=QString::number(i+1);
            QMessageBox::warning(this, "Предупреждение", s);
        }

        try
        {
            if (ListPatternOperations.at(NumberChosenPatternOperation).ConvStatus.at(i) == "")
            {
                c2->setCurrentText("Отсутствует");
            }
            else
            {
                c2->setCurrentText(ListPatternOperations.at(NumberChosenPatternOperation).ConvStatus.at(i));
            }
        }
        catch (exception)
        {
            QString s = "Ошибка определения статуса конвертора для для релевантного ресурса № ";
            s+=QString::number(i+1);
            QMessageBox::warning(this, "Предупреждение", s);
        }

        try
        {
            if (ListPatternOperations.at(NumberChosenPatternOperation).ConvBegin.at(i) == "")
            {
                c3->setCurrentText("Отсутствует");
            }
            else
            {
                c3->setCurrentText(ListPatternOperations.at(NumberChosenPatternOperation).ConvBegin.at(i));
            }
        }
        catch (exception)
        {
            QString s = "Ошибка определения статуса конвертора начала для для релевантного ресурса № ";
            s+=QString::number(i+1);
            QMessageBox::warning(this, "Предупреждение", s);
        }

        try
        {
            if (ListPatternOperations.at(NumberChosenPatternOperation).ConvEnd.at(i) == "")
            {
                c4->setCurrentText("Отсутствует");
            }
            else
            {
                c4->setCurrentText(ListPatternOperations.at(NumberChosenPatternOperation).ConvBegin.at(i));
            }
        }
        catch (exception)
        {
            QString s = "Ошибка определения статуса конвертора конца для для релевантного ресурса № ";
            s+=QString::number(i+1);
            QMessageBox::warning(this, "Предупреждение", s);
        }



        listlbl21.append(l1);
        listlbl22.append(l2);
        listlbl23.append(l3);
        listlbl24.append(l4);
        listlbl25.append(l5);
        listlbl26.append(l6);
        listlbl27.append(l7);
        listlbl28.append(l8);
        listlbl29.append(l9);
        listlbl30.append(l10);

        listtxt21.append(t1);
        listtxt22.append(t2);
        listtxt23.append(t3);
        listtxt24.append(t4);
        listtxt25.append(t5);
        listtxt26.append(t6);

        listcmb21.append(c1);
        listcmb22.append(c2);
        listcmb23.append(c3);
        listcmb24.append(c4);

        listfrm1.append(exl1);


    }


}

FormEditPatternOperation::~FormEditPatternOperation()
{
    delete ui;
}

void FormEditPatternOperation::on_pushButton_clicked()
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
    exl1->setText("______________________");

    colTxtBox7+=1;

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

    lay1->addWidget(exl1,((colTxtBox7-1)*6) + 5,0);
    lay1->addWidget(l1,((colTxtBox7-1)*6),0);
    lay1->addWidget(l2,((colTxtBox7-1)*6) +1,0);
    lay1->addWidget(l3,((colTxtBox7-1)*6) +2,0);
    lay1->addWidget(l4,((colTxtBox7-1)*6) +3,0);
    lay1->addWidget(l5,((colTxtBox7-1)*6) +4,0);
    lay1->addWidget(t1,((colTxtBox7-1)*6), 1);
    lay1->addWidget(c1,((colTxtBox7-1)*6) +1,1);
    lay1->addWidget(c2,((colTxtBox7-1)*6) +2,1);
    lay1->addWidget(c3,((colTxtBox7-1)*6) +3,1);
    lay1->addWidget(c4,((colTxtBox7-1)*6) +4,1);

    lay1->addWidget(l6,((colTxtBox7-1)*6) ,3);
    lay1->addWidget(l7,((colTxtBox7-1)*6) +1,3);
    lay1->addWidget(l8,((colTxtBox7-1)*6) +2,3);
    lay1->addWidget(l9,((colTxtBox7-1)*6) +3,3);
    lay1->addWidget(l10,((colTxtBox7-1)*6) +4,3);

    lay1->addWidget(t2,((colTxtBox7-1)*6) ,4);
    lay1->addWidget(t3,((colTxtBox7-1)*6) +1,4);
    lay1->addWidget(t4,((colTxtBox7-1)*6) +2,4);
    lay1->addWidget(t5,((colTxtBox7-1)*6) +3,4);
    lay1->addWidget(t6,((colTxtBox7-1)*6) +4,4);
    lay1->setColumnMinimumWidth(4,650);


    ui->scrollContents->setLayout(lay1);

    extern QList<TypeResource> ListTypeResources;

    for (int i=0; i < ListTypeResources.count(); i++)
    {
         c1->addItem(ListTypeResources.at(i).TypeName);
    }

    c2->addItems(QStringList()<<"Не_изменять"<<"Сохранить"<<"Отсутствует");
    c3->addItems(QStringList()<<"Не_изменять"<<"Сохранить"<<"Отсутствует");
    c4->addItems(QStringList()<<"Не_изменять"<<"Сохранить"<<"Отсутствует");

    listlbl21.append(l1);
    listlbl22.append(l2);
    listlbl23.append(l3);
    listlbl24.append(l4);
    listlbl25.append(l5);
    listlbl26.append(l6);
    listlbl27.append(l7);
    listlbl28.append(l8);
    listlbl29.append(l9);
    listlbl30.append(l10);

    listtxt21.append(t1);
    listtxt22.append(t2);
    listtxt23.append(t3);
    listtxt24.append(t4);
    listtxt25.append(t5);
    listtxt26.append(t6);

    listcmb21.append(c1);
    listcmb22.append(c2);
    listcmb23.append(c3);
    listcmb24.append(c4);

    listfrm1.append(exl1);
}

void FormEditPatternOperation::on_pushButton_2_clicked()
{
    if (colTxtBox7 > 1)
    {
        delete listlbl21.at(listlbl21.count() - 1);
        delete listlbl22.at(listlbl22.count() - 1);
        delete listlbl23.at(listlbl23.count() - 1);
        delete listlbl24.at(listlbl24.count() - 1);
        delete listlbl25.at(listlbl25.count() - 1);
        delete listlbl26.at(listlbl26.count() - 1);
        delete listlbl27.at(listlbl27.count() - 1);
        delete listlbl28.at(listlbl28.count() - 1);
        delete listlbl29.at(listlbl29.count() - 1);
        delete listlbl30.at(listlbl30.count() - 1);

        delete listtxt21.at(listtxt21.count() - 1);
        delete listtxt22.at(listtxt22.count() - 1);
        delete listtxt23.at(listtxt23.count() - 1);
        delete listtxt24.at(listtxt24.count() - 1);
        delete listtxt25.at(listtxt25.count() - 1);
        delete listtxt26.at(listtxt26.count() - 1);

        delete listcmb21.at(listcmb21.count() - 1);
        delete listcmb22.at(listcmb22.count() - 1);
        delete listcmb23.at(listcmb23.count() - 1);
        delete listcmb24.at(listcmb24.count() - 1);

        delete listfrm1.at(listfrm1.count() - 1);

        listlbl21.removeAt(listlbl21.count() - 1);
        listlbl22.removeAt(listlbl22.count() - 1);
        listlbl23.removeAt(listlbl23.count() - 1);
        listlbl24.removeAt(listlbl24.count() - 1);
        listlbl25.removeAt(listlbl25.count() - 1);
        listlbl26.removeAt(listlbl26.count() - 1);
        listlbl27.removeAt(listlbl27.count() - 1);
        listlbl28.removeAt(listlbl28.count() - 1);
        listlbl29.removeAt(listlbl29.count() - 1);
        listlbl30.removeAt(listlbl30.count() - 1);

        listtxt21.removeAt(listtxt21.count() - 1);
        listtxt22.removeAt(listtxt22.count() - 1);
        listtxt23.removeAt(listtxt23.count() - 1);
        listtxt24.removeAt(listtxt24.count() - 1);
        listtxt25.removeAt(listtxt25.count() - 1);
        listtxt26.removeAt(listtxt26.count() - 1);

        listcmb21.removeAt(listcmb21.count() - 1);
        listcmb22.removeAt(listcmb22.count() - 1);
        listcmb23.removeAt(listcmb23.count() - 1);
        listcmb24.removeAt(listcmb24.count() - 1);

        listfrm1.removeAt(listfrm1.count() - 1);

        colTxtBox7--;
    }
}

void FormEditPatternOperation::on_pushButton_5_clicked()
{
    extern QString ChosenPatternOperation;
    extern int NumberChosenPatternOperation;

    ChosenPatternOperation = "";
    NumberChosenPatternOperation = -1;
    listlbl21.clear();
    listlbl22.clear();
    listlbl23.clear();
    listlbl24.clear();
    listlbl25.clear();
    listlbl26.clear();
    listlbl27.clear();
    listlbl28.clear();
    listlbl29.clear();
    listlbl30.clear();

    listtxt21.clear();
    listtxt22.clear();
    listtxt23.clear();
    listtxt24.clear();
    listtxt25.clear();
    listtxt26.clear();

    listcmb21.clear();
    listcmb22.clear();
    listcmb23.clear();
    listcmb24.clear();

    listfrm1.clear();
    close();
}

void FormEditPatternOperation::on_pushButton_4_clicked()
{
    extern QList<PatternOperation> ListPatternOperations;
    extern QString ChosenPatternOperation;
    extern int NumberChosenPatternOperation;

    ListPatternOperations.removeAt(NumberChosenPatternOperation);

    QString s = "Образец операции \"";
    s+=ChosenPatternOperation;
    s+="\" успешно удален!";
    QMessageBox::warning(this, "Предупреждение", s);

    ChosenPatternOperation = "";
    NumberChosenPatternOperation = -1;
    listlbl21.clear();
    listlbl22.clear();
    listlbl23.clear();
    listlbl24.clear();
    listlbl25.clear();
    listlbl26.clear();
    listlbl27.clear();
    listlbl28.clear();
    listlbl29.clear();
    listlbl30.clear();

    listtxt21.clear();
    listtxt22.clear();
    listtxt23.clear();
    listtxt24.clear();
    listtxt25.clear();
    listtxt26.clear();

    listcmb21.clear();
    listcmb22.clear();
    listcmb23.clear();
    listcmb24.clear();

    listfrm1.clear();
    close();
}

void FormEditPatternOperation::on_pushButton_3_clicked()
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

    for (int i=0; i<listtxt21.count(); i++)
    {
        if (listtxt21.at(i)->text() == "")
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

     for (int i=0; i<listcmb22.count();i++)
     {
         if ((ui->cmbPatternType->currentText() == "Нерегулярное_событие") && (listcmb22.at(i)->currentText() == "Отсутствует"))
         {
             QString s = "Для нерегулярного события необходимо задать статус конвертора! Не задан для релевантного ресурса №  ";
             s+=QString::number(i+1);
             s+=" !";
             QMessageBox::warning(this, "Предупреждение", s);
             check4 = false;
         }
     }

     for (int i=0; i<listcmb22.count(); i++)
     {
         if ((ui->cmbPatternType->currentText() == "Нерегулярное_событие") && (listcmb23.at(i)->currentText() != "Отсутствует" || listcmb24.at(i)->currentText() != "Отсутствует"))
         {
             QString s = "Для нерегулярного события нельзя задавать статус конвертора начала или конца (релевантный ресурс №  ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check4 = false;
         }
     }

     for (int i=0; i<listcmb22.count();i++)
     {
         if ((ui->cmbPatternType->currentText() == "Правило") && (listcmb22.at(i)->currentText() == "Отсутствует"))
         {
             QString s = "Для правила необходимо задать статус конвертора! Не задан для релевантного ресурса №  ";
             s+=QString::number(i+1);
             s+=" !";
             QMessageBox::warning(this, "Предупреждение", s);
             check4 = false;
         }
     }

     for (int i=0; i<listcmb22.count(); i++)
     {
         if ((ui->cmbPatternType->currentText() == "Правило") && (listcmb23.at(i)->currentText() != "Отсутствует" || listcmb24.at(i)->currentText() != "Отсутствует"))
         {
             QString s = "Для правила нельзя задавать статус конвертора начала или конца (релевантный ресурс №  ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check4 = false;
         }
     }

     for (int i=0; i<listcmb23.count(); i++)
     {
         if ((ui->cmbPatternType->currentText() == "Операция") && (listcmb23.at(i)->currentText() == "Отсутствует"))
         {
             QString s = "Для операции необходимо задать статус конвертора начала! Не задан для релевантного ресурса № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check4 = false;
         }
     }

     for (int i=0; i<listcmb24.count(); i++)
     {
         if ((ui->cmbPatternType->currentText() == "Операция") && (listcmb24.at(i)->currentText() == "Отсутствует"))
         {
             QString s = "Для операции необходимо задать статус конвертора конца! Не задан для релевантного ресурса № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check4 = false;
         }
     }


     for (int i=0; i<listcmb22.count(); i++)
     {
         if ((ui->cmbPatternType->currentText() == "Операция") && (listcmb22.at(i)->currentText() != "Отсутствует"))
         {
             QString s = "Для операции нельзя задавать статус конвертора (релевантный ресурс № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check4 = false;
         }
     }

     for (int i=0; i<listtxt22.count(); i++)
     {
         if ((ui->cmbPatternType->currentText() == "Нерегулярное_событие") && (listtxt22.at(i)->text() != ""))
         {
             QString s = "Для нерегулярного события нельзя задавать предусловие! (релевантный ресурс № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check5 = false;
         }

         if ((ui->cmbPatternType->currentText() == "Правило") && (listtxt22.at(i)->text() == ""))
         {
             QString s = "Для правила необходимо задать предусловие! (релевантный ресурс № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check5 = false;
         }

         if ((ui->cmbPatternType->currentText() == "Операция") && (listtxt22.at(i)->text() == ""))
         {
             QString s = "Для операции необходимо задать предусловие! (релевантный ресурс № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check5 = false;
         }
     }

     for (int i=0; i<listtxt23.count(); i++)
     {
         if ((ui->cmbPatternType->currentText() == "Нерегулярное_событие") && (listtxt23.at(i)->text() == ""))
         {
             QString s = "Для нерегулярного события необходимо описать действия в convert Event! (релевантный ресурс № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check5 = false;
         }

         if ((ui->cmbPatternType->currentText() == "Правило") && (listtxt23.at(i)->text() != ""))
         {
             QString s = "Для правила нельзя описывать действия в Convert Event! (релевантный ресурс № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check5 = false;
         }

         if ((ui->cmbPatternType->currentText() == "Операция") && (listtxt23.at(i)->text() != ""))
         {
             QString s = "Для операции нельзя описывать действия в Convert Event! (релевантный ресурс № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check5 = false;
         }

     }

     for (int i=0; i<listtxt24.count(); i++)
     {
         if ((ui->cmbPatternType->currentText() == "Нерегулярное_событие") && (listtxt24.at(i)->text() != ""))
         {
             QString s = "Для нерегулярного события нельзя задавать действия в Convert Rule! (релевантный ресурс № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check5 = false;
         }

         if ((ui->cmbPatternType->currentText() == "Правило") && (listtxt24.at(i)->text() == ""))
         {
             QString s = "Для правила необходимо задать действия в Convert Rule! (релевантный ресурс № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check5 = false;
         }

         if ((ui->cmbPatternType->currentText() == "Операция") && (listtxt24.at(i)->text() != ""))
         {
             QString s = "Для операции нельзя задавать действия в Convert Rule! (релевантный ресурс № ";
             s+=QString::number(i+1);
             s+=") !";
             QMessageBox::warning(this, "Предупреждение", s);
             check5 = false;
         }
     }

    for (int i=0; i<listtxt25.count(); i++)
    {
        if ((ui->cmbPatternType->currentText() == "Нерегулярное_событие") && (listtxt25.at(i)->text() != ""))
        {
            QString s = "Для нерегулярного события нельзя задавать действия в Convert Begin! (релевантный ресурс № ";
            s+=QString::number(i+1);
            s+=") !";
            QMessageBox::warning(this, "Предупреждение", s);
            check5 = false;
        }

        if ((ui->cmbPatternType->currentText() == "Правило") && (listtxt25.at(i)->text() != ""))
        {
            QString s = "Для правила нельзя задавать действия в Convert Begin! (релевантный ресурс № ";
            s+=QString::number(i+1);
            s+=") !";
            QMessageBox::warning(this, "Предупреждение", s);
            check5 = false;
        }

        if ((ui->cmbPatternType->currentText() == "Операция") && (listtxt25.at(i)->text() == ""))
        {
            QString s = "Для операции необходимо задать действия в Convert Begin! (релевантный ресурс № ";
            s+=QString::number(i+1);
            s+=") !";
            QMessageBox::warning(this, "Предупреждение", s);
            check5 = false;
        }

    }


    for (int i=0; i<listtxt26.count(); i++)
    {
        if ((ui->cmbPatternType->currentText() == "Нерегулярное_событие") && (listtxt26.at(i)->text() != ""))
        {
            QString s = "Для нерегулярного события нельзя задавать действия в Convert End! (релевантный ресурс № ";
            s+=QString::number(i+1);
            s+=") !";
            QMessageBox::warning(this, "Предупреждение", s);
            check5 = false;
        }

        if ((ui->cmbPatternType->currentText() == "Правило") && (listtxt26.at(i)->text() != ""))
        {
            QString s = "Для правила нельзя задавать действия в Convert End! (релевантный ресурс № ";
            s+=QString::number(i+1);
            s+=") !";
            QMessageBox::warning(this, "Предупреждение", s);
            check5 = false;
        }

        if ((ui->cmbPatternType->currentText() == "Операция") && (listtxt26.at(i)->text() == ""))
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
        extern QString ChosenPatternOperation;
        extern int NumberChosenPatternOperation;

        QString l;


        for (int i=0; i<listtxt21.count(); i++)
        {
            RelResName.append(listtxt21.at(i)->text());
            Condition.append(listtxt22.at(i)->text());
            ConvertEvent.append(listtxt23.at(i)->text());
            ConvertRule.append(listtxt24.at(i)->text());
            ConvertBegin.append(listtxt25.at(i)->text());
            ConvertEnd.append(listtxt26.at(i)->text());
            TypeNameW.append(listcmb21.at(i)->currentText());

            if (listcmb22.at(i)->currentText() == "Отсутствует")
            {
                ConvStatus.append("");
            }
            else
            {
                ConvStatus.append(listcmb22.at(i)->currentText());
            }

            if (listcmb23.at(i)->currentText() == "Отсутствует")
            {
                ConvBegin.append("");
            }
            else
            {
                ConvBegin.append(listcmb23.at(i)->currentText());
            }

            if (listcmb24.at(i)->currentText() == "Отсутствует")
            {
                ConvEnd.append("");
            }
            else
            {
                ConvEnd.append(listcmb24.at(i)->currentText());
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
            ListPatternOperations.removeAt(NumberChosenPatternOperation);
            ListPatternOperations.insert(NumberChosenPatternOperation, ptr1);
            QString s = "Образец операции '";
            s+=ChosenPatternOperation;
            s+="' успешно изменен!";
            ChosenPatternOperation = "";
            NumberChosenPatternOperation = -1;
            listtxt21.clear();
            listtxt22.clear();
            listtxt23.clear();
            listtxt24.clear();
            listtxt25.clear();
            listtxt26.clear();

            listlbl21.clear();
            listlbl22.clear();
            listlbl23.clear();
            listlbl24.clear();
            listlbl25.clear();
            listlbl26.clear();
            listlbl27.clear();
            listlbl28.clear();
            listlbl29.clear();
            listlbl30.clear();

            listcmb21.clear();
            listcmb22.clear();
            listcmb23.clear();
            listcmb24.clear();

            listfrm1.clear();
            QMessageBox::warning(this, "Предупреждение", s);

            close();


        }
    }

}
