#ifndef PARSER_JSON_H
#define PARSER_JSON_H

#include <QObject>
#include <QString>
#include <QFile>

class parser_JSON : public QObject
{
    Q_OBJECT
public:
    parser_JSON(QObject *parent =  nullptr);
    void setFile();
    void changeFile();
    void saveFile();

private:
    QString pfad;
    QFile file;

signals:
    void finished();
};

#endif // PARSER_JSON_H
