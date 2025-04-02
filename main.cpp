#include "mbed.h"
#include "pins_variables_umbrales.h"
#include "boton.h"
#include <cstdio>


int main() 
{   
    float humedadActual = 0;
    
    boton.fall(&botonPresionado);
    boton.rise(&botonLibre);
    
    while(true) 
    {
        humedadActual = humedad.read(); 
    }
}
