//Copyright author
//Sanjoli Narang
#ifndef PRESSURE_H_INCLUDED
#define PRESSURE_H_INCLUDED
#include <SFE_BMP180.h>
#include <Wire.h>
SFE_BMP180 pressure;
double thresh = 30;
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
int function1()
{
  int x=0,y=0,z=0,w=0,u=0;
  int delta1,delta2=0;
  int t1 = 150;
//  int t2 = 200;
  while(readPressure() < thresh);
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

    //5
  delta1 = millis();
  delta2 = 0;
  while(readPressure() > thresh)
  {
    delta2=millis();

  }
  if((delta2-delta1) > t1)
  x=2;
  else if(delta2 != 0)
  x=1;
  Serial.print("x = ");
  Serial.println(x);

  delta1 = millis();
  while(readPressure() < thresh)
  {
    delta2 = millis();
    if((delta2 - delta1) > 2000)
    return  16*x+8*y+4*z+2*w+u;
    }

     return 16*x+8*y+4*z+2*w+u;
}


#endif // PRESSURE_H_INCLUDED
