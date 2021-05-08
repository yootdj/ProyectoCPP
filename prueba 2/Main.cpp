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
	ModeloUsuario* usuario = NULL;

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
			break;
		case OpcionesMenu::Salir:
			std::cout << "hasta luego" << std::endl;
			break;
		default:
			std::cout << " opcion seleccionada no es valida" << std::endl;
			opcionSeleccionada = OpcionesMenu::Ninguno;
			break;
		}

		//switch (opcionSeleccionada)
		//{
		//case OpcionesMenu::AgregarUsuario:
		//	Usuario::AgregarUsuario();
		//	break;
		//case OpcionesMenu::EditarUusiario:
		//	Usuario::EditarUsuario();
		//	break;
		//case OpcionesMenu::ConsultarUsuario:
		//	usuario = Usuario::ConsultarUsuario();
		//	if (usuario != NULL)
		//	{
		//		std::cout << usuario->toString() << std::endl;
		//	}
		//	else
		//	{
		//		std::cout << "no encontro el usuario" << std::endl;
		//	}
		//	break;
		//case OpcionesMenu::ListaUsuarios:
		//	Usuario::MostrarListaUsuarios();
		//	break;
		//case OpcionesMenu::GuardarUsuarios:
		//	Usuario::GuardarUsuarios();
		//	break;
		//case OpcionesMenu::Salir:
		//	exit(EXIT_SUCCESS);
		//	break;
		//default:
		//	std::cout << "la opcion seleccionada no es valida" << std::endl;
		//	break;
		//}
		std::cin.clear();
	}

	return EXIT_SUCCESS;
}