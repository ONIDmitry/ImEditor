#include "immodel.h"
#include <string>
#include <list>
#include <resource.h>
#include <typeresource.h>
#include <patternoperation.h>
#include <operation.h>
#include <QList>

QList<TypeResource> ListTypeResources;
QList<Resource> ListResources;
QList<PatternOperation> ListPatternOperations;
QList<Operation> ListOperations;

QString ChosenTypeResource;
int NumberChosenTypeResource;
QString ChosenResource;
int NumberChosenResource;
QString ChosenPatternOperation;
int NumberChosenPatternOperation;
QString ChosenOperation;
int NumberChosenOperation;
ImModel::ImModel()
{

}
