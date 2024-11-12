const int TRIGGER = 8;
const int ECHO = 9;
const unsigned int MAX = 23200;

void setup() {
    pinMode(TRIGGER, OUTPUT);
    digitalWrite(TRIGGER, LOW);
    Serial.begin(9600);
    DDRD = 0xFF;
    PORTD = B10000000;
}
    

void loop() {
    unsigned long zeit_1;
    unsigned long zeit_2;
    unsigned long puls_weite;

    float cm;

    digitalWrite(TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER, LOW);

    while (digitalRead(ECHO) == 0);
    zeit_1 = micros();

    while (digitalRead(ECHO) == 1);
    zeit_2 = micros();

    puls_weite = zeit_2 - zeit_1;
    cm = puls_weite / 29.0 / 2.0; 

    if (cm >= 1 && cm <= 10) {
      PORTD = B00000100;
    }
    if (cm > 10 && cm <= 20){
      PORTD = B00001000;
    }
    if (cm > 20 && cm <= 30){
      PORTD = B00010000;
    }
    if (cm > 30 && cm <= 40) {
      PORTD = B00100000;
    }
    if (cm > 40 && cm <= 50){
      PORTD = B01000000;
    }
    if (cm > 50 && cm <= 60){
      PORTD = B10000000;
    }
  


    if (puls_weite > MAX) {
        Serial.println("Messbereich beachten!");
    } else {
        Serial.print("Abstand: ");
        Serial.print(cm);
        Serial.print(" cm ");
        Serial.println("");
    }

    delay(60); 
