#include<Wire.h>
 
// Iniciar sensor al que se pasa la dirección I2C
// Por defecto es un número de 7-bit 1000000 que equivale al 40 en hexadecimal
// Por defecto la precisión es de 14-bit para temperatura y humedad
#define Addr 0x40
 
void setup()
{
// Initializando comunicacion I2C como MASTER
Wire.begin();
// Initializando comunicacion serial, establecer la tasa de compilaciones = 9600
Serial.begin(9600);

Serial.println(" ");
Serial.println("Iniciando sensor HDC1080");
}
void loop (){}
