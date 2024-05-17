/*
 * @Author: ziyefbk 2827567189@qq.com
 * @Date: 2024-05-17 21:22:44
 * @LastEditors: ziyefbk 2827567189@qq.com
 * @LastEditTime: 2024-05-17 21:53:56
 * @FilePath: \xlab_1\src\main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <Arduino.h>
int incomingByte = 0,flag[7] = {0};
void setup() {
  for(int i = 2; i < 8; i++)
    pinMode(i,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    incomingByte = Serial.read();
    if(incomingByte>='1'&&incomingByte<='6'){
      int id = incomingByte-'1';
      flag[id] = (flag[id]+1)%2;
      digitalWrite(id+2,flag[id]?HIGH:LOW);
      Serial.print("LED:");
      Serial.println(incomingByte-'1'+1);
    } 
  }
}
