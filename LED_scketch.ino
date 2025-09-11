//#include "printf.h"

const int GREEN = 3;
const int YELLOW = 4;
const int RED = 5;

void setup() {
  DDRD = 0b00000000;
  DDRB = 0b00111111;
  PORTD = 0b00000000;
  Serial.begin(9600);
}

void loop() {
  if (PIND != 0) {
      byte readed_byte = PIND;

      if ((readed_byte & (1 << GREEN)) != 0) {
      PINB = PINB | readed_byte;
      Serial.println("Кнопка нажата");
      Serial.print("Считан бит ");
      Serial.print(bitRead(readed_byte, GREEN));
      Serial.print(" С позиции ");
      Serial.print(GREEN);
      Serial.print(" С байта ");
      Serial.print(readed_byte, BIN);
      Serial.print("\n");
    } if ((readed_byte & (1 << YELLOW)) != 0) {
      PINB = PINB | readed_byte;
      Serial.println("Кнопка нажата");
      Serial.print("Считан бит ");
      Serial.print(bitRead(readed_byte, YELLOW));
      Serial.print(" С позиции ");
      Serial.print(YELLOW);
      Serial.print(" С байта ");
      Serial.print(readed_byte, BIN);
      Serial.print("\n");
    } if ((readed_byte & (1 << RED)) != 0) {
      PINB = PINB | readed_byte;
      Serial.println("Кнопка нажата");
      Serial.print("Считан бит ");
      Serial.print(bitRead(readed_byte, RED));
      Serial.print(" С позиции ");
      Serial.print(RED);
      Serial.print(" С байта ");
      Serial.print(readed_byte, BIN);
      Serial.print("\n");
    }
  }
}
  