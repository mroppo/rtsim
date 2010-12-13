#ifndef __RM_DEADLINES_GLOBAL_SCHED_H__
#define __RM_DEADLINES_GLOBAL_SCHED_H__

#include "simulator.h"
#include <string.h>
#include <stdio.h>
#include <math.h>

#include "task.h"
#include "processor.h"
#include "sched_event.h"
#include "trace_event.h"

extern int start_rm_deadline_main(int argc, char *argv[],int argid);
extern void print_rm_deadline_usage();

#endif