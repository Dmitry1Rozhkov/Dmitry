#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Scena = new TScene();
    IntE = new TEylerMod();
    IntD = new TDormandPriceIntegrator();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
        double h = 1;
        IntE->seth(h);
        IntE->run(*Scena);

int N = Scena->Items[0]->getResult().rowCount();
 QVector<double> x(N), y(N), z(N);

 for (int i =0; i<N; i++)
 {
     x[i] = Scena->Items[0]->getResult()(i,1);
     y[i] = Scena->Items[0]->getResult()(i,2);
     z[i] = Scena->Items[0]->getResult()(i,3);
 }

  N = Scena->Items[1]->getResult().rowCount();
  QVector<double> x1(N), y1(N), z1(N);

  for (int i =0; i<N; i++)
  {
      x1[i] = Scena->Items[1]->getResult()(i,1);
      y1[i] = Scena->Items[1]->getResult()(i,2);
      z1[i] = Scena->Items[1]->getResult()(i,3);
  }


  N = Scena->Items[0]->Items[0]->getResult().rowCount();
  QVector<double> x2(N), y2(N), z2(N);

  for (int i =0; i<N; i++)
  {
      x2[i] = Scena->Items[0]->Items[0]->getResult()(i,1);
      y2[i] = Scena->Items[0]->Items[0]->getResult()(i,2);
      z2[i] = Scena->Items[0]->Items[0]->getResult()(i,3);
  }
//////////////////////////////xy
 ui->widget->addGraph();
 ui->widget->graph(0)->setData(x, y);

 ui->widget->addGraph();
 ui->widget->graph(1)->setData(x1, y1);

 ui->widget->addGraph();
 ui->widget->graph(2)->setData(x2, y2);

ui->widget->graph(0)->setPen(QPen(QColor(Qt::red)));
ui->widget->graph(2)->setPen(QPen(QColor(Qt::black)));

 ui->widget->xAxis->setLabel("x");
 ui->widget->yAxis->setLabel("y");
 ui->widget->xAxis->setRange(0, 10000);
 ui->widget->yAxis->setRange(0, 10000);
 ui->widget->replot();
 /////////////////////////////////xz
 ui->widget_2->addGraph();
 ui->widget_2->graph(0)->setData(x, z);

 ui->widget_2->addGraph();
 ui->widget_2->graph(1)->setData(x1, z1);

 ui->widget_2->addGraph();
 ui->widget_2->graph(2)->setData(x2, z2);

ui->widget_2->graph(0)->setPen(QPen(QColor(Qt::red)));
ui->widget_2->graph(2)->setPen(QPen(QColor(Qt::black)));

 ui->widget_2->xAxis->setLabel("x");
 ui->widget_2->yAxis->setLabel("z");
 ui->widget_2->xAxis->setRange(0, 10000);
 ui->widget_2->yAxis->setRange(0, 10000);
 ui->widget_2->replot();
 //////////////////////////////////////zy
 ui->widget_3->addGraph();
 ui->widget_3->graph(0)->setData(z, y);

 ui->widget_3->addGraph();
 ui->widget_3->graph(1)->setData(z1, y1);

 ui->widget_3->addGraph();
 ui->widget_3->graph(2)->setData(z2, y2);

ui->widget_3->graph(0)->setPen(QPen(QColor(Qt::red)));
ui->widget_3->graph(2)->setPen(QPen(QColor(Qt::black)));

 ui->widget_3->xAxis->setLabel("z");
 ui->widget_3->yAxis->setLabel("y");
 ui->widget_3->xAxis->setRange(0, 10000);
 ui->widget_3->yAxis->setRange(0, 10000);
 ui->widget_3->replot();
      /*  //Рисуем график y=x*x

         //Сгенерируем данные
         //Для этого создадим два массива точек:
         //один для созранения x координат точек,
         //а второй для y соответственно

         double a = -1; //Начало интервала, где рисуем график по оси Ox
         double b =  1; //Конец интервала, где рисуем график по оси Ox
         double h = 0.01; //Шаг, с которым будем пробегать по оси Ox

         int N=(b-a)/h + 2; //Вычисляем количество точек, которые будем отрисовывать
         QVector<double> x(N), y(N); //Массивы координат точек

         //Вычисляем наши данные
         int i=0;
         for (double X=a; X<=b; X+=h)//Пробегаем по всем точкам
         {
             x[i] = X;
             y[i] = X*X;//Формула нашей функции
             i++;
         }

         ui->widget->clearGraphs();//Если нужно, но очищаем все графики
         //Добавляем один график в widget
         ui->widget->addGraph();
         //Говорим, что отрисовать нужно график по нашим двум массивам x и y
         ui->widget->graph(0)->setData(x, y);

         //Подписываем оси Ox и Oy
         ui->widget->xAxis->setLabel("x");
         ui->widget->yAxis->setLabel("y");

         //Установим область, которая будет показываться на графике
         ui->widget->xAxis->setRange(a, b);//Для оси Ox

         //Для показа границ по оси Oy сложнее, так как надо по правильному
         //вычислить минимальное и максимальное значение в векторах
         double minY = y[0], maxY = y[0];
         for (int i=1; i<N; i++)
         {
             if (y[i]<minY) minY = y[i];
             if (y[i]>maxY) maxY = y[i];
         }
         ui->widget->yAxis->setRange(minY, maxY);//Для оси Oy

         //И перерисуем график на нашем widget
         ui->widget->replot();*/
}
