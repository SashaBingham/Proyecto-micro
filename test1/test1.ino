#define _DEBUG_
#include <Wire.h>
#include "ClosedCube_HDC1080.h"

// Instancia a la clase
ClosedCube_HDC1080 hdc1080;

void setup() {
#ifdef _DEBUG_
  Serial.begin(9600);
#endif

  // Iniciar sensor al que se pasa la dirección I2C
  // Por defecto es un número de 7-bit 1000000 que equivale al 40 en hexadecimal
  // Por defecto la precisión es de 14-bit para temperatura y humedad
  
  hdc1080.begin(0x40);
#ifdef _DEBUG_
  Serial.println(" ");
  Serial.println("Iniciado el sensor HDC1080");
#endif
}

void loop() {}
