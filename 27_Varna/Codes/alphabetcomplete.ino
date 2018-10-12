#include <SFE_BMP180.h>
#include <Wire.h>
SFE_BMP180 pressure;
double thresh = 500;                              //changes with temperature
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("REBOOT");


   if (pressure.begin())
   
    Serial.println("BMP180 init success");
  else
  {
    Serial.println("BMP180 init fail\n\n");
    while(1); // Pause forever.
  }
}


void loop()
{
 String sr;
String sen;
while(readPressure() < thresh)
Serial.println(readPressure());
sr = GetLine();
Serial.println(sr);
delay(1000);

}
//Make use of the library and read pressure from the sensor
double readPressure()
{
  char status;
  double T,P;
   status = pressure.startTemperature();
  if (status != 0)
  {
  delay(status);
     status = pressure.getTemperature(T);
    if (status != 0)
    {
       status = pressure.startPressure(2);   // 2 stands for resolution
      if (status != 0)
      {
         delay(status);
          status = pressure.getPressure(P,T);
        if (status != 0)
        {
           
          return ((P-1000)*100);
  
         }
        else return 0;
      }
      else return 0;
    }
    else return 0;
  }
  else return 0;

}

 // takes sensor data, identifies long and short breathe, encodes it into a pattern and converts it to an integer
int function1()                  
{
  int x=0,y=0,z=0,w=0,u=0;        
  int delta1,delta2=0;
  int t1 = 150;
//  int t2 = 200;

 //1
  delta1 = millis();
  delta2 = 0;
  while(readPressure() > thresh)
  {
    delta2=millis();
   
  }
  if((delta2-delta1) > t1)
  u=2;
  else if(delta2 != 0)
  u=1;
  Serial.print("u = ");
  Serial.println(u);
  
  delta1 = millis();
  while(readPressure() < thresh)
  {
    delta2 = millis();
    if((delta2 - delta1) > 2000)
    return  u;
    }

 //2
  delta1 = millis();
  delta2 = 0;
  while(readPressure() > thresh)
  {
    delta2=millis();
   
  }
  if((delta2-delta1) > t1)
  w=2;
  else if(delta2 != 0)
  w=1;
  Serial.print("w = ");
  Serial.println(w);
  
  delta1 = millis();
  while(readPressure() < thresh)
  {
    delta2 = millis();
    if((delta2 - delta1) > 2000)
    return  2*w+u;
    }

 //3
  delta1 = millis();
  delta2 = 0;
  while(readPressure() > thresh)
  {
    delta2=millis();
   
  }
  if((delta2-delta1) > t1)
  z=2;
  else if(delta2 != 0)
  z=1;
  Serial.print("z = ");
  Serial.println(z);
  
  delta1 = millis();
  while(readPressure() < thresh)
  {
    delta2 = millis();
    if((delta2 - delta1) > 2000)
    return  4*z+2*w+u;
    }


//4
  delta1 = millis();
  delta2 = 0;
  while(readPressure() > thresh)
  {
    delta2=millis();
   
  }
  if((delta2-delta1) > t1)
  y=2;
  else if(delta2 != 0)
  y=1;
  Serial.print("y = ");
  Serial.println(y);
  
  delta1 = millis();
  while(readPressure() < thresh)
  {
    delta2 = millis();
    if((delta2 - delta1) > 2000)
    return  8*y+4*z+2*w+u;
    }

     return 8*y+4*z+2*w+u;
}

// takes integer from the previuos fuction and returns a character corresponding to it
String ConvertToAlphabet(int n)
{
  if(n == 1)
  return ".";

  if(n == 2)
  return " ";

  if(n == 3)
  return "i";

  if(n == 4)
  return "a";

  if(n == 5)
  return "n";

  if(n == 6)
  return "m";

  if(n == 7)
  return "s";

  if(n == 8)
  return "u";

  if(n == 9)
  return "r";

  if(n == 10)
  return "w";

  if(n == 11)
  return "d";

  if(n == 12)
  return "k";

  if(n ==13)
  return "g";

  if(n == 14)
  return "o";

  if(n == 15)
  return "h";

  if(n == 16)
  return "v";

  if(n == 17)
  return "f";

  if(n == 18)
  return "?";
  
  if(n == 19)
  return "l";

  if(n == 20)
  return "!";

  if(n == 21)
  return "p";

  if(n == 22)
  return "j";

  if(n == 23)
  return "b";

  if(n == 24)
  return "x";

  if(n == 25)
  return "c";

  if(n == 26)
  return "y";

  if(n == 27)
  return "z";

  if(n == 28)
  return "q";

  if(n == 29)
  return "e";

  if(n == 30)
  return "t";

  return "@";
}

//keeps on taking the alphabets , convert them into a word until an ending character comes
String GetWord()
{
  String Word;
  
  String ch = "";
  int no;
 
  while(true)
  { 
      while(readPressure() < thresh);                                              // add the check
     no = function1();
     ch = ConvertToAlphabet(no);
     if(ch == " ") 
     return Word;
     if(ch == "")                                         // mode changed
     return Word;
     Word += ch; 
     Serial.println(ch);
     
  }
  return Word;
}

//keeps on taking the words and creates a sentence until an ending character comes
String GetLine()
{
  String sentence;
  String Wrd;
  while(true)
  { 
    while(readPressure() < thresh);
    Wrd = GetWord();
    if(Wrd == ".")
    break;
    sentence += " ";
    sentence += Wrd;
   
    Serial.println(Wrd);
  }
  return sentence;
}

