//程式一：搖桿數值讀取
#include <AFMotor.h>                  //引入一個函式庫 
AF_DCMotor motorX(1, MOTOR12_8KHZ); //設定馬達X軸(接腳,頻率)
AF_DCMotor motorY(2, MOTOR12_8KHZ); //設定馬達Y軸(接腳,頻率)
AF_DCMotor motorZ(3, MOTOR12_8KHZ); //設定馬達Z軸(接腳,頻率)
int joystickXpin = A0;                // 搖桿 X軸 接 Arduino Analog pin A0
int joystickYpin = A1;                // 搖桿 Y軸 接 Arduino Analog pin A1
int Xpos = 0;                         // 定義X軸位置參數
int Ypos = 0;                         // 定義Y軸位置參數

void setup() {                        //初始化程式設定

  Serial.begin(9600);                  //鮑率Baud Rate：arduino與電腦溝通的頻率設定為9600

  motorX.setSpeed(220);               //可調轉速範圍為150~到255
  motorY.setSpeed(150);
  motorZ.setSpeed(150);
}
void loop() {
Xpos = analogRead(joystickXpin);            // 讀入搖桿 X 軸數值，範圍為0-1023
Ypos = analogRead(joystickYpin);            // 讀入搖桿 Y 軸數值，範圍為0-1023
  Serial.print("X=");
  Serial.print(Xpos);                        // 序列埠監控視窗顯示"X="和 X 軸數值
  Serial.print("   Y=");
  Serial.println(Ypos);                      // 序列埠監控視窗顯示"/Y="和 Y 軸數值                      
                                            // 序列埠監控視窗「換行」顯示
  motorX.run(RELEASE);                      //馬達X軸執行 run 程式中的 RELEASE 指令(p.s.RELEASE指令就是讓馬達停止運轉)
  motorY.run(RELEASE);                      //馬達Y軸執行 run 程式中的 RELEASE 指令
  delay(2);

//X軸(範圍0~1023)控制//////////////////////////////////////////////////////////////////////////////////////////////////////////
if (Xpos<510)                              //如果 讀取到搖桿的X軸值<500時
{
  motorX.run(FORWARD);                     //馬達X軸執行 run 程式中的 FORWARD 指令(p.s.FORWARD指令就是讓馬達正轉)
  delay(2);                                //休息(正確來說是「延遲」)0.002秒
}
else if(Xpos>520)                          //如果不符合上面條件，而當 讀取到搖桿的X軸值>510時
{
  motorX.run(BACKWARD);                    //馬達X軸執行 run 程式中的 BACKWARD 指令(p.s.BACKWARD指令就是讓馬達逆轉)
  delay(2);                                //延遲0.002秒
}

//Y軸(範圍0~1023)控制//////////////////////////////////////////////////////////////////////////////////////////////////////////
if (Ypos<504)
{     
  motorY.run(FORWARD);   
  delay(2);
}
else if(Ypos>510)
{                   
  motorY.run(BACKWARD);
  delay(2);  
}
}
