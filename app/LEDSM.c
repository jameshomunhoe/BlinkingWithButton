#include <stdio.h>
#include "LEDSM.h"
#include "Message.h"


void ledInitData(LedData *data){
  data->state = LED_OFF;
}



void ledSM(LedData *data){
  switch(data->state){
    case LED_OFF:
      //turnOffLED
      if(msg == CHANGE_MODE){
        data->state = LED_BLINKING_ON;
        msg = DO_NOTHING;
      }
      break;
    
    case LED_ON:
      //turnOnLED
      if(msg == CHANGE_MODE){
        data->state = LED_OFF;
        msg = DO_NOTHING;
      }
      break;
    
    case LED_BLINKING_OFF:
      //turnOffLED
      //if(timerExpired)
      data->state = LED_BLINKING_ON;
      if(msg == CHANGE_MODE){
        data->state = LED_ON;
        msg = DO_NOTHING;
      }
      break;
    
    case LED_BLINKING_ON:
      //turnOnLED
      //if(timerExpired)
      data->state = LED_BLINKING_OFF;
      if(msg == CHANGE_MODE){
        data->state = LED_ON;
        msg = DO_NOTHING;
      }
      break;
      
    
    
    
    
    default:
      printf("Error: Unknown state encountered in ledSM %d\n", data->state);
      break;
  }
}
