#include <stdio.h>
#include "ButtonSM.h"

void buttonSM(ButtonData *data){
  switch(data->state){
    default:
      printf("Error: Unknown state encountered in buttonSM %d\n", data->state);
      break;
  }
}
