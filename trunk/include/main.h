#include "edf_global_sched.h"
#include "rm_global_sched.h"
#include "edf_deadlines_global_sched.h"
#include "rm_deadlines_global_sched.h"
#include "fifo_global_sched.h"

typedef enum {
	EDF = 0,
	RM,
	EDF_DEADLINES,
	RM_DEADLINES,
	FIFO,
} simulation_method;

