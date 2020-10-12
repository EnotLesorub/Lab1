
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif

/* Motor function */
void FB_motor(struct FB_motor* inst)
{
	inst->integrator.in = (inst->u*(1/inst->ke) - inst->w)*(inst->dt/inst->Tm);
	FB_Integrator(&(inst->integrator));
	inst->w = inst->integrator.out;
	
	inst->integrator.in = inst->w*inst->dt;
	FB_Integrator(&(inst->integrator));
	inst->phi = inst->integrator.out;
}
