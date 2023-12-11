//  戦場の絆２のUSBIO代理ボード用(Arduino Nano用)
//  2023 applesorce https://chiptune.tips
//
//　フットペダルの値をA0、A1でよんで、512以下はHIGH,それ以上はLOWとして返す(相手プルアップっぽいのでアクティブLOW)
//  アナログスティック左をA2,A3でよんで、上下左右のDPADに変換してD4-D7でLOWで出す。（これはUSBHIDではなくトリガを起こす、アーケードなジョイスティック基板で処理する）
//　アナログスティック右をA4,A5でよんで、上下左右のDPADに変換してD8-D11でLOWで出す。
const int _LIN = A0;    // 入力ピンをA0に固定 L.PEDAL
const int _RIN = A1;    // 入力ピンをA1に固定 R.PEDAL
const int _AXLIN = A2;    // 入力ピンをA2に固定 VRX_L
const int _AYLIN = A3;    // 入力ピンをA3に固定 VRY_L
const int _AXRIN = A4;    // 入力ピンをA4に固定 VRX_R
const int _AYRIN = A5;    // 入力ピンをA5に固定 VRY_R
int LVOLUME;                  // 変数を整数型で宣言
int RVOLUME;                  // 変数を整数型で宣言
int AXLVOLUME;                  // 変数を整数型で宣言
int AYLVOLUME;                  // 変数を整数型で宣言
int AXRVOLUME;                  // 変数を整数型で宣言
int AYRVOLUME;                  // 変数を整数型で宣言

void setup() {
  pinMode(A0,INPUT);    //A0からアナログ値を入れる
  pinMode(A1,INPUT);    //A1からアナログ値を入れる
  pinMode(A2,INPUT);    //A2からアナログ値を入れる
  pinMode(A3,INPUT);    //A3からアナログ値を入れる
  pinMode(2, OUTPUT);  //D2を出力する L.PEDAL_D
  pinMode(3, OUTPUT);  //D3を出力する R.PEDAL_D
  pinMode(4, OUTPUT);  //D4を出力する DP_UP
  pinMode(5, OUTPUT);  //D5を出力する DP_DOWN
  pinMode(6, OUTPUT);  //D6を出力する DP_LEFT
  pinMode(7, OUTPUT);  //D7を出力する DP_RIGHT
  pinMode(8, OUTPUT);  //D8を出力する DP_UP_R
  pinMode(9, OUTPUT);  //D9を出力する DP_DOWN_R
  pinMode(10, OUTPUT);  //D10を出力する DP_LEFT_R
  pinMode(11, OUTPUT);  //D11を出力する DP_RIGHT_R 
  Serial.begin(9600);  // シリアル通信の開始
}
void loop() {
//アナログ地を格納する
LVOLUME = analogRead(_LIN);                  //フットペダルLを格納
RVOLUME = analogRead(_RIN);                  //フットペダルRを格納
AXLVOLUME = analogRead(_AXLIN);                  //アナログLX軸を格納
AYLVOLUME = analogRead(_AYLIN);                  //アナログLY軸を格納
AXRVOLUME = analogRead(_AXRIN);                  //アナログRX軸を格納
AYRVOLUME = analogRead(_AYRIN);                  //アナログRY軸を格納

// 入力値表示(デバック用なのでいらないときはsetupのシリアルごと閉じる)
  Serial.print("LVolume: ");        // シリアルモニタに出力
  Serial.print(LVOLUME);
  Serial.print(",RVolume: ");        // シリアルモニタに出力
  Serial.print(RVOLUME);
  Serial.print(",AXLVolume: ");        // シリアルモニタに出力
  Serial.print(AXLVOLUME);
  Serial.print(",AYLVolume: ");        // シリアルモニタに出力
  Serial.print(AYLVOLUME);
  Serial.print(",AXRVolume: ");        // シリアルモニタに出力
  Serial.print(AXRVOLUME);
  Serial.print(",AYRVolume: ");        // シリアルモニタに出力
  Serial.println(AYRVOLUME);
// アナログ処理
if (LVOLUME > 380) { //0-1023の間をいい感じに設定すればいい。下げると敏感になる
  Serial.println("L_PEDAL");
  digitalWrite(2, LOW);
} else {
  digitalWrite(2, HIGH);
}
if (RVOLUME > 380) { //0-1023の間をいい感じに設定すればいい。下げると敏感になる
  Serial.println("R_PEDAL");
  digitalWrite(3, LOW);
} else {
  digitalWrite(3, HIGH);
}

//アナログスティック処理(512付近はドリフト対策で入力を無視する)
if(AXLVOLUME < 390){ //DOWN処理
  Serial.println("DOWN");
  digitalWrite(5, LOW);
} else {
  digitalWrite(5, HIGH);
}

if(AXLVOLUME > 600){ //UP処理
  Serial.println("UP");
  digitalWrite(4, LOW);
} else {
  digitalWrite(4, HIGH);
}

if(AYLVOLUME < 390){ //LEFT処理
  Serial.println("LEFT");
  digitalWrite(6, LOW);
} else {
  digitalWrite(6, HIGH);
}

if(AYLVOLUME > 600){ //UP処理
  Serial.println("RIGHT");
  digitalWrite(7, LOW);
} else {
  digitalWrite(7, HIGH);
}




//アナログR処理
if(AXRVOLUME < 390){ //DOWN処理
  Serial.println("DOWN_R");
  digitalWrite(9, LOW);
} else {
  digitalWrite(9, HIGH);
}

if(AXRVOLUME > 600){ //UP処理
  Serial.println("UP_R");
  digitalWrite(8, LOW);
} else {
  digitalWrite(8, HIGH);
}

if(AYRVOLUME < 390){ //LEFT処理
  Serial.println("LEFT_R");
  digitalWrite(10, LOW);
} else {
  digitalWrite(10, HIGH);
}

if(AYRVOLUME > 600){ //UP処理
  Serial.println("RIGHT_R");
  digitalWrite(11, LOW);
} else {
  digitalWrite(11, HIGH);
}
}