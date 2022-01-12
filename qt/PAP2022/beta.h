#ifndef BETA_H
#define BETA_H

#include <QObject>

class Beta : public QObject
{
    Q_OBJECT
public:
    explicit Beta(QObject *parent = nullptr);
    ~Beta();

public slots:
    void reazione(const QString& msg);

};

#endif // BETA_H
