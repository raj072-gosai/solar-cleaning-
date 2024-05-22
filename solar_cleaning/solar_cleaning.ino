// Define pin numbers for the components
#define BUTTON_PIN 26
#define moter 13
#define valv_1 5
#define valv_2 14
#define valv_3 27

// Define delays
#define DELAY_SHORT 2000  // 2 seconds
#define DELAY_LONG 38000  // 38 seconds
#define DELAY_MID 36000   // 36 seconds

void setup() {
  // Set pin modes
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(moter, OUTPUT);
  pinMode(valv_1, OUTPUT);
  pinMode(valv_2, OUTPUT);
  pinMode(valv_3, OUTPUT);

  // Initialize LEDs to be off
  digitalWrite(moter, HIGH);
  digitalWrite(valv_1, HIGH);
  digitalWrite(valv_2, HIGH);
  digitalWrite(valv_3, HIGH);
}

void loop() {
  // Check if the button is pressed
  if (digitalRead(BUTTON_PIN) == LOW) {
    // Sequence start
    digitalWrite(moter, LOW);
    digitalWrite(valv_1, LOW);
    delay(DELAY_LONG);  //38 seconmds
    digitalWrite(valv_2, LOW);
    delay(DELAY_SHORT);  // 2 seconds
    digitalWrite(valv_1, HIGH);
    delay(DELAY_MID);  //36 seconds
    digitalWrite(valv_3, LOW);
    delay(DELAY_SHORT);  // 2 seconds
    digitalWrite(valv_2, HIGH);
    delay(DELAY_MID);  // 36 seconds
    digitalWrite(moter, HIGH);
    delay(DELAY_SHORT);  // 2 seconds
    digitalWrite(valv_3, HIGH);
  }
}
