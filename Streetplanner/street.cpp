#include "street.h"

Street::Street(City* city1, City* city2)
    : city1(city1), city2(city2)
{
}

void Street::draw(QGraphicsScene& scene)
{
    city1->draw(scene);
    city2->draw(scene);
    scene.addLine(city1->getX(), city1->getY(), city2->getX(), city2->getY());
}
bool Street::hasCity(const City* city) const {
    return (city1 == city || city2 == city);
}

City* Street::getOppositeCity(const City* city) const  {
    if (city == city1) {
        return city2;
    } else if (city == city2) {
        return city1;
    } else {
        return nullptr;
    }
}
double Street::getLength() const{
    int xDiff = city2->getX() - city1->getX(); // Calculate the difference in x-coordinates
    int yDiff = city2->getY() - city1->getY(); // Calculate the difference in y-coordinates
    double length = std::sqrt(xDiff * xDiff + yDiff * yDiff); // Calculate the hypotenuse using the Euclidean distance formula
    return length;
}
void Street::drawRed(QGraphicsScene& scene)
{
    QPen pen;
    if (isShortestPath) {
        pen.setColor(Qt::red); // Setze die Stiftfarbe auf rot für den kürzesten Weg
        pen.setWidth(3); // Setze eine breitere Linienstärke für den kürzesten Weg
    } else {
        pen.setColor(Qt::black); // Setze die Standard-Stiftfarbe für andere Straßen
        pen.setWidth(1); // Setze die Standard-Linienstärke für andere Straßen
    }

    scene.addLine(city1->getX(), city1->getY(), city2->getX(), city2->getY(), pen); // Zeichne die Straße in der Szene
}


City* Street::getCity1()const{return city1;}
City* Street::getCity2()const{return city2;}
