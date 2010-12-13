#include "simulator.h"

#include <string.h>
#include <stdio.h>
#include <math.h>

#include "simulator.h"
#include "task.h"
#include "processor.h"
#include "sched_event.h"
#include "trace_event.h"


extern int start_fifo_main(int argc, char *argv[], int argid);
extern void print_fifo_usage();