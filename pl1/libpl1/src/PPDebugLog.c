#include "PPDebugLog.h"

/* 
   this is the main switch that will turn on debugging mode 
   regardless of  weather or not debugging structures/data
   are turned on in Flex/Bison.  You should not modify this
   variable it is controled by command line options.
*/

/* default is turned off */

int ppDebugLogEnabled=DL_NO_TRACE;


