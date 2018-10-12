//Copyright author
//Sanjoli Narang
#ifndef VARIABLE_H_INCLUDED
#define VARIABLE_H_INCLUDED

char line[100];
char sentence[200];
int volume = 2;    //default
int speeds = 5;
int tones = 5;
int voice_type = 51;
int ring = 0;
//double thresh = 67;
int iter = 0;
char attr[50] = "[g2][x0][v2][s5][m51][t5][h2]";
void setControls(int n)
{
  if(n < 10)                    //set volume
  {
    volume = n;
    //set volume
    sprintf(line ,"Volume set to %d",volume);
   // Serial.print(level);

  }
  else if(n < 20)                    //set speed
  {
    speeds = n%10;
    // set speed
    sprintf(line,"Speed set to %d",speeds);
  }
  else if(n < 30)                    //set tone
  {
    tones = n%10;
    // set tone3
   sprintf(line,"tone set to %d",tones);
  }

  else if(n<36)            //set voice type
  {
      int hey = 50 + n%10;
    switch(hey)
    {
      case 51:
      {
        voice_type = 51;
        sprintf(line,"Voice set to gentle male");
        break;
      }
      case 52:
      {
        voice_type = 52;
        sprintf(line,"Voice set to broader male");
        break;
      }
      case 53:
      {
         voice_type = 53;
        sprintf(line,"Voice set to mature female");
        break;
      }
      case 54:
      {
         voice_type = 54;
        sprintf(line,"Voice set to Donald duck");
        break;
      }
      case 55:
      {
         voice_type = 55;
        sprintf(line,"Voice set to young girl");
        break;
      }
      default :
      {
         voice_type = 51;
        sprintf(line,"Default voice single male");
      }
    }

  }
  else
  {
      sprintf(line,"Wrong argument given");
  }
      sprintf(attr ,"[g2][x0][v%d][s%d][m%d][t%d]",volume,speeds,voice_type,tones);
}
#endif // VARIABLE_H_INCLUDED
