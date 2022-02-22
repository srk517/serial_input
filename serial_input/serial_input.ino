#include<LiquidCrystal.h>
const double rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int incomingByte = 0; // for incoming serial data
float f=0,e=0,res1=0,res2=0;
String a,b,c,g; 
int d,str_len;
void setup() {
  Serial.begin(115200); // opens serial port, sets data rate to 9600 bps
  lcd.begin(20, 4);
}

void loop() {
  // send data only when you receive data:
  while (Serial.available()) {
 a=Serial.readString();
 str_len = a.length()+1;
 for (int i=0;i<str_len;i++)
 {
    if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
    {
      for(int k=0;k<i;k++)
      {
        c+=a[k];
        res1=c.toFloat();
      }
      for(int j=i+1;j<str_len;j++)
      {
       g+= a[j];//save forward in some var
       res2=g.toFloat();
      }
      switch(a[i]){
        case '+':
        f=res1+res2;
        lcd.setCursor(0,0);
        lcd.print(res1);lcd.print("+");lcd.print(res2);
        lcd.setCursor(0,1);
        lcd.print("Result = ");lcd.print(f);
        res1=0,res2=0,f=0;
        break;
        case '-':
        f=res1-res2;
        lcd.setCursor(0,0);
        lcd.print(res1);lcd.print("-");lcd.print(res2);
        lcd.setCursor(0,1);
        lcd.print("Result = ");lcd.print(f);
        //lcd.print("Result ");lcd.print(f);
        res1=0,res2=0,f=0;
        break;
        case '*':
        f=res1*res2;
        lcd.setCursor(0,0);
        lcd.print(res1);lcd.print("X");lcd.print(res2);
      //  lcd.print("Result ");lcd.print(f);
        lcd.setCursor(0,1);
        lcd.print("Result = ");lcd.print(f);
        res1=0,res2=0,f=0;
        break;
        case '/':
        f=res1/res2;
        lcd.setCursor(0,0);
        lcd.print(res1);lcd.print("/");lcd.print(res2);
        lcd.setCursor(0,1);
        lcd.print("Result = ");lcd.print(f);
        res1=0,res2=0,f=0;
        break;
      }
     // lcd.clear();
      g="";c="";
    }
    
 }
}
}
