// Bibliotecas
  #include <esp_system.h>
  #include <M5StickCPlus.h>

  #include "Variables.h"
  #include "LCD.h"

void setup() {
  M5.begin(); 	                                                                        // Inicializa todas las funciones del Modulo

// IO Config
  pinMode(PIN_LED, OUTPUT);                                                             // Configuramos el pin como salida
  digitalWrite(PIN_LED, HIGH);                                                          // Apagamos el LED al inicio
// Lcd
  LcdConfig();
  LcdMarco(Text01);
  LcdTexto_01(3, 2); 
}

void loop() {
  M5.update();                                                                          // Permite leer el estado de los pulsadores
  tiempoActual = millis();

if (M5.BtnB.pressedFor(2000)) {                                                       // Funcion Reset
  ESP.restart();
  }

if (AnimacionOn == 1){
  switch (Menu_01) {                                                                  // Controla la animacion de cuenta atras
    case 1:                                                                           // Animacion "5"
      if (tiempoActual - ultimoTiempoActualizado >= intervaloActualizacion) {
      ultimoTiempoActualizado = tiempoActual; 
      LcdMarco(Text01);
      LcdTexto_02("5", 7, 50);
      Menu_01 = 2;
      }
      break;
    case 2:                                                                           // Animacion "4"
      if (tiempoActual - ultimoTiempoActualizado >= intervaloActualizacion) {
      ultimoTiempoActualizado = tiempoActual; 
      LcdMarco(Text01);
      LcdTexto_02("4", 7, 50);
      Menu_01 = 3;
      }
      break;
    case 3:                                                                           // Animacion "3"
      if (tiempoActual - ultimoTiempoActualizado >= intervaloActualizacion) {
      ultimoTiempoActualizado = tiempoActual;
      LcdMarco(Text01);
      LcdTexto_02("3", 7, 50);
      Menu_01 = 4;
      }
      break;
    case 4:                                                                           // Animacion "2"
      if (tiempoActual - ultimoTiempoActualizado >= intervaloActualizacion) {
      ultimoTiempoActualizado = tiempoActual;
      LcdMarco(Text01);
      LcdTexto_02("2", 7, 50);
      Menu_01 = 5; 
      }
      break;
    case 5:                                                                           // Animacion "1"
      if (tiempoActual - ultimoTiempoActualizado >= intervaloActualizacion) {
      ultimoTiempoActualizado = tiempoActual;
      LcdMarco(Text01);
      LcdTexto_02("1", 7, 50);
      Menu_01 = 6; 
      }
      break;
    case 6:                                                                           // Animacion "Start"
      if (tiempoActual - ultimoTiempoActualizado >= intervaloActualizacion) {
      ultimoTiempoActualizado = tiempoActual;
      LcdMarco(Text01);
      LcdTexto_02("Start", 4, 10);
      Menu_01 = 7; 
      }
      break;
    case 7:                                                                           // Animacion "Inicio"
      if (tiempoActual - ultimoTiempoActualizado >= intervaloActualizacion) {
      ultimoTiempoActualizado = tiempoActual;
      LcdMarco(Text01);
      LcdTexto_03(Tiempo);
      LcdTexto_04();
      AnimacionOn = 0;
      BlinkOn = 1;
      BotonesOn = 1;
      Menu_01 = 10;
      } 
      break;
    default:                                                                          // Espera para comenzar la animacion
      if (M5.BtnA.pressedFor(1000)) { 
        if (millis() - tiempo_anterior_01 >= INTERVALO_01) {
        tiempo_anterior_01 += INTERVALO_01;
        Menu_01 = 1; 
        }
      }     
      break;
  }
}
if (BlinkOn == 01) {                                                                    // Funcion Blink
  if (millis() - tiempo_anterior_02 >= INTERVALO_02) {                                  // Verificamos si ha pasado el tiempo suficiente para cambiar el estado del LED
    tiempo_anterior_02 += INTERVALO_02;
    estado_led = !estado_led;
    digitalWrite(PIN_LED, estado_led);

    }
  } 
if (BotonesOn == 1){                                                                    // Funciones vinculadas a los botones
  if (M5.BtnA.wasReleased()) {                                                          // Funcion "+"   
    incrementar(INTERVALO_02);                                                          // Funcion incremental
    Tiempo = INTERVALO_02;                                                              // Variable para mostrar
    LcdMarco(Text01);
    LcdTexto_03(Tiempo);
    LcdTexto_04();
    }
  if (M5.BtnB.wasReleased()) {                                                          // Funcion "-"
    decrementar(INTERVALO_02);                                                          // Funcion Decremental
    Tiempo = INTERVALO_02;                                                              // Variable para mostrar                
    LcdMarco(Text01);
    LcdTexto_03(Tiempo);
    LcdTexto_04();
    } 
  }
}