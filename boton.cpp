#include "pins_umbrales.h"

void botonPresionado(){
    riegoManual = true;
    bomba = 1;
    ledRiego = 1;
}

void botonLibre(){
    riegoManual = false; 
    bomba = 0;
    ledRiego = 0;
}