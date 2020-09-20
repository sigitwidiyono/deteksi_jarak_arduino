// deteksi jarak dengan led dan buzzer
#define buzzerPin 10
#define ledPin1 6
#define ledPin2 7
#define triggerPin 9
#define echoPin 8

int durasi, jarak ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(triggerPin, LOW);
  durasi = pulseIn(echoPin, HIGH);
  jarak = (durasi/2) / 29.1;

    if (jarak <= 0 || jarak >100) {
      Serial.println("Obyek tidak ditemukan!");
      digitalWrite(buzzerPin,LOW);
      digitalWrite(ledPin1,LOW);
      digitalWrite(ledPin2,LOW);
      noTone(buzzerPin);
      } else if(jarak > 0 && jarak <=30) {
        Serial.println("Objek kurang dari 30cm \n");
        Serial.print("Jarak = ");              
        Serial.print(jarak);        //prints the distance if it is between the range 0 to 200
        Serial.println(" cm");
        tone(buzzerPin,2000);              // play tone of 400Hz for 500 ms
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,LOW);
      } else if(jarak > 30 && jarak <= 100) {
        Serial.println("Objek lebih dari 30cm \n");
        Serial.print("Jarak = ");              
        Serial.print(jarak);        //prints the distance if it is between the range 0 to 200
        Serial.println(" cm");
        tone(buzzerPin,3000);              // play tone of 400Hz for 500 ms
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin1,LOW);
      }
  
}
