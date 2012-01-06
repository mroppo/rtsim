#include "rm_global_sched.h"

// ################################################################3
// 1. Add the include.h of where the new partial function or method is located
// ################################################################3
// #include "rm_nf_ll.h"

#include "rm_bf_ip.h"

// ################################################################3
// 2. Add the name of the command that was used in TCL to call native code
// ################################################################3
//name used for command call from TCL
//#define COMMAND_NAME "rmbfduuo"

//name command that will used within TCL to call the native code
#define COMMAND_NAME "rmbfip"

//example of calling from TCL 
//set r [catch {eval COMMAND_NAME $algorithmSelected $numberProcessors $simulationTime $pathSavedTasks } errmsg]

// ################################################################3
// 3. Rename "partial_function" by the name of the new partial function or method to be added
// ################################################################3
//call to the partial function
processor_t* partial_function(processor_t* list, int nproc, char *file)
{
	//partial function or method that is will call in this library 
	// ## Change to function by the new partial function  
	//list = start_rm_nf_ll(nproc, file);
	list = start_rm_bf_ip(nproc, fileSimuladorCmd);
	return list;
}

// name the common method used to access running the scheduler 
static int SimulatorCmd(ClientData clientData, Tcl_CmdDeleteProc* proc, int objc, Tcl_Obj* const objv[]);

// ################################################################
// 4. Rename the function using the name of the library + _Init
// ################################################################
// example Rmnfll_init for rmnfll
int Rmbfip_Init(Tcl_Interp *interp)
{
	DBG("\nrmbfip_Init TCL v[%s]", TCL_VERSION);
	
    if (Tcl_InitStubs(interp, TCL_VERSION, 0) == NULL) {
		DBG("\nerror ");
		return TCL_ERROR;
    }
	
	DBG("\nCreating command [%s]\n",COMMAND_NAME);
	
	//once it receives the command from TCL COMMAND_NAME,is sent the function call SimulatorCmd
    Tcl_CreateObjCommand(interp, COMMAND_NAME, SimulatorCmd, NULL, NULL);
    Tcl_PkgProvide(interp, COMMAND_NAME, "1.1");

	return TCL_OK;
}


//#define USE_RESOURCES
#define USE_TRACE_FILE
//#define END_ON_MISS_DEADLINE

//include code common for all methods
#include "../common_rm_global_sched.cxx"