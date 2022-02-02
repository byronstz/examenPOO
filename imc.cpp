#include "imc.h"
#include "ui_imc.h"
#include <QDate>
#include <QChar>
#include <QDebug>
#include <QSet>
#include <QFile>
#include <QDir>


#include <QMessageBox>

IMC::IMC(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IMC)
{
    ui->setupUi(this);
    iniciDat();
    abrD();
}

IMC::~IMC()
{
    delete ui;
}

void IMC::almcnr()
{
    QString fecha;
    float pesodu[50];
    float alturadu[50];
    float imcdu[50];

    QDate date;
    fecha = date.currentDate().toString("dd/MM/yyyy");

    for(int i=0; i<total; i++){
        pesodu[i] = usuario[i]->pesodu();
        alturadu[i] = usuario[i]->alturadu();
        usuario[i]->calcular();
        imcdu[i] = usuario[i]->imcdu();
    }
    QString pesou[50];
    QString alturau[50];
    QString im[50];
    for(int i=0; i<total; i++){
        pesou[i] = QString::number(usuario[i]->pesodu(), 'f', 2);
        alturau[i] = QString::number(usuario[i]->alturadu(), 'f', 2);
        usuario[i]->calcular();
        im[i] = QString::number(usuario[i]->imcdu(), 'f', 2);
    }
    QString file = QDir::currentPath() + "C:/Users/Byron/Desktop/examenPOO/registro.txt";
    QFile archivo(file);
    if(archivo.open(QFile::WriteOnly | QFile::Truncate)){
        for(int i=0; i<total; i++){
            QTextStream out(&archivo);
            out<<fecha<<"  ;"<<pesodu[i]<<"  ;"<<alturadu[i]<<"  ;"<<imcdu[i]<<" \n";
        }
        qDebug() << "Archivo guardado aqui: " << QDir::currentPath();
        archivo.close();
    }
}
void IMC::iniciDat()
{
    QStringList cabecera = {"Fecha. Actual ", "Peso. Kg", "Altura .M ,Cm ", "'I.M.C'"};
    ui->outRegistro->setColumnCount(4);
    ui->outRegistro->setHorizontalHeaderLabels(cabecera);
}

void IMC::abrD()
{
    QString nombre = QDir::currentPath() + "C:/Users/Byron/Desktop/examenPOO/registro.txt";

    QFile file(nombre);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QStringList datos;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString linea = in.readLine();
        datos << linea;
    }
    QStringList partes[50];
    for(int i=0; i<datos.size(); i++){
        partes[i]= datos[i].split(";");
    }
    for(int i=0; i<datos.size(); i++){

        ui->outRegistro->insertRow(i);

        ui->outRegistro->setItem(i,0, new QTableWidgetItem(partes[i][0]));
        ui->outRegistro->setItem(i,1, new QTableWidgetItem(partes[i][1]));
        ui->outRegistro->setItem(i,2, new QTableWidgetItem(partes[i][2]));
        ui->outRegistro->setItem(i,3, new QTableWidgetItem(partes[i][3]));

        int indice = total;
        usuario[indice] = new calcularIndice(partes[i][0],partes[i][1].toFloat(),partes[i][2].toFloat());
        this->total++;
    }
    file.close();
}
void IMC::on_btnCalcular_clicked()
{
    float peso = ui->inPeso->value();
    float altura = ui->inAltura->value();
    float imc;
    float menos;
    float mas = 0;
    QString resultab;
    QDate fecha;
    QString date = fecha.currentDate().toString("dd/MM/yyyy");

    int indice = total;
    usuario[indice] = new calcularIndice(date, peso, altura);
    this->total++;
    usuario[indice]->calcular();

    imc = usuario[indice]->imcdu();
    resultab = usuario[indice]->resultab();

    QString actual = QString::number(peso,'f',2);
    QString ind = QString::number(imc,'f',2);
    ui->outPactual->setText(actual + " Kg");
    ui->outIndice->setText(ind);
    ui->outEstado->setText(resultab);

    for(int i=0; i<total; i++){
        menos = usuario[0]->pesodu();
        float pesu = usuario[i]->pesodu();
        if(pesu > mas){
            mas = pesu;
        }
    }
    for(int i=0; i<total; i++){
        menos = usuario[0]->pesodu();
        float men = usuario[i]->pesodu();
        if(menos > men){
            menos = men;
        }
    }
    QString max = QString::number(mas, 'f', 2);
    ui->outPmax->setText(max + " Kg.");
    QString min = QString::number(mas, 'f', 2);
    ui->outPmin->setText(min + " Kg.");

     ui->outRegistro->setRowCount(0);
    for(int i=0; i<total; i++){
        usuario[i]->calcular();
        int posicion = ui->outRegistro->rowCount();
        ui->outRegistro->insertRow(posicion);
        ui->outRegistro->setItem(posicion,0,new QTableWidgetItem(date));
        ui->outRegistro->setItem(posicion,1,new QTableWidgetItem(QString::number(usuario[i]->pesodu())));
        ui->outRegistro->setItem(posicion,2,new QTableWidgetItem(QString::number(usuario[i]->alturadu())));
        ui->outRegistro->setItem(posicion,3,new QTableWidgetItem(QString::number(usuario[i]->imcdu())));
    }


}
