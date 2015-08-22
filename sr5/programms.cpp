#include "programms.h"

programms::programms()
{

    QString aufspuren("Dieses Programm späht die Ziele des Charak"
                      "ters für ihn aus und macht es leichter, sie in der physischen"
                      "Welt zu finden. Der Charakter erhält einen Bonus von +2 auf"
                      "Datenverarbeitung bei der Handlung Icon Aufspüren. Wenn "
                      "sein Gegner das Programm Tarnkappe laufen hat, heben die "
                      "beiden Wirkungen einander einfach auf. Das Programm hat in "
                      "diesem Fall keine weitere Wirkung");


    QString ausnutzen("Dieses  Programm  sucht  und  analysiert  die"
                      "Schwächen  von  Firewalls.  Der  Charakter  erhält  einen  Bonus"
                      "von +2 auf das Attribut Schleicher, wenn er die Handlung Eili"
                      "ges Hacken durchführt.");


    QString babymonitor("Dieses  Programm  basiert  auf  Algorithmen,"
                        "die der Grid Overwatch Division gestohlen wurden. Es verfolgt"
                        "die Aktivitäten des Charakters in der Matrix und sorgt dafür,"
                        "dass er jederzeit seinen aktuellen Overwatch-Wert kennt.");


    QString Biofeedback("Wenn der Charakter angreift, versieht dieses"
                        "Programm  seine  Angriffe  gegen  andere  Icons  mit  gefährli"
                        "chen Biofeedback-Signalen, wie sie von Schwarzem IC und"
                        "den  G-Men  benutzt  werden.  Dieses  Programm  funktioniert"
                        "nur  gegen  biologische  Ziele  (wie  zum  Beispiel  Sicherheits"
                        "spinnen). Wenn der Angriff des Charakters erfolgreich Mat"
                        "rixschaden verursacht, wird das Ziel von derselben Menge an"
                        "Geistigem  (bei  kaltem  Sim)  oder  Körperlichem  (bei  heißem"
                        "Sim)  Schaden  durch  Biofeedback  getroffen.  Auch  der  Mat"
                        "rixschaden  durch  misslungene  Angriffshandlungen  gegen"
                        "den Charakter wird beim Angreifer um Biofeedback-Schaden"
                        "vermehrt. Schaden durch Biofeedback wird mit Willenskraft +"
                        "Firewall widerstanden.");
    QString BiofeedbackFilter("Dieses Programm dient als eine Art Fi"
                              "rewall für das Sim-Modul und gewährt dem Charakter einen"
                              "Würfelpoolbonus  von  +2  zum  Widerstand  gegen  Schaden"
                              "durch Biofeedback");
    QString Blackout("Das ist die nettere Version des Programms Bio-"
                     "feedback. Es funktioniert genauso, verursacht aber (auch bei"
                     "heißem Sim) nur Geistigen Schaden durch Biofeedback.");
    QString Entschlusseln("Diese  Analyse-Algorithmen  verleihen"
                          "dem Charakter einen Bonus von +1 auf das Attribut Angriff.");
    QString Fessel("Wenn der Charakter an einer Persona Schaden ver"
                   "ursacht,  wird  diese  Persona  mit  einer Linksperre belegt, bis"
                   "er das Programm beendet oder sich der Gegner erfolgreich"
                   "ausstöpselt.");

    QString Gabel("Der Charakter kann mit diesem Programm eine ein"
                  "zelne  Matrixhandlung  gegen  zwei  Ziele  gleichzeitig  durch"
                  "führen. Er legt nur eine Probe ab, die von allen Modifikatoren"
                  "der beiden Ziele kumulativ beeinflusst wird. Jedes Ziel vertei"
                  "digt sich mit seinem eigenen Würfelpool. Die Auswirkungen"
                  "der Handlung des Charakters werden für jedes Ziel separat"
                  "bestimmt.");
    QString Hammer("Immer  wenn  der  Charakter  mit  einer  Handlung"
                   "Matrixschaden  verursacht,  erhöht  ihn  dieses  Offensivpro"
                   "gramm um +2. Das betrifft aber nicht den Matrixschaden, den"
                   "Angreifer durch gescheiterte Angriffshandlungen erleiden.");
    QString Irrefuhrung("Dieses Programm schickt den Matrixverkehr"
                        "des Charakters über komplizierte Routen, wodurch er einen"
                        "Würfelpoolbonus von +2 zur Verteidigung gegen die Hand"
                        "lung Icon Aufspüren erhält. Außerdem erfährt ein Halbgott,"
                        "wenn  er  auf  den  Charakter  fokussiert,  seinen  physischen"
                        "Standort nicht, obwohl der Charakter immer noch von allen"
                        "anderen Auswirkungen der Fokussierung getroffen wird.");
    QString Panzerung("Dieses  Programm  wirkt  zusammen  mit  der"
                      "Firmware  des  Charakters  als  zweite  Firewall.  Der  Charakter"
                      "erhält einen Würfelpoolbonus von +2 für den Widerstand ge-"
                      "gen Matrixschaden.");
    QString Schild("Dieses  Programm  sucht  nach  Schwachstellen  des"
                   "Charakters, um diese zu schützen. Er erleidet weniger zusätz"
                   "lichen Schaden durch Marken des Angreifers (-1 pro Marke).");

    QString Schutzschirm("Dieses  Programm  verleiht  dem  Charakter"
                         "mit seinen Filter-Algorithmen einen Würfelpoolbonus von +1"
                         "zum  Widerstand  gegen  Matrixschaden  und  Schaden  durch"
                         "Biofeedback. Dieser Bonus wirkt mit ähnlichen Boni anderer"
                         "Programme kumulativ.");
    QString Splitterschutz(" Dieses  Programm  errichtet  Barrieren  zwi"
                           "schen  dem  Charakter  und  einer  Datenbombe,  wodurch  er"
                           "einen Würfelpoolbonus von +4 zum Widerstand gegen den"
                           "Schaden durch Datenbomben erhält.");
    QString Superbombe("Dieses  Programm  unterstützt  die  Program"
                       "mierung von Datenbomben. Die Datenbomben des Charak"
                       "ters erhalten eine um 1 höhere Stufe, wenn er sie legt, solan"
                       "ge das Programm läuft.");

    QString Tarnkappe("Dieses schlaue Programm verleiht dem Charak"
                      "ter einen Bonus von +1 auf das Attribut Schleicher.");

    QString uberfall("Dieses Programm verfolgt die Marken des Cha"
                     "rakters aktiv und erhöht den zusätzlichen Schaden um +1 pro"
                     "Marke.");
    QString Konfigurator(" Wenn der Charakter dieses Programm laufen"
                         "lässt, wählt er eine Konfiguration für sein Deck aus, die sich"
                         "von der gerade eingesetzten unterscheidet. Diese alternative"
                         "Konfiguration wird vom Programm gespeichert. Beim nächs"
                         "ten Mal, wenn der Charakter sein Deck umkonfiguriert, kann"
                         "er diese alternative Konfiguration auswählen, statt nur zwei"
                         "Attribute oder Programme zu vertauschen, selbst wenn das"
                         "bedeutet,  dass  das  Programm  Konfigurator  dadurch  been"
                         "det wird. Die gespeicherte Konfiguration wird dadurch nicht"
                         "verändert; er kann sie später erneut aufrufen, sofern das Pro"
                         "gramm Konfigurator läuft.");
    QString Schmoker(" Diese  praktische  Suchmaschine  halbiert  den"
                     "Grundzeitraum für die Handlung Matrixsuche.");
    QString Signalreiniger(" Dieses  Programm  analysiert  Hintergrund"
                           "rauschen und eingehende Signale und verleiht dem Charakter"
                           "dadurch Rauschunterdrückung 2.");

    QString Toolbox("Dieses  Programm  zur  Speicherverwaltung  ver"
                    "leiht dem Charakter einen Bonus von +1 auf das Attribut Da"
                    "tenverarbeitung.");

    QString Verschlussel("Dieses Programm verleiht dem Charakter"
                         "einen Bonus von +1 auf sein Firewallattribut.");

    QString vmaschine("Dieses Programm schafft einen virtu"
                      "ellen Speicher im Deck des Charakters, was mehr Programme"
                      "gleichzeitig laufen lässt, aber die Systemstabilität beeinträch"
                      "tigt.  Der  Charakter  kann  zwei  Programme  mehr  auf  seinem"
                      "Deck  laufen  lassen.  Allerdings  erleidet  seine  Persona  jedes"
                      "Mal, wenn sie Matrixschaden erhält, 1 Kästchen Matrixscha"
                      "den zusätzlich (dem nicht widerstanden werden kann)");
    QString Editieren("Dieses Programm hat ein smartes Interface, das"
                      "sich dem Stil des Charakters anpasst und ihm sogar Vorschlä"
                      "ge machen kann, und macht dadurch das Editieren von Datei"
                      "en leichter. Das Limit Datenverarbeitung des Charakters steigt"
                      "um 2 für alle Editierenproben, die er ablegt, solange das Pro"
                      "gramm läuft.");
    QString Verwandlung("Dieses  Programm  überbrückt  die  Matrix-"
                        "protokolle  für  Icons.  Während  es  läuft,  kann  das  Icon  des"
                        "Charakters durch die Handlung Icon Verändern beliebig ge"
                        "staltet werden. In der Matrix könnte ein Hammer-Programm"
                        "wie  eine  Musikdatei  aussehen,  eine Ares Predator wie ein"
                        "Credstick und die Persona des Charakters wie ein Mitsubishi"
                        "Nightsky. Andere Personas können die verwandelten Icons"
                        "als  das  erkennen,  was  sie  sind.  Dazu  muss  diese  Persona"
                        "aber  zumindest  einen  Verdacht  haben,  der  es  rechtfertigt,"
                        "die  dazugehörige  Matrixwahrnehmungsprobe  (S.  239)  ab-"
                        "zulegen.");
    QString Crash("One  thing  deckers  have  learned  about  the"
                  "new Matrix protocols is that the ability to force devices"
                  "to reboot can be very beneficial. Crash is there to help"
                  "deckers who want to do this. When running, it attempts"
                  "to fill a targeted device with an exceptional amount of"
                  "reboot-worthy errors, adding 2 to the Data Processing"
                  "attribute  of  a  deck  running  this  program  when  it  at"
                  "tempts a Reboot Device action (p. 242, SR5).");
    QString Evaluate("With constant updates from a series of Black"
                     "BBS that specialize in monitoring paydata auctions, this"
                     "program calculates how much a certain amount of pay-"
                     "data might be worth, in order to allow the decker to only "
                     "take an amount that would limit the amount of heat they "
                     "would generate in stealing a little extra while on the job.");
    QString lisa("Matrix Suche +2");

    this->progList.insert("Aufspüren (X)", aufspuren);
    this->progList.insert("Ausnutzen (X)", ausnutzen);
    this->progList.insert("Babymonitor (X)", babymonitor);
    this->progList.insert("Biofeedback", Biofeedback);
    this->progList.insert("Biofeedback-Filter", BiofeedbackFilter);
    this->progList.insert("Blackout (X)", Blackout);
    this->progList.insert("Editieren (X)", Editieren);
    this->progList.insert("Entschlüsseln", Entschlusseln);
    this->progList.insert("Fessel", Fessel);
    this->progList.insert("Gabel (X)", Gabel);
    this->progList.insert("Hammer", Hammer);
    this->progList.insert("Irreführung (X)", Irrefuhrung);
    this->progList.insert("Panzerung", Panzerung);
    this->progList.insert("Schild (X)", Schild);
    this->progList.insert("Schutzschirm", Schutzschirm);
    this->progList.insert("Superbombe", Superbombe);
    this->progList.insert("Tarnkappe (X)", Tarnkappe);
    this->progList.insert("Überfall",uberfall);
    this->progList.insert("Konfigurator (X)", Konfigurator);
    this->progList.insert("Schmöker (X)", Schmoker);
    this->progList.insert("Signalreiniger (X)", Signalreiniger);
    this->progList.insert("Toolbox", Toolbox);
    this->progList.insert("Verschlüsseln (X)", Verschlussel);
    this->progList.insert("Virtuelle Maschine (X)", vmaschine);
    this->progList.insert("Editieren", Editieren);
    this->progList.insert("Verwandlung", Verwandlung);
    this->progList.insert("Crash (X)", Crash);
    this->progList.insert("Evaluate (X)", Evaluate);
    this->progList.insert("Mona Lisa (X)", lisa);
    this->progList.insert("Splitterschutz", Splitterschutz);

}

QString programms::getProgrammDescription(QString programm)
{
    return this->progList.value(programm);
}

QStringList programms::getProgrammList()
{
    QStringList toReturn;
    toReturn.append("Aufspüren");
    toReturn.append("Ausnutzen");
    toReturn.append("Babymonitor");
    toReturn.append("Biofeedback");
    toReturn.append("Biofeedback-Filter");
    toReturn.append("Blackout");
    toReturn.append("Entschlüsseln");
    toReturn.append("Fessel");
    toReturn.append("Gabel");
    toReturn.append("Hammer");
    toReturn.append("Irreführung");
    toReturn.append("Panzerung");
    toReturn.append("Schild");
    toReturn.append("Schutzschirm");
    toReturn.append("Superbombe");
    toReturn.append("Tarnkappe");
    toReturn.append("Überfall");
    toReturn.append("Konfigurator");
    toReturn.append("Schmöker");
    toReturn.append("Signalreiniger");
    toReturn.append("Toolbox");
    toReturn.append("Verschlüssel");
    toReturn.append("Virtuelle Maschine");
    toReturn.append("Editieren");
    toReturn.append("Verwandlung");
    toReturn.append("Crash");
    toReturn.append("Evaluate");
    toReturn.append("Mona Lisa");
    return toReturn;
}

