#ifndef SHADOWRUNTOOL_H
#define SHADOWRUNTOOL_H

#include <QMainWindow>
#include <QTableWidget>
#include <QMap>

#include "inventory.h"
#include "skills.h"
#include "programms.h"
#include "reader.h"

namespace Ui {
class ShadowrunTool;
}

class ShadowrunTool : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShadowrunTool(QWidget *parent = 0);
    ~ShadowrunTool();

public slots:
    void on_closing();

private slots:

    void on_diceroll_clicked();

    void on_addfivedice_clicked();

    void on_addtendice_clicked();

    void on_subfivedice_clicked();

    void on_subtendice_clicked();

    void on_uiSkillTable_clicked(const QModelIndex &index);

    void on_uiSkillTable_2_clicked(const QModelIndex &index);

    void on_addtwodice_2_clicked();

    void on_subtwodice_2_clicked();

    void on_hotsim_clicked();

    void on_coldsim_clicked();

    void on_prog_one_currentIndexChanged(const QString &arg1);

    void on_prog_two_currentIndexChanged(const QString &arg1);

    void on_prog_three_currentIndexChanged(const QString &arg1);

    void on_prog_four_currentIndexChanged(const QString &arg1);

    void on_ini_roll_clicked();

    void on_arsim_clicked();

    void on_endRound_clicked();

    void on_uiSkillTable_3_clicked(const QModelIndex &index);

    void on_uiSkillTable_4_clicked(const QModelIndex &index);

    void on_uiSkillTable_5_clicked(const QModelIndex &index);

    void on_progDescribBox_one_clicked();

    void on_progDescribBox_two_clicked();

    void on_progDescribBox_three_clicked();

    void on_progDescribBox_four_clicked();

    void on_currInventory_clicked(const QModelIndex &index);

    void openInventory();

    void on_conf_std_clicked();

    void on_conf_schl_clicked();

    void on_conf_dv_clicked();

    void on_conf_var_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);



private:
    Ui::ShadowrunTool *ui;
    Inventory *inventar;
    QWidget *zweitesWidget;
    QStringList modifikations;

    QTableWidget *mSkillList;
    QTableWidget *mSkillList_2;
    QTableWidget *mSkillList_3;
    QTableWidget *mSkillList_4;
    QTableWidget *mSkillList_5;
    int randValue(int high, int low);
    int randValue();

    QString getASkilldescrb(QString arg1);

    void checkStatusLabel();
    QString getSkillBoni(QString skill);
    void setDescriptionText(QString descrip);


    std::random_device rd;
    skills descriptionFactory;
    programms programmsFactory;
    reader fileReader;



};

#endif // SHADOWRUNTOOL_H
