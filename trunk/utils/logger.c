/*   FILE:

	 logger.c

    DESCRIPTION:

	 Trace event sctructure and data definitions

    Copyright (C) 2008

	 Arnoldo D�az Ram�rez, Pedro Mejia Alvarez

   This is free software;  you can  redistribute it  and/or modify it under
   terms of the  GNU General Public License as published  by the Free Soft-
   ware  Foundation;  either version 2,  or (at your option) any later ver-
   sion.  It is distributed in the hope that it will be useful, but WITH-
   OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
   for  more details.  You should have  received  a copy of the GNU General
   Public License;  see file COPYING.  If not, write to  the Free Software
   Foundation,  59 Temple Place - Suite 330,  Boston, MA 02111-1307, USA.

   LAST REVISION:    January 2010

 */
#include <stdio.h>
#include <stdarg.h>
#include "../include/logger.h"


void logger(const char* fmt, ...)
{
    char str[5*1024];
    va_list arg_list;

    va_start(arg_list, fmt);
    vsprintf(str, fmt, arg_list);

    //printf("%s", str);
	fprintf(stderr, "%s", str);
//#ifdef DEBUG_IN_FILE
 //   FILE* file = fopen("dbg.txt", "a+");
	//if(file)
	//{
	//	fprintf(file, "%s", str);
	//	fclose(file);
	//}
//#endif
}


void dbg(const char* fmt, ...)
{
	char str[5*1024];
    va_list arg_list;

    va_start(arg_list, fmt);
    vsprintf(str, fmt, arg_list);

    logger("%s", str);
}