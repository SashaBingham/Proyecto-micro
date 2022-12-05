#include<Wire.h>
 
// la direccion HDC1000 I2C es 0x40
#define Addr 0x40
 
void setup()
{
// Inicializa la comunicacion I2C como MASTER
Wire.begin();
// Inicializa la comunicacion serial communication
Serial.begin(9600);
 
// Empieza la comunicacion I2C
Wire.beginTransmission(Addr);
// Seleccionar la configuracion desde el registro
Wire.write(0x02);
// Temperatura, humedad habilitada, resolulcion = 14-bits, heater on
Wire.write(0x30);
Serial.println("Temperatura habilitada :");
// Termina la transmision I2C
Wire.endTransmission();
delay(300);
}
 
void loop()
{
unsigned int data[2];
 
// enviar la medida de la humedad al comando
Wire.beginTransmission(Addr);
// Send temp measurement command
Wire.write((byte)0x00);
// Termina la transmision I2C
Wire.endTransmission();
delay(500);
 
// solicitar 2 bytes de dato
Wire.requestFrom(Addr, 2);
 
// Leer 2 bytes de dato
// temperatura msb, humedad lsb
if (Wire.available() == 2)
{
data[0] = Wire.read();
data[1] = Wire.read();
}
// Convert the data
int temp = (data[0] * 256) + data[1];
float cTemp = (temp / 65536.0) * 165.0 - 40;
float fTemp = cTemp * 1.8 + 32;
 
// salida del monitor serial
Serial.print("Temperatura en Celsius :");
Serial.print(cTemp);
Serial.println(" C");
Serial.print("Temperatura en Fahrenheit :");
Serial.print(fTemp);
Serial.println(" F");
delay(500);
}
