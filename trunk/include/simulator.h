#ifndef __SIMULATOR_H__
#define __SIMULATOR_H__

	//#define OS_WINDOWS
	#define OS_LINUX


	#ifdef OS_LINUX
		#define USE_THREAD			//ONLY for linux version
	#endif

	//#ifdef USE_THREAD
		#include <pthread.h>
	//#endif


#endif //__CONFIG_H__
