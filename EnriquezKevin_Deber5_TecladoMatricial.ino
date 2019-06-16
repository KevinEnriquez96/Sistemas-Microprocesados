/*
 * Nombre: Kevin Enriquez
 * Tema; Teclado Matricial
 */

#include <Keypad.h> //Exportacion de la libreria que permite utilizar el teclado
const byte Filas= 4 ; //Declaracion del numero de filas del teclado
const byte Columnas=4 ; //Declaracion de numero de columnas del teclado
char letras [Filas][Columnas] = { //Asignacion de las letras a cada posicion del teclado
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','2','#','D'}
} ; 
byte FilasPin [Filas]= {9,8,7,6} ; //Declaracion de los pines a utilizar para las filas
byte ColumnasPin [Columnas] = {5,4,3,2} ; //Declaracion de los pines a utilizar para las columnas
int Led1 = 10 ; //Pin que valida la contraseña ingresada
int Led2= 11 ; //Pin que valida una contraseña incorrecta
Keypad teclado = Keypad(makeKeymap(letras),FilasPin, ColumnasPin, Filas, Columnas); //Declaracion de los parametros para utilizar el teclado
char LetraIngresada ; //Variable que almacena las letras ingresadas por el teclado
char contrasenaIngresada [6] ; //Variable que almacena las 6 posiciones de la contraseña
char contrasenaMaestra [6] = "ABC12"; //Variable que almacena la contraseña del sistema
int contador= 0  ; //Variable que permite contabilizar las ingresadas
void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600) ;

}

void loop() {
  // put your main code here, to run repeatedly:
  LetraIngresada=teclado.getKey () ; //Condicion para "Getear" los datos ingresados por medio del teclado
  if (LetraIngresada){ //Condicion que permite evaluar el numero de carácteres de la contraseña ingresada con el numero de carácteres de la contraseña del sistema
    contrasenaIngresada[contador] = LetraIngresada ;
    contador++ ;
    Serial.print (LetraIngresada) ;
}
  if (contador==5) { //Contdiciones para evaluar la contraseña
    if (!strcmp (contrasenaIngresada, contrasenaMaestra)){
    Serial.println ("  Contraseña Valida") ;  
    digitalWrite (Led1, HIGH) ;
    digitalWrite (Led2, LOW) ;
    contador=0 ;
    }
    else{
    Serial.println ("   Contraseña Invalida") ;
    contador = 0 ;
    digitalWrite (Led1, LOW) ;
    digitalWrite (Led2, HIGH) ;    
    }
    }
  }
