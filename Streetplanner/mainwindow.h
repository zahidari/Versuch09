#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mapio.h"
#include "qgraphicsscene.h"
#include <QMainWindow>
#include "map.h"
#include "mapio.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_pushButton_teste_was_clicked();

    void on_actionExit_2_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_Test_Draw_City_clicked();

    void on_map_testen_clicked();

    void on_street_test_clicked();

    void on_street2_testen_clicked();

    void on_checkBox_clicked();

    void on_button_add_city_clicked();

    void on_pushButton_fill_map_clicked();

    void on_pushButton_AbstractMap_clicked();

    void on_pushButton_dijkstra_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    Map m_map; // Das Attribut m_map als Instanz der Map-Klasse hinzufügen
    MapIo* mapIo;
};
#endif // MAINWINDOW_H
