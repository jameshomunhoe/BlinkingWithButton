#include <stdio.h>
#include "LEDSM.h"


void ledSM(LedData *data){
  switch(data->state){
    default:
      printf("Error: Unknown state encountered in ledSM %d\n", data->state);
      break;
  }
}
