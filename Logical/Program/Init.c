
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	enable = 1;
	count = 0;
	speed = 0;
	
	fb_controller.dt = 0.01;
	fb_controller.k_i = 200;
	fb_controller.k_p = 8;
	fb_controller.max_abs_value = 24;
	
	fb_motor_1.dt = 0.01;
	fb_motor_1.ke = 16;
	fb_motor_1.Tm = 0.04;
	
	fb_motor_2.dt = 0.01;
	fb_motor_2.ke = 16;
	fb_motor_2.Tm = 0.04;
}
