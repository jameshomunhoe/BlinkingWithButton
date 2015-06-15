#include <stdio.h>
#include "Button.h"
#include "LEDSM.h"
#include "Time.h"
#include "Message.h"



void ledInitData(LedData *data){
  data->state = LED_OFF;
}



void ledSM(LedData *data){
  static uint32_t previousTime = 0;
  
  switch(data->state){
    case LED_OFF:
      //turnOffLED
      if(msg == CHANGE_MODE){
        data->state = LED_BLINKING_ON;
        msg = DO_NOTHING;
      }
      data->time = getCurrentTime();
      break;
    
    case LED_ON:
      //turnOnLED
      if(msg == CHANGE_MODE){
        data->state = LED_OFF;
        msg = DO_NOTHING;
      }
      data->time = getCurrentTime();
      break;
    
    case LED_BLINKING_OFF:
      //turnOffLED
      if(getCurrentTime() - data->time >= 500){
        data->state = LED_BLINKING_ON;
        data->time = getCurrentTime();
      } 
      if(msg == CHANGE_MODE){
        data->state = LED_ON;
        msg = DO_NOTHING;
      }
      data->time = getCurrentTime();
      break;
    
    case LED_BLINKING_ON:
      //turnOnLED
      if(getCurrentTime() - data->time >= 500){
        data->state = LED_BLINKING_OFF;
        data->time = getCurrentTime();
      }
      if(msg == CHANGE_MODE){
        data->state = LED_ON;
        msg = DO_NOTHING;
        data->time = getCurrentTime();
      }
      break;

    default:
      printf("Error: Unknown state encountered in ledSM %d\n", data->state);
      break;
  }
}
