#include "inventory.h"
#include "ui_inventory.h"
#include "qdebug.h"

Inventory::Inventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inventory)
{
    ui->setupUi(this);

}
Inventory::~Inventory()
{
    delete ui;
}

QList<QString> Inventory::getInventory()
{
    return this->currItems;
}

void Inventory::on_pushButton_clicked()
{
    QList<QListWidgetItem*> selectedItems = this->ui->home->selectedItems();
    foreach(QListWidgetItem *item, selectedItems)
    {
        this->ui->inventory->addItem(item->text());

        this->currItems.append(item->text());

        delete item;
    }
}

void Inventory::on_pushButton_2_clicked()
{
    QList<QListWidgetItem*> selectedItems = this->ui->inventory->selectedItems();
    foreach(QListWidgetItem *item, selectedItems)
    {
        this->ui->home->addItem(item->text());
        this->currItems.removeOne(item->text());

        delete item;
    }
}
