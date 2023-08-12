#include "city.h"
#include "qgraphicsitem.h"

City::City(QString name,int x,int y)
    :m_name(name), m_x(x), m_y(y){}


void City::draw(QGraphicsScene &scene){

    //andere nethode um die funktion zu machen.
    //        //erstellen eines punktes
    //        scene.addEllipse(x,y,4,4,QPen(Qt::red)
    //                         ,QBrush(Qt::red,Qt::SolidPattern));

    //        // Ausgabe in Console
    //        QString tempStr = QString("City: %1, Koordinaten:(%2,%3)").arg(name).arg(x).arg(y);
    //        qDebug() << tempStr<< Qt::endl;




    //erstellen eines punktes
    scene.addEllipse(m_x,m_y,4,4,QPen(Qt::red)
                     ,QBrush(Qt::red,Qt::SolidPattern));

    // Textobjekt erstellen und platzieren
    QGraphicsTextItem* textItem = new QGraphicsTextItem(m_name);
    textItem->setPos(m_x + 5, m_y - 15);  // Position des Textobjekts anpassen
    //textItem->setPlainText(m_name); //wurde direkt beim erstellen der name des stadtes übergeben.
    scene.addItem(textItem);

    // Ausgabe in Console
    QString tempStr = QString("City: %1, Koordinaten:(%2,%3)").arg(m_name).arg(m_x).arg(m_y);
    qDebug() << tempStr<< Qt::endl;
}
QString City::getName(){
    return m_name;
}
int City::getX(){return m_x;}
int City::getY(){return m_y;}
