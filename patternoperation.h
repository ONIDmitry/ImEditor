#ifndef PATTERNOPERATION_H
#define PATTERNOPERATION_H
#include <QString>
#include <QList>
using namespace std;

class PatternOperation
{
public:
    QString PatternName;
    QString PatternType;
    QString PatternTrace;
    QString TypeTime;
    QString TimeValue;
    QString TimeLaw;
    QString StartInt;
    QString EndInt;
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
    PatternOperation(QString patternName, QString patternType, QString patternTrace, QString typeTime, QString timeValue, QString timeLaw, QString startInt, QString endInt, QList<QString> relResName,  QList<QString> typeNameW, QList<QString> convStatus, QList<QString> convBegin, QList<QString> convEnd, QList<QString> condition, QList<QString> convertEvent, QList<QString> convertRule, QList<QString> convertBegin, QList<QString> convertEnd);
};

#endif // PATTERNOPERATION_H
