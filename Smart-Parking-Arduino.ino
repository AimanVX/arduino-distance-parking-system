// ===== Pins =====
int trigPin = 10;
int echoPin = 11;

int redLed    = 6;
int yellowLed = 5;
int greenLed  = 3;
int buzzer    = 2;

// ===== Variables =====
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // إرسال نبضة للحساس
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // استقبال النبضة
  duration = pulseInLong(echoPin, HIGH);

  // حساب المسافة (cm)
  distance = 0.034 * duration / 2;

  Serial.println(distance);

  // ===== الحالات =====

  // 🔴 قريب جدًا (وقف!)
  if (distance <= 4 && distance > 0) {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);

    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(100);
  }

  // 🟡 متوسط (انتبه)
  else if (distance <= 20 && distance > 4) {
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, HIGH);

    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(300);
  }

  // 🟢 بعيد (آمن)
  else if (distance <= 50 && distance > 20) {
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);

    digitalWrite(buzzer, HIGH);
    delay(800);
    digitalWrite(buzzer, LOW);
    delay(500);
  }

  // ❌ خارج النطاق
  else {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzer, LOW);
  }
}