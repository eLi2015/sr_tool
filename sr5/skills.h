#ifndef SKILLS_H
#define SKILLS_H

#include "QList"
#include "QPair"
#include "QMultiMap"
#include "QString"

class skills
{
public:
    skills();



    QString getSkillDescription(QString skill);
    QString getSkillBoni(QString skill);


private:
    QMultiMap<QString, QString> skillList;

};

#endif // SKILLS_H
