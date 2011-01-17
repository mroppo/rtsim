#include "./include/main.h"



void printUsage(int method)
{
	printf("Simulator Usage: \n ./simulator.run method processors time taskfile");
	printf("\n methods:");
	printf("\n   0: EDF GLOBAL");
	printf("\n   1: EDF PARTIAL NF");
	printf("\n   2: EDF PARTIAL FF");

	printf("\n   3: RM Global");
	printf("\n   4: RM Partial NF LL");

	printf("\n   4: EDF With Deadlines");
	printf("\n   5: RM With Deadlines");
	printf("\n   6: FIFO");
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

int main(int argc, char *argv[])
{
	int method = -1;
	int res = -1;
	int argidx = 2; //first arg is app file, second is method used
	//int param_idx = 0;
	//char params[6][255];
	ALGORITHM_PARAMS parameters;
	//	char*args = argv;

	if (argc > 2) {

		
		method = atoi(argv[1]);

		switch (method) {
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
		}
		
		parameters.processor	= atoi(argv[argidx++]);
		parameters.time			= atoi(argv[argidx++]);
		strcpy(parameters.data, argv[argidx++]);

		parameters.param_count = argc - 2;
		//strcpy(params[param_idx++], argv[argidx++]);	//processor count
		//strcpy(params[param_idx++], argv[argidx++]);	//time
		//strcpy(params[param_idx++], argv[argidx++]);	//data file

		//argc = 3;
		//method = 1;
		//method = atoi(params[0]);
		switch ((int)parameters.algorithm) {
			case EDF:
				res = start_edf_main(parameters);
				break;
			case RM:
				res = start_rm_main(parameters);
				break;




			case EDF_DEADLINES:
				res = start_edf_deadline_main(argc - 2, argv, argidx);
				break;
			case RM_DEADLINES:
				res = start_rm_deadline_main(argc - 2, argv, argidx);
				break;
			case FIFO:
				res = start_fifo_main(argc - 2, argv, argidx);
				break;
		}
	}


	if (res == -1) {
		printUsage(method);
	}



	return(res);
}
