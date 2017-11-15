#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "formcreatetyperesource.h"
#include "formcreateresource.h"
#include "formcreatepatternoperation.h"
#include "formedittyperesource.h"
#include "formeditresource.h"
#include "formeditpatternoperation.h"
#include "formeditoperation.h"
#include "immodel.h"
#include "formcreateoperation.h"
#include <QFile>
#include <QTextCodec>
#include <QFileDialog>

#include "immodel.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   // QList<TypeResource> ListTypeResources;
    //ui->cmbTypeResources->setBackgroundRole(yellow);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_3_triggered()
{
    FormCreateTypeResource *frm2 = new FormCreateTypeResource();
    frm2->show();

}


void MainWindow::on_pushButton_clicked()
{
    extern QList<TypeResource> ListTypeResources;
    extern QList<Resource> ListResources;
    extern QList<PatternOperation> ListPatternOperations;
    extern QList<Operation> ListOperations;

    ui->cmbTypeResources->clear();
    ui->cmbResources->clear();
    ui->cmbPatternOperations->clear();
    ui->cmbOperations->clear();

    for (int i=0; i<ListTypeResources.count(); i++)
    {
        ui->cmbTypeResources->addItem(ListTypeResources.at(i).TypeName);
    }

    for (int i=0; i<ListResources.count(); i++)
    {
        ui->cmbResources->addItem(ListResources.at(i).ResourceName);
    }

    for (int i=0; i<ListPatternOperations.count(); i++)
    {
        ui->cmbPatternOperations->addItem(ListPatternOperations.at(i).PatternName);
    }

    for (int i=0; i<ListOperations.count(); i++)
    {
        ui->cmbOperations->addItem(ListOperations.at(i).OperationName);
    }



}



void MainWindow::on_action_5_triggered()
{
    extern QList<TypeResource> ListTypeResources;
    if (ListTypeResources.count() == 0)
    {
        QString s = " Создайте хотя бы один тип ресурсов! ";
        QMessageBox::warning(this, "Предупреждение", s);
    }
    else
    {
        formcreateresource *frm3 = new formcreateresource();
        frm3->show();
    }
}

void MainWindow::on_action_4_triggered()
{
    extern QList<TypeResource> ListTypeResources;
    if (ListTypeResources.count() == 0)
    {
        QString s = " Создайте хотя бы один тип ресурсов! ";
        QMessageBox::warning(this, "Предупреждение", s);
    }
    else
    {
        FormCreatePatternOperation *frm4 = new FormCreatePatternOperation();
        frm4->show();
    }
}

void MainWindow::on_action_6_triggered()
{
    extern QList<TypeResource> ListResources;
    if (ListResources.count() == 0)
    {
        QString s = " Создайте хотя бы один ресурс! ";
        QMessageBox::warning(this, "Предупреждение", s);
    }
    else
    {
        FormCreateOperation *frm5 = new FormCreateOperation();
        frm5->show();
    }
}

void MainWindow::on_action_7_triggered()
{
    extern QList<TypeResource> ListTypeResources;
    extern QList<Resource> ListResources;
    extern QList<PatternOperation> ListPatternOperations;
    extern  QList<Operation> ListOperations;

    QTextCodec *codec = QTextCodec::codecForName("UTF8");
    QTextCodec::setCodecForLocale(codec);

    QFile f("D:\\ImModel.xml");
    if(f.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream writer(&f);
        writer.setCodec("UTF-8");

        writer << trUtf8("<Модель>");
        writer << endl;

        for (int i=0; i<ListTypeResources.count();i++)
        {
            writer << "       ";
            writer << trUtf8("<Тип_ресурсов Имя_типа_ресурсов=\"")<<ListTypeResources.at(i).TypeName<<trUtf8("\" Вид_типа_ресурсов=\"");
            writer << ListTypeResources.at(i).TempValue<<trUtf8("\">");
            writer << endl;
            for (int j=0; j<ListTypeResources.at(i).ParamName.count(); j++)
            {
                writer << "               ";
                writer << trUtf8("<Параметр_типа Имя_параметра=\"")<<ListTypeResources.at(i).ParamName.at(j) << trUtf8("\" Тип_параметра=\"");
                writer << ListTypeResources.at(i).ParamType.at(j)<<ListTypeResources.at(i).ParamVariant.at(j)<<trUtf8("\" Умолчание=\"");
                writer << ListTypeResources.at(i).ParamDefault.at(j)<<trUtf8("\"/>")<<endl;
            }
            writer<<"       "<<trUtf8("</Тип_ресурсов>")<<endl;
        }
        writer << endl;

        for (int i=0; i<ListResources.count(); i++)
        {
            writer<<"       "<<trUtf8("<Ресурс Имя_ресурса=\"")<<ListResources.at(i).ResourceName<<trUtf8("\" Имя_типа_ресурсов=\"");
            writer<<ListResources.at(i).TypeName<<trUtf8("\" Трассировка=\"")<<ListResources.at(i).TraseValue<<trUtf8("\" Начальные_значения=\"{");
            for (int j=0;j<ListResources.at(i).ParamValue.count();j++)
            {
                writer<<ListResources.at(i).ParamValue.at(j);
                if (j!= ListResources.at(i).ParamValue.count() -1)
                {
                    writer<<", ";
                }
            }
            writer<<"}\"/>"<<endl;
        }

        writer << endl;

        for (int i=0; i<ListPatternOperations.count(); i++)
        {
            writer << trUtf8("<Образец_операции Имя_образца=\"")<< ListPatternOperations.at(i).PatternName << trUtf8("\" Тип_образца=\"");
            writer << ListPatternOperations.at(i).PatternType << trUtf8("\" Трассировка=\"")<< ListPatternOperations.at(i).PatternTrace << "\">" << endl;

            for (int j=0; j<ListPatternOperations.at(i).RelResName.count(); j++)
            {
                writer << "                "<<trUtf8("<Релевантный_ресурс Имя_релевантного_ресурса=\"")<<ListPatternOperations.at(i).RelResName.at(j);
                writer <<trUtf8("\" Описатель=\"")<<ListPatternOperations.at(i).TypeNameW.at(j)<<trUtf8("\" Статус_конвертора=\"");
                writer<<ListPatternOperations.at(i).ConvStatus.at(j)<<trUtf8("\" Статус_конвертора_начала=\"")<<ListPatternOperations.at(i).ConvBegin.at(j);
                writer << trUtf8("\" Статус_конвертора_конца=\"") << ListPatternOperations.at(i).ConvEnd.at(j)<<"\"/>"<<endl;
            }
            writer << "                "<<trUtf8("<Время Тип=\"")<<ListPatternOperations.at(i).TypeTime<<trUtf8("\" Закон=\"");
            writer<<ListPatternOperations.at(i).TimeLaw<<trUtf8("\" Значение=\"")<<ListPatternOperations.at(i).TimeValue;
            writer<<trUtf8("\" Начало_интервала=\"")<<ListPatternOperations.at(i).StartInt<<trUtf8("\" Конец_интервала=\"");
            writer<<ListPatternOperations.at(i).EndInt<<"\"/>"<<endl;
            writer<<"                "<<trUtf8("<Тело_образца>")<<endl;

            for (int k=0; k<ListPatternOperations.at(i).RelResName.count(); k++)
            {
                writer<<"                        "<<trUtf8("<Релевантный_ресурс Имя_релевантного_ресурса=\"")<<ListPatternOperations.at(i).RelResName.at(k);
                writer<<"\">"<<endl;
                writer<<"                        "<<trUtf8("<Правило_использования Предусловие=\"")<<ListPatternOperations.at(i).Condition.at(k)<<"\" Convert_event=\"";
                writer<<ListPatternOperations.at(i).ConvertEvent.at(k)<<"\" Convert_rule=\""<<ListPatternOperations.at(i).ConvertRule.at(k)<<"\" Convert_begin=\"";
                writer<<ListPatternOperations.at(i).ConvertBegin.at(k)<<"\" Convert_end=\""<<ListPatternOperations.at(i).ConvertEnd.at(k)<<"\"/>"<<endl;
                writer<<"                        "<<trUtf8("</Релевантный_ресурс>")<<endl;
            }
            writer<<"                "<<trUtf8("</Тело_образца>")<<endl;
            writer<<"         "<<trUtf8("</Образец_операции>")<<endl<<endl;
        }

        for (int i=0; i<ListOperations.count(); i++)
        {
            writer<<"        "<<trUtf8("<Операция Имя_операции=\"")<<ListOperations.at(i).OperationName<<trUtf8("\" Имя_образца=\"");
            writer<<ListOperations.at(i).PatternName<<trUtf8("\" Тело_операции=\"")<<ListOperations.at(i).PatternName;
            writer<<"(";
            for (int j=0; j<ListOperations.at(i).ResourceNames.count();j++)
            {
                writer<<ListOperations.at(i).ResourceNames.at(j);
                if (j != ListOperations.at(i).ResourceNames.count() - 1)
                {
                    writer<<", ";
                }
            }

            writer<<");\"/>"<<endl;
        }

        writer << endl <<endl <<endl<<endl<<endl<<endl;
        writer << "        "<<trUtf8("<Функция Имя_функции=\"\" Возвращаемый_тип =\"\" Тело_функции=\"\" > ")<<endl;
        writer << "               "<<trUtf8("<Параметр_функции Имя_параметра_функции=\"\" Тип_параметра_функции=\"\" />")<<endl;
        writer<<"        "<<trUtf8("</Функция>")<<endl<<endl<<trUtf8("</Модель>")<<endl;
        f.close();
    }
    else
    {
        QString s = " Файл D:\\ImModel.xml не может быть открыт для записи! ";
        QMessageBox::warning(this, "Предупреждение", s);
        f.close();
    }

}

void MainWindow::on_action_triggered()
{
    extern QList<TypeResource> ListTypeResources;
    extern QList<Resource> ListResources;
    extern QList<PatternOperation> ListPatternOperations;
    extern  QList<Operation> ListOperations;

    ListTypeResources.clear();
    ListResources.clear();
    ListPatternOperations.clear();
    ListOperations.clear();

    QString FileNameString = " ";
    QString begin = "\"";
    QString end = "\"";
    int StringCount = 0;
    QString s = "";


    QString FilePath = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Открыть файл"),
                                "D:\\",
                                "XML files (*.xml)");
    QFile OpenFile(FilePath);

    if (OpenFile.open(QIODevice::ReadOnly))
    {

        QTextStream reader(&OpenFile);
        QTextCodec *codec = QTextCodec::codecForName("UTF8");
        QTextCodec::setCodecForLocale(codec);
        reader.setCodec("UTF-8");

        while (!reader.atEnd())
        {
            s = reader.readLine();
            StringCount+=1;
            if (s.contains("<Тип_ресурсов"))
            {
                QString TypeName = "";
                QString TraseValue = "Да";
                QString TempValue = "";
                int n=0;
                QList<QString> ParamName;
                QList<QString> ParamType;
                QList<QString> ParamVariant;
                QList<QString> ParamDefault;

                n = s.indexOf(begin);
                if (n>=0)
                {
                    s=s.remove(0, n+1);
                }
                else
                {
                    QString z = "Не найден символ начала \"\" для определения имени типа ресурсов в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n=s.indexOf(end);
                if (n>=0)
                {
                    TypeName = s.mid(0 , n);
                    s = s.remove(0, n+1);
                }
                else
                {
                    QString z = "Не найден символ конца \"\" для определения имени типа ресурсов в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(begin);
                if (n>=0)
                {
                    s = s.remove( 0, n+1);
                }
                else
                {
                    QString z = "Не найден символ начала \"\" для определения вида типа ресурсов в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(end);
                if (n>=0)
                {
                    TempValue = s.mid(0, n);
                }
                else
                {
                    QString z = "Не найден символ конца \"\" для определения вида типа ресурсов в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                s = reader.readLine();
                StringCount += 1;
                while (!s.contains(trUtf8("</Тип_ресурсов>")))
                {
                    QString p;
                    QString t;
                    n = s.indexOf(begin);
                    if (n>=0)
                    {
                        s = s.remove(0, n + 1);
                    }
                    else
                    {
                        QString z = "Не найден символ начала \"\" для определения имени параметра типа ресурсов в строке номер ";
                        z+=QString::number(StringCount);
                        QMessageBox::warning(this, "Предупреждение", z);
                    }
                    n = s.indexOf(end);
                    if (n>=0)
                    {
                        p = s.mid(0, n);
                        ParamName.append(p);
                        s = s.remove(0, n + 1);
                    }
                    else
                    {
                        QString z = "Не найден символ конца \"\" для определения имени параметра типа ресурсов в строке номер ";
                        z+=QString::number(StringCount);
                        QMessageBox::warning(this, "Предупреждение", z);
                    }
                    n = s.indexOf(begin);
                    if (n>=0)
                    {
                        s = s.remove(0, n + 1);
                    }
                    else
                    {
                        QString z = "Не найден символ начала \"\" для определения типа параметра типа ресурсов в строке номер ";
                        z+=QString::number(StringCount);
                        QMessageBox::warning(this, "Предупреждение", z);
                    }
                    n = s.indexOf(end);
                    if (n>=0)
                    {
                        p = s.mid(0, n);
                        if ((p.contains("Enum")) || (p.contains("enum")))
                        {
                            n = p.indexOf("{");
                            if (n>=0)
                            {
                                ParamType.append("Enum");
                                p = p.remove(0, n);
                            }
                            else
                            {
                                QString z = "Не найден символ { начала описания возможных значений для типа Enum в строке номер ";
                                z+=QString::number(StringCount);
                                QMessageBox::warning(this, "Предупреждение", z);
                            }
                            n = p.indexOf("}");
                            if (n>=0)
                            {
                                t = p.mid(0, n + 1);
                                ParamVariant.append(t);
                            }
                            else
                            {
                                QString z = "Не найден символ } окончания написания возможных значений для типа Enum в строке номер ";
                                z+=QString::number(StringCount);
                                QMessageBox::warning(this, "Предупреждение", z);
                            }
                        }
                        else
                        {
                            ParamType.append(p);
                            ParamVariant.append("");
                        }
                    }
                    else
                    {
                        QString z = "Не найден символ конца \"\" для определения типа параметра типа ресурсов в строке номер ";
                        z+=QString::number(StringCount);
                        QMessageBox::warning(this, "Предупреждение", z);
                    }

                    n = s.indexOf(end);
                    if (n>=0)
                    {
                        s = s.remove(0, n + 1);
                    }
                    else
                    {
                        QString z = "Не найден символ конца \"\" для определения типа параметра типа ресурсов в строке номер ";
                        z+=QString::number(StringCount);
                        QMessageBox::warning(this, "Предупреждение", z);
                    }
                    n = s.indexOf(begin);
                    if (n >= 0)
                    {
                        s = s.remove(0, n + 1);
                    }
                    else
                    {
                        QString z = "Не найден символ начала \"\" для определения начального значения параметра типа ресурсов в строке номер ";
                        z+=QString::number(StringCount);
                        QMessageBox::warning(this, "Предупреждение", z);
                    }
                    n = s.indexOf(end);
                    if (n >= 0)
                    {
                        p = s.mid(0, n);
                        ParamDefault.append(p);
                    }
                    else
                    {
                        QString z = "Не найден символ конца \"\" для определения начального значения параметра типа ресурсов в строке номер ";
                        z+=QString::number(StringCount);
                        QMessageBox::warning(this, "Предупреждение", z);
                    }
                    s = reader.readLine();
                    StringCount += 1;
                }

                TypeResource type1(TypeName, TraseValue, TempValue, ParamName, ParamType, ParamVariant, ParamDefault);
                ListTypeResources.append(type1);
            }

            if (s.contains("Ресурс"))
            {
                int n = 0;
                QString p;
                QString ResourceName = "";
                QString TypeName = "";
                QString TraseValue = "";
                QList<QString> ParamValue;

                n = s.indexOf(begin);
                if (n >= 0)
                {
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ начала \"\" для определения имени ресурса в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(end);
                if (n >= 0)
                {
                    ResourceName = s.mid(0, n);
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ конца \"\" для определения имени ресурса в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(begin);
                if (n >= 0)
                {
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ начала \"\" для определения имени типа ресурсов в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(end);
                if (n>=0)
                {
                    TypeName = s.mid(0, n);
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ конца \"\" для определения имени типа ресурсов в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(begin);
                if (n >= 0)
                {
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ начала \"\" для определения трассировки ресурса в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(end);
                if (n >= 0)
                {
                    TraseValue = s.mid(0, n);
                }
                else
                {
                    QString z = "Не найден символ конца \"\" для определения трассировки ресурса в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf("{");

                if (n >= 0)
                {
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Неверный формат определения начальных значений ресурса в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }

                while (s.contains(","))
                {
                    n = s.indexOf(",");
                    if (n >= 0)
                    {
                        p = s.mid(0, n);
                        p = p.replace(" ", "");
                        ParamValue.append(p);
                        s = s.remove(0, n + 1);
                    }
                    else
                    {
                        QString z = "Неверный формат определения начальных значений ресурса в строке номер ";
                        z+=QString::number(StringCount);
                        QMessageBox::warning(this, "Предупреждение", z);
                    }
                }
                n = s.indexOf("}");
                if (n >= 0)
                {
                    p = s.mid(0, n);
                    p = p.replace(" ", "");
                    ParamValue.append(p);
                }
                else
                {
                    QString z = "Неверный формат определения начальных значений ресурса в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }

                Resource rs1(TypeName, ResourceName, ParamValue, TraseValue);
                ListResources.append(rs1);

            }
            if (s.contains("<Образец_операции"))
            {
                int n = 0;
                QString PatternName = "";
                QString PatternType = "";
                QString PatternTrace = "";
                QString TypeTime = "";
                QString TimeValue = "";
                QString TimeLaw = "";
                QString StartInt = "";
                QString EndInt = "";
                QList<QString> RelResName;
                QList<QString> TypeNameW;
                QList<QString> ConvStatus;
                QList<QString> ConvBegin;
                QList<QString> ConvEnd;
                QList<QString> Condition;
                QList<QString> ConvertEvent;
                QList<QString> ConvertRule;
                QList<QString> ConvertBegin;
                QList<QString> ConvertEnd;

                n = s.indexOf(begin);
                if (n >= 0)
                {
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ начала \"\" для определения имени образца операции в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(end);
                if (n >= 0)
                {
                    PatternName = s.mid(0, n);
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ конца \"\" для определения имени образца операции в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(begin);
                if (n >= 0)
                {
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ начала \"\" для определения типа образца операции в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(end);
                if (n >= 0)
                {
                    PatternType = s.mid(0, n);
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ конца \"\" для определения типа образца операции в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(begin);
                if (n >= 0)
                {
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ начала \"\" для определения трассировки образца операции в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(end);
                if (n >= 0)
                {
                     PatternTrace = s.mid(0, n);
                }
                else
                {
                    QString z = "Не найден символ конца \"\" для определения трассировки образца операции в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                s = reader.readLine();
                StringCount += 1;

                while (s.contains("<Релевантный_ресурс"))
                {
                    n = s.indexOf(begin);
                    if (n >= 0)
                    {
                        s = s.remove(0, n + 1);
                    }
                    else
                    {
                        QString z = "Не найден символ начала \"\" для определения имени релевантного ресурса в строке номер ";
                        z+=QString::number(StringCount);
                        QMessageBox::warning(this, "Предупреждение", z);
                    }
                    n = s.indexOf(end);
                    if (n >= 0)
                    {
                        RelResName.append(s.mid(0, n));
                        s = s.remove(0, n + 1);
                    }
                    else
                    {
                        QString z = "Не найден символ конца \"\" для определения имени релевантного ресурса в строке номер ";
                        z+=QString::number(StringCount);
                        QMessageBox::warning(this, "Предупреждение", z);
                    }
                    n = s.indexOf(begin);
                    if (n >= 0)
                    {
                        s = s.remove(0, n + 1);
                    }
                    else
                    {
                        QString z = "Не найден символ начала \"\" для определения описателя в строке номер ";
                        z+=QString::number(StringCount);
                        QMessageBox::warning(this, "Предупреждение", z);
                    }
                    n = s.indexOf(end);
                    if (n >= 0)
                    {
                        TypeNameW.append(s.mid(0, n));
                        s = s.remove(0, n + 1);
                    }
                    else
                    {
                        QString z = "Не найден символ конца \"\" для определения описателя в строке номер ";
                        z+=QString::number(StringCount);
                        QMessageBox::warning(this, "Предупреждение", z);
                    }
                    n = s.indexOf(begin);
                    if (n >= 0)
                    {
                        s = s.remove(0, n + 1);
                    }
                    else
                    {
                        QString z = "Не найден символ начала \"\" для определения статуса конвертора в строке номер ";
                        z+=QString::number(StringCount);
                        QMessageBox::warning(this, "Предупреждение", z);
                    }
                    n = s.indexOf(end);
                    if (n >= 0)
                    {
                        ConvStatus.append(s.mid(0, n));
                        s = s.remove(0, n + 1);
                    }
                    else
                    {
                        QString z = "Не найден символ конца \"\" для определения статуса конвертора в строке номер ";
                        z+=QString::number(StringCount);
                        QMessageBox::warning(this, "Предупреждение", z);
                    }
                    n = s.indexOf(begin);
                    if (n >= 0)
                    {
                        s = s.remove(0, n + 1);
                    }
                    else
                    {
                        QString z = "Не найден символ начала \"\" для определения статуса конвертора начала в строке номер ";
                        z+=QString::number(StringCount);
                        QMessageBox::warning(this, "Предупреждение", z);
                    }
                    n = s.indexOf(end);
                    if (n >= 0)
                    {
                        ConvBegin.append(s.mid(0, n));
                        s = s.remove(0, n + 1);
                    }
                    else
                    {
                        QString z = "Не найден символ конца \"\" для определения статуса конвертора начала в строке номер ";
                        z+=QString::number(StringCount);
                        QMessageBox::warning(this, "Предупреждение", z);
                    }
                    n = s.indexOf(begin);
                    if (n >= 0)
                    {
                        s = s.remove(0, n + 1);
                    }
                    else
                    {
                        QString z = "Не найден символ начала \"\" для определения статуса конвертора конца в строке номер ";
                        z+=QString::number(StringCount);
                        QMessageBox::warning(this, "Предупреждение", z);
                    }
                    n = s.indexOf(end);
                    if (n >= 0)
                    {
                        ConvEnd.append(s.mid(0, n));
                    }
                    else
                    {
                        QString z = "Не найден символ конца \"\" для определения статуса конвертора конца в строке номер ";
                        z+=QString::number(StringCount);
                        QMessageBox::warning(this, "Предупреждение", z);
                    }
                    s = reader.readLine();
                    StringCount += 1;
                }

                n = s.indexOf(begin);
                if (n >= 0)
                {
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ начала \"\" для определения типа времени в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(end);
                if (n >= 0)
                {
                    TypeTime = s.mid(0, n);
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ конца \"\" для определения типа времени в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(begin);
                if (n >= 0)
                {
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ начала \"\" для определения закона времени в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(end);
                if (n >= 0)
                {
                    TimeLaw = s.mid(0, n);
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ конца \"\" для определения закона времени в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(begin);
                if (n >= 0)
                {
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ начала \"\" для определения значения времени в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(end);
                if (n >= 0)
                {
                    TimeValue = s.mid(0, n);
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ конца \"\" для определения значения времени в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(begin);
                if (n >= 0)
                {
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ начала \"\" для определения начала интервала в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(end);
                if (n >= 0)
                {
                    StartInt = s.mid(0, n);
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ конца \"\" для определения начала интервала в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(begin);
                if (n >= 0)
                {
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ начала \"\" для определения конца интервала в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(end);
                if (n >= 0)
                {
                    EndInt = s.mid(0, n);
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ конца \"\" для определения конца интервала в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                s = reader.readLine();
                StringCount += 1;

                while (!s.contains("</Образец_операции>"))
                {
                    if (s.contains("<Правило_использования"))
                    {
                        n = s.indexOf(begin);
                        if (n >= 0)
                        {
                            s = s.remove(0, n + 1);
                        }
                        else
                        {
                            QString z = "Не найден символ начала \"\" для определения действий в предусловии в строке номер ";
                            z+=QString::number(StringCount);
                            QMessageBox::warning(this, "Предупреждение", z);
                        }
                        n = s.indexOf(end);
                        if (n >= 0)
                        {
                            Condition.append(s.mid(0, n));
                            s = s.remove(0, n + 1);
                        }
                        else
                        {
                            QString z = "Не найден символ конца \"\" для определения действий в предусловии в строке номер ";
                            z+=QString::number(StringCount);
                            QMessageBox::warning(this, "Предупреждение", z);
                        }
                        n = s.indexOf(begin);
                        if (n >= 0)
                        {
                            s = s.remove(0, n + 1);
                        }
                        else
                        {
                            QString z = "Не найден символ начала \"\" для определения действий в ConvertEvent в строке номер ";
                            z+=QString::number(StringCount);
                            QMessageBox::warning(this, "Предупреждение", z);
                        }
                        n = s.indexOf(end);
                        if (n >= 0)
                        {
                            ConvertEvent.append(s.mid(0, n));
                            s = s.remove(0, n + 1);
                        }
                        else
                        {
                            QString z = "Не найден символ конца \"\" для определения действий в ConvertEvent в строке номер ";
                            z+=QString::number(StringCount);
                            QMessageBox::warning(this, "Предупреждение", z);
                        }

                        n = s.indexOf(begin);
                        if (n >= 0)
                        {
                            s = s.remove(0, n + 1);
                        }
                        else
                        {
                            QString z = "Не найден символ начала \"\" для определения действий в ConvertRule в строке номер ";
                            z+=QString::number(StringCount);
                            QMessageBox::warning(this, "Предупреждение", z);
                        }
                        n = s.indexOf(end);
                        if (n >= 0)
                        {
                            ConvertRule.append(s.mid(0, n));
                            s = s.remove(0, n + 1);
                        }
                        else
                        {
                            QString z = "Не найден символ конца \"\" для определения действий в ConvertRule в строке номер ";
                            z+=QString::number(StringCount);
                            QMessageBox::warning(this, "Предупреждение", z);
                        }
                        n = s.indexOf(begin);
                        if (n >= 0)
                        {
                            s = s.remove(0, n + 1);
                        }
                        else
                        {
                            QString z = "Не найден символ начала \"\" для определения действий в ConvertBegin в строке номер ";
                            z+=QString::number(StringCount);
                            QMessageBox::warning(this, "Предупреждение", z);
                        }
                        n = s.indexOf(end);
                        if (n >= 0)
                        {
                            ConvertBegin.append(s.mid(0, n));
                            s = s.remove(0, n + 1);
                        }
                        else
                        {
                            QString z = "Не найден символ конца \"\" для определения действий в ConvertBegin в строке номер ";
                            z+=QString::number(StringCount);
                            QMessageBox::warning(this, "Предупреждение", z);
                        }
                        n = s.indexOf(begin);
                        if (n >= 0)
                        {
                            s = s.remove(0, n + 1);
                        }
                        else
                        {
                            QString z = "Не найден символ начала \"\" для определения действий в ConvertEnd в строке номер ";
                            z+=QString::number(StringCount);
                            QMessageBox::warning(this, "Предупреждение", z);
                        }
                        n = s.indexOf(end);
                        if (n >= 0)
                        {
                            ConvertEnd.append(s.mid(0, n));
                        }
                        else
                        {
                            QString z = "Не найден символ конца \"\" для определения действий в ConvertEnd в строке номер ";
                            z+=QString::number(StringCount);
                            QMessageBox::warning(this, "Предупреждение", z);
                        }
                        s = reader.readLine();
                        StringCount += 1;
                    }
                    else
                    {
                        s = reader.readLine();
                        StringCount += 1;
                    }
                }


                PatternOperation ptr1(PatternName, PatternType, PatternTrace, TypeTime, TimeValue, TimeLaw, StartInt, EndInt, RelResName, TypeNameW, ConvStatus, ConvBegin, ConvEnd, Condition, ConvertEvent, ConvertRule, ConvertBegin, ConvertEnd);
                ListPatternOperations.append(ptr1);
            }

            if (s.contains("<Операция"))
            {
                int n = 0;
                QString p;
                QString OperationName = "";
                QString  PatternName = "";
                QList<QString> ResourceNames;

                n = s.indexOf(begin);
                if (n >= 0)
                {
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ начала \"\" для определения имени операции в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(end);
                if (n >= 0)
                {
                    OperationName = s.mid(0, n);
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ конца \"\" для определения имени операции в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(begin);
                if (n >= 0)
                {
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ начала \"\" для определения имени образца операций в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf(end);
                if (n >= 0)
                {
                    PatternName = s.mid(0, n);
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Не найден символ начала \"\" для определения имени образца операций в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }
                n = s.indexOf("(");
                if (n >= 0)
                {
                    s = s.remove(0, n + 1);
                }
                else
                {
                    QString z = "Неверный формат описания ресурсов, релевантных в операции в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }

                while (s.contains(","))
                {
                    n = s.indexOf(",");
                    if (n >= 0)
                    {
                        p = s.mid(0, n);
                        ResourceNames.append(p);
                        s = s.remove(0, n + 1);
                    }
                    else
                    {
                        QString z = "Неверный формат описания ресурсов, релевантных в операции в строке номер ";
                        z+=QString::number(StringCount);
                        QMessageBox::warning(this, "Предупреждение", z);
                    }
                }

                n = s.indexOf(")");
                if (n >= 0)
                {
                    p = s.mid(0, n);
                    ResourceNames.append(p);
                }
                else
                {
                    QString z = "Неверный формат описания ресурсов, релевантных в операции в строке номер ";
                    z+=QString::number(StringCount);
                    QMessageBox::warning(this, "Предупреждение", z);
                }

                Operation op1(OperationName, PatternName, ResourceNames);
                ListOperations.append(op1);
            }
        }
        OpenFile.close();
    }
    else if (FilePath != "")
    {
        QString s = " Файл ";
        s+=FileNameString;
        s+=" не может быть открыт для чтения!";
        QMessageBox::warning(this, "Предупреждение", s);
        OpenFile.close();
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    extern QList<TypeResource> ListTypeResources;
    extern QString ChosenTypeResource;
    extern int NumberChosenTypeResource;

    int k=0;

    if (ui->cmbTypeResources->currentText() == "")
    {
         QMessageBox::warning(this, "Предупреждение", "Выберите тип ресурсов!");
    }
    else
    {
        for (int i=0; i<ListTypeResources.count(); i++)
        {
            if (ui->cmbTypeResources->currentText() == ListTypeResources.at(i).TypeName)
            {
                k=i;
            }
        }

        ChosenTypeResource = ui->cmbTypeResources->currentText();
        NumberChosenTypeResource = k;

        FormEditTypeResource *form11 = new FormEditTypeResource();
        form11->show();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    extern QList<Resource> ListResources;
    extern QString ChosenResource;
    extern int NumberChosenResource;

    int k=0;

    if (ui->cmbResources->currentText() == "")
    {
         QMessageBox::warning(this, "Предупреждение", "Выберите ресурс!");
    }
    else
    {
        for (int i=0; i<ListResources.count(); i++)
        {
            if (ui->cmbResources->currentText() == ListResources.at(i).ResourceName)
            {
                k=i;
            }
        }

        ChosenResource = ui->cmbResources->currentText();
        NumberChosenResource = k;

        FormEditResource *form12 = new FormEditResource();
        form12->show();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    extern QList<PatternOperation> ListPatternOperations;
    extern QString ChosenPatternOperation;
    extern int NumberChosenPatternOperation;

    int k=0;

    if (ui->cmbPatternOperations->currentText() == "")
    {
         QMessageBox::warning(this, "Предупреждение", "Выберите образец операции!");
    }
    else
    {
        for (int i=0; i<ListPatternOperations.count(); i++)
        {
            if (ui->cmbPatternOperations->currentText() == ListPatternOperations.at(i).PatternName)
            {
                k=i;
            }
        }

        ChosenPatternOperation = ui->cmbPatternOperations->currentText();
        NumberChosenPatternOperation = k;

        FormEditPatternOperation *form13 = new FormEditPatternOperation();
        form13->show();
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    extern QList<Operation> ListOperations;
    extern QString ChosenOperation;
    extern int NumberChosenOperation;

    int k=0;

    if (ui->cmbOperations->currentText() == "")
    {
         QMessageBox::warning(this, "Предупреждение", "Выберите операцию!");
    }
    else
    {
        for (int i=0; i<ListOperations.count(); i++)
        {
            if (ui->cmbOperations->currentText() == ListOperations.at(i).OperationName)
            {
                k=i;
            }
        }

        ChosenOperation = ui->cmbOperations->currentText();
        NumberChosenOperation = k;

        FormEditOperation *form14 = new FormEditOperation();
        form14->show();
    }
}
