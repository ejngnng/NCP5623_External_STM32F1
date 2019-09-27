#ifndef VTASK_NAV_H
#define VTASK_NAV_H

#include "FreeRTOS/FreeRTOS.h"
#include "FreeRTOS/task.h"
#include "driver/driver_dma1.h"
#include "driver/driver_tim2.h"
#include "driver/driver_ws2812.h"

void vTask_Nav(void *args);

#endif