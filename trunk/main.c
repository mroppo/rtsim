#include "./include/main.h"


void printUsage(int method)
{
	printf("Simulator Usage: \n ./simulator.run method processors time taskfile");
	printf("\n methods:");
	printf("\n   0: EDF Global");
	printf("\n   1: EDF Partial NF");
	printf("\n   2: EDF Partial FF");
	printf("\n   3: EDF Partial BF");
	printf("\n   4: EDF Partial WF");



	printf("\n   5: RM Global");
	printf("\n   6: RM Partial NF LL");
	printf("\n   7: RM Partial BF LL");
	printf("\n   8: RM Partial FF LL");
	printf("\n   9: RM Partial WF LL");

	printf("\n   10: RM Partial FF DU UO");
	printf("\n   11: RM Partial FF IP");
	printf("\n   12: RM Partial GT");
	printf("\n   13: RM Partial NF IP");
	printf("\n   14: RM Partial ST");

	printf("\n   15: RM Partial BF IP");
	printf("\n   16: RM Partial BF DU UO");
	printf("\n   17: RM Partial MP");
	printf("\n   18: RM Partial MP BF");
	printf("\n   19: RM Partial MP NFR");
	

	printf("\n   20: EDF With Deadlines");
	printf("\n   21: RM With Deadlines");
	printf("\n   22: FIFO");
	/*printf("\n mode:");
	printf("\n   0: Global");
	printf("\n   1: Partial");*/
	printf("\n processors:");
	printf("\n   number processors used, should be > 0");
	printf("\n time:");
	printf("\n   simulation time , set 0 for calculate lcm");
	printf("\n taskfile:");
	printf("\n   path to file with task information");
	printf("\n");
}

#ifdef SIMLUATOR_LIB_TCL


static int SimulatorCmd(ClientData clientData, Tcl_CmdDeleteProc* proc, int objc, Tcl_Obj* const objv[]) {
	int res =     TCL_OK;
	char* strings[255];
	int t = 0;
printf("\n called with %d arguments\n", objc);

for(t=0;t<objc;t++)
{
	printf("\n%d: %s",t, (*objv[t]).bytes);
	strings[t] = (*objv[t]).bytes;
}
	res = simulator_main(objc, strings);


printf("\n end main: %d",res);
return res;
//return TCL_OK;
}
int Simulator_Init(Tcl_Interp *interp) {
	printf("\nSimulator_Init");
	//ClientData data;
    if (Tcl_InitStubs(interp, TCL_VERSION, 0) == NULL) {
	return TCL_ERROR;
    }
    printf("\ncreating simulator command");
    Tcl_CreateObjCommand(interp, "simulator", SimulatorCmd, NULL, NULL);
    Tcl_PkgProvide(interp, "simulator", "1.1");

return TCL_OK;
}


int simulator_main(int argc, char* argv[])
#else
int main(int argc, char *argv[])
#endif
{
	MENU_ITEM method = -1;
	int res = -1;
	int argidx = 2; //first arg is app file, second is method used
	//int param_idx = 0;
	//char params[6][255];
	ALGORITHM_PARAMS parameters;
	//	char*args = argv;
	int i=0;

	for(i=0;i<argc;i++)
	{
		printf("\n %d: %s",i,argv[i]);
	}
	printf("\n");


	if (argc > 2) {

		
		method = atoi(argv[1]);

		switch (method) {
//////////// EDF
			case MENU_EDF_GLOBAL:
				parameters.algorithm	= EDF;
				parameters.mode			= MODE_GLOBAL;
				parameters.partial_func = 0;
			break;
			case MENU_EDF_PARTIAL_NF:
				parameters.algorithm	= EDF;
				parameters.mode			= MODE_PARTIAL;
				parameters.partial_func = EDF_PARTIAL_NF;
			break;
			case MENU_EDF_PARTIAL_FF:
				parameters.algorithm	= EDF;
				parameters.mode			= MODE_PARTIAL;
				parameters.partial_func = EDF_PARTIAL_FF;
			break;
			case MENU_EDF_PARTIAL_BF:
				parameters.algorithm	= EDF;
				parameters.mode			= MODE_PARTIAL;
				parameters.partial_func = EDF_PARTIAL_BF;
			break;
			case MENU_EDF_PARTIAL_WF:
				parameters.algorithm	= EDF;
				parameters.mode			= MODE_PARTIAL;
				parameters.partial_func = EDF_PARTIAL_WF;
			break;


//////////// RM
			case MENU_RM_GLOBAL:
				parameters.algorithm	= RM;
				parameters.mode			= MODE_GLOBAL;
				parameters.partial_func = 0;
			break;
			case MENU_RM_PARTIAL_NF_LL:
				parameters.algorithm	= RM;
				parameters.mode			= MODE_PARTIAL;
				parameters.partial_func = RM_PARTIAL_NF_LL;
			break;
			case MENU_RM_PARTIAL_BF_LL:
				parameters.algorithm	= RM;
				parameters.mode			= MODE_PARTIAL;
				parameters.partial_func = RM_PARTIAL_BF_LL;
			break;
			case MENU_RM_PARTIAL_FF_LL:
				parameters.algorithm	= RM;
				parameters.mode			= MODE_PARTIAL;
				parameters.partial_func = RM_PARTIAL_FF_LL;
			break;
			case MENU_RM_PARTIAL_WF_LL:
				parameters.algorithm	= RM;
				parameters.mode			= MODE_PARTIAL;
				parameters.partial_func = RM_PARTIAL_WF_LL;
			break;

			case MENU_RM_PARTIAL_FF_DU_UO:
				parameters.algorithm	= RM;
				parameters.mode			= MODE_PARTIAL;
				parameters.partial_func = RM_PARTIAL_FF_DU_UO;
			break;
			case MENU_RM_PARTIAL_FF_IP:
				parameters.algorithm	= RM;
				parameters.mode			= MODE_PARTIAL;
				parameters.partial_func = RM_PARTIAL_FF_IP;
			break;
			case MENU_RM_PARTIAL_GT:
				parameters.algorithm	= RM;
				parameters.mode			= MODE_PARTIAL;
				parameters.partial_func = RM_PARTIAL_GT;
			break;
			case MENU_RM_PARTIAL_NF_IP:
				parameters.algorithm	= RM;
				parameters.mode			= MODE_PARTIAL;
				parameters.partial_func = RM_PARTIAL_NF_IP;
			break;
			case MENU_RM_PARTIAL_ST:
				parameters.algorithm	= RM;
				parameters.mode			= MODE_PARTIAL;
				parameters.partial_func = RM_PARTIAL_ST;
			break;



			case MENU_RM_PARTIAL_BF_IP:
				parameters.algorithm	= RM;
				parameters.mode			= MODE_PARTIAL;
				parameters.partial_func = RM_PARTIAL_BF_IP;
			break;
			case MENU_RM_PARTIAL_BF_DU_UO:
				parameters.algorithm	= RM;
				parameters.mode			= MODE_PARTIAL;
				parameters.partial_func = RM_PARTIAL_BF_DU_UO;
			break;
			case MENU_RM_PARTIAL_RBOUND_MP:
				parameters.algorithm	= RM;
				parameters.mode			= MODE_PARTIAL;
				parameters.partial_func = RM_PARTIAL_RBOUND_MP;
			break;
			case MENU_RM_PARTIAL_RBOUND_MP_BF:
				parameters.algorithm	= RM;
				parameters.mode			= MODE_PARTIAL;
				parameters.partial_func = RM_PARTIAL_RBOUND_MP_BF;
			break;
			case MENU_RM_PARTIAL_RBOUND_MP_NFR:
				parameters.algorithm	= RM;
				parameters.mode			= MODE_PARTIAL;
				parameters.partial_func = RM_PARTIAL_RBOUND_MP_NFR;
			break;


//////////// others
			case MENU_EDF_DEADLINES:
				parameters.algorithm	= EDF_DEADLINES;
				parameters.mode			= 0;
				parameters.partial_func = 0;
			break;
			case MENU_RM_DEADLINES:
				parameters.algorithm	= RM_DEADLINES;
				parameters.mode			= 0;
				parameters.partial_func = 0;
			break;
			case MENU_FIFO:
				parameters.algorithm	= FIFO;
				parameters.mode			= 0;
				parameters.partial_func = 0;
			break;
		}
		
		parameters.processor	= atoi(argv[argidx++]);
		parameters.time			= atoi(argv[argidx++]);
		strcpy(parameters.data, argv[argidx++]);

		parameters.param_count = argc - 2;
		

		switch ((int)parameters.algorithm) {
			case EDF:
				res = start_edf_main(parameters);
				break;
			case RM:
				res = start_rm_main(parameters);
				break;


			case EDF_DEADLINES:
				res = start_edf_deadline_main(parameters);
				break;
			case RM_DEADLINES:
				res = start_rm_deadline_main(parameters);
				break;
			case FIFO:
				res = start_fifo_main(parameters);
				break;
		}
	}


	if (res == -1) {
		printUsage(method);
	} else
	{
		printf("\nEnd: %d",res);
	}

	

	return(res);
}


