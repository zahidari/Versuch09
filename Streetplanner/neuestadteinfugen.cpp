#include "neuestadteinfugen.h"
#include "ui_neuestadteinfugen.h"
#include <QDebug>
#include <QString>

NeueStadtEinfugen::NeueStadtEinfugen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NeueStadtEinfugen)
{
    ui->setupUi(this);
}

NeueStadtEinfugen::~NeueStadtEinfugen()
{
    delete ui;
}

City* NeueStadtEinfugen::createCity()
{
    //parameter von dem neuen Fenster(neustadteinfugen) aus einlesen.
    QString cityName = ui->lineEdit_city_name->text();
    int latitude = ui->lineEdit_latitude->text().toInt();//zu int converten.
    int longitude = ui->lineEdit_longitde->text().toInt();

    //Ausgabe der Werten in die Console
    qDebug() << "City Name: " << cityName;
    qDebug() << "Latitude: " << latitude;
    qDebug() << "Longitude: " << longitude;

    //Obj erstellen, zurück geben.
    City* newCity = new City(cityName, latitude, longitude);
    return newCity;
}
