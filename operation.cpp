#include "operation.h"

Operation::Operation(QString operationName, QString patternName, QList<QString> resourceName) :
    OperationName(operationName),
    PatternName(patternName),
    ResourceNames(resourceName)
{

}
