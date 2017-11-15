#include "resource.h"

Resource::Resource(QString typeName, QString resourceName, QList<QString> paramValue, QString traseValue):
    TypeName(typeName),
    ResourceName(resourceName),
    ParamValue(paramValue),
    TraseValue(traseValue)
{

}
