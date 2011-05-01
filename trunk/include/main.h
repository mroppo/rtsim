#include "simulator.h"

#include "edf_global_sched.h"
#include "rm_global_sched.h"
#include "edf_deadlines_global_sched.h"
#include "rm_deadlines_global_sched.h"
#include "fifo_global_sched.h"


#include <tcl.h>
#include <stdio.h>
extern int SimulatorCmd(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[]);
extern int Simulator_Init(Tcl_Interp *interp);


