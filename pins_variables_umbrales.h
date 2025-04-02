#define PIN_HUMEDAD A1
#define PIN_RIEGO D1
#define PIN_ACTIVO D2
#define PIN_BOMBA D3
#define PIN_BOTON D4
// Pins
AnalogIn humedad(PIN_HUMEDAD);      // Sensor de humedad
DigitalOut ledRiego(PIN_RIEGO);     // Led de riego activo
DigitalOut ledActivo(PIN_ACTIVO);   // LED de sistema activo
DigitalOut bomba(PIN_BOMBA);        // Control de la bomba
InterruptIn boton(PIN_BOTON);       // Botón de riego manual

// Variables
float umbralHumedad = 0.3;
bool riegoManual = false;
