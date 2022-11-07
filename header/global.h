#include <stdio.h>
#include <stdlib.h>

#ifdef 	__linux__
#define clean   system("clear");
#endif

#ifdef _WIN32
#define clean   system("cls");
#define color   system("color 70");
#endif

#ifndef wait
#define wait    printf("\nAppuyez sur entree pour continuer...");\
                scanf("%*c%c", &trash);
#endif

#ifndef _rep_
#define _rep_   scanf(" %c", &rep);
#endif