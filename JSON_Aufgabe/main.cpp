#include <QCoreApplication>
#include <parser_json.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    parser_JSON parser;
    //QObject::connect(&parser, SIGNAL(finished()), &a, SLOT(quit()));
    return a.exec();
}

