#include <iostream>
#include "Herramientas.h"

//limpia la consola
void limpiarPantalla()
{
#if defined _WIN32 || defined _WIN64
	system("cls");
#elif defined (__LINUX__)	|| defined(__gnu_linux__) || defined(__linux__)
	system("clear");
#elif defined(__apple__)
	system("clear");
#endif
}