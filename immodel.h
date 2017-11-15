#ifndef IMMODEL_H
#define IMMODEL_H
#include <string>
#include <list>
#include <resource.h>
#include <typeresource.h>
#include <patternoperation.h>
#include <operation.h>
#include <QList>

using namespace std;

class ImModel
{
public:
    ImModel();

    static string ChosenTypeResource;
    static int NumberChosenTypeResource;
    static string ChosenResource;
    static int NumberChosenResource;
    static string ChosenPatternOperation;
    static int NumberChosenPatternOperation;
    static string ChosenOperation;
    static int NumberChosenOperation;

    QList<TypeResource> ListTypeResources;
    QList<Resource> ListResources;
    QList<PatternOperation> ListPatternOperations;
    QList<Operation> ListOperations;
};

#endif // IMMODEL_H
