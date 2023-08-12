#ifndef STREET_H
#define STREET_H

#include "city.h"

class Street
{
public:
    Street(City* city1, City* city2);
    void draw(QGraphicsScene& scene);

    bool hasCity(const City* city) const;
    City* getOppositeCity(const City* city)const;
    double getLength() const;
    void drawRed(QGraphicsScene& scene);

    ///////////////////////////
    /// \brief Getters
    /// \return city1 and city2
    /// ///////////////////////

    City* getCity1()const;
    City* getCity2()const;

    bool isShortestPath;
private:
    City* city1;
    City* city2;

};

#endif // STREET_H
