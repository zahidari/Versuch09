#ifndef NEUESTADTEINFUGEN_H
#define NEUESTADTEINFUGEN_H

#include <QDialog>
#include "city.h"

namespace Ui {
class NeueStadtEinfugen;
}

class NeueStadtEinfugen : public QDialog
{
    Q_OBJECT

public:
    explicit NeueStadtEinfugen(QWidget *parent = nullptr);
    ~NeueStadtEinfugen();

     City* createCity(); // Funktion zur Erzeugung einer neuen Stadt

private:
    Ui::NeueStadtEinfugen *ui;
};

#endif // NEUESTADTEINFUGEN_H
