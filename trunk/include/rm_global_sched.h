#ifndef __RM_GLOBAL_SCHED_H__
#define __RM_GLOBAL_SCHED_H__


#include <string.h>
#include <stdio.h>
#include <math.h>

#include "task.h"
#include "processor.h"
#include "sched_event.h"
#include "trace_event.h"

extern int start_rm(int mode, int no_proc, double max_time, task_set_t *t, char* basename_trace);
extern int start_rm_main(int argc, char *argv[], int argid);
extern void print_rm_usage();

#endif