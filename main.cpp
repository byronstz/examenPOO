#include "imc.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>
#include <QChar>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator T;
    QStringList langs;
    langs << "Español" <<"Hindi";
    const QString lang = QInputDialog::getItem(NULL,"Languaje", "Select a languaje", langs);
    if (lang == "Hindi"){
        T.load(":/Hindi.qm");
    }
    if(lang != "Español"){
        a.installTranslator(&T);
    }
    a.setStyle("fusion");
    IMC w;
    w.show();
    return a.exec();
}
