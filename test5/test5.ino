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
Serial.println("Humidad abilitada");
// Termina la transmision I2C
Wire.endTransmission();
delay(300);
}
 
void loop()
{
unsigned int data[2];
 
// comienza la comunicacion I2C communication
Wire.beginTransmission(Addr);

// enviar la medida de la humedad al comando
Wire.write(0x01);
// Termina la transmision I2C
Wire.endTransmission();
delay(500);
 
// solicitar 2 bytes de dato
Wire.requestFrom(Addr, 2);
 
// Leer 2 bytes de dato
// humedad msb, humedad lsb
if (Wire.available() == 2)
{
data[0] = Wire.read();
data[1] = Wire.read();
}
 
// Calculando la humedad
float humidity = (data[0] * 256) + data[1];
humidity = (humidity / 65536.0) * 100.0;
 
// salida del monitor serial
Serial.print("Humedad Relativa :");
Serial.print(humidity);
Serial.println(" %RH");
delay(500);
}
