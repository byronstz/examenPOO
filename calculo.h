#ifndef CALCULO_H
#define CALCULO_H

#include <QObject>

class calcularIndice : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float alturadu READ alturadu)
    Q_PROPERTY(float pesodu READ pesodu)
    Q_PROPERTY(float imcdu READ imcdu)
private:
    float m_pesodu;
    float m_alturadu;
    float m_imcdu;
    QString m_resultab;
    QString m_ingrFecha;

public:
    explicit calcularIndice(QObject *parent = nullptr);
    calcularIndice(QString ingrFecha, float pesodu, float alturadu);

    QString ingrFecha() const;
    QString resultab() const;
    void calcular();
    float pesodu() const;
    float alturadu() const;
    float imcdu() const;

signals:

};

#endif // CALCULO_H
