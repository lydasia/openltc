#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char hourCount = 0;
volatile unsigned char minuteCount = 0;
volatile unsigned char secondCount = 0;
volatile unsigned char frameCount = 0;

volatile unsigned char bitCount = 0;
volatile unsigned char updateCnt = 0;
volatile unsigned char currentBit = 0;

volatile unsigned char lastLevel = 0;
volatile unsigned char polarBit = 0;

int main(void)
{
  DDRD = 0b00101000;
  DDRB = 0b00110000;
  
  //50% PWM Ground Level
  TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM01) | _BV(WGM00);
  TCCR0B = _BV(WGM02) | _BV(CS00);
  OCR0A = 1;
  OCR0B = 0;

  //Set Output to Ground Level
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(WGM22) | _BV(CS20);
  OCR2A = 127;
  OCR2B = 63;
  
  //Per 1/2-Bit Interrupt
  TCCR1A = 0b00 << WGM10;
  TCCR1B = 0b01 << WGM12 | 0b001 << CS10;
  OCR1A = 3995;//3999@25fps
  TIMSK1 = 1 << OCIE1A;
  sei();

  while(1)
  {    
  }
}

void setLevel(void)
{
  switch(bitCount)
  {
    case 0:
      polarBit = 0;
      currentBit = (((frameCount % 10) >> (1 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 1:
      currentBit = (((frameCount % 10) >> (2 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 2:
      currentBit = (((frameCount % 10) >> (3 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 3:
      currentBit = (((frameCount % 10) >> (4 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 4:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 5:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 6:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 7:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 8:
      currentBit = (((frameCount / 10 % 10) >> (1 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;  
    case 9:
      currentBit = (((frameCount / 10 % 10) >> (2 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;  
    case 10:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 11:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 12:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 13:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 14:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 15:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 16:
      currentBit = (((secondCount % 10) >> (1 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 17:
      currentBit = (((secondCount % 10) >> (2 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 18:
      currentBit = (((secondCount % 10) >> (3 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 19:
      currentBit = (((secondCount % 10) >> (4 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 20:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 21:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 22:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 23:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 24:
      currentBit = (((secondCount /10 % 10) >> (1 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 25:
      currentBit = (((secondCount /10 % 10) >> (2 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break; 
    case 26:
      currentBit = (((secondCount /10 % 10) >> (3 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 27:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 28:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 29:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 30:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 31:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 32:
      currentBit = (((minuteCount % 10) >> (1 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 33:
      currentBit = (((minuteCount % 10) >> (2 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 34:
      currentBit = (((minuteCount % 10) >> (3 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 35:
      currentBit = (((minuteCount % 10) >> (4 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 36:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 37:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 38:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 39:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 40:
      currentBit = (((minuteCount / 10 % 10) >> (1 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 41:
      currentBit = (((minuteCount / 10 % 10) >> (2 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 42:
      currentBit = (((minuteCount / 10 % 10) >> (3 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 43:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 44:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break; 
    case 45:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 46:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 47:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break; 
    case 48:
      currentBit = (((hourCount % 10) >> (1 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 49:
      currentBit = (((hourCount % 10) >> (2 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 50:
      currentBit = (((hourCount % 10) >> (3 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 51:
      currentBit = (((hourCount % 10) >> (4 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 52:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 53:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 54:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 55:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 56:
      currentBit = (((hourCount / 10 % 10) >> (1 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 57:
      currentBit = (((hourCount / 10 % 10) >> (2 - 1)) & 1);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break; 
    case 58:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 59:
      currentBit = (polarBit);
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 60:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 61:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 62:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 63:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 64:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 65:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 66:
      currentBit = 1;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 67:
      currentBit = 1;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 68:
      currentBit = 1;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 69:
      currentBit = 1;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 70:
      currentBit = 1;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 71:
      currentBit = 1;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 72:
      currentBit = 1;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 73:
      currentBit = 1;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 74:
      currentBit = 1;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 75:
      currentBit = 1;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 76:
      currentBit = 1;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 77:
      currentBit = 1;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 78:
      currentBit = 0;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    case 79:
      currentBit = 1;
      OCR2B = (lastLevel = (updateCnt?(currentBit?(!lastLevel):(lastLevel)):(!lastLevel))?(1):(0))?(100):(27);
      if((updateCnt)&(!currentBit)){polarBit=!polarBit;};
      break;
    default:
      OCR2B = 63;
  }
}

void timeUpdate(void)
{
  
  if(bitCount < 79)
    {
      bitCount ++;
    }
    else
    {
      bitCount = 0;
      if(frameCount < 24)
      {
        frameCount ++;
      }
      else
      {
        frameCount = 0;
        if(secondCount < 59)
        {
          secondCount ++;
        }
        else
        {
          secondCount = 0;
          if(minuteCount < 59)
          {
            minuteCount ++;
          }
          else
          {
            minuteCount = 0;
            if(hourCount < 23)
            {
              hourCount ++;
            }
            else
            {
              hourCount = 0;
            }
          }
        }
      }      
    }
    
}

ISR(TIMER1_COMPA_vect)
{
    
  setLevel();

  if(updateCnt == 0)
  {
    updateCnt ++;
  }
  else
  {
    updateCnt = 0;
    timeUpdate();
  }          
}
