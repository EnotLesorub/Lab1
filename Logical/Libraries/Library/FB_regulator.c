
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif

/* Regulator function */
void FB_regulator(struct FB_regulator* inst)
{
	inst->e_kp = inst->e*inst->k_p;
	
	inst->integrator.in = inst->e*inst->dt*inst->k_i + inst->iyOld;
	FB_integrator(&(inst->integrator));
	
	if (inst->e_kp < inst->max_abs_value || inst->e_kp > -inst->max_abs_value);	
	else
	{
		if (inst->e_kp > 0)
			inst->e_kp = inst->max_abs_value;
		else
			inst->e_kp = -inst->max_abs_value;
	}
	
	inst->e_kp += inst->integrator.out;
	
	if (inst->e_kp < inst->max_abs_value || inst->e_kp > -inst->max_abs_value)
		inst->u = inst->e_kp;
	else
	{
		if (inst->e_kp > 0)
			inst->u = inst->max_abs_value;
		else
			inst->u = -inst->max_abs_value;
	}
	
	inst->iyOld = inst->u - inst->e_kp;
}
