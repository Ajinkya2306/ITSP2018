//Copyright author
//Sanjoli Narang
#ifndef TTS_H_INCLUDED
#define TTS_H_INCLUDED
#include <SoftwareSerial.h>

SoftwareSerial ss(12, 13); // rx, tx

void speakIt(char* msg) {
  ss.write(0xFD);
  ss.write((byte)0x0);
  ss.write(2 + strlen(msg));
  ss.write(0x01);
  ss.write((byte)0x0);
  ss.write(msg);
}

void waitForSpeech(unsigned long timeout = 5000) {
  unsigned long startt = millis();
  bool done = true;
  while ((millis() - startt) < timeout)  {
    while ( ss.available() ) {
     // Serial.println(ss.read(),HEX);
      if ( ss.read() == (byte)0x4F ) {
        done = false;
        break;
      }
    }
    if(done == false)
    break;
  }
}

void StopSpeech()
{
  ss.write(0xFD);
  ss.write((byte)0x0);
  ss.write(0x01);
  ss.write(0x02);
}

void PauseSpeech()
{
  ss.write(0xFD);
  ss.write((byte)0x0);
  ss.write(0x01);
  ss.write(0x03);
}

void ResumeSpeech()
{
  ss.write(0xFD);
  ss.write((byte)0x0);
  ss.write(0x01);
  ss.write(0x04);
}
void GetStatus()
{
   ss.write(0xFD);
  ss.write((byte)0x0);
  ss.write(0x01);
  ss.write(0x21);
  delay(10);
  Serial.println(ss.read() , HEX);
  delay(500);
}

#endif // TTS_H_INCLUDED
