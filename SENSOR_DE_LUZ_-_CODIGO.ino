#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int lightPin = 0; // Pin LDR.
int ledPin = 10; // Pin LED.
int valor; // Variable para cálculos.
int valor2; // Variable para cálculos.
int min = 20; // Valor minimo obtenido por A0.
int max = 990; // Valor maximo obtenido por A0.
int cont=1;
void setup(){
Serial.begin(9600); // Inicializa el puerto serie.
pinMode( ledPin, OUTPUT ); // ledPin como salida.
pinMode(7,INPUT);
lcd.begin(16,2);
} 
 
void loop(){
cont=digitalRead(7);
valor = analogRead(lightPin); // Leemos el valor de A0.
valor2 = analogRead(lightPin); // Leemos el valor de A0. 
valor2 = constrain(valor2, min, max); // Normalizamos el valor.
valor2 = map(valor2, min, max, 0, 100); // Re-mapeamos.
delay(5);
lcd.setCursor(7,0);
lcd.print("UTN");
lcd.setCursor(0,1);
lcd.print("Por: ");
lcd.setCursor(6,1);
lcd.print(valor2);
lcd.setCursor(9,1);
lcd.print("%");
delay(600);
lcd.clear();
Serial.print ("Valor de salida: ");
Serial.println(valor2); // Valor de salida del LED.

}
