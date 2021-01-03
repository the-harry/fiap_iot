#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 3;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {11, 10, 9, 8};
byte colPins[COLS] = {7, 6, 5};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

char password[4];
int i = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  char keyStroke = customKeypad.getKey();

  if (keyStroke == '*') {
    reset();
  } else if (keyStroke) {
    password[i++] = keyStroke;
    Serial.println(keyStroke);
  }

  if (i == 4) {
    delay(200);

    if (!(strncmp(password, "1234", 4))) {
      Serial.println("Bem vindo");
    } else {
      Serial.println("Sai fora");
    }

    i = 0;
    delay(2000);
  }
}

void reset() {
  while (i != 0) {
    password[i--] = "";
  }

  Serial.println("Cleared...");
  delay(500);
}
