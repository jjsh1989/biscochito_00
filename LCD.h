void LcdConfig(){                                                           
  // Lcd Config
    M5.Lcd.setRotation(0);                                      
}

void LcdMarco(String Titulo){                                                           // dibuja los marcos ademas de mostrar el titulo del programa y el mensaje para reinicio
  M5.Lcd.setTextSize(2);
  M5.Lcd.fillScreen(BLACK);
  M5.lcd.drawLine(1  , 1  , 135, 1  , WHITE);                                           // Marco superior 1 de 2
  M5.lcd.drawLine(1  , 2  , 135, 2  , WHITE);                                           // Marco superior 2 de 2
  M5.Lcd.setCursor(3, 5);
  M5.Lcd.println(Titulo);
  M5.lcd.drawLine(1  , 20 , 135, 20 , WHITE);                                           // Barra intermedia 1 - 1 de 2
  M5.lcd.drawLine(1  , 21 , 135, 21 , WHITE);                                           // Barra intermedia 1 - 2 de 2
  M5.Lcd.setTextSize(1);
  M5.Lcd.setCursor(15, 24);
  M5.Lcd.println("Manten Pulsado 'B'");
  M5.Lcd.setCursor(15, 31);
  M5.Lcd.println("para reiniciar");
  M5.lcd.drawLine(1  , 40 , 135, 40 , WHITE);                                           // Barra intermedia 2 - 1 de 2
  M5.lcd.drawLine(1  , 41 , 135, 41 , WHITE);                                           // Barra intermedia 2 - 2 de 2
  // Texto
  M5.lcd.drawLine(1  , 236, 133, 236, WHITE);                                           // Marco inferior 1 de 2 
  M5.lcd.drawLine(1  , 237, 133, 237, WHITE);                                           // Marco inferior 2 de 2
  M5.lcd.drawLine(1  , 1  , 1  , 237, WHITE);                                           // Marco Izq 1 de 2
  M5.lcd.drawLine(2  , 1  , 2  , 237, WHITE);                                           // Marco Izq 2 de 2
  M5.lcd.drawLine(133, 1  , 133, 237, WHITE);                                           // Marco Drch 1 de 2
  M5.lcd.drawLine(134, 1  , 134, 237, WHITE);                                           // Marco Drch 2 de 2
}

void LcdTexto_01(int X, int Size){                                                      // Muestra mensaje para dar inicio a la animacion de cuenta atras
  M5.Lcd.setTextSize(Size);
  M5.Lcd.setCursor(X, 43);
  M5.Lcd.println(" Presionar");
  M5.Lcd.setCursor(X, 59);
  M5.Lcd.println(" Boton 'A'");
  M5.Lcd.setCursor(X, 75);
  M5.Lcd.println("  por 2s  ");
  M5.Lcd.setCursor(X, 91);
  M5.Lcd.println("   para   ");
  M5.Lcd.setCursor(X, 107);
  M5.Lcd.println(" continuar");
}

void LcdTexto_02(String Texto, int Size, int X){                                        // Muestra el mensaje de cada animacion 
  M5.Lcd.setTextSize(Size);
  M5.Lcd.setCursor(X, 100);
  M5.Lcd.println(Texto);
}

void LcdTexto_03(float Tiempo){                                                         // Muestra el intervalo actual para el parpadeo
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(7, 71);
  M5.Lcd.println("T. Actual:");
  M5.Lcd.setTextSize(4);
  M5.Lcd.setCursor(8, 87);
  M5.Lcd.print(Tiempo/ 1000);
  M5.Lcd.println("s");
}

void LcdTexto_04(){                                                                     // Complemento de LcdMArco();
  M5.lcd.drawLine(1  , 143, 133, 143, WHITE);                                           // Marco inferior 1 - 1 de 2 
  M5.lcd.drawLine(1  , 144, 133, 144, WHITE);                                           // Marco inferior 1 - 2 de 2
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(16, 147);
  M5.Lcd.println("Boton A:");
  M5.Lcd.setTextSize(3);
  M5.Lcd.setCursor(15, 163);
  M5.Lcd.println("+0,25s");
  M5.lcd.drawLine(1  , 189, 133, 189, WHITE);                                           // Marco inferior 2 - 1 de 2 
  M5.lcd.drawLine(1  , 190, 133, 190, WHITE);                                           // Marco inferior 2 - 2 de 2
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(16, 193);
  M5.Lcd.println("Boton B:");
  M5.Lcd.setTextSize(3);
  M5.Lcd.setCursor(15, 210);
  M5.Lcd.println("-0,25s");
}