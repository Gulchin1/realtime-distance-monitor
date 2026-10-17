const int trigPin = 8;
const int echoPin = 9;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Trigger siqnalı göndəririk
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // pulseIn funksiyasına 30 millisaniyə limit qoyuruq ki, sistem donmasın
  long duration = pulseIn(echoPin, HIGH, 30000);
  
  int distance = duration * 0.034 / 2;
  
  // Ekrana nəticəni yazdırırıq
  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(500);
}