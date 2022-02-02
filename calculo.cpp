#include "calculo.h"
#include <math.h>

float calcularIndice::imcdu() const
{
    return m_imcdu;
}
QString calcularIndice::ingrFecha() const
{
    return m_ingrFecha;
}
float calcularIndice::pesodu() const
{
    return m_pesodu;
}

float calcularIndice::alturadu() const
{
    return m_alturadu;
}
QString calcularIndice::resultab() const
{
    return m_resultab;
}
calcularIndice::calcularIndice(QString ingrFecha, float pesodu, float alturadu)
{
    this->m_pesodu = pesodu;
    this->m_alturadu = alturadu;
    this->m_ingrFecha = ingrFecha;
}
void calcularIndice::calcular()
{
    {
        m_imcdu = m_pesodu / (pow(m_alturadu,2));

        if(m_imcdu >= 0 && m_imcdu <18.5){
            m_resultab = "Peso muy bajo debes comer mas";
        }else if(m_imcdu >= 18.5 && m_imcdu <= 24.9){
            m_resultab = "Peso normal...muy bien";
        }else if(m_imcdu >= 25 && m_imcdu <= 29.9){
            m_resultab = "Peso demasiado algo";
        }else if(m_imcdu >= 30){
            m_resultab = "Tiene Sobrepeso";
        }
    }
}
calcularIndice::calcularIndice(QObject *parent) : QObject(parent)
{
    {
        m_imcdu = m_pesodu / (pow(m_alturadu,2));

        if(m_imcdu >= 0 && m_imcdu <18.5){
            m_resultab = "Peso muy bajo debes comer mas";
        }else if(m_imcdu >= 18.5 && m_imcdu <= 24.9){
            m_resultab = "Peso normal...muy bien";
        }else if(m_imcdu >= 25 && m_imcdu <= 29.9){
            m_resultab = "Peso demasiado algo";
        }else if(m_imcdu >= 30){
            m_resultab = "Tiene Sobrepeso";
        }

    }
}
