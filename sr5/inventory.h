#ifndef INVENTORY_H
#define INVENTORY_H

#include <QWidget>
#include <QListWidgetItem>
#include <QMultiMap>

namespace Ui {
class Inventory;
}

class Inventory : public QWidget
{
    Q_OBJECT

public:
    explicit Inventory(QWidget *parent = 0);
    ~Inventory();

    QList<QString> getInventory();

    void setItems(QMultiMap<QString, QString> map);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_home_itemClicked(QListWidgetItem *item);

private:
    Ui::Inventory *ui;
    QList<QString> currItems;
    QMultiMap<QString, QString> itemMap;
    QStringList itemKeyList;
};

#endif // INVENTORY_H
