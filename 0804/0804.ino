#include <SoftwareSerial.h>
#include <Servo.h>


SoftwareSerial BTSerial(3, 2);
Servo servo;
int value = 120;

int M1 = 8; /*int1*/
int M2 = 9; /*int2*/
int flag=1;

void setup() 
{
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(11, OUTPUT);
  servo.attach(11);
  BTSerial.begin(115200);

  Serial.begin(115200);
  Serial.print("모터가 준비 되었습니다. 숫자 1,2,3,4중 하나를 입력해주세요.");
  servo.write(value);
}

void loop() {
if(BTSerial.available())
{
int n = BTSerial.read();
if(n>205 & n<225) flag=1;
if(n>=225 & n<255) flag=0;
 int L ,R;
 
if(flag==1)
{

    
    
    
     Serial.println(n);
     
      if(n<20)
    {
      digitalWrite(M1, HIGH);
      digitalWrite(M2, HIGH);
    }

      if(n>=20 & n<80)
    {
         digitalWrite(M1, LOW);
         digitalWrite(M2, HIGH);
         analogWrite(5,n*5);
       
    }

    if(n>100 & n <200)
    {

          
          
      
         R = map(n,100,200,130,25);   //  120~140   90~140
         servo.write(R);
         
    }

    


       
  }




if(flag==0)
{

    
 
         Serial.println(n);
     
         digitalWrite(M1, HIGH);
         digitalWrite(M2, LOW);
         analogWrite(5,170);

  

    if(n>100 & n <200)
    {

          
          
      
         R = map(n,100,200,130,25);   //  120~140   90~140
         servo.write(R);

        digitalWrite(M1, HIGH);
         digitalWrite(M2, LOW);
         analogWrite(5,170);
         
    }





         
         
    }



       
  




}



}
