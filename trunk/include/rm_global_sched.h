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
#include "rm_nf_ll.h"
#include "rm_bf_ll.h"
#include "rm_ff_ll.h"
#include "rm_wf_ll.h"
#include "rm_ff_du_uo.h"
#include "rm_ff_ip.h"
#include "rm_gt.h"
#include "rm_nf_ip.h"
#include "rm_st.h"

#include "rm_bf_ip.h"
#include "rm_bf_du_uo.h"
#include "rbound_mp.h"
#include "rbound_mp_bf.h"
#include "rbound_mp_nfr.h"

extern int start_rm(int mode, int no_proc, double max_time, task_set_t *t, char* basename_trace);
extern int start_rm_main(ALGORITHM_PARAMS parameters);
extern void print_rm_usage();

typedef enum
{
	RM_PARTIAL_NF_LL=0,
	RM_PARTIAL_BF_LL,
	RM_PARTIAL_FF_LL,
	RM_PARTIAL_WF_LL,

	RM_PARTIAL_FF_DU_UO,
	RM_PARTIAL_FF_IP,
	RM_PARTIAL_GT,
	RM_PARTIAL_NF_IP,
	RM_PARTIAL_ST,

	RM_PARTIAL_BF_IP,
	RM_PARTIAL_BF_DU_UO,
	RM_PARTIAL_RBOUND_MP,
	RM_PARTIAL_RBOUND_MP_BF,
	RM_PARTIAL_RBOUND_MP_NFR,

	RM_PARTIAL_COUNT,
}RM_PARTIAL_MODE;

#endif