#ifndef VTASK_TAIL_H
#define VTASK_TAIL_H

#include "FreeRTOS/FreeRTOS.h"
#include "FreeRTOS/task.h"
#include "driver/driver_dma1.h"
#include "driver/driver_tim2.h"
#include "driver/driver_ws2812.h"

void vTask_Tail(void *args);

#endif