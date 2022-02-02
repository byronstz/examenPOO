#ifndef IMC_H
#define IMC_H

#include <QMainWindow>
#include "calculo.h"


QT_BEGIN_NAMESPACE
namespace Ui { class IMC; }
QT_END_NAMESPACE

class IMC : public QMainWindow
{
    Q_OBJECT
public:
    IMC(QWidget *parent = nullptr);
    ~IMC();
    void almcnr();
    void iniciDat();
    void abrD();

private slots:

    void on_btnCalcular_clicked();

private:
    Ui::IMC *ui;
    calcularIndice *usuario[100];
    int total=0;

    /**QBarSet *set0;
    QBarSet *set1;
    QBarSet *set2;
    QBarSet *set3;

    QHorizontalPercentBarSeries *series;
    QChart *chart;
    QBarCategoryAxis *categoryAxis;
    QValueAxis *valueAxis;
    QChartView *chartView;**/
};
#endif // IMC_H
