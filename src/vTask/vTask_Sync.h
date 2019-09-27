#ifndef VTASK_SYNC_H
#define VTASK_SYNC_H

#include "FreeRTOS/FreeRTOS.h"
#include "FreeRTOS/task.h"
#include "driver/driver_dma1.h"
#include "driver/driver_i2c.h"
#include "driver/driver_tim2.h"
#include "driver/driver_ws2812.h"

void vTask_Sync(void *args);

#endif