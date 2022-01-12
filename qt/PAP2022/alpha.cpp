#include "alpha.h"

Alpha::Alpha(QObject *parent)
    : QObject{parent}
{

}

void Alpha::verifica(int valore)
{
    if (valore > 50) {
        emit allarme("Valore troppo alto");
    } else {
        emit allarme("Valore ok");
    }
}
