#ifndef CITY_H
#define CITY_H
#include <QString>
#include<QGraphicsScene>
#include <QGraphicsView>

class City
{
public:
    City(QString name, int x, int y);
    void draw(QGraphicsScene &scene);




    ///////////////////
    ///   getters
    //////////////////
    QString getName();
    int getX();
    int getY();

private:
    QString m_name;
    int m_x;
    int m_y;
};

#endif // CITY_H
