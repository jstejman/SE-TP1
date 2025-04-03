/**
 * @file main.cpp
 * @author Julián (jstejman@fi.uba.ar)
 * @brief En este archivo se ejecutan todas las tareas a realizar del sistema de riego
 * @version 0.1
 * @date 2025-04-03
 * 
 * @copyright Copyright (c) 2025
 * 
 */

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
        /**
         * @brief Lectura de humedad cada vez que se reinicia el bucle
         * 
         */
        humedadActual = humedad.read(); 
        
        /**
         * @brief Condiciones de activación de bomba en sistema de riego
         * 
         */
        if (!riegoManual && humedadActual < umbralHumedad) {
            bomba = 1;
            ledRiego = 1;
        } else if(!riegoManual) {
            bomba = 0;
            ledRiego = 0;
        }
        
        /**
         * @brief Parpadeo de LED Activo
         * 
         */
        if (ledActivo == 1) {
            ledActivo = 0;
        } else {
            ledActivo = 1;
        }
        
        /**
         * @brief Salida UART del estado de riego y del botón, como de la humedad medida.
         * 
         */
        printf(
            "Riego: %s | Botón: %s | Humedad: %.2f \n",
            (bomba == 1) ? "Activo" : "Inactivo",
            riegoManual = "Activado" : "Desactivado",
            humedadActual 
        );
        /**
         * @brief Se espera 1 segundo antes de reiniciar el bucle
         * 
         */
        ThisThread::sleep_for(1000);
    }
}
