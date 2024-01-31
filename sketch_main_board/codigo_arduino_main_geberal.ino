//+------------------------------------------+
//TITULO: PROGRAMACION PLACA PRINCIPAL IBIZA
//ENGINER: Braismp007
//FECHA-IN: 31/01/2024
//VERSION: Version_Ibiza_1.3101.24.A
//STATUS: IN DEVELOP - NO TESTING

//(CC) CubeBrain Labs - Open Source Code
//+------------------------------------------+

#include <Ultrasonic.h>

#define TRIGGER_PIN  7
#define ECHO_PIN     6

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

float ULTRASONIC_DATA; // Variable para almacenar la distancia del sensor de ultrasonidos

const int ZUMBADOR_PIN = 8; // Define el pin del zumbador
const int DISTANCIA_MINIMA = 3; // Define la distancia mínima para que el zumbador suene (en cm)

void setup() {
  Serial.begin(9600);
  pinMode(ZUMBADOR_PIN, OUTPUT); // Configura el pin del zumbador como salida
}

void loop() {
  float distancia = ultrasonic.read();
  ULTRASONIC_DATA = distancia; // Almacena la distancia en la variable ULTRASONIC_DATA
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if (distancia < DISTANCIA_MINIMA) {
    // Si la distancia es menor que la distancia mínima definida, haz que el zumbador suene intermitentemente
    zumbadorIntermitente();
  } else {
    // Si la distancia es mayor o igual a la distancia mínima, apaga el zumbador
    digitalWrite(ZUMBADOR_PIN, LOW);
  }

  delay(500);
}

void zumbadorIntermitente() {
  // Hace que el zumbador suene intermitentemente
  for (int i = 0; i < 3; i++) {
    digitalWrite(ZUMBADOR_PIN, HIGH); // Enciende el zumbador
    delay(200); // Espera 200 milisegundos
    digitalWrite(ZUMBADOR_PIN, LOW); // Apaga el zumbador
    delay(200); // Espera 200 milisegundos
  }
  delay(500); // Espera adicional para evitar sonido continuo
}
