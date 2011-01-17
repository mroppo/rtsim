#ifndef __RM_GLOBAL_SCHED_H__
#define __RM_GLOBAL_SCHED_H__

#include "simulator.h"

#include <string.h>
#include <stdio.h>
#include <math.h>

#include "task.h"
#include "processor.h"
#include "sched_event.h"
#include "trace_event.h"

extern int start_rm(int mode, int no_proc, double max_time, task_set_t *t, char* basename_trace);
extern int start_rm_main(ALGORITHM_PARAMS parameters);
extern void print_rm_usage();

typedef enum
{
	RM_PARTIAL_NF_LL=0,
	//RM_PARTIAL_FF,
	RM_PARTIAL_COUNT,

}EDF_PARTIAL_MODE;

#endif