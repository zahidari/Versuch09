#ifndef MAP_H
#define MAP_H

#include <QDebug>
#include <QObject>
#include <QList>
#include "abstractmap.h"
#include "city.h"
#include "street.h"

class Map : public QObject, public AbstractMap
{
    Q_OBJECT
public:
    explicit Map(QObject *parent = nullptr);


    //////////////////// ADDers ///////////////////////
    ///
    /// \brief addCity
    /// \param city
    ///
    void addCity(City* city) override;


    /// \brief addStreet
    /// \param street
    /// \return
    bool addStreet(Street* street) override;





    ///////////////////// GETTERS //////////////////////////////////
    /// \brief findCity
    /// \param cityName
    /// \return
    ///
    City* findCity(const QString cityName)  const override;


//    /// \brief getCities
//    /// \return
//    ///
//    QVector<City*> getCities() const;


    /// \brief getStreetList
    /// \param city
    /// \return
    ///
    QVector<Street*> getStreetList(const City* city) const override;


    /// \brief getOppositeCity
    /// \param street
    /// \param city
    /// \return
    ///
    City* getOppositeCity(const Street* street, const City* city) const override;


    /// \brief getLength
    /// \param street
    /// \return
    ///
    double getLength(const Street* street) const override;

    //////////////////////////////////////////////////////



    ///////////// DRAW   ////////////////////
    ///
    /// \brief draw Cities and streets
    /// \param scene
    ///
    void draw(QGraphicsScene& scene) ;



private:
    QVector<City*> cities;
    QVector<Street*> streets;
};

#endif // MAP_H
