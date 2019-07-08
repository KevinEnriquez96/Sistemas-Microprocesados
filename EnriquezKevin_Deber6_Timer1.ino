/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * FICA-CIERCOM
 * SISTEMAS MICROPROCESADOS
 * NOMBRE: KEVIN ENRIQUEZ
 * DEBER:  Realizar un programa de seguridad domótica que permita encender las luces de 
 * un domicilio de 5 habitaciones de forma aleatoria solo en horario nocturno. El sistema se activa al ingresar una contraseña por comunicación serial.
 */

#include <TimerOne.h> //Libreria del timer1
int j =0 ;//Variable que permite almacenar el ciclo de los numero randoms
int horero ; //Variable que almacena las horas del reloj
int minutero ;//Variable que almacena los minutos del reloj
int segundero ;//Variable que almacena los segundos del reloj
int sensor ; //Variable que representa los sensores que se activarán
String clave ; //Cadena de caracteres del la contraseña
int sensor1=4 ; //Pin de salida que almacena el primer sensor
int sensor2=5 ; //Pin de salida que almacena el segundo sensor
int sensor3=6 ; //Pin de salida que almacena el tercer sensor
int sensor4=7 ; //Pin de salida que almacena el cuarto sensor
int sensor5=8 ; //Pin de salida que almacena el quinto sensor
boolean validar ; //Variable boolean que autentifica la contraseña ingresada



void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600) ; //Velocidad para la transmision serial
  Timer1.initialize (1000000) ; //Conteo cada un segundo
  Timer1.attachInterrupt (reloj) ;//Metodo para invocar el metodo reloj en un segundo plano
  pinMode (sensor1,OUTPUT) ; //Declaración de los pines como salida
  pinMode (sensor2,OUTPUT) ;
  pinMode (sensor3,OUTPUT) ;
  pinMode (sensor4,OUTPUT) ;
  pinMode (sensor5,OUTPUT) ;

}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available ()>0) { //Condicion para ingresar datos a traves de la comunicacion serial
    clave=Serial.readString () ; //Ingreso de datos
    if (clave.length () == 4) { //Condicion para validar la contraseña
      validar=clave.equals ("QWER") ;
      if (validar==true) {
        Serial.println (" ") ;
        Serial.println ("Contrasena Valida") ;
        conteo () ;
        
      }else {
        Serial.println ("Contrasena Invalida") ;
      }
      
    }else {
      Serial.println ("Contrasena Invalida") ;
      
      }
  }
}
void conteo () {
  if (segundero>=0 && minutero>=0 && horero>=19) { //Condicion para activar la contraseña en horario nocturno
  
  for (j=0; j<7;j++) {
    Serial.println ("ACTIVANDO SENSORES") ;
    sensor = random (0,4) ; //Condicion para declarar valores aleatorios desde 0 a 4
    Serial.print ("Sensor: ") ;
    Serial.println (sensor) ;
    //delay (2000) ;
    switch (sensor) {
    case 0 : 
    digitalWrite (sensor1,HIGH) ;
    delay (2000) ;
    tone (9, 3000, 1000) ;
    digitalWrite (sensor1,LOW) ;
    delay (1000)  ;
    break ;
    case 1 : 
    digitalWrite (sensor2,HIGH) ;
    delay (2000) ;
    tone (10, 3000, 1000) ;
    digitalWrite (sensor2,LOW) ;
    delay (1000)  ;    
    break;
    case 2 :
    digitalWrite (sensor3,HIGH) ;
    delay (2000) ;
    digitalWrite (sensor3,LOW) ;
    delay (1000)  ;    
    break ;
    case 3 :
    digitalWrite (sensor4,HIGH) ;
    delay (2000) ;
    tone (11, 3000, 1000) ;
    digitalWrite (sensor4,LOW) ;
    delay (1000)  ;    
    break ;
    case 4 :
    digitalWrite (sensor5,HIGH) ;
    delay (2000) ;
    tone (12, 3000, 1000) ;
    digitalWrite (sensor5,LOW) ;
    delay (1000)  ;    
    break ;
    }
    
    if (j==6) { //Condicion para reniciar el conteo de los 5 sensores
      j=0 ;
      
    }
  }
  } else {
    Serial.println ("HORARIO NO ESTABLECIDO") ;
  }
  
}
void reloj(){ //Metodo para desarrollar el conteo del reloj
  if(segundero<60){
    segundero++;
    Serial.print(segundero);
    Serial.print(':');
    Serial.print(minutero);
    Serial.print(':');
    Serial.println(horero);       
  }
  else{         //else segundero
    segundero=0;
    Serial.print(segundero);
    Serial.print(':');
    Serial.print(minutero);
    Serial.print(':');
    Serial.println(horero);
    if(minutero<60){
      minutero++;
      Serial.print(segundero);
      Serial.print(':');
      Serial.print(minutero);
      Serial.print(':');
      Serial.println(horero);
    }  
    else{         //else minutero
      minutero=0;
      Serial.print(segundero);
      Serial.print(':');
      Serial.print(minutero);
      Serial.print(':');
      Serial.println(horero);
      if(horero<24){
        horero++;
        Serial.print(segundero);
        Serial.print(':');
        Serial.print(minutero);
        Serial.print(':');
        Serial.println(horero);
      }    
      else{       //else horero
        horero=0;  
        Serial.print(segundero);
        Serial.print(':');
        Serial.print(minutero);
        Serial.print(':');
        Serial.println(horero);
      }
    }
  }            
}
