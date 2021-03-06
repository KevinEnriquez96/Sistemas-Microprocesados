/*Nombre:Kevin Enriquez
 * Docente: Ing. PAul Rosero
 * Tema: Comunicacion Serial
 * Tarea:Valide la cédula ecuatoriana que se ingresa por comunicación serial con el Formato. 100124578-9 
 * 
 */



String cedula ; //Cadena que almacena los datos de la cedula
String D1 ; //Variable que almacena el primer digito de la cedula
String D2 ;//Variable que almacena el segundo digito de la cedula
String D3 ;//Variable que almacena el tercer digito de la cedula
String D4 ;//Variable que almacena el cuarto digito de la cedula
String D5 ;//Variable que almacena el quinto digito de la cedula
String D6 ;//Variable que almacena el sexto digito de la cedula
String D7 ;//Variable que almacena el septimo digito de la cedula
String D8 ;//Variable que almacena el octavo digito de la cedula
String D9 ;//Variable que almacena el noveno digito de la cedula
String guion ; //Variable que almacena el guion de la cedula
String D10 ; //Variable que almacena el decimo digito de la cedula
int suma ; //Variable que almacena los dos primero digitos de la cedula e identifica la provincia que corresponde la cedula
int sumaImpares ; //Variable que almacena los numeros en las posiciones impares de la cedula
int sumaPares ;//Variable que almacena los numeros en las posiciones pares de la cedula
int decena ; //Variable que almacena las decenas de la suma de los dos primeros digitos de la cedula
int digito1; //Variable que almacena el primer digito de la cedula en tipo entero
int digito2;//Variable que almacena el segundo digito de la cedula en tipo entero
int digito3;//Variable que almacena el tercerr digito de la cedula en tipo entero
int digito4;//Variable que almacena el cuarto digito de la cedula en tipo entero
int digito5;//Variable que almacena el quinto digito de la cedula en tipo entero
int digito6;//Variable que almacena el sexto digito de la cedula en tipo entero
int digito7;//Variable que almacena el septimo digito de la cedula en tipo entero
int digito8;//Variable que almacena el octavo digito de la cedula en tipo entero
int digito9 ;//Variable que almacena el noveno digito de la cedula en tipo entero
int digito10;//Variable que almacena el decimo digito de la cedula en tipo entero
  int sumaValidacion ; //Variable que almacena la suma de las posiciones pares e impares, y a su vez permite validar la cedula
  int numeroValidador ; //Variable que almacena el dato validador de la cedula
  int PosicionImpar1 ; //Variable que almacena la primera posicion impar la de cedula
  int PosicionImpar2 ;//Variable que almacena la segunda posicion impar la de cedula
  int PosicionImpar3 ;//Variable que almacena la tercera posicion impar la de cedula
  int PosicionImpar4 ;//Variable que almacena la cuarta posicion impar la de cedula
  int PosicionImpar5 ;//Variable que almacena la quinta posicion impar la de cedula
  int PosicionPar1 ;//Variable que almacena la primera posicion par la de cedula
  int PosicionPar2 ; //Variable que almacena la segunda posicion par la de cedula
  int PosicionPar3 ;//Variable que almacena la tercera posicion par la de cedula
  int PosicionPar4 ;//Variable que almacena la cuarta posicion par la de cedula

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600) ; //Esteblecimiento de la transmision de datos

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available () >0){
    cedula=Serial.readString () ;
    while ((cedula.length ()>11 || cedula.length ()<11) && cedula.charAt(9)!= ('-')){ //Parametros que debe tener la cedula ingresada para inciar para la validacion
      Serial.println ("Ingrese correctamente su numero de cedula") ;
      cedula=Serial.readString () ; //Comando que permite recibir los datos de la cedula
      delay (3000) ;
    }
    

        Serial.println ("La cedula ingresada es: ") ;
    Serial.println (cedula) ;//Permite que permite leer los datos ingresados en la Cadena Cedula
    D1=cedula.substring(0,1) ; //Variable que almacena el primer digito de la cedula en tipo String
    digito1=D1.toInt () ;//Variable que almacena el primer digito de la cedula en tipo Int
    D2=cedula.substring (1,2) ;//Variable que almacena el segundo digito de la cedula en tipo String
    digito2=D2.toInt () ;//Variable que almacena el segundo digito de la cedula en tipo Int
    D3=cedula.substring (2,3) ;//Variable que almacena el tercer digito de la cedula en tipo String
    digito3=D3.toInt ();//Variable que almacena el Tercer digito de la cedula en tipo Int
    D4=cedula.substring (3,4) ;//Variable que almacena el cuarto digito de la cedula en tipo String
    digito4=D4.toInt () ;//Variable que almacena el Cuarto digito de la cedula en tipo Int
    D5=cedula.substring (4,5) ;//Variable que almacena el quinto digito de la cedula en tipo String
    digito5=D5.toInt () ;//Variable que almacena el Quinto digito de la cedula en tipo Int
    D6=cedula.substring (5,6) ;//Variable que almacena el sexto digito de la cedula en tipo String
    digito6=D6.toInt () ;//Variable que almacena el Sexto digito de la cedula en tipo Int
    D7=cedula.substring (6,7) ;//Variable que almacena el septimo digito de la cedula en tipo String
    digito7=D7.toInt () ;//Variable que almacena el Septimo digito de la cedula en tipo Int
    D8=cedula.substring (7,8) ;//Variable que almacena el octavo digito de la cedula en tipo String
    digito8=D8.toInt () ;//Variable que almacena el Octavo digito de la cedula en tipo Int
    D9=cedula.charAt (8) ;//Variable que almacena el noveno digito de la cedula en tipo String
    digito9=D9.toInt () ;//Variable que almacena el noveo digito de la cedula en tipo Int
    D10=cedula.substring(10,11) ; //Variable que almacena el decimo digito de la cedula en tipo String
    digito10=D10.toInt () ;//Variable que almacena el decimo digito de la cedula en tipo Int
    decena=digito1*10 ; //Extraccion de las decenas de la suma realiza entre los primeros digitos de la cedula
    suma= decena+digito2 ; //Suma de los dos primero digitos
    Serial.print ("El codigo de provincia es: ") ;
    if (suma>0 && suma<24){ //Condicion para designar la provincia correspondiente de la cedula
      Serial.println ("El codigo de provincia es valido") ;
      provincia (suma) ; //Llamamiento del metodo Provincia. Este permite identificar la provincia que corresponde a la cedula
      validacionDigito (digito1,digito2,digito3,digito4,digito5,digito6,digito7,digito8,digito9,digito10) ; //Llamamiento del metodo ValidacionDigito. Esto permite saber si el ultimo digito de la cedula concuerda con numero validador de la cedula obtenido a traves de la sumatoria de las posiciones pares e impares.
    }else{
      Serial.print ("El codigo de provincia es invalido") ;   
  }
}
}



void provincia (int dato){ //Lista de provincias del Ecuador. Este metodo permite conocer, la provincia que corresponde a la cedula ingresada

  switch (dato){
    case 1:
    Serial.println ("La cedula corresponde a la provincia: Azuay") ;
    break;
    case 2:
    Serial.println ("La cedula corresponde a la provincia: Bolivar") ;
    break;
    case 3:
    Serial.println ("La cedula corresponde a la provincia: Cañzr") ;
    break;        
    case 4:
    Serial.println ("La cedula corresponde a la provincia: Carchi") ;
    break;
    case 5:
    Serial.println ("La cedula corresponde a la provincia: Cotopaxi") ;
    break;
    case 6:
    Serial.println ("La cedula corresponde a la provincia: Chimborazo") ;
    break;
    case 7:
    Serial.println ("La cedula corresponde a la provincia: El Oro") ;
    break;
    case 8:
    Serial.println ("La cedula corresponde a la provincia: Esmeraldas") ;
    break;
    case 9:
    Serial.println ("La cedula corresponde a la provincia: Guayas") ;
    break;
    case 10:
    Serial.println ("La cedula corresponde a la provincia: Imbabura") ;
    break;
    case 11:
    Serial.println ("La cedula corresponde a la provincia: Loja") ;
    break;
    case 12:
    Serial.println ("La cedula corresponde a la provincia: Los Rios") ;
    break;
    case 13:
    Serial.println ("La cedula corresponde a la provincia: Manabí") ;
    break;
    case 14:
    Serial.println ("La cedula corresponde a la provincia: Morona Santiago") ;
    break;
    case 15:
    Serial.println ("La cedula corresponde a la provincia: Napo") ;
    break;
    case 16:
    Serial.println ("La cedula corresponde a la provincia: Pastaza") ;
    break;
    case 17:
    Serial.println ("La cedula corresponde a la provincia: Pichincha") ;
    break;    
    case 18:
    Serial.println ("La cedula corresponde a la provincia: Tungurahua") ;
    break;
    case 19:
    Serial.println ("La cedula corresponde a la provincia: Zamora Chinchipe") ;
    break;
    case 20:
    Serial.println ("La cedula corresponde a la provincia: Galapagos") ;
    break;
    case 21:
    Serial.println ("La cedula corresponde a la provincia: Sucumbios") ;
    break;
    case 22:
    Serial.println ("La cedula corresponde a la provincia: Orellana") ;
    break;
    case 23:
    Serial.println ("La cedula corresponde a la provincia: Santo Domingo de los Tsachilas") ;
    break;
    case 24:
    Serial.println ("La cedula corresponde a la provincia: Santa Elena") ;
    break;
  
  }  
}

void validacionDigito (int dato1,int dato2,int dato3,int dato4,int dato5,int dato6,int dato7,int dato8,int dato9,int dato10){ //Metodo que realiza las operaciones con los digitos de las posiciones pares e impares
  //A las posiciones impares se multiplican por dos, y si el resultado es mayor a 9 se le resta 9.
  PosicionImpar1= 2*dato1 ;
  int numeroDecenas ;
  if (PosicionImpar1>9){
    PosicionImpar1=PosicionImpar1-9 ;
  }
  PosicionImpar2= 2*dato3 ;
   if (PosicionImpar2>9){
    PosicionImpar2=PosicionImpar2-9 ;
  }
  PosicionImpar3= 2*dato5 ;
   if (PosicionImpar3>9){
    PosicionImpar3=PosicionImpar3-9 ;
  }
  PosicionImpar4=2*dato7 ;
   if (PosicionImpar4>9){
    PosicionImpar4=PosicionImpar4-9 ;
  }
  PosicionImpar5=2*dato9 ;
   if (PosicionImpar5>9){
    PosicionImpar5=PosicionImpar5-9 ;
  }
  sumaImpares= PosicionImpar1 + PosicionImpar2 + PosicionImpar3+PosicionImpar4+PosicionImpar5 ; //Sumatoria de las posiciones impares, tomando en cuenta las condiciones planteadas
  sumaPares = dato2+dato4 +dato6 + dato8 ; //Para la sumtaria de las posiciones pares no se toma ninguna condicion
  sumaValidacion=sumaImpares+sumaPares ;
  numeroDecenas=sumaValidacion/10 ; //Se realiza la sumatoria de las posiciones pares e impares. Si el moduelo de esta es 0, el numero validador será 0, pero si este diferente a cero se toma la unidad de la suma y este será el numero validador
  if (sumaValidacion/10 == 0){ //Condicion para indicar si el modula de la sumatoria es 0.
    numeroValidador=0 ;
  } else{
    numeroValidador=10-(sumaValidacion-(numeroDecenas*10)); // Operacion para encontrar el numero validador cuando el modulo es diferente a 0
  }
  if (numeroValidador==dato10){ //Finalmente, si el numero validador es igual al ultimo digita de la cedula, esta sera valida, caso contrario será una cedula invalida.
    Serial.println ("El numero validador coincide con el de su cedula") ;
    Serial.println ("La cedula es valida")  ;
  } else {
    Serial.println ("El numero validador no coincide con el de su cedula") ;
    Serial.println ("Ingrese nuevamente su Numero de cedula") ;
  }
}
