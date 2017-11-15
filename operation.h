#ifndef OPERATION_H
#define OPERATION_H
#include <QString>
#include <QList>
using namespace std;

class Operation
{
public:
    QString OperationName;
    QString PatternName;
    QList<QString> ResourceNames;

    Operation(QString operationName, QString patternName, QList<QString> resourceName);
};

#endif // OPERATION_H
