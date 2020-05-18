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
    QString text;
    QFile file(pfad);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    text = file.readAll();
    file.close();
    QJsonDocument document = QJsonDocument::fromJson(text.toUtf8());
    qDebug() << document;
    QJsonObject object= document.object();
    QJsonValueRef ref = object.find("Address").value();
    QJsonObject m_addvalue = ref.toObject();
    m_addvalue.insert("Street","India");//set the value you want to modify
    ref=m_addvalue; //assign the modified object to reference
    document.setObject(object); // set to json document
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(document.toJson());
    file.close();
    //saveFile();
}

void parser_JSON::saveFile(){
    emit finished();
}

