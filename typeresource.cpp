#include "typeresource.h"
#include <QString>
#include <QList>

TypeResource::TypeResource(QString typeName,QString traseValue,QString tempValue, QList<QString> paramName, QList<QString> paramType, QList<QString> paramVariant, QList<QString> paramDefault)

{
    TypeName = typeName;
    TraseValue = traseValue;
    TempValue = tempValue;
    ParamName = paramName;
    ParamType = paramType;
    ParamVariant = paramVariant;
    ParamDefault = paramDefault;
}
