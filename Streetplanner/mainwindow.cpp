#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include "qmessagebox.h"
#include <QDebug>
#include <QMessageBox>
#include <QGraphicsRectItem>
#include "city.h"
#include "mapionrw.h"
#include "neuestadteinfugen.h"
#include "map.h"
#include "dijkstra.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);  // Übergabe der QGraphicsScene an QGraphicsView
    mapIo = new MapIoNrw();





}


MainWindow::~MainWindow()
{
    delete ui;
    delete mapIo;

}


void MainWindow::on_pushButton_teste_was_clicked()
{

    QMessageBox msgBox;


    int zufall = rand()*250/RAND_MAX; // Zufällige Zahl zwischen 0 und 9
    int zufall2 = rand()*250/RAND_MAX;
    // Zufällig positioniertes Rechteck zur Szene hinzufügen
    QGraphicsRectItem *rectItem = new QGraphicsRectItem(zufall, zufall2, 5, 5);
    QPen pen = QPen(Qt::red);
    rectItem->setPen(pen);
    rectItem->setBrush(Qt::blue);
    scene.addItem(rectItem);



    QString eingabeStr = ui->lineEdit_teste_was->text();

    bool ok; // ist es convertiert oder nicht  ?
    int istEsEineZahl = eingabeStr.toInt(&ok);
    if(!ok)
    {
        // wenns ein string ist.
        QString ausgabeStr =QString("String lautet: %L1")
                                         .arg(eingabeStr,10);
        qDebug() << ausgabeStr << Qt::endl;
        msgBox.setText(ausgabeStr);
    }else{

        //wenn es eine Zahl ist.
        qDebug() << "Zahl erhöht um 4 und lautet damit:" << istEsEineZahl+4<< Qt::endl;
        msgBox.setText(QString("Zahl erhöht um 4 und lautet damit:%1").arg(istEsEineZahl+4));
    }
    msgBox.exec();
}


void MainWindow::on_actionExit_2_triggered()
{
    close();
}


void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.about(this,"info:","Kurze beschriebung ausgeben");
}


void MainWindow::on_Test_Draw_City_clicked()
{
    // Erstellen und Zeichnen von zwei Städten
    City city1("City A", 50, 50);
    city1.draw(scene);

    City city2("City B", 100, 100);
    city2.draw(scene);
}


void MainWindow::on_map_testen_clicked()
{
    // Erstellen und Zeichnen von Städten
    City city1("City A", 50, 50);
    City city2("City B", 100, 100);

    // Hinzufügen der Städte zur Map
    m_map.addCity(&city1);
    m_map.addCity(&city2);

    // Zeichnen der Map
    m_map.draw(scene);
}


void MainWindow::on_street_test_clicked()
{

    City city1("City 1", 100, 100);
    City city2("City 2", 200, 200);
    Street street(&city1, &city2);
    street.draw(scene);

}


void MainWindow::on_street2_testen_clicked()
{
    Map map;

    City city1("City 1", 100, 100);
    City city2("City 2", 200, 200);
    Street street(&city1, &city2);

    map.addCity(&city1);
    map.addCity(&city2);
    map.addStreet(&street);
    map.draw(scene);
}


void MainWindow::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked()) {
        ui->Test_Draw_City->hide();
        ui->map_testen->hide();
        ui->street_test->hide();
        ui->street2_testen->hide();
        ui->pushButton_teste_was->hide();
        ui->lineEdit_teste_was->hide();
        ui->label_eingabe->hide();

        } else {
        ui->Test_Draw_City->show();
        ui->street_test->show();
        ui->street2_testen->show();
        ui->map_testen->show();
        ui->pushButton_teste_was->show();
        ui->lineEdit_teste_was->show();
        ui->label_eingabe->show();
    }
}


void MainWindow::on_button_add_city_clicked()
{

    NeueStadtEinfugen dialog;
    int result = dialog.exec();
    qDebug() << "Dialog result: " << result;

    bool inputValid = false;

    while (!inputValid)
    {
        // Öffnen Sie den Dialog, um die Benutzereingabe zu erhalten

        if(QDialog::Accepted){
            City* newCity = dialog.createCity();

            // Überprüfen Sie die eingegebenen Daten auf Korrektheit
            if(m_map.findCity(newCity->getName())){
                QMessageBox::warning(this, "Fehler", "Es gibt schon eine Stadt mit dem Namen.");
                continue;
            }
            if (!newCity->getName().isEmpty() && newCity->getX() >= -300.0 && newCity->getX() <= 300.0 && newCity->getY() >= -300.0 && newCity->getY() <= 300.0)
            {
                    inputValid = true;
                    m_map.addCity(newCity);
                    m_map.draw(scene); // Funktion zum Neuzeichnen der Karte aufrufen
            }    // Die Benutzereingabe ist korrekt
            else{
                  QMessageBox::warning(this, "Fehler", "Ungültige Eingabe. Bitte überprüfen Sie Ihre Daten.");
            }

        }else {
            // Der Benutzer hat den Dialog abgebrochen
            break;
        }
    }
}


void MainWindow::on_pushButton_fill_map_clicked()
{
    scene.clear(); // Szene leeren


    mapIo->fillMap(m_map); // Karte füllen


    m_map.draw(scene); // Karte zeichnen
}




void MainWindow::on_pushButton_AbstractMap_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = m_map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}


void MainWindow::on_pushButton_dijkstra_clicked()
{

    scene.clear(); // Szene leeren
    mapIo->fillMap(m_map); // Karte füllen
    m_map.draw(scene); // Karte zeichnen

    QVector<Street*>shortestPath = Dijkstra::search(m_map,"Aachen","Bonn");

    // Überprüfen, ob ein kürzester Weg gefunden wurde
    if (!shortestPath.isEmpty()) {
        // Kürzester Weg wurde gefunden, gehe durch jede Straße und markiere sie als Teil des kürzesten Weges
        for (Street* street : shortestPath) {
            street->isShortestPath = true; // Setze die Straße als Teil des kürzesten Weges
            street->drawRed(scene); // Zeichne die Straße in rot
        }
    } else {
        // Kein kürzester Weg gefunden, gib eine Fehlermeldung aus
        qDebug() << "Es wurde kein kürzester Weg gefunden.";
    }
}

