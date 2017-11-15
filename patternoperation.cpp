#include "patternoperation.h"
#include <QList>
#include <QString>

PatternOperation::PatternOperation(QString patternName, QString patternType, QString patternTrace, QString typeTime, QString timeValue, QString timeLaw, QString startInt, QString endInt, QList<QString> relResName,  QList<QString> typeNameW, QList<QString> convStatus, QList<QString> convBegin, QList<QString> convEnd, QList<QString> condition, QList<QString> convertEvent, QList<QString> convertRule, QList<QString> convertBegin, QList<QString> convertEnd):
    PatternName(patternName),
    PatternType(patternType),
    PatternTrace(patternTrace),
    TypeTime(typeTime),
    TimeValue(timeValue),
    TimeLaw(timeLaw),
    StartInt(startInt),
    EndInt(endInt),
    RelResName(relResName),
    TypeNameW(typeNameW),
    ConvStatus(convStatus),
    ConvBegin(convBegin),
    ConvEnd(convEnd),
    Condition(condition),
    ConvertEvent(convertEvent),
    ConvertRule(convertRule),
    ConvertBegin(convertBegin),
    ConvertEnd(convertEnd)
{

}
