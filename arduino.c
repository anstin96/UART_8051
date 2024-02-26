String Data1 = " ";
void setup() {
  Serial.begin(2400);

}

void loop() {
 Data1 = Serial.readString();
 Serial.print(Data1);
 delay(1000);

}
