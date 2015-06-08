#ifndef LEDSM_H
#define LEDSM_H

#include "State.h"
#include <stdint.h>

typedef struct{
  State state;
  uint32_t time;
}LedData;

//function prototype
void ledInitData(LedData *data);
void ledSM(LedData *data);

#endif // LEDSM_H
