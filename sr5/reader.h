#ifndef READER_H
#define READER_H

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QFile>
#include <QDebug>
#include <QObject>
#include <QVariantMap>
#include <QTableWidget>
#include <QMap>

class reader
{
public:
    reader();
    ~reader();

    QMap<QString, QString> readJson(QString filename);

    void saveTableToJson(QTableWidget *table, QString filename);

    void saveJsonToTable(QTableWidget *table, QString filename);
};

#endif // READER_H
