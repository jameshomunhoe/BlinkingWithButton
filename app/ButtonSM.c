#include <stdio.h>
#include "ButtonSM.h"
#include "Button.h"
#include "Message.h"

void buttonInitData(ButtonData *data){
  data->state = RELEASE;
}


void buttonSM(ButtonData *data){
  switch(data->state){
    case RELEASE:
      if(isButtonPress() == 1){
        msg = CHANGE_MODE;
        data->state = PRESS;
      }
      break;
      
      
    case PRESS:
      if(isButtonPress() == 0){
        msg = DO_NOTHING;
        data->state = RELEASE;
      }
      break;
    
    
    
    default:
      printf("Error: Unknown state encountered in buttonSM %d\n", data->state);
      break;
  }
}
