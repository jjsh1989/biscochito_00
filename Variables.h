// IO Config
  const int PIN_LED = 10;                                                               // Pin del LED "HIHG = OFF"
  const int Btn_A = 39;                                                                 // Pin Boton A "M5"
  const int Btn_B = 37;                                                                 // Pin Boton B "Lateral Izquierdo"

// Variables
  bool estado_led = HIGH;                                                               // Estado inicial del LED
  float Tiempo;                                                                         // Almacena el intervalo actual para poder ser mostrado en la pantalla
  int TiempoMinimo = 0;                                                                 // Limita el minimo que puede tomar el Intervalo del Blink
  int TiempoMaximo = 5000;                                                              // Limita el maximo que puede tomar el intervalo del Blink

  int incrementar (int &Variable) {                                                     // Funcion incremental con limitador maximo de variable
    Variable = Variable + 250;
    if (Variable > TiempoMaximo) Variable = TiempoMaximo;
    return Variable;
    }

  int decrementar (int &Variable) {                                                     // Funcion decremental con limitador minimo de variable
    Variable = Variable - 250;
    if (Variable < TiempoMinimo) Variable = TiempoMinimo;
    return Variable;
    }

// Mensajes de Texto 
  String Text01 = "-Led Blink-";
  
// Retardo para empezar 
  unsigned long tiempo_anterior_01;                                                     // Tiempo anterior para el primer Temporizador
  const unsigned long INTERVALO_01 = 1000;                                              // Intervalo de tiempo (en ms) 

// Temporizador para el parpadeo
  int tiempo_anterior_02;                                                               // Tiempo anterior para el segundo Temporizador
  int INTERVALO_02;                                                                     // Intervalo de tiempo (en ms)

// Animacion cuenta atras
  unsigned long tiempoActual;                                                           // Tiempo anterior para el Temporizador con retardo
  unsigned long ultimoTiempoActualizado;                                                // ultimo intervalo actualizado           
  const unsigned long intervaloActualizacion = 1000;                                    // Actualizar cada segundo

// Menus
  int Menu_01 = 9;                                                                      // Variable para menu animacion cuenta atras "switch"

// Memorias
  int AnimacionOn = 1;                                                                  // desabilita la animacion para dejar paso a la funcion Blink
  int BlinkOn;                                                                          // desabilita o habilita la funcion para Blink
  int BotonesOn;                                                                        // desabilita o habilita las funciones de los botones
