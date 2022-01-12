#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
    , ui{new Ui::MainWindow}, a{new Alpha}, b{new Beta}
{
    ui->setupUi(this);
    a->setParent(this);
    b->setParent(this);

    connect(a, SIGNAL(allarme(QString)), b, SLOT(reazione(const QString&)));
    // oppure connect(a, &Alpha::allarme, b, &Beta::reazione);
    connect(ui->dial, SIGNAL(valueChanged(int)), a, SLOT(verifica(int)));
    // oppure connect(ui->dial, &QDial::valueChanged, a, Alpha::verifica);
    connect(ui->dial, SIGNAL(valueChanged(int)), this, SLOT(valoreCambiato(int)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(valoreCambiato(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

static void foo(Alpha o) {

};


void MainWindow::on_bottone_clicked()
{
    Alpha a;
    Alpha a2;
    //a = a2; // Errore: non posso copiare oggetti che derivano da QObject
    //foo(a); // Errore: non posso copiare oggetti che derivano da QObject

    new Beta{&a};
    new Beta{&a};
    auto b{new Beta};
    b->setParent(&a);

    // non è necessario liberare esplicitamente la memoria degli oggetti Beta
    // perché 'a' è il parent, e quando distruggo 'a' tutti gli oggetti "figlio" vengono
    // distrutti automaticamente


    a->verifica(ui->dial->value());
}

void MainWindow::valoreCambiato(int)
{
    QObject* origine{sender()}; // origine del segnale
    if (origine == ui->horizontalSlider) {
        qDebug() << "Valore cambiato dallo slider";
    } else if (origine == ui->dial) {
        qDebug() << "Valore cambiato dal dial";
    }
}

