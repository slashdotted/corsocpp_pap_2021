#ifndef ALPHA_H
#define ALPHA_H

#include <QObject>
#include <QString>

class Alpha : public QObject
{
    Q_OBJECT
public:
    explicit Alpha(QObject *parent = nullptr);

public slots:
    void verifica(int valore);

signals:
    void allarme(QString msg);

};

#endif // ALPHA_H
