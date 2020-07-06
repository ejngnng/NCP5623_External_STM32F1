#ifndef VERSION_H
#define VERSION_H

#ifdef LED_NCP5623
#define THISFIRMWARE    "APM_EXTERNAL_LED_COM"
#else
#define THISFIRMWARE    "APM_EXTERNAL_LED_PRO"
#endif
#define THISVERSION     "V2.0.4"

#endif