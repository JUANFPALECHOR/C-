#include "Utils.h"

bool esBisiesto(int año) {
    if (año % 4 != 0) return false;
    if (año % 100 != 0) return true;
    if (año % 400 != 0) return false;
    return true;
}

bool esFechaValida(const FechaHora& fh) {
    if (fh.mes < 1 || fh.mes > 12) return false;

    int diasEnMes;
    switch (fh.mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            diasEnMes = 31;
            break;
        case 4: case 6: case 9: case 11:
            diasEnMes = 30;
            break;
        case 2:
            diasEnMes = esBisiesto(fh.año) ? 29 : 28;
            break;
        default:
            return false;
    }

    if (fh.dia < 1 || fh.dia > diasEnMes) return false;
    if (fh.hora < 0 || fh.hora > 23) return false;
    if (fh.minuto < 0 || fh.minuto > 59) return false;
    if (fh.segundo < 0 || fh.segundo > 59) return false;

    return true;
}
