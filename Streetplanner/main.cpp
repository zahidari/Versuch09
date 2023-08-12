// doc.qt.io


#include "mainwindow.h"

#include <QApplication>
#include <QDebug> // qDebug() <<  -> cout <<
#include <QString>
///
#include <QMessageBox>
///
#include <QLineEdit> // ui-> lineEdit-> text();
#include <QPushButton> //qlineedit
///
#include <QGraphicsView>
#include <QGraphicsTextItem>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

//    ////////////////////////////////////////////////////

//    QMessageBox msgBox;
//    msgBox.setText("The doc has been modiefied.");
//    msgBox.setInformativeText("Do you want to save your changes?");

//    msgBox.setStandardButtons(QMessageBox::Save |
//                              QMessageBox::Discard|
//                              QMessageBox::Cancel);

//    msgBox.setDefaultButton(QMessageBox::Save);

//    int ret = msgBox.exec();


//    QMessageBox result;
//    switch(ret){
//    case QMessageBox::Save:
//        result.setText("Save was clicked");
//        break;
//    case QMessageBox::Discard:
//        result.setText("Discard was clicked");
//        break;
//    case QMessageBox::Cancel:
//        result.setText("Cancel was clicked");
//        break;
//    default:
//        result.setText("This should be impossible");
//        break;
//    }
//    result.exec();

//    ///////////////////////////////
//    QString str;
//   str = Ui->lineEdit-> text();

//    QMessageBox  msgBox;
//   msgBox.setText(str);
//    msgBox.exec();
///////////////////////////////////
//    QGraphicsView view;
//    QGraphicsScene scene;
//    view.setScene(&scene);


//    scene.addEllipse(100,100,4,4,QPen(Qt::red),QBrush(Qt::red,Qt::SolidPattern));

//    QPen pen;
//    pen.setWidth(5);
//    pen.setColor(Qt::yellow);
//    scene.addLine(10,10,190,10,pen);

//    //um text anzuzeigen

//    QGraphicsTextItem* text = new QGraphicsTextItem;
//    text->setPos(80,70);
//    text->setPlainText("hallo mallo");
//    scene.addItem(text);


    w.show();
    return a.exec();



}
