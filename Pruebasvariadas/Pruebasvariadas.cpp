// Pruebasvariadas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

int main()
{
	char cadenaCaracteres[20];

	strcpy_s(cadenaCaracteres, "");

	std::cout << "cadena de caracteres" << cadenaCaracteres << "." << std::endl;

	strcpy_s(cadenaCaracteres, "yoot cracki xd");

	std::cout << "cadenaCaracteres" << std::endl;

	char* cadenaCaracteresApuntador = {};

	rsize_t sizeL = sizeof("yootcrackilandia");
	strcpy_s(cadenaCaracteresApuntador, sizeL, "yootcrackilandia");

	std::cout << cadenaCaracteresApuntador << std::endl;

	std::string cadenaCaracteresString = "yoot crackilanda";

	cadenaCaracteresString = "otra asignacion de cadena";

	const char* resultadoApuntador = cadenaCaracteresString.c_str();

	return EXIT_SUCCESS;
}