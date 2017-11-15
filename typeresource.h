#ifndef TYPERESOURCE_H
#define TYPERESOURCE_H
#include <QString>
#include <QList>
using namespace std;

class TypeResource
{
public:
    QString TypeName;
    QString TraseValue;
    QString TempValue;
    QList<QString> ParamName;
    QList<QString> ParamType;
    QList<QString> ParamVariant;
    QList<QString> ParamDefault;

    TypeResource(QString typeName, QString traseValue, QString tempValue, QList<QString> paramName, QList<QString> paramType, QList<QString> paramVariant, QList<QString> paramDefault);

};

#endif // TYPERESOURCE_H
