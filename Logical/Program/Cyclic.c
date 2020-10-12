
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	if (enable == 1)
	{
		count += 10;
		if (count >= 10000 && count <= 15000)
			speed = 5;
		else
			speed = 0;
	}
	else
		speed = 0;
	
	fb_controller.e = speed - fb_motor_1.w;
	FB_regulator(&(fb_controller));
	
	fb_motor_1.u = fb_controller.u;
	fb_motor_2.u = speed;
	
	FB_motor(&(fb_motor_1));
	FB_motor(&(fb_motor_2));
}
