/*SISTEMAS MICROPROCESADOS
 * NOMBRE: Kevin Enriquez
 * Docente: Ing. Paul Rosero
 * Tema: Recepcion de datos
 * Deber:Realizar una validación de placa de vehículo donde indique: *La provincia *si ha registrado los 4 dígitos necesarios. *si no tiene números en la parte de las letras
 */


String placa ; //Variable donde se alojará los datos ingresados de la placa
String cadenaLetras ; //Cadena de datos donde almacena las letras de la placa
String cadenaNumeros ; //Cadena de datos donde se almacena los numeros de la placa
char primerLetra ; //Variable donde se realiza la validacion del canton de donde es la placa
char segundaLetra ;
char tercerLetra ;
char primerNumero ; // Variable donde se realiza la validadcion de los numeros de laplca
char segundoNumero ;
char tercerNumero ;
char cuartoNumero ;
char guion ; //Variable que almacena el dato del guio

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600) ; //Velocidad de transmision de los datos

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available ()>0){ //Condicion para leer los datos 
    placa=Serial.readString () ; //Comando para ingresar los datos de la placa
    guion=placa.charAt (3) ; //Declaracion de la variable del guion para obtener su dato en la placa
    if (guion==45){ //Condicion del guion para que valide los parametros de la placa. Este valor se tomó en cuenta del codigo ASCII
      Serial.print ("Numero de placa ingresado: ") ;
      Serial.println (placa) ; //Comando para imprimir los datos ingresados de la placa
      cadenaLetras=placa.substring (0,placa.indexOf("-",0)) ; //Comando para separa las letras del guion y de los numeros
      cadenaNumeros=placa.substring (placa.indexOf ("-")+1, placa.length ()) ; //Comando para separa los numeros del guion y de las letras
      primerLetra=cadenaLetras.charAt (0) ; //Asignacion del valor de la variable "primerLetra"
      segundaLetra=cadenaLetras.charAt (1) ; //Asignacion del valor de la variable "segundaLetra"
      tercerLetra=cadenaLetras.charAt (2) ;
      primerNumero=cadenaNumeros.charAt (0) ;
      if (primerLetra>=65 && primerLetra<=90 && cadenaNumeros.length ()==4){ //Condiciones para que valide los parametros de la placa. La variable "primeraLetra" debe estar entre los valores 65 y 122 que son el estandar del codigo ASCII , y la segunda condicion establece que la cadena de los numeros debeser igual a 3
        provincia (primerLetra) ;
      }
      else if (cadenaNumeros.length ()!=4  ){ //Condicion que identifica si hay mas de 4 numero en la placa
        Serial.println ("Ingrese los 4 numeros de su placa ") ;
      }
      else if(primerLetra>=95 && primerLetra <=120){ //Condicion para validar solo letras mayusculas. Se tomó como referencia al codigo ASCII
        Serial.println ("Ingrese las letras en mayusculas") ;
      }
      else if (primerLetra>=0 && primerLetra <=64){ //Condicion para validar solo letras.
        Serial.println("Ingrese solo letras en los primeros digitos") ;
      }
    }else {
    Serial.println ("Ingrese adecuadamente el guion") ;
    Serial.print ("Numero de placa ingresado: ") ;
    Serial.println (placa) ;    
  }
  }

}



void provincia (char letra){
  switch (letra){ //Lista del menu con respecto a las provincias que equivalen a la primera letra de la placa
    case 65 :
    Serial.println ("La placa ingresada corresponde a la provincia de Azuay") ; //
    break ;
    case 66 :
    Serial.println ("La placa ingresada corresponde a la provincia de Bolivar") ;
    break ;
    case 67 :
    Serial.println ("La placa ingresada corresponde a la provincia de Carchi") ;
    break ;
    case 69 :
    Serial.println ("La placa ingresada corresponde a la provincia de Esmeraldas") ;
    break ;
    case 71 :
    Serial.println ("La placa ingresada corresponde a la provincia de Guayas") ;
    break ;
    case 72 :
    Serial.println ("La placa ingresada corresponde a la provincia de Chimborazo") ;
    break ;
    case 73 :
    Serial.println ("La placa ingresada corresponde a la provincia de Imbabura") ;
    break ;
    case 74 :
    Serial.println ("La placa ingresada corresponde a la provincia de Santo Domingo de los Tshachilas") ;
    break ;
    case 75 :
    Serial.println ("La placa ingresada corresponde a la provincia de Sucumbios") ;
    break ;
    case 76 :
    Serial.println ("La placa ingresada corresponde a la provincia de Loja") ;
    break ;
    case 77 :
    Serial.println ("La placa ingresada corresponde a la provincia de Manabi") ;
    break ;
    case 78 :
    Serial.println ("La placa ingresada corresponde a la provincia de Napo") ;
    break ;
    case 79 :
    Serial.println ("La placa ingresada corresponde a la provincia de El Oro") ;
    break ;
    case 80 :
    Serial.println ("La placa ingresada corresponde a la provincia de Pichincha") ;
    break ;
    case 81 :
    Serial.println ("La placa ingresada corresponde a la provincia de Orellana") ;
    break ;
    case 82 :
    Serial.println ("La placa ingresada corresponde a la provincia de Los Rios") ;
    break ;
    case 83 :
    Serial.println ("La placa ingresada corresponde a la provincia de Pastaza") ;
    break ;
    case 84 :
    Serial.println ("La placa ingresada corresponde a la provincia de Tungurahua") ;
    break ;
    case 85 :
    Serial.println ("La placa ingresada corresponde a la provincia de Cañar") ;
    break ;
    case 86 :
    Serial.println ("La placa ingresada corresponde a la provincia de Morona Santiago") ;
    break ;
    case 87 :
    Serial.println ("La placa ingresada corresponde a la provincia de Galapagos") ;
    break ;
    case 88 :
    Serial.println ("La placa ingresada corresponde a la provincia de Cotopaxi") ;
    break ;
    case 89 :
    Serial.println ("La placa ingresada corresponde a la provincia de Santa Elena") ; 
    break ;
    case 90 :
    Serial.println ("La placa ingresada corresponde a la provincia de Zamora Chinchipe") ;
    break ;
  }  
}
