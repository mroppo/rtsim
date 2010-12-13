#include "simulator.h"

#include <string.h>
#include <stdio.h>
#include <math.h>
#include "task.h"
#include "processor.h"
#include "sched_event.h"
#include "trace_event.h"
#include "edf_nf.h"

extern int start_edf_main(int argc, char *argv[], int argid);
extern void print_edf_usage();