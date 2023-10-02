#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDataStream>
#include <QMessageBox>
#include <QtGlobal>
#include <QtConcurrent>
#include <algorithm>

///Подключаем все что нужно для графиков
#include "qcustomplot.h"

#define FD 1000.0 //частота дискретизации Гц
#define GT 1000.0 //длина оси X графика миллисекунды

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //Метод считывает данные из исходного файла
    QVector<uint32_t> ReadFile(QString path, uint8_t numberChannel);
    //Метод преобразует данные физические величины, В?
    QVector<double> ProcessFile(QVector<uint32_t> dataFile);
    //Метод ищет Максимумы
    QVector<double> FindMax(QVector<double> resultData);
    //Метод ищет минимумы
    QVector<double> FindMin(QVector<double> resultData);
    //Метод отображает результаты
    void DisplayResult(QVector<double> mins, QVector<double> maxs);

signals:
	void sig_end_calculation();

private slots:
    void on_pb_path_clicked();
    void on_pb_start_clicked();
	void show_graph();



private:
    Ui::MainWindow *ui;
	QString pathToFile = "F:/CxxICE/__Projects/9. Qt_Homeworks/9.7_QT_Charts_CustomPlot/testData.adc";
    uint8_t numberSelectChannel = 0xEA;

    QVector<uint32_t> readData;
    QVector<double> procesData;
    QVector<double> mins, maxs;

	QMainWindow *gWin;
	QWidget *proxyWidget;
	QGridLayout *layout;
	QCustomPlot *customPlot;
	QCPGraph *graph;

	const double kSampling = FD;//частота дискретизации Гц
	const double kGraphTime = GT;//длина оси X графика миллисекунды

};
#endif // MAINWINDOW_H
