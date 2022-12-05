#define _DEBUG_
#include <Wire.h>
#include "ClosedCube_HDC1080.h"

// Instancia a la clase
ClosedCube_HDC1080 hdc1080;

void setup() {
#ifdef _DEBUG_
  Serial.begin(9600);
#endif

// Cambiar resolución
  hdc1080.setResolution(HDC1080_RESOLUTION_8BIT, HDC1080_RESOLUTION_11BIT);
 
#ifdef _DEBUG_
  Serial.println(" ");
  Serial.println("Cambio de resolución");
#endif
}
void loop() {
  }
