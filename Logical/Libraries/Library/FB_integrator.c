
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif

/* Integrator function */
void FB_integrator(struct FB_integrator* inst)
{
	inst->out += inst->in;
}
