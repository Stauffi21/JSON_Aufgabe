#include "parser_json.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include <stdlib.h>

parser_JSON::parser_JSON(QObject *parent) :
    QObject(parent)
{
    setFile();
}

void parser_JSON::setFile(){
    QTextStream out(stdout);
    out << "Bitte Absoluten Pfad eingeben:\n";
    out.flush();
    QTextStream in(stdin);
    in >> pfad;
    changeFile();
}

void parser_JSON::changeFile(){
    //File lesen
    QString text;
    QFile file(pfad);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    text = file.readAll();
    file.close();

    //Parsen und ändern
    QJsonDocument document = QJsonDocument::fromJson(text.toUtf8());
    //qDebug() << document;
    QJsonObject object= document.object();
    QJsonValueRef ref = object.find("Address").value();
    QJsonObject addvalue = ref.toObject();
    addvalue.insert("Street","India");
    addvalue.insert("City", "Zürich");
    ref=addvalue;
    document.setObject(object);

    //in File schreiben
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(document.toJson());
    file.close();
    //saveFile();
}

void parser_JSON::saveFile(){
    emit finished();
}

