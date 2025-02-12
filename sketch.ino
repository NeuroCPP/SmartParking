#include <Arduino.h>

const int trigPins[8] = {5, 4, 14, 27, 26, 25, 33, 12};  
const int echoPins[8] = {18, 19, 21, 22, 23, 32, 35, 34};  
const char* sensorNames[8] = {  
    "F1-R1-C1", "F1-R1-C2", "F1-R2-C1", "F1-R2-C2",
    "F2-R1-C1", "F2-R1-C2", "F2-R2-C1", "F2-R2-C2"
};

void setup() {
    Serial.begin(115200);
    for (int i = 0; i < 8; i++) {
        pinMode(trigPins[i], OUTPUT);
        pinMode(echoPins[i], INPUT);
    }
}

void loop() {
    for (int i = 0; i < 8; i++) {
        digitalWrite(trigPins[i], LOW);
        delayMicroseconds(2);
        digitalWrite(trigPins[i], HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPins[i], LOW);

        long duration = pulseIn(echoPins[i], HIGH);
        int distance = duration * 0.034 / 2;
        int presence = (distance > 0 && distance <= 25) ? 100 : 0;

        Serial.print(sensorNames[i]);
        Serial.print(" | Distance: ");
        Serial.print(distance);
        Serial.print(" cm | Presence: ");
        Serial.print(presence);
        Serial.println("%");
    }
    Serial.println("----------------------");
    delay(1000);
}
