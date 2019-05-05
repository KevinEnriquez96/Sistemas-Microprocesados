//Sistemas Microprecesados
//Nombre: Kevin Enriquez
//Docente: Paul Rosero
//Tema: Puertos de Entrada
//Realice un programa que mediante dos pulsadores (operando 1 y operando 2) sumen su valor de veces (hasta 25 cada uno)que han sido presionados. Dicho valor se mostrará en display multiplexados al presionar un tercer pulsador.
int btn1 = 2 ; //Boton que inicia el contador 1
int btn2 = 3 ;//Boton que inicia el contador 2
int btn3 = 4 ; //Boton que da la sumatorio de los dos contadores
int contador1= 0 ; // Variable que almacena los estados presionados por el contador 1
int contador2 = 0 ; // Variable que almacena los estados presionados por el contador 2
int estadoAnterior1= 0 ; //Variable que permite corregir los rebotes realizados por el boton 1
int estadoAnterior2 = 0; //Variable que permite corregir los rebotes realizados por el boton 2
int unidad ; //Variable que permite almacenar las unidades de la sumatoria 
int decena ;//Variable que permite almacenar las decenas de la sumatoria 
int estadoA=5 ; //Pin de salida que representa la primera posicion del numero binario 
int estadoB=6 ; //Pin de salida que representa la segunda posicion del numero binario 
int estadoC=7 ; //Pin de salida que representa la tercera posicion del numero binario 
int estadoD=8 ; //Pin de salida que representa la cuarta posicion del numero binario 
int displayUnidad=9 ; //Pin de salida que permite encender el display de las unidades de la sumatoria
int displayDecena=10 ; //Pin de salida que permite encender el display de las decenas de la sumatoria



 void contador (int estado){ //Metodo que establece los estados del 0 al 9 en binario, 
    switch (estado) {
      case 0 : //Representacion del numero 0 en binario
      digitalWrite (estadoA, LOW) ;
      digitalWrite (estadoB, LOW) ;
      digitalWrite (estadoC, LOW) ;
      digitalWrite (estadoD, LOW) ;
      break ;
      case 1 : //Representacion del numero 1 en binario
      digitalWrite (estadoA, HIGH) ;
      digitalWrite (estadoB, LOW) ;
      digitalWrite (estadoC, LOW) ;
      digitalWrite (estadoD, LOW) ;
      break ;
            case 2 : //Representacion del numero 2 en binario
      digitalWrite (estadoA, LOW) ;
      digitalWrite (estadoB, HIGH) ;
      digitalWrite (estadoC, LOW) ;
      digitalWrite (estadoD, LOW) ;
      break ;
            case 3: //Representacion del numero 3 en binario
      digitalWrite (estadoA, HIGH) ;
      digitalWrite (estadoB, HIGH) ;
      digitalWrite (estadoC, LOW) ;
      digitalWrite (estadoD, LOW) ;
      break ;
            case 4 : //Representacion del numero 4 en binario
      digitalWrite (estadoA, LOW) ;
      digitalWrite (estadoB, LOW) ;
      digitalWrite (estadoC, HIGH) ;
      digitalWrite (estadoD, LOW) ;
      break ;
            case 5 : //Representacion del numero 5 en binario
      digitalWrite (estadoA, HIGH) ;
      digitalWrite (estadoB, LOW) ;
      digitalWrite (estadoC, HIGH) ;
      digitalWrite (estadoD, LOW) ;
      break ;
             case 6 : //Representacion del numero 6 en binario
      digitalWrite (estadoA, LOW) ;
      digitalWrite (estadoB, HIGH) ;
      digitalWrite (estadoC, HIGH) ;
      digitalWrite (estadoD, LOW) ;
      break ;
               case 7: //Representacion del numero 7 en binario
      digitalWrite (estadoA, HIGH) ;
      digitalWrite (estadoB, HIGH) ;
      digitalWrite (estadoC, HIGH) ;
      digitalWrite (estadoD, LOW) ;
      break ;
               case 8 : //Representacion del numero 8 en binario
      digitalWrite (estadoA, LOW) ;
      digitalWrite (estadoB, LOW) ;
      digitalWrite (estadoC, LOW) ;
      digitalWrite (estadoD, HIGH) ;
      break ;
           case 9 : //Representacion del numero 9 en binario
      digitalWrite (estadoA, HIGH) ;
      digitalWrite (estadoB, LOW) ;
      digitalWrite (estadoC, LOW) ;
      digitalWrite (estadoD, HIGH) ;
      break ;
}
}


void setup() {
  // put your setup code here, to run once:
  pinMode (2, INPUT) ; //Pin de entrada para el pusador 1
  pinMode (3, INPUT) ; //Pin de entrada para el pusador 2
  pinMode (4, INPUT) ; //Pin de entrada para el pusador 3
  pinMode (5, OUTPUT) ; //Pin de salida que representa el primer posicion del numero binario
  pinMode (6, OUTPUT) ; //Pin de salida que representa la segunda posicion del numero binario
  pinMode (7, OUTPUT) ; //Pin de salida que representa la tercera posicion del numero binario
  pinMode (8, OUTPUT) ; //Pin de salida que representa la cuarta posicion del numero binario
  pinMode (9, OUTPUT) ; //Pin de salida para el display que representa las unidades de la sumatoria
  pinMode (10, OUTPUT) ; //Pin de salida para el display que representa las decenas de la sumatoria
  Serial.begin(9600) ; // Establecimiento para la transmisión de los datos
}

void loop() {
 
          int estado=digitalRead(btn1) ; 
          if (estado!=estadoAnterior1){ //Activación del primer pulsador
          if(estado==HIGH){  //Condicion para eliminar los rebotes
              contador1++;
              Serial.println(contador1) ; //Parámetro que permite imprimir el numero de las pulsaciones realizados por el pulsador 1 a través del terminal
            }
          }
          estadoAnterior1=estado ;
          if(contador1==26){ //Condición del contador, si este es mayor a 25 este se reinicia a 0
          contador1= 0 ;
           }
          int estado1=digitalRead(btn2) ;
          if (estado1!=estadoAnterior2){ //Activación del segundo pulsador
          if(estado1==HIGH){  //Cobdicion para eliminar los rebotes
              contador2++;
              Serial.println(contador2) ; //Parámetro que permite imprimir el numero de las pulsaciones realizados por el pulsador 2 a través del terminal
            }
          }
           estadoAnterior2=estado1 ;
           if(contador2==26){ //Condición del contador, si este es mayor a 25 este se reinicia a 0
            contador2= 0 ;
           }
           
           if (digitalRead(btn3)==HIGH){ //Activacion del tercer pulsador 
            delay (300) ;;
              int suma  ;
            suma=contador1+contador2 ; //Sumataria de los pulsos realizados
            unidad= suma % 10 ; //Condición para conocer el valor de la unidad de la sumatoria
            decena= suma / 10 ; //Condición para conocer el valor de la decena de la sumatoria
            Serial.println(suma) ; //Parámetro que permite imprimir la sumatoria total de las pulsaciones realizadas a través del terminal
           digitalWrite (displayDecena,HIGH) ;
           digitalWrite (displayUnidad,LOW) ;
           contador (decena) ;
           delay (25) ;
           digitalWrite (displayDecena, LOW) ;
           digitalWrite (displayUnidad, HIGH) ;
           contador (unidad) ;
           delay (25) ;
   }              
   

  }
