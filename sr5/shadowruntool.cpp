#include "shadowruntool.h"
#include "ui_shadowruntool.h"
#include "QTime"
#include <QtGlobal>
#include <QDebug>
#include <qtableview.h>
#include <random>
#include <QtCore/QString>
#include <QtCore/QFile>
#include <QtCore/QTextStream>

ShadowrunTool::ShadowrunTool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShadowrunTool)
{
    ui->setupUi(this);
    mSkillList = this->ui->uiSkillTable;
    mSkillList_2 = this->ui->uiSkillTable_2;
    mSkillList_3 = this->ui->uiSkillTable_3;
    mSkillList_4 = this->ui->uiSkillTable_4;
    mSkillList_5 = this->ui->uiSkillTable_5;

    this->modifikations.append("Modifikationen: \n");
    this->modifikations.append("Würfel \n");
    this->modifikations.append("Programm 1 \n");
    this->modifikations.append("Programm 2 \n");
    this->modifikations.append("Programm 3 \n");
    this->modifikations.append("Programm 4 \n");

    QStringList hackingProgs;

    hackingProgs.append("Ausnutzen (X)");
    hackingProgs.append("Aufspüren (X)");
    hackingProgs.append("Babymonitor (X)");
    hackingProgs.append("Biofeedback");
    hackingProgs.append("Biofeedback-Filter");
    hackingProgs.append("Blackout (X)");
    hackingProgs.append("Entschlüsseln");
    hackingProgs.append("Editieren (X)");
    hackingProgs.append("Fessel");
    hackingProgs.append("Gabel (X)");
    hackingProgs.append("Hammer");
    hackingProgs.append("Irreführung (X)");
    hackingProgs.append("Panzerung");
    hackingProgs.append("Schild (X)");
    hackingProgs.append("Schutzschirm");
    hackingProgs.append("Splitterschutz");
    hackingProgs.append("Superbombe");
    hackingProgs.append("Tarnkappe (X)");
    hackingProgs.append("Überfall");
    hackingProgs.append("Verwandlung");
    hackingProgs.append("Konfigurator (X)");
    hackingProgs.append("Schmöker (X)");
    hackingProgs.append("Signalreiniger (X)");
    hackingProgs.append("Toolbox");
    hackingProgs.append("Verschlüsseln (X)");
    hackingProgs.append("Virtuelle Maschine (X)");
    hackingProgs.append("Crash (X)");
    hackingProgs.append("Evaluate (X)");
    hackingProgs.append("Mona Lisa (X)");


    this->ui->prog_one->addItems(hackingProgs);
    this->ui->prog_two->addItems(hackingProgs);
    this->ui->prog_three->addItems(hackingProgs);
    this->ui->prog_four->addItems(hackingProgs);

    zweitesWidget = new QWidget();
    this->inventar = new Inventory(zweitesWidget);

    connect(ui->actionInventar, SIGNAL(triggered(bool)), this, SLOT(openInventory()));

    fileReader.saveJsonToTable(this->ui->uiSkillTable, "../general.json");
    fileReader.saveJsonToTable(this->ui->uiSkillTable_2, "../attack.json");
    fileReader.saveJsonToTable(this->ui->uiSkillTable_3, "../datenverarb.json");
    fileReader.saveJsonToTable(this->ui->uiSkillTable_4, "../schleicher.json");
    fileReader.saveJsonToTable(this->ui->uiSkillTable_5, "../firewall.json");

}

ShadowrunTool::~ShadowrunTool()
{
    delete ui;

}

void ShadowrunTool::on_closing()
{
    fileReader.saveTableToJson(this->ui->uiSkillTable, "../general.json");
    fileReader.saveTableToJson(this->ui->uiSkillTable_2, "../attack.json");
    fileReader.saveTableToJson(this->ui->uiSkillTable_3, "../datenverarb.json");
    fileReader.saveTableToJson(this->ui->uiSkillTable_4, "../schleicher.json");
    fileReader.saveTableToJson(this->ui->uiSkillTable_5, "../firewall.json");
}

int ShadowrunTool::randValue(int high, int low)
{
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);
    return dis(gen);
    //return qrand() % ((high + 1)-low)+low;
}
int ShadowrunTool::randValue()
{
    return this->randValue(0,0);
}

void ShadowrunTool::on_diceroll_clicked()
{
    //QTime time = QTime::currentTime();

    this->ui->output->setText(QString::number(qrand()));
    QList<int> rolledValues;

    int diceCount = this->ui->dicecount->value();

//    QFile tmpOutput("result.txt");
//    if(tmpOutput.open(QIODevice::WriteOnly | QIODevice::Text))
//    {

//    }
//    else
//    {
//        qDebug() << "möööööp kann ich nicht öffnen";
//    }
    //QTextStream out(&tmpOutput);


    //for(int j = 0; j < 1000; j++) {

        for(int i = 0; i < diceCount; i++) {
            //        time = QTime::currentTime();
            //        qsrand((uint) time.msec());
            //rolledValues.append(randValue(6, 1));

            rolledValues.append(randValue());

            //out << rolledValues.last() << ", ";

            //QTest::qSleep(1);
        }
      //  out << "; \n";
      //  tmpOutput.flush();
    //}
    //tmpOutput.close();

    //1:  2:  3:  4:  5:  6:
    int counter[6] = {0};

    for(int i = 0; i < rolledValues.size(); i++) {
        if(rolledValues[i] == 1) {
            counter[0]++;
        }
        else if(rolledValues[i] == 2)
        {
            counter[1]++;
        }
        else if(rolledValues[i] == 3)
        {
            counter[2]++;
        }
        else if(rolledValues[i] == 4)
        {
            counter[3]++;
        }
        else if(rolledValues[i] == 5)
        {
            counter[4]++;
        }
        else if(rolledValues[i] == 6)
        {
            counter[5]++;
        }
    }
    QString output(" 1: "+QString::number(counter[0])
            +"\n 2: "+QString::number(counter[1])
            +"\n 3: "+QString::number(counter[2])
            +"\n 4: "+QString::number(counter[3])
            +"\n 5: "+QString::number(counter[4])
            +"\n 6: "+QString::number(counter[5]));
    this->ui->rolledDice->setText(output);
    this->ui->output->setText(
                "1: "+QString::number(counter[0])
            +" 2: "+QString::number(counter[1])
            +" 3: "+QString::number(counter[2])
            +" 4: "+QString::number(counter[3])
            +" 5: "+QString::number(counter[4])
            +" 6: "+QString::number(counter[5]));

    //    int sum = 0;
    //    for(int i = 0; i < rolledValues.size(); i++) {
    //        sum += rolledValues[i];
    //    }
    //    sum /= rolledValues.size();
    //    this->ui->output->setText(QString::number(sum));
    //janskdn
    // set statistics
    if(counter[0] > rolledValues.size()/2)
    {
        this->ui->diceresults->setText("Würfel Egebnisse: \n Patzer");

        if(counter[4] == 0 && counter[5] == 0 && counter[0])
        {
            this->ui->diceresults->setText("Würfel Egebnisse: \n Kritischer Patzer");
        }

    }
    else
    {
        this->ui->diceresults->setText(QString("Würfel Egebnisse: \n 5: ").append(QString::number(counter[4]).append(", 6: ").append(QString::number(counter[5]))).append(" Erfolge: ").append(QString::number(counter[4]+counter[5])));
    }


}

void ShadowrunTool::on_addfivedice_clicked()
{
    this->ui->dicecount->setValue(this->ui->dicecount->value()+5);
}

void ShadowrunTool::on_addtendice_clicked()
{
    this->ui->dicecount->setValue(this->ui->dicecount->value()+10);
}

void ShadowrunTool::on_subfivedice_clicked()
{
    this->ui->dicecount->setValue(this->ui->dicecount->value()-5);
    if(this->ui->dicecount->value() < 0) {
        this->ui->dicecount->setValue(0);
    }
}

void ShadowrunTool::on_subtendice_clicked()
{
    this->ui->dicecount->setValue(this->ui->dicecount->value()-10);
    if(this->ui->dicecount->value() < 0) {
        this->ui->dicecount->setValue(0);
    }
}

void ShadowrunTool::on_uiSkillTable_clicked(const QModelIndex &index)
{
    int value = mSkillList->item(index.row(), 0)->text().toInt();
    //this->ui->output->setText(QString::number(value));
    this->ui->dicecount->setValue(value);
    QTableWidgetItem *header = mSkillList->verticalHeaderItem(index.row());

    this->setDescriptionText(header->text());

}

void ShadowrunTool::on_uiSkillTable_2_clicked(const QModelIndex &index)
{
    int value = mSkillList_2->item(index.row(), 0)->text().toInt();
    //this->ui->output->setText(QString::number(value));
    this->ui->dicecount->setValue(value);

    QTableWidgetItem *header = mSkillList_2->verticalHeaderItem(index.row());
    this->setDescriptionText(header->text());

}

void ShadowrunTool::on_uiSkillTable_3_clicked(const QModelIndex &index)
{
    int value = mSkillList_3->item(index.row(), 0)->text().toInt();
    //this->ui->output->setText(QString::number(value));
    this->ui->dicecount->setValue(value);

    QTableWidgetItem *header = mSkillList_3->verticalHeaderItem(index.row());

    this->setDescriptionText(header->text());

}

void ShadowrunTool::on_uiSkillTable_4_clicked(const QModelIndex &index)
{
    int value = mSkillList_4->item(index.row(), 0)->text().toInt();
    //this->ui->output->setText(QString::number(value));
    this->ui->dicecount->setValue(value);

    QTableWidgetItem *header = mSkillList_4->verticalHeaderItem(index.row());
    this->setDescriptionText(header->text());
}

void ShadowrunTool::on_uiSkillTable_5_clicked(const QModelIndex &index)
{
    int value = mSkillList_5->item(index.row(), 0)->text().toInt();
    //this->ui->output->setText(QString::number(value));
    this->ui->dicecount->setValue(value);

    QTableWidgetItem *header = mSkillList_5->verticalHeaderItem(index.row());
    this->setDescriptionText(header->text());

}

void ShadowrunTool::on_addtwodice_2_clicked()
{
    this->ui->dicecount->setValue(this->ui->dicecount->value()+2);
}

void ShadowrunTool::on_subtwodice_2_clicked()
{
    this->ui->dicecount->setValue(this->ui->dicecount->value()-2);
    if(this->ui->dicecount->value() < 0) {
        this->ui->dicecount->setValue(0);
    }
}


void ShadowrunTool::on_hotsim_clicked()
{
    if(this->ui->coldsim->isChecked()) {
        this->ui->coldsim->setChecked(false);
    }
    if(this->ui->arsim->isChecked()) {
        this->ui->arsim->setChecked(false);
    }
    this->modifikations[1] = "Sim Modi: +2 Würfel \n";
    this->checkStatusLabel();
}

void ShadowrunTool::on_coldsim_clicked()
{
    if(this->ui->hotsim->isChecked()) {
        this->ui->hotsim->setChecked(false);
    }
    if(this->ui->arsim->isChecked()) {
        this->ui->arsim->setChecked(false);
    }
    this->modifikations[1] = "Sim Modi: +0 Würfel \n";
    this->checkStatusLabel();

}
void ShadowrunTool::on_arsim_clicked()
{
    if(this->ui->hotsim->isChecked()) {
        this->ui->hotsim->setChecked(false);
    }
    if(this->ui->coldsim->isChecked()) {
        this->ui->coldsim->setChecked(false);
    }
    this->modifikations[1] = "Sim Modi: -2 Würfel \n";
    this->checkStatusLabel();

}


void ShadowrunTool::on_prog_one_currentIndexChanged(const QString &arg1)
{
    this->ui->skilldescription_lab->setText(QString(arg1).append(":\n").append(this->getASkilldescrb(arg1)));


    this->modifikations[2] = QString("Programm 1: ").append(this->getSkillBoni(arg1));
    this->checkStatusLabel();
}

void ShadowrunTool::on_prog_two_currentIndexChanged(const QString &arg1)
{
    this->ui->skilldescription_lab->setText(QString(arg1).append(":\n").append(this->getASkilldescrb(arg1)));
    this->modifikations[3] = QString("Programm 2: ").append(this->getSkillBoni(arg1));
    this->checkStatusLabel();
}

void ShadowrunTool::on_prog_three_currentIndexChanged(const QString &arg1)
{
    this->ui->skilldescription_lab->setText(QString(arg1).append(":\n").append(this->getASkilldescrb(arg1)));
    this->modifikations[4] = QString("Programm 3: ").append(this->getSkillBoni(arg1));
    this->checkStatusLabel();
}

void ShadowrunTool::on_prog_four_currentIndexChanged(const QString &arg1)
{
    this->ui->skilldescription_lab->setText(QString(arg1).append(":\n").append(this->getASkilldescrb(arg1)));
    this->modifikations[5] = QString("Programm 4: ").append(this->getSkillBoni(arg1));
    this->checkStatusLabel();
}


void ShadowrunTool::on_ini_roll_clicked()
{
    //this->ui->output->setText(QString::number());
    int initiative = 4+this->ui->spinData->value();
    //QTime time = QTime::currentTime();
    int rolledValues = initiative;
    int diceCount = 0;
    if(this->ui->coldsim->isChecked()) {
        diceCount = 3;
        if(this->ui->additionalIniDie->isChecked())
        {
            diceCount++;
        }
    }
    if(this->ui->hotsim->isChecked()) {
        diceCount = 4;
        if(this->ui->additionalIniDie->isChecked())
        {
            diceCount++;
        }
    }
    if(this->ui->arsim->isChecked()) {
        initiative = 6;
        diceCount = 1;
    }

    //qDebug() << "Wuerfle: " << diceCount << "Ini: " << initiative;
    for(int i = 0; i < diceCount; i++) {
        //time = QTime::currentTime();
        //qsrand((uint) time.msec());
        rolledValues+=(randValue(6, 1));
        //QTest::qSleep(1);
    }
    this->ui->iniValue->setText(QString::number(rolledValues));

}

void ShadowrunTool::on_endRound_clicked()
{
    bool ok = false;
    QString tmp = this->ui->iniValue->text();
    int aktValue = tmp.toInt(&ok);
    if(ok)
    {
        aktValue -= 10;
    }
    if(aktValue < 0) {
        this->ui->iniValue->setText(QString::number(0));
    } else {
        this->ui->iniValue->setText(QString::number(aktValue));
    }
}


QString ShadowrunTool::getASkilldescrb(QString arg1)
{
    return this->programmsFactory.getProgrammDescription(arg1);
}

void ShadowrunTool::on_progDescribBox_one_clicked()
{
    this->ui->skilldescription_lab->setText(QString(this->ui->prog_one->currentText()).append(":\n").append(getASkilldescrb(this->ui->prog_one->currentText())));
    this->checkStatusLabel();
}

void ShadowrunTool::on_progDescribBox_two_clicked()
{
    this->ui->skilldescription_lab->setText(QString(this->ui->prog_two->currentText()).append(":\n").append(getASkilldescrb(this->ui->prog_two->currentText())));
}

void ShadowrunTool::on_progDescribBox_three_clicked()
{
    this->ui->skilldescription_lab->setText(QString(this->ui->prog_three->currentText()).append(":\n").append(getASkilldescrb(this->ui->prog_three->currentText())));
}

void ShadowrunTool::on_progDescribBox_four_clicked()
{
    this->ui->skilldescription_lab->setText(QString(this->ui->prog_four->currentText()).append(":\n").append(getASkilldescrb(this->ui->prog_four->currentText())));
}

void ShadowrunTool::on_currInventory_clicked(const QModelIndex &index)
{
    (void) index;
    QList<QString> currItems = this->inventar->getInventory();
    this->ui->currInventory->clear();

    foreach(QString item, currItems)
    {
        this->ui->currInventory->addItem(item);
    }

    if(currItems.size() == 0)
        this->ui->currInventory->addItem("Inventar");
}

void ShadowrunTool::openInventory()
{
    zweitesWidget->show();
}

void ShadowrunTool::on_conf_std_clicked()
{
    this->ui->spinAttack->setValue(7);
    this->ui->spinData->setValue(5);
    this->ui->spinFirewall->setValue(4);
    this->ui->spinSleep->setValue(7);

    this->ui->prog_one->setCurrentIndex(2);
    this->ui->prog_two->setCurrentIndex(21);
    this->ui->prog_three->setCurrentIndex(1);
    this->ui->prog_four->setCurrentIndex(28);
}

void ShadowrunTool::on_conf_schl_clicked()
{
    this->ui->spinAttack->setValue(4);
    this->ui->spinData->setValue(6);
    this->ui->spinFirewall->setValue(6);
    this->ui->spinSleep->setValue(7);

    this->ui->prog_one->setCurrentIndex(0);
    this->ui->prog_two->setCurrentIndex(26);
    this->ui->prog_three->setCurrentIndex(9);
    this->ui->prog_four->setCurrentIndex(17);
}

void ShadowrunTool::on_conf_dv_clicked()
{
    this->ui->spinAttack->setValue(4);
    this->ui->spinData->setValue(9);
    this->ui->spinFirewall->setValue(5);
    this->ui->spinSleep->setValue(5);
}

void ShadowrunTool::on_conf_var_clicked()
{
    this->ui->spinAttack->setValue(7);
    this->ui->spinData->setValue(5);
    this->ui->spinFirewall->setValue(4);
    this->ui->spinSleep->setValue(7);
}

void ShadowrunTool::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1.contains("Multi. Co-Proc."))
    {
        this->ui->additionalIniDie->setChecked(true);
    }
    else
    {
        this->ui->additionalIniDie->setChecked(false);
    }
}

void ShadowrunTool::checkStatusLabel()
{
    QString newText;
    foreach(QString item, this->modifikations)
    {
        newText.append(item);
    }
    this->ui->status_sim->setText(newText);
}

QString ShadowrunTool::getSkillBoni(QString skill)
{
    if(skill.contains("Aufspüren"))
    {
        return "+2 auf DV bei Icon Aufspüren \n";
    }

    if(skill.contains("Ausnutzen"))
    {
        return "+2 auf S bei Eiligem Hacking \n";
    }

    if(skill.contains("Babymonitor"))
    {
        return "Siehe Beschreibung \n";
    }

    if(skill.contains("Biofeedback"))
    {
        return "Siehe Beschreibung \n";
    }
    //17
    if(skill.contains("Biofeedback-Filter"))
    {
        return "+2 Widerstand gegen Biofeedback \n";
    }
    if(skill.contains("Blackout"))
    {
        return "Siehe Beschreibung \n";
    }
    if(skill.contains("Entschlüsseln"))
    {
        return "+1 Angriff \n";
    }
    if(skill.contains("Fessel"))
    {
        return "Siehe Beschreibung \n";
    }
    if(skill.contains("Gabel"))
    {
        return "Siehe Beschreibung \n";
    }
    if(skill.contains("Hammer"))
    {
        return "+2 Würfel Matrixschaden \n";;
    }
    if(skill.contains("Irreführung"))
    {
        return "+2 Würfel gegen Icon Aufspüren \n";
    }
    if(skill.contains("Panzerung"))
    {
        return "+2 Würfel für Matrixwiderstand \n";
    }
    if(skill.contains("Schild"))
    {
        return "Siehe Beschreibung \n";
    }
    if(skill.contains("Schutzschirm"))
    {
        return "+1 Würfel gegen Matrixschaden & Biofeedback \n";
    }
    if(skill.contains("Splitterschutz"))
    {
        return "+4 Würfel gegen Datenbombenschaden \n";
    }
    if(skill.contains("Superbombe"))
    {
        return "Siehe Beschreibung \n";
    }
    if(skill.contains("Tarnkappe"))
    {
        return "+1 auf Schleicher \n";
    }
    if(skill.contains("Überfall"))
    {
        return "Siehe Beschreibung \n";
    }
    if(skill.contains("Konfigurator"))
    {
        return "Siehe Beschreibung \n";
    }
    if(skill.contains("Schmöker"))
    {
        return "Siehe Beschreibung \n";
    }
    if(skill.contains("Signalreiniger"))
    {
        return "+2 Rauschunterdrückung \n";
    }
    if(skill.contains("Toolbox"))
    {
        return "+1 auf Datenverarbeitung \n";
    }
    if(skill.contains("Verschlüssel"))
    {
        return "+1 auf Firewall \n";
    }
    if(skill.contains("Virtuelle Maschine"))
    {
        return "Siehe Beschreibung \n";
    }

    if(skill.contains("Editieren"))
    {
        return "+2 Würfel auf alle Editierenproben \n";
    }

    if(skill.contains("Verwandlung"))
    {
        return "Siehe Beschreibung \n";
    }
    if(skill.contains("Crash"))
    {
        return "+2 Würfel auf DV bei Programm Neustarten \n";
    }

    if(skill.contains("Evaluate"))
    {
        return "Siehe Beschreibung \n";
    }
    if(skill.contains("Mona Lisa"))
    {
        return "+2 Würfel bei Matrixsuche \n";
    }
    return "Siehe Beschreibung \n";
}

void ShadowrunTool::setDescriptionText(QString descrip)
{
    this->ui->skilldescription_lab->setText(this->descriptionFactory.getSkillDescription(descrip));
}
