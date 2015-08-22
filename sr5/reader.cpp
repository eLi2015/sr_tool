#include "reader.h"

reader::reader()
{

}

reader::~reader()
{

}

QMap<QString, QString> reader::readJson(QString filename)
{

    QString val;
    QFile file;
    file.setFileName(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    //qWarning() << val;
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());

    QJsonObject jObject = d.object();
    QStringList keyList = jObject.keys();
    //qDebug() << keyList;
    QMap<QString, QString> toReturn;
    foreach(QString key, keyList)
    {
        QJsonObject subObject = jObject.value(key).toObject();
        QStringList subKeyList = subObject.keys();
        foreach(QString subKey, subKeyList)
        {
            QJsonValue tmp = subObject.value(subKey);
            //qDebug() << QString(subKey) <<": " << tmp.toString();
            toReturn.insert(key, tmp.toString());
        }
    }
    return toReturn;
}

void reader::saveTableToJson(QTableWidget *table, QString filename)
{
    QJsonDocument toSave;

    QJsonObject rootObj;

    QFile outputFile(filename);
    outputFile.open(QIODevice::WriteOnly);
    for(int i = 0; i < table->columnCount(); i++)
    {

        for(int j = 0; j < table->rowCount(); j++)
        {
            QJsonObject subObj;
            QJsonValue val = table->item(j, i)->text();
            QString key = table->verticalHeaderItem(j)->text();

            subObj.insert("value", val);

            rootObj.insert(key, subObj);
        }


    }

    toSave.setObject(rootObj);
    outputFile.write(toSave.toJson());

    outputFile.close();

}

void reader::saveJsonToTable(QTableWidget *table, QString filename)
{
    QMap<QString, QString> tableData = this->readJson(filename);

    QStringList keyList = tableData.keys();

    //this->ui->uiSkillTable->clear();

    table->setColumnCount(1);
    table->setRowCount(keyList.size());

    //qDebug() << "Keylist Size: " << keyList.size();
    //qDebug() << tableData;

    for(int i = 0; i < keyList.size(); i++)
    {
        //this->ui->uiSkillTable->insertRow(i);
        table->setVerticalHeaderItem(i, new QTableWidgetItem(keyList[i]));
        table->setHorizontalHeaderItem(0, new QTableWidgetItem("Wert"));
        table->setItem(i, 0, new QTableWidgetItem(tableData.value(keyList[i])));
    }
}

