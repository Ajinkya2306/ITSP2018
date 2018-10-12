//Copyright author
//Sanjoli Narang
#include "text.h"
#include<string.h>
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
ss.begin(9600);
}

void loop() {
  iter++;
  if(iter == 1)
  {
   thresh = readPressure() + 30;
   iter =0;
  }
  // put your main code here, to run repeatedly:
  while(readPressure() < thresh)
  Serial.println(readPressure());
  
  int newno;
  newno = function1();
  Serial.println(newno);
  if(newno == 7)
  StopSpeech();
  else if(newno == 8)
  PauseSpeech();
  else if(newno == 9)
  ResumeSpeech();
  else if(newno == 10)
  GetStatus();
  else
  {
    
  GetText(newno);
  Serial.println(line);
  Serial.println(attr);
  sprintf(sentence ,"%s%s",attr,line);
  Serial.println(sentence);
 // delay(1000);
  speakIt(sentence);
  waitForSpeech();
  }
 Serial.println("done");
if(ring==1)
ring = 0;
sprintf(attr ,"[g2][x0][v%d][s%d][m%d][t%d]",volume,speeds,voice_type,tones);
//delay(1000);

}
