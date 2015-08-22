#ifndef INVENTORY_H
#define INVENTORY_H

#include <QWidget>
#include "QListWidgetItem"

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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



private:
    Ui::Inventory *ui;
    QList<QString> currItems;
};

#endif // INVENTORY_H
