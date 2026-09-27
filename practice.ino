const int trigPin = 8;
const int echoPin = 7;

void setup() {
  pinMode(trigPin, OUTPUT);   // Trigは信号を送る側 → 出力 or 入力？
  pinMode(echoPin, INPUT);   // Echoは信号を受け取る側 → 出力 or 入力？

  Serial.begin(9600);       // よく使われる通信速度は？（ヒント：9600）
}

void setColor(int distance) {
  if (distance < ___) {
    // 赤
    analogWrite(RED, ___);
    analogWrite(GREEN, ___);
    analogWrite(BLUE, ___);
  } else if (distance < ___) {
    // 黄色（赤+緑）
    analogWrite(RED, ___);
    analogWrite(GREEN, ___);
    analogWrite(BLUE, ___);
  } else {
    // 緑
    analogWrite(RED, ___);
    analogWrite(GREEN, ___);
    analogWrite(BLUE, ___);
  }
}



void loop() {
  // 1. Trigをリセット（念のため一度LOWにしておく）
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // 2. Trigを10μs以上HIGHにする
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);   // 10μs以上、という条件だった
  digitalWrite(trigPin, LOW);

  // 3. Echoのパルス幅を測る（マイクロ秒が返ってくる）
  long duration = pulseIn(echoPin, HIGH);

  // 4. 距離を計算する（cm）
  //    ヒント：340m/s = 0.034cm/μs
  //    durationは「往復」の時間なので、2で割るのを忘れずに
  float distance = 0.034*duration/2.0;


  // 5. 結果を表示
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);  // 見やすいように0.5秒おきに更新
}