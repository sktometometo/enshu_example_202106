#define SERVO_PIN 2 // set digital pin ID
#include <Servo.h>

Servo servo;

void setup()
{
  servo.attach(SERVO_PIN); // サーボモーターのピンの設定
  Serial.begin(9600); // シリアルポートを開き,データレートを9600 bpsにセットする
  while (!Serial) {
    ; // シリアルポートが接続されるのを待つ
  }
}

int angle = 0;
void loop() {
  if (Serial.available() > 0) {
    angle = Serial.readStringUntil('\0').toInt(); // 受信した角度データを整数値として保持
    servo.write(angle); // angle 度にサーボモータを動かす
    
    // デバッグ用の出力
    Serial.print("Change angle to ");
    Serial.println(angle, DEC);  
  }
}
