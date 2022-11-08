//www.elegoo.com
//2016.12.8

// Define Pins
#define BLUE 3 //-------------------------EDITADO POR DIANGELOCURAS-----------------------------// #definir ROJO 6: rojo y 6 será lo mismo
#define GREEN 5 // Esta sección es muy simple, declaramos los PIN PWM que estamos usando (numeros de entradas del PIN) como BLUE, GREEN RED, es decir, RED = 6 
#define RED 6 // después de asignar el pin 6 a RED con #define podemos usarlo para declarar nuestros puertos en el void setup el cual solo se ejecuta una vez al comenzar el programa

void setup()
{
pinMode(RED, OUTPUT); // declaramos los pines que vamos a usar podríamos poner 6 en vez de *RED* pero seria mas complicado usarlo así ya que te puedes confundir con los numeros 
pinMode(GREEN, OUTPUT); //  también será OUTPUT (salida) porque en vez de recibir información le enviaremos (POR medio de pwn) si fuera un sensor para obtener informacion sería INPUT (lo veremos mas adelante)
pinMode(BLUE, OUTPUT);
digitalWrite(RED, HIGH);  // Declaramos que al iniciar el rojo estará encendido y los que estan en low apagados de todas maneras tenemos el loop para cambiar colores así que no quedará en rojo   
digitalWrite(GREEN, LOW);
digitalWrite(BLUE, LOW);
}

// define variables
int redValue;       // VARIABLES EL CUAL GUARDARAN EL PWM EN NUMEROS ENTEROS, PUEDE SER DE 0 A 255 *int es usado para guardar numeros enteros (no decimales)
int greenValue;    // Y luego le asignamos un nombre a la variable, en este caso esta en ingles Valor del Verde
int blueValue;

// main loop
void loop()
{
#define delayTime 10 // fading time between colors  // el tiempo en que tardara en cambiar colores, tambien lo estan definiendo para que sea mas facil

redValue = 255; // choose a value between 1 and 255 to change the color.
greenValue = 0; // Aqui es donde le asignamos los numeros que queramos a las variables, es decir, si queremos otro color cambiamos numeros aqui de 0 a 255
blueValue = 0;

// this is unnecessary as we've either turned on RED in SETUP
// or in the previous loop ... regardless, this turns RED off
// analogWrite(RED, 0);
// delay(1000);

for(int i = 0; i < 255; i += 1) // fades out red bring green full when i=255    // Tendrá un efecto de desvanecimiento como en el video ya que sumamos continuamente con for LOOP
{
redValue -= 1;
greenValue += 1;
// The following was reversed, counting in the wrong directions
// analogWrite(RED, 255 - redValue);
// analogWrite(GREEN, 255 - greenValue);
analogWrite(RED, redValue);
analogWrite(GREEN, greenValue);
delay(delayTime);
// La lógica es así, creamos una variable llamada i el cual es igual a 0 dentro de for () luego de la coma tenemos la condicion y es mientras la i sea menor que 255 , i va a ser sumado con el 1 
//y adentro de los corchetes se ejecutara el codigo mientras esta condicion sea verdadera 
//TODOS LOS DEMAS FOR() SON PARECIDOS PERO PARA CADA COLOR (CADA PIN GREEN, RED, BLUE) ASI CREA EL EFECTO DEL VIDEO
//RECUERDEN QUE EL CAMBIO DE COLORES ESTA SIENDO CONTROLADO POR LOS LOOPS O ESTAS CONDICIONALES SI QUIEREN TENER CONTROL BORREN TODOS LOS FOR  Y ESTABLEZCAN LOS NUMEROS MANUALMENTE
//ARRIBA EN REDVALUE, GREENVALUE, BLUEVALUE YA QUE SI LO HACEN SIN BORRAR LOS FOR LOOPS NO TENDRA EFECTO YA QUE SE CAMBIARA RAPIDAMENTE POR LAS VARIABLES FOR
//visita esto si necesitas mas informacion de los bucle FOR() https://www.arduino.cc/reference/es/ traducelo al español si sale ne ingles o busca online
}

redValue = 0;
greenValue = 255;
blueValue = 0;

for(int i = 0; i < 255; i += 1) // fades out green bring blue full when i=255
{
greenValue -= 1;
blueValue += 1;
// The following was reversed, counting in the wrong directions
// analogWrite(GREEN, 255 - greenValue);
// analogWrite(BLUE, 255 - blueValue);
analogWrite(GREEN, greenValue);
analogWrite(BLUE, blueValue);
delay(delayTime);
}

redValue = 0;
greenValue = 0;
blueValue = 255;

for(int i = 0; i < 255; i += 1) // fades out blue bring red full when i=255
{
// The following code has been rearranged to match the other two similar sections
blueValue -= 1;
redValue += 1;
// The following was reversed, counting in the wrong directions
// analogWrite(BLUE, 255 - blueValue);
// analogWrite(RED, 255 - redValue);
analogWrite(BLUE, blueValue);
analogWrite(RED, redValue);
delay(delayTime);
}
}

