#include "maingui.h"
#include <QApplication>
#include <QDebug>
#include <QCommandLineOption>
#include <QCommandLineParser>

int main(int argc, char *argv[]){

    QApplication app(argc, argv);
    QCommandLineParser parser;

    Q_INIT_RESOURCE(application);

    QCoreApplication::setOrganizationName("-- alu0100908480 --");
    QCoreApplication::setApplicationName("App de procesado de imágenes");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    parser.setApplicationDescription(QCoreApplication::applicationName());
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("imagen", "imagen a procesar.");
    parser.process(app);

    MainGui Mainw;

    if(!parser.positionalArguments().isEmpty()){
       // Mainw.loadFile(parser.positionalArguments().first());
    }

    Mainw.show();
    return app.exec();
}
