#include "beta.h"
#include <QDebug>

Beta::Beta(QObject *parent)
    : QObject{parent}
{

}

Beta::~Beta()
{
    qDebug() << "Distruzione di Beta";
}

void Beta::reazione(const QString &msg)
{
    qDebug() << "Ricevuto segnale:" << msg;
}
