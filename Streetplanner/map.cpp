#include "map.h"

Map::Map(QObject *parent)
{

}
void Map::addCity(City* city)
{
    cities.append(city);
    qDebug() << "Added city: " << city->getName();
}
bool Map::addStreet(Street* street)
{
    if (cities.contains(street->getCity1()) && cities.contains(street->getCity2()))
    {
        streets.append(street);

        qDebug() << "Zwischen "<<street->getCity1()->getName()<<" und "<<street->getCity2()->getName()<<" ist die Straße eingefügt.";
        return true;
    }
    else
    {
        qDebug() << "Straße konnte nicht eingefügt werden. Staedte wurden nicht gefunden.";
        return false;
    }
}
void Map::draw(QGraphicsScene& scene)
{
    for (City* city : cities)
    {
        city->draw(scene);
    }
      for (Street* street : streets)
      {
          street->draw(scene);
      }
}
City* Map::findCity(const QString cityName) const{
      for (City* city : cities) {
          if (city->getName() == cityName) {
              return city;
          }
      }
      return nullptr;
}
//QVector<City*> getCities() {
//      return cities.toVector();
//}
//QVector<Street*> getStreetList(const City* city){
//      QVector<Street*> cityStreets;
//      for (Street* street : streets) {
//          if (street->hasCity(city)) {
//              cityStreets.append(street);
//          }
//      }
//      return cityStreets;
//}
QVector<Street*> Map::getStreetList(const City* city) const {
      QVector<Street*> cityStreets;
      for (int i = 0; i < streets.size(); i++) {
          Street* street = streets[i];
          if (street->hasCity(city)) {
              cityStreets.append(street);
          }
      }
      return cityStreets;
}

City* Map::getOppositeCity(const Street* street, const City* city) const {
      if (street->getCity1() == city) {
          return const_cast<Street*>(street)->getCity2();
      } else if (street->getCity2() == city) {
          return const_cast<Street*>(street)->getCity1();
      } else {
          return nullptr;
      }
}
double Map::getLength(const Street* street) const {
      return street->getLength();
}

