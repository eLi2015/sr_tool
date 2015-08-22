#ifndef PROGRAMMS_H
#define PROGRAMMS_H

#include <QMultiMap>
#include <QString>
#include <QStringList>

class programms
{
public:
    programms();

    QString getProgrammDescription(QString programm);
    QStringList getProgrammList();

private:
    QMultiMap<QString, QString> progList;
};

#endif // PROGRAMMS_H
