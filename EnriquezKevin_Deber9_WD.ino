/*Nombre: Kevin Enriquez
 *  Realizar un sistema que permita en intervalos de tiempo (puede ser cada 2 segundos )establecidos dormir al sistema 
 *  y levantarse para lecturas de un conversor análogo digital. Toma la lectura, la envía por comunicación serial 
 *  y se vuelve a dormir. 
 */
#include <LowPower.h>
#include <MsTimer2.h>
float entrada ; //Variable que almacena los datos captados de la entrada análoga

void setup() {
  Serial.begin(9600); //Velocidad de transmision de datos                 
  MsTimer2::set(1000, rutina); //Declaracion del timer con el metodo de rutina      
  MsTimer2::start(); //Inicializacion del timer        
}

void loop() {
  entrada = analogRead(0);                
  Serial.print("Entrada: ");
  Serial.println(entrada,7);
}
void rutina() {  
  LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
}
