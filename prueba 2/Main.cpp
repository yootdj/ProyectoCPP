// prueba 2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

//librerias del visual studio
#include <iostream>

//´librerias creadas por nocotros
#include "usuario.h"
#include "OpcionesMenu.h"

int main()
{
	ModeloUsuario* usuario = NULL;

	OpcionesMenu opcionSeleccionada = OpcionesMenu::MostrarMenu;

	//Usuario::CargarUsuarios();

	while (opcionSeleccionada != OpcionesMenu::Salir) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		//se muestra el mensaje al usuario para que seleccione una opcion del menu
		std::cout << "Seleccione una opcion del menu" << std::endl;
		std::cout << "2.- registrar nuevo usuario" << std::endl;
		std::cout << "3.- editar usuario" << std::endl;
		std::cout << "5.- mostrar usuarios" << std::endl;
		std::cout << "4.- consultar usuario" << std::endl;
		std::cout << "6.- guardar usuarios" << std::endl;
		std::cout << "0.- salir" << std::endl;

		//se guarda la opcion seleccionada del usuario en la variable opcion de tipo int
		std::cin >> opcionSeleccionada;

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
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln