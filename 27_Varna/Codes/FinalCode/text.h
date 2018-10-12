//Copyright author
//Sanjoli Narang
#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include "pressure.h"
#include "variable.h"
#include "tts.h"
void GetText(int m)
{
    switch(m)
    {
default :
  break;

    case 1 :            //get sentence mode
            int no ;
            no = function1();
            Serial.println(no);
                if(no==1)
               sprintf(line , "I need water");

                if(no==2)
                sprintf(line ,"I need food");

                if(no==3)
                sprintf(line , "Shut up");

                if(no==4)
                sprintf(line , "Let's have a meeting then");

                if(no==5)
                sprintf(line , "Hello dear! How are you?");

                if(no==6)
               sprintf(line , "I beg your pardon");

                if(no==7)
                sprintf(line , "I am absolutely fine");

                if(no==8)
                sprintf(line , "Have a nice day");

                if(no==9)
                sprintf(line , "I don't think so");

                if(no==10)
                sprintf(line , "I knew it");

                if(no==11)
                sprintf(line , "Where do you work?");

                if(no==12)
                sprintf(line , "It is nearly impossible");

                if(no==13)
                sprintf(line , "See you soon again");

                if(no==14)
                sprintf(line , "Silence please");

                if(no==15)
                sprintf(line , "What do you want");

                if(no==16)
                sprintf(line , "What did you say?");

                if(no==17)
                sprintf(line , "What a terrible day!");

                if(no==18)
                sprintf(line , "Hey! What is going on");

                if(no==19)
                sprintf(line , "You are welcome");

                if(no==20)
               sprintf(line , "Absolutely not");

                if(no==21)
                sprintf(line , "Are you sure?");

                if(no==22)
                sprintf(line , "As soon as possible");

                if(no==23)
                sprintf(line , "How much?");

                if(no==24)
               sprintf(line , "Oh, pretty big");

                if(no==25)
                sprintf(line , "What about you?");

                if(no==26)
                sprintf(line , "Thanks to the builders");

                if(no==27)
                sprintf(line , "How are your family members?");

                if(no==28)
                sprintf(line , "It is fine completely");

                if(no==29)
                sprintf(line , "I want to go out");

                if(no==30)
                sprintf(line , "I want to meet that person");

                if(no==31)
                sprintf(line , "May I know your name");

                if(no==32)
                sprintf(line , "Can I have your number");

                if(no==33)
                sprintf(line , "It is absolutely incredible");

                if(no==34)
                sprintf(line , "Congratulations dear");

                 if(no==35)
                sprintf(line , "May God bless you!");

                 if(no==36)
                sprintf(line , "Of course");

                 if(no==37)
                sprintf(line , "I trust you");

                 if(no==38)
                sprintf(line , "Never mind");

                 if(no==39)
                sprintf(line , "Do you understand");

                 if(no==40)
                sprintf(line , "Thank you so much");

                 if(no==41)
                sprintf(line , "For God's sake");

                 if(no==42)
                sprintf(line , "May you live long!");

                 if(no==43)
                sprintf(line , "What are you doing");

                 if(no==44)
                sprintf(line , "What have you got");

                 if(no==45)
                sprintf(line , "Can someone give me fruits?");

                 if(no==46)
                sprintf(line , "Show me");

                 if(no==47)
                sprintf(line , "Work hard, you will succeed");

                 if(no==48)
                sprintf(line , "I see that person often");

                 if(no==49)
                sprintf(line , "Please have a dining with us");

                 if(no==50)
                sprintf(line , "You are looking awesome");

                 if(no==51)
                sprintf(line , "Pretty descent");

                 if(no==52)
                sprintf(line ,  "Wait for a second");

                if(no==53)
               sprintf(line ,  "I just don't care");

                if(no==54)
               sprintf(line ,  "Are you kidding?");

                if(no==55)
                sprintf(line ,  "I am having difficulty in breathing");

                if(no==56)
               sprintf(line ,  "It is feeling hot");

                if(no==57)
                sprintf(line ,  "Really smart");

                if(no==58)
                sprintf(line ,  "I heard somebody speaking");

                if(no==59)
                sprintf(line ,  "Mind your own business");

                if(no==60)
              sprintf(line ,  "I don't know");

                if(no==61)
                sprintf(line ,  "It is so harsh and cold");

                if(no==62)
               sprintf(line ,  "Please help me");
                break;

        
    case 2 :                    //Let us create a number
        
            while(readPressure() < thresh);
            int number ;
            while(true)
            {

                int no1 = function1();
                if(no1 == 10)
                no1 = 0;
                if(no1 > 9)                     //10 is 122
                    break;
                number = number*10;
                number += no1;

            }
            sprintf(line,"%d",number);
            break;
        

    case 3 :                    //here comes the builtin words
        
            int no2 ;
            no2 = function1();
            Serial.println(no2);
            if(no2==1)
            sprintf(line,"Yes");

            if(no2==2)
            sprintf(line,"No");

            if(no2==3)
            sprintf(line,"lol");

            if(no2==4)
            sprintf(line,"sad");

            if(no2==5)
            sprintf(line,"lonely");

            if(no2==6)
            sprintf(line , "proud of it");

            if(no2==7)
            sprintf(line , "anxious");

            if(no2==8)
            sprintf(line , "excellent");

            if(no2==9)
            sprintf(line , "Aggrieved");

            if(no2==10)
            sprintf(line , "Bored");

            if(no2==11)
            sprintf(line , "Love u");

            if(no2==12)
            sprintf(line , "sick");

            if(no2==13)
            sprintf(line , "Damn Shit");

            if(no2==14)
            sprintf(line , "sweet");

            if(no2==15)
            sprintf(line , "Beautiful");

            if(no2==16)
            sprintf(line , "an apple a day keeps the doctor away");

            if(no2==17)
            sprintf(line , "mango");

            if(no2==18)
            sprintf(line , "my favourite");

            if(no2==19)
            sprintf(line , "Happy Birthday");

            if(no2==20)
            sprintf(line , "Happy anniversary");

            if(no2==21)
            sprintf(line , "Miss u");

            if(no2==22)
            sprintf(line , "Don't worry");

            if(no2==23)
            sprintf(line , "My God");

            if(no2==24)
            sprintf(line , "restless");

            if(no2==25)
            sprintf(line , "Delicious");

            if(no2==26)
            sprintf(line , "Good morning");

            if(no2==27)
            sprintf(line , "Good night");

            if(no2==28)
            sprintf(line , "ridiculous");

            if(no2==29)
            sprintf(line , "Dreamy");

            if(no2==30)
            sprintf(line , "Food ready?");

            if(no2==31)
            sprintf(line , "Handle with care");

            if(no2==32)
            sprintf(line , "Clothes");

            if(no2==33)
            sprintf(line , "Lights offff");

            if(no2==34)
            sprintf(line , "Uneasiness");

            if(no2==35)
            sprintf(line , "Lucky");

            if(no2==36)
            sprintf(line , "Forgive me");

            if(no2==37)
            sprintf(line , "arrogant");

            if(no2==38)
            sprintf(line , "milk");

            if(no2==39)
            sprintf(line , "medicines");

            if(no2==40)
            sprintf(line , "for you");

             if(no2==41)
            sprintf(line , "How can it be");

             if(no2==42)
            sprintf(line , "Fond of it");

             if(no2==43)
            sprintf(line , "Crying out loud");

             if(no2==44)
            sprintf(line ,"what's wrong");

             if(no2==45)
            sprintf(line ,"So sad");

             if(no2==46)
            sprintf(line , "leave");

             if(no2==47)
            sprintf(line , "Be quick");

             if(no2==48)
            sprintf(line , "What");

            if(no2==49)
            sprintf(line , "Why");

            if(no2==50)
            sprintf(line , "near");

             if(no2==51)
            sprintf(line , "see");

             if(no2==52)
            sprintf(line , "turn it off");

             if(no2==53)
            sprintf(line , "louder please");

             if(no2==54)
            sprintf(line , "Hear it again");

             if(no2==55)
            sprintf(line , "You");

             if(no2==56)
            sprintf(line , "stop");

             if(no2==57)
            sprintf(line , "what time is it now");

             if(no2==58)
            sprintf(line , "agree");

             if(no2==59)
            sprintf(line , "disagree");

             if(no2==60)
            sprintf(line , "depressed");

             if(no2==61)
            sprintf(line , "scared");

             if(no2==62)
            sprintf(line , "cancel");
            break;
            
            
    case 4:                         //controls
        
            int no3 ;
            no3 = function1();
            Serial.println(no3);
            setControls(no3);
            break;
        
    case 5:                          //set ringtones
        
            int no4 ;
            no4 = function1();
            Serial.println(no4);
            sprintf(attr , "[x1]");
            ring =1;
            int val;
            val = 101;
            if(no4 <= 10)
            {
                val = 100 + no4;
            }
            else if(no4 <= 20)
            {
                val = 200 + no4;
            }
            else if(no4 <= 30)
            {
                val = 300 + no4;
            }

            sprintf(line,"sound%d",val);
            break;

     case 6:

           char ch;
           int i=0;
           char Word[7];
           for(int j=0;j<7;j++)
           {
            Word[j] = ch;
           }
          while(i<7)
{
 
            int n = function1();
  if(n == 1)
  ch = '.';

  else if(n == 2)
  ch = '-';

  else if(n == 3)
  ch = 'i';

  else if(n == 4)
  ch = 'a';

  else if(n == 5)
  ch = 'n';

  else if(n == 6)
  ch = 'm';

  else if(n == 7)
  ch = 's';

  else if(n == 8)
  ch = 'u';

  else if(n == 9)
  ch = 'r';

 else if(n == 10)
  ch = 'w';

  else if(n == 11)
  ch = 'd';

  else if(n == 12)
  ch = 'k';

  else if(n ==13)
  ch = 'g';

  else if(n == 14)
  ch = 'o';

  else if(n == 15)
  ch = 'h';

  else if(n == 16)
  ch = 'v';

  else if(n == 17)
  ch = 'f';

  else if(n == 18)
  ch = '?';
  
  else if(n == 19)
  ch = 'l';

  else if(n == 20)
  ch = '!';

  else if(n == 21)
  ch = 'p';

  else if(n == 22)
  ch = 'j';

  else if(n == 23)
  ch = 'b';

  else if(n == 24)
  ch = 'x';

  else if(n == 25)
  ch ='c';

  else if(n == 26)
  ch = 'y';

  else if(n == 27)
  ch = 'z';

  else if(n == 28)
  ch = 'q';

  else if(n == 29)
  ch = 'e';
  
  else if(n == 30)
  ch = 't';
  Serial.println(ch);
  if(ch == '-')
  break;
   Word[i] = ch;
   i++;
  
}
sprintf(line,"%s",Word);
         break;   
   
       }
}

#endif // TEXT_H_INCLUDED
