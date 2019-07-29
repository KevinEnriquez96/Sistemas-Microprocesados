#include<EEPROM.h> //Llamado de las librerias
#include<LiquidCrystal.h>//Llamado de las librerias
#include<avr/wdt.h>//Llamado de las librerias
#include<MsTimer2.h>//Llamado de las librerias
#include<avr/sleep.h>//Llamado de las librerias
#include<avr/power.h>//Llamado de las librerias
#include<TimerOne.h>//Llamado de las librerias
LiquidCrystal lcd={10,9,8,7,6,5} ; //Declaracion de pines digitales
int horero,minutero,segundero ;//Declaracion de variables
void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600) ; //Velocidad de transmision de datos
  lcd.begin (16,2) ;
  MsTimer2::set (1000,reloj) ; //Declarar el metodo en el timer
  MsTimer2::start () ; //Inicio del timer
  segundero=EEPROM.read (0) ; //Almacenamiento de los datos en la memoria EEPROM
  horero=EEPROM.read (1) ;//Almacenamiento de los datos en la memoria EEPROM
  minutero=EEPROM.read (2) ;//Almacenamiento de los datos en la memoria EEPROM



}

void loop() {
  // put your main code here, to run repeatedly:
  mostrar () ;

  
}

void reloj () { //METODO PARA QUE DE FUNCIONAMIENTO AL RELOJ
  segundero ++ ;
  EEPROM.write (0,segundero) ;
  if (segundero>59) {
    segundero=0 ;
    minutero++ ;
      EEPROM.write (2,minutero) ;
      if (minutero>59) {
        minutero=0 ;
        horero++ ;
            EEPROM.write (1,horero) ;
          if (horero>23) {
            horero=0 ;
          }
      }
  }
  if(horero==0 && minutero==10 && segundero==50){
    EEPROM.update(0,11);
    EEPROM.update(2,10);
    delay(100);
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("REINICIO");
    wdt_enable(WDTO_8S);
    MsTimer2::stop();
  }
}


void mostrar () { //Metodo para indicar el reloj en el display
    lcd.setCursor (0,0) ;
  lcd.print ("Reloj") ;
  if (segundero<9) {
    lcd.setCursor (0,1) ;
    lcd.print ("0") ;
    lcd.setCursor  (1,1) ;
    lcd.print (segundero) ;
  } else {
  lcd.setCursor (0,1) ;
  lcd.print (segundero) ;
  }
  lcd.setCursor (2,1) ;
  lcd.print (":") ;
  if (minutero<9) {
    lcd.setCursor (3,1) ;
    lcd.print ("0") ;
    lcd.setCursor  (4,1) ;
    lcd.print (minutero) ;
  }else {
    lcd.setCursor (3,1) ;
    lcd.print (minutero) ;
    
  }
  lcd.setCursor (5,1) ;
  lcd.print (":") ;
  if (horero<9) {
    lcd.setCursor (6,1) ;
    lcd.print ("0") ;
    lcd.setCursor  (7,1) ;
    lcd.print (horero) ;    
  }else {
    lcd.setCursor (6,1) ;
    lcd.print (horero) ;
  }
  }
