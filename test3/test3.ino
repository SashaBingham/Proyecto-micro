#define _DEBUG_
#include <Wire.h>
#include "ClosedCube_HDC1080.h"

// Instancia a la clase
ClosedCube_HDC1080 hdc1080;

void setup() {
  
#ifdef _DEBUG_
  Serial.begin(9600);
#endif

#ifdef _DEBUG_
  Serial.println(" ");
  Serial.println("Inicado sensor HDC1080");
  Serial.println("Calefactor encendido. Por favor espere...");
#endif

// Activar calefactor
  hdc1080.heatUp(15); // activa el calefactor 15 segundos

#ifdef _DEBUG_
  Serial.println("Calefactor apagado");
#endif
}
void loop() {
  }
