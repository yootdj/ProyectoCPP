// prueba 2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

//librerias del visual studio
#include <iostream>

//´librerias creadas por nocotros
#include "usuario.h"
#include "OpcionesMenu.h"
#include "Herramientas.h"

int main()
{
	OpcionesMenu opcionSeleccionada = OpcionesMenu::Ninguno;

	//Usuario::CargarUsuarios();

	while (opcionSeleccionada != OpcionesMenu::Salir) {
		limpiarPantalla();
		//std::cin.clear();
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		//se muestra el mensaje al usuario para que seleccione una opcion del menu
		std::cout << "seleccione una opcion del menu" << std::endl;
		std::cout << "1 menu de usuarios" << std::endl;
		std::cout << "2 - salir" << std::endl;

		//se guarda la opcion seleccionada del usuario en la variable opcion de tipo int
		std::cin >> opcionSeleccionada;

		//verificamos que opcion se seleccione para realizar la accion en especifica
		switch (opcionSeleccionada)
		{
		case OpcionesMenu::Usuarios:
			Usuario::MostrarMenuUsuarios();
			break;
		case OpcionesMenu::Salir:
			std::cout << "hasta luego" << std::endl;
			TiempoEsperaPantalla();
			break;
		default:
			opcionSeleccionada = OpcionesMenu::Ninguno;
			std::cout << " opcion seleccionada no es valida" << std::endl;
			TiempoEsperaPantalla();
			break;
		}

		std::cin.clear();
	}

	return EXIT_SUCCESS;
}