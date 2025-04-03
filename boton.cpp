/**
 * @file boton.cpp

 * @brief En este archivo se define el comportamiento de los botones al ser o dejar de ser presionados. 
 * @version 0.1
 * @date 2025-04-03
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "pins_umbrales.h"
/**
 * @brief Esta función define qué sucede cuando el botón se aprieta. 
 * 
 * 
 */
void botonPresionado(){
    riegoManual = true; /**> Se enciende el riego manual */
    bomba = 1; /**> Se enciende la bomba */
    ledRiego = 1; /**> Se enciende LED de riego */
}
/**
 * @brief Esta función define qué sucede cuando el botón se deja de apretar
 * 
 */
void botonLibre(){
    riegoManual = false;  /**> Se apaga el riego manual */
    bomba = 0; /**> Se apaga la bomba */
    ledRiego = 0; /**> Se apaga LED de riego */
}