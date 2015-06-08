#ifndef ButtonSM_H
#define ButtonSM_H

#include <stdint.h>
#include "State.h"

typedef struct{
  State state;
}ButtonData;

//function prototype
void buttonInitData(ButtonData *data);
void buttonSM(ButtonData *data);

#endif // ButtonSM_H
