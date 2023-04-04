#include "Timer0_interface.h"
#include "STD_TYPES.h"
#include "Timer0_cfg.h"

Timer0_cfg_t Timer0_Config ={NORMAL,                                //Timer Mode
							 CTC_NORMAL_OC_DISCONNECT,	           //CTC_OC_Mode
							 PWM_NONE,	                          //PWM_OC_Mode
							 //PRESCALER_256                        //PRESCALER_mode
};
