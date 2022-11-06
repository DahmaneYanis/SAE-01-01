#include <stdio.h>
#include <stdlib.h>

#ifdef 	__linux__
#define clean system("clear");
#endif

#ifdef _WIN32
#define clean system("cls");
#endif