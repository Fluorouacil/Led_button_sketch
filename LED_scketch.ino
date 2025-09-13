const int GREEN = 3;
const int YELLOW = 4;
const int RED = 5;

void setup() {
  // Установим все пины области D на выход а пины области B на вход
  DDRD = 0b00000000;
  DDRB = 0b00111111;
  PORTD = 0b00000000;
  // Запустим Serial для ведения логов
  Serial.begin(9600);
}

void loop() {
  // Если есть какой-то сигнал в области D
  if (PIND != 0) {
    // Считываем байт
      byte readed_byte = PIND;

      // Если сигнал пришел из бита Green
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
      // Если сигнал пришел из бита Yellow
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
      // Если сигнал пришел из бита Red
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
  