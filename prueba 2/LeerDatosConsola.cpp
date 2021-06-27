#include "LeerDatosConsola.h"

void LeerDatoConsola(std::string mensaje, std::string& dato, bool esBase64)
{
	ConfigurarCaracteres();

	std::string datoInterno;

	do {
		limpiarPantalla();

		limpiarCin();

		std::cout << mensaje << std::endl;

		std::getline(std::cin, datoInterno);
	} while (std::cin.fail() || datoInterno.empty());

	if (esBase64)
	{
		datoInterno = base64_encode(datoInterno);
	}

	dato = datoInterno;
}

void LeerDatoConsola(std::string mensaje, short& dato)
{
	ConfigurarCaracteres();

	short datoInterno = 0;

	do {
		limpiarPantalla();

		limpiarCin();

		std::cout << mensaje << std::endl;
		std::cin >> datoInterno;
		std::cout << std::endl;
	} while (std::cin.fail());
	dato = datoInterno;
}