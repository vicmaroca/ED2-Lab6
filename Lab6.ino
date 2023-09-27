#include <SPI.h>
#include <SD.h>

//Variables de selección y respuesta
int selector;
char ans, esc, ichar;
char input[50];

File myFile;

void setup() {
  // put your setup code here, to run once:
  //Inicializando la Comunicación Serial
  Serial.begin(115200);
  SPI.setModule(0);

  //Indicating that we are initializing and selecting the slave select
  Serial.println("Inicializando la tarjeta SD...");
  pinMode(PA_3, OUTPUT);

  //If the initalization failed
  if(!SD.begin(PA_3)) {
    Serial.println("Inicialización fallida!");
    return;
  }

  Serial.println("Inicialización completa.");
}

void loop() {
  // put your main code here, to run repeatedly: 
  //Desplegando las opciones para seleccionar las imagenes
  Serial.println("\n");
  Serial.println("Bienvenido al menú!");
  Serial.println("Presiona 1 para desplegar la imagen 1");
  Serial.println("Presiona 2 para desplegar la imagen 2");
  Serial.println("Presiona 3 para desplegar la imagen 3");
  Serial.println("Presiona 4 para crear una imagen");
  Serial.println("Presiona 5 para abrir la imagen creada");

  selector = 0;

  //Loop to get the answer from the user
  while(selector == 0) {
    ans = Serial.read(); //Reading the user response
  //if else block to indicate the selected image
    if (ans == '1') 
      selector = 1;
    else if (ans == '2') 
      selector = 2;
    else if (ans == '3') 
      selector = 3;
   else if (ans == '4')
      selector = 4;
   else if (ans == '5')
      selector = 5;
   else
      selector = 0;
  }

  if(ans == '1') {
    myFile = SD.open("nikeArt.txt"); //Opening the file 

    //If the file is opened
    if(myFile) {
      Serial.println("\n \t \t Nike Art");

      //Until there exist information of the available file
      while (myFile.available()) {
        //Writing in the terminal the content of the file
        Serial.write(myFile.read()); 
      }
      //Closing the file
      myFile.close();
    }
    else {
      Serial.println("¡Este archivo no pudo abrirse!");
    }
    selector = 0;   
  }
    else  if(ans == '2') {
    myFile = SD.open("test2.txt"); //Opening the file 

    //If the file is opened
    if(myFile) {
      Serial.println("\n \t \t Adidas Art");

      //Until there exist information of the available file
      while (myFile.available()) {
        //Writing in the terminal the content of the file
        Serial.write(myFile.read()); 
      }
      //Closing the file
      myFile.close();
    }
    else {
      Serial.println("¡Este archivo no pudo abrirse!");
    }
    selector = 0; 
    }
    else if(ans == '3') {
    myFile = SD.open("test3.txt"); //Opening the file 

    //If the file is opened
    if(myFile) {
      Serial.println("\n \t \t Spiderman Art");

      //Until there exist information of the available file
      while (myFile.available()) {
        //Writing in the terminal the content of the file
        Serial.write(myFile.read()); 
      }
      //Closing the file
      myFile.close();
    }
    else {
      Serial.println("¡Este archivo no pudo abrirse!");
    }
    selector = 0;      
  }

  else if(ans == '4') {

    SD.remove("ImageC.txt");

    myFile = SD.open("ImageC.txt", FILE_WRITE); //Opening the file 

    //If the file is available
    if(myFile) {
      Serial.println("\nWrite characters to create your image, press \"e\" to close the document when you have finished");

    int i = 0;
    //e is the scape character. While blocks reads the entered characters.
    while (ichar != 'e') {
      if(Serial.available() > 0){
          ichar = Serial.read();
          Serial.println(ichar);
          delay(200);

            if (ichar != 'e') {
              input[i] = ichar;
              i++;
            }

          if (i >= 50)
              break;
      }
    }
      myFile.println(input);
 
      //Closing the file
      myFile.close();
    }
    else {
      Serial.println("The file could created!");
    }
    selector = 0;   
  }

 else if(ans == '5') {
    myFile = SD.open("ImageC.txt"); //Opening the file 

    //If the file is opened
    if(myFile) {
      Serial.println("\n \t \t Image Created");

      //Until there exist information of the available file
      while (myFile.available()) {
        //Writing in the terminal the content of the file
        Serial.write(myFile.read()); 
      }
      //Closing the file
      myFile.close();
    }
    else {
      Serial.println("The file could not be opened!");
    }
    selector = 0;      
  }

  
}
