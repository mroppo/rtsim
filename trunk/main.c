#include "./include/main.h"



void printUsage(int method)
{
	printf("Simulator Usage: \n ./simulator.run method processors time taskfile");
	printf("\n methods:");
	printf("\n   0: EDF");
	printf("\n   1: RM");
	printf("\n   2: EDF With Deadlines");
	printf("\n   3: RM With Deadlines");
	printf("\n   4: FIFO");
	printf("\n mode:");
	printf("\n   0: Global");
	printf("\n   1: Partial");
	printf("\n processors:");
	printf("\n   number processors used, should be > 0");
	printf("\n time:");
	printf("\n   simulation time , set 0 for calculate lcm");
	printf("\n taskfile:");
	printf("\n   path to file with task information");
	printf("\n");


	/*switch (method) {
		case EDF:
			print_edf_usage();
			break;
		case RM:
			print_rm_usage();
			break;
		case EDF_DEADLINES:
			print_edf_deadline_usage();
			break;
		case RM_DEADLINES:
			print_rm_deadline_usage();
			break;
		case FIFO:
			print_fifo_usage();
			break;

	}*/
}

int main(int argc, char *argv[])
{
	int method = -1;
	int res = -1;
	int argidx = 2; //first arg is app file, second is method used
	//	char*args = argv;

	if (argc > 2) {

		
		method = atoi(argv[1]);

		//argc = 3;
		//method = 1;
		switch (method) {
			case EDF:
				res = start_edf_main(argc - 2, argv, argidx);
				break;
			case RM:
				res = start_rm_main(argc - 2, argv, argidx);
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
