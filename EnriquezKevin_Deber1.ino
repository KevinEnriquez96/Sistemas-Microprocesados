//Nombre: Kevin Enriquez
//Materia: Sistemas Microprocesados
int i = 0 ; //Declaracion de la variable i
int VectorLeds [8]={2,3,4,5,6,7,8,9}; //Declaración del vector en donde se alojarán los leds.


void setup() {
  for(;i<8;i++){
    pinMode(VectorLeds[i], OUTPUT) ; //Se activan los puertos de salida en donde se encederán los leds.
    }
}

void loop() {

  for (i=0;i<8;i=2+i){  // Primer juego de leds: Se encienden los leds en las posiciones pares
      digitalWrite (VectorLeds[i], HIGH) ;
      delay (200) ;
      digitalWrite (VectorLeds[i], LOW) ;
      delay (200) ;
    }
   for (i=1;i<8;i=i+2){ // Segundo juego de leds: Se encienden los leds en las posiciones impares
      digitalWrite (VectorLeds[i], HIGH) ;
      delay (200) ;
      digitalWrite (VectorLeds[i], LOW) ;
      delay (200) ;
      }
   for(i=0;i<8;i++){ // Tercer juego de leds: Se encienden los leds uno a uno en forma ascendente
       digitalWrite (VectorLeds[i], HIGH) ;
       delay (100) ;
       digitalWrite (VectorLeds[i], LOW);
       delay (200) ;
      }
   for (i=7; i>0 ; i--){ // Cuarto juego de leds: Se encienden los leds uno a uno en forma descendente
       digitalWrite (VectorLeds[i], HIGH) ;
       delay (100) ;
       digitalWrite (VectorLeds[i], LOW);
       delay (200) ;
      }
   for(i=0;i<8;i++){
       digitalWrite (VectorLeds[i],HIGH); // Quinto juego de leds: Se encienden los leds en barrido
       delay(50) ;  
      }
   for (i=7; i>0 ; i--){ //Se apagan los leds en barrido.
       digitalWrite (VectorLeds[i], LOW); 
       delay (50) ;
      }     
        
}
