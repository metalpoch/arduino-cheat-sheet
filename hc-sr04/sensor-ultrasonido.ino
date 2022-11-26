/*

Autor: Keiber Urbila <keiberup.dev@gmail.com>

Este codigo se encarga de monstrar por el monitor serial y
display lcd la distancia en cm obtenida por el sensor de
ultrasonido HC-SR04

*/

// Importar libreria del display
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Constantes del sensor ultrasonico
int const ECHO = 8;
int const TRIG = 9;

// Variables para el calculo de distancia
float distancia;
float tiempo;

// Configuracion inicial
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2); 
  
  lcd.print("Distancia");  // Mensaje del primera fila
  pinMode(TRIG, OUTPUT); // Trig como salida
  pinMode(ECHO, INPUT);  // Echo como entrada
}

void loop()
{
  // Envio de pulsos ultrasonico
  digitalWrite(TRIG, HIGH); 
  delayMicroseconds(10);  // 10 uS por recomendacion del fabricante
  digitalWrite(TRIG, LOW); 

  // Capturar el eco del pulso
  tiempo = pulseIn(ECHO, HIGH);  // Captura del pulso
  
  // Calculo de la distancia
  distancia = tiempo / 58;  // uS/58 por recomendacion del fabricante
  
  
  // Imprimir valores por la terminal serial (para debug)
  Serial.print("Distancia ");
  Serial.print(distancia);
  Serial.print(" cm");
  Serial.println("");
  
  // Imprimir valores de distancia por el display lcd
  lcd.setCursor(0, 1);
  lcd.print(distancia);
  lcd.print(" cm");
  delay(100); // Esperar 100 millisegundos  
}
