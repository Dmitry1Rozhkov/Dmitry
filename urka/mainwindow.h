#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model.h"
#include "integrators.h"

using namespace iii;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    TScene* Scena;
    TEylerMod* IntE;
    TDormandPriceIntegrator* IntD;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
