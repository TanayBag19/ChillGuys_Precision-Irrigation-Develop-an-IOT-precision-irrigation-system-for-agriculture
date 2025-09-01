int sensorPin = A0;   // Soil sensor input (potentiometer)
int ledPin = 8;       // Pump/LED output
int threshold = 500;  // Adjust this for dry/wet soil level

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);  // Read soil moisture level
  Serial.print("Soil Moisture Value: ");
  Serial.println(sensorValue);

  if (sensorValue > threshold) {
    // Soil is dry → turn ON pump (LED)
    digitalWrite(ledPin, HIGH);
  } else {
    // Soil is wet → turn OFF pump (LED)
    digitalWrite(ledPin, LOW);
  }

  delay(1000); // Wait 1 second before next reading
}
