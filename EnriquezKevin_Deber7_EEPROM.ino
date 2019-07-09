/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * FICA-CIERCOM
 * KEVIN ENRIQUEZ
 * Tema:  Realice un sistema reloj con alarma almacenada en la EEPROM.
 * 
 * 
 * 
 * 
 */

#include <EEPROM.h> //Llamado de libreria EEPROM
#include <MsTimer2.h>//Llamado de libreria del timer 2
#include <TimerOne.h> //Llamado de libreria del timer1

int boton = 2 ; //Variable que almacena la interrupcion para ingresar los datos a la alarma
int minutero ; //Variable que almacena los minutos del reloj
int horero ; //Variable que almacena las horas del reloj
int segundero ; //Variable que almacena los segundos del reloj
String hora ; //Variable que almacena las horas en tipo String 
String minuto ; //Variable que almacena los minutos en tipo String 
String segundo ; //Variable que almacena los segundos en tipo String 
int horai=0 ; //Variable que almacena las horas inicializado en 0
int minutoi=0 ;//Variable que almacena los minutos inicializado en 0
int segundoi=0 ; //Variable que almacena los segundos inicializado en 0
int on=0 ; //Variable que almacena los estados de la interrupcion donde permite ingresar los datos en la alarma
int bocina=9 ; //Variable de salida que activa la alarma 
int led=10 ; //Variable de salida que activa la alarma
int apagar=3 ; //Variable que almacena la interrupcion que permite apagar la alarma
int i ; //Variable que permite almacenar los datos del reloj en la EEPROM
void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600) ; //Velocidad de transmision
  MsTimer2::set (1000, reloj) ; //Inicializacion del Timer2 con el metodo RELO
  MsTimer2::start () ;
  Timer1.initialize(1000000); //Inicializacion del timer ONE
  Timer1.attachInterrupt(backup);  //Timer one con el metodo backup
  segundero=EEPROM.read(0); //Metodo para almacenar los segundos del reloj en la memoria EEPROM
  minutero=EEPROM.read(1);//Metodo para almacenar los minutos del reloj en la memoria EEPROM
  horero=EEPROM.read(2);//Metodo para almacenar las horas del reloj en la memoria EEPROM
  attachInterrupt (0,alarma,LOW) ; //Interrupcion que permite ingresar los datos en la alarma
  attachInterrupt (1,apagado,LOW) ; //Interrupcion que permite apagar la alarma
  pinMode (9, OUTPUT)  ;  //Pin de salida que activa la bocina
  pinMode (10, OUTPUT) ;//Pin de salida que activa el eled
  Serial.println ("ALARMA") ;
  Serial.print ("Minuto ") ;
  Serial.println (EEPROM.read (4)) ; //Metodo que permite almacenar los minutos de la alarma en la EEPROM
  Serial.print ("Hora ") ;
  Serial.println (EEPROM.read (5)) ; //Metodo que permite almacenar los segundos de la alarma en la EEPROM
      if (minutoi==minutero  && horai==horero) { //Condicion para activar la alarma
      MsTimer2::start () ; 
      Serial.println ("Alarma Activada") ;
      tone (9, 100, 10) ;
      digitalWrite (led, HIGH) ;
    } if (minutoi!=minutero  && horai!=horero) { //Condicion para desactivar la alarma
       Serial.println ("ALARMA APAGADA") ;
       digitalWrite (led, LOW) ;
    }

  

}

void loop() {
  if (Serial.available () >0) {    
     if (on==1) {
    minuto=Serial.readString () ;
    Serial.println (" ") ;
    Serial.println ("Minuto ingresado: "+minuto) ;   
    minutoi=minuto.toInt () ; 
    EEPROM.write (4, minutoi) ;
        while (minutoi>60) {
      Serial.println ("Ingrese adecuadamente el valor del segundo") ;
      segundo=Serial.readString () ;
      segundoi=segundo.toInt () ;
    }
   } else if (on==2 ) {
    hora=Serial.readString () ;
    Serial.println (" ") ;
    Serial.println ("Hora ingresado: "+hora) ;
     horai=hora.toInt () ;
     EEPROM.write (5, horai) ;
        while (horai>24) {
      Serial.println ("Ingrese adecuadamente el valor de la hora") ;
      hora=Serial.readString () ;
      horai=segundo.toInt () ;
      
    }
              Serial.println ("La alarma esta programa para la hora: ") ;
    Serial.print ("_") ;
    Serial.print (":") ;
    Serial.print (minutoi) ;
    Serial.print (":") ;
    Serial.println (horai) ;
    MsTimer2::start () ;
    if (minutoi==minutero  && horai==horero) {
      MsTimer2::start () ;
      Serial.println ("Alarma Activada") ;
      tone (9, 100, 10) ;
      digitalWrite (led, HIGH) ;
    } if (minutoi!=minutero  && horai!=horero) {
       Serial.println ("ALARMA APAGADA") ;
       digitalWrite (led, LOW) ;
    }
   } 
  }

  
}
void reloj () {
  
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
void alarma ()  {
  on ++ ;
  if (on>0 && on<3) {
    MsTimer2::stop () ;
  } 
      switch (on) {
      case 1:
      Serial.println ("INGRESE EL MINUTO DE LA ALARMA") ; 
      

      break ;
      case 2 :
      Serial.println ("INGRESE LA HORA DE LA ALARMA") ;
      break ;
      case 3 :
      Serial.println ("REAUNUDANDO") ;
      on=0 ;
      break ;    
    }

}  

void backup () {
    i++;
  if(i==1){
    //Serial.println("Backup");
    EEPROM.write(0,segundero);
    EEPROM.write(1,minutero);
    EEPROM.write(2,horero);  
    i=0;
  }
}
void apagado () {
  horai=0 ;
  minutoi= 0;
}
