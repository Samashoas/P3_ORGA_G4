#include <Servo.h>

int servoPin = 53;   // Primer servomotor
int servoPin2 = 52;  // Segundo servomotor
int servoPosInicial = 0; //Posicion inicial
int servoPosFinal = 90; //Posicion FInal
int buzzerPin 47; //Buzzer

// Primer sensor ultrasónico
int trigPin = 51; //Trig Pin
int echoPin = 50; //echoPin
int pingTravelTime; //variable para medir el tiempp

// Segundo sensor ultrasónico
int trigPin2 = 49; //Trig Pin
int echoPin2 = 48; //echo Pin
int pingTravelTime2; // variable para medir el tiempo del segundo servomotor
 //Inicializan ambos servomotores
Servo myServo;
Servo myServo2;

void setup() {
  myServo.attach(servoPin);
  myServo2.attach(servoPin2);
//Se abre consola
  Serial.begin(9600);
  //se definen los input y outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
  //Snesor 1
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pingTravelTime = pulseIn(echoPin, HIGH);
  Serial.print("Sensor 1: ");
  Serial.println(pingTravelTime);

  // Condicion donde si el tiempo detectado es menor a 5 segundos, coloca el motor a 90 grados
  if (pingTravelTime > 0 && pingTravelTime < 500) {
    myServo.write(servoPosFinal);
    delay(5000);
    myServo.write(servoPosInicial); 
  }

  //Sensor 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  pingTravelTime2 = pulseIn(echoPin2, HIGH);
  Serial.print("Sensor 2: ");
  Serial.println(pingTravelTime2);

// Condicion donde si el tiempo detectado es menor a 5 segundos, coloca el motor a 90 grados
  if (pingTravelTime2 > 0 && pingTravelTime2 < 500) {
    myServo2.write(servoPosFinal); 
    delay(5000);                   
    myServo2.write(servoPosInicial); 
  }

  delay(100); // Un delay para hacer cada lectura un poco mas lenta y evitar problemas
}