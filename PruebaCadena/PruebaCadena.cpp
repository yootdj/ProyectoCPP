#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	//declaramos una variable tipo caracter y le asignamos un caracter
	char caracter = 'a';

	//declaramos un arreglo de caracteres y le asigno caracteres al arreglo
	char carateres[6] = { 'p', 'r', 'u', 'e', 'b', 'a' };

	for (int i = 0; i < 6; i++)
	{
		std::cout << carateres[i];
	}

	//declaramos una variable de tipo cadena de caracteres y le asignamos caracteres a la cadena
	std::string cadena = "prueba";

	std::cout << std::endl << cadena << std::endl;

	for (auto caracter : cadena)
	{
		std::cout << caracter << std::endl;
	}

	return EXIT_SUCCESS;
}