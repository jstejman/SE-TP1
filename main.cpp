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
        //Leer humedad
        humedadActual = humedad.read(); 
        
        // Condiciones para iniciar riego
        if (!riegoManual && humedadActual < umbralHumedad) {
            bomba = 1;
            ledRiego = 1;
        } else if(!riegoManual) {
            bomba = 0;
            ledRiego = 0;
        }
        
        // Parpadeo de LED
        if (ledActivo == 1) {
            ledActivo = 0;
        } else {
            ledActivo = 1;
        }
        // Salida UART
        printf(
            "Riego: %s | Botón: %s | Humedad: %.2f \n",
            (bomba == 1) ? "Activo" : "Inactivo",
            riegoManual = "Activado" : "Desactivado",
            humedadActual 
        );
        // Esperar 1 segundo para reiniciar el ciclo
        ThisThread::sleep_for(1000);
    }
}
