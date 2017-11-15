#ifndef RESOURCE_H
#define RESOURCE_H
#include <QString>
#include <QList>
using namespace std;
class Resource
{
public:
    QString ResourceName;
    QString TypeName;
    QList<QString> ParamValue;
    QString TraseValue;

    Resource(QString typeName, QString resourceName, QList<QString> paramValue, QString traseValue);
};

#endif // RESOURCE_H
