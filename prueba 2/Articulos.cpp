#include "Articulo.h"

Articulo::Articulo()
{
}

void Articulo::MostrarMenuArticulos()
{
	//crearemos la variable para guardar la opcion seleccionada y la inizializemos en ninguno
	OpcionesArticulo opcionArticulo = OpcionesArticulo::Ninguno;

	ModeloArticulo* articulo = NULL;

	while (opcionArticulo != OpcionesArticulo::salir)
	{
		limpiarPantalla();

		std::cout << "1- Agregar articulo" << std::endl;
		std::cout << "2- Editar articulo" << std::endl;
		std::cout << "3- Consultar articulos" << std::endl;
		std::cout << "4- Mostrar lista articulos " << std::endl;
		std::cout << "7- salir." << std::endl;

		std::cin >> opcionArticulo;

		switch (opcionArticulo)
		{
		case OpcionesArticulo::Agregar:
			break;
		case OpcionesArticulo::Editar:
			break;
		case OpcionesArticulo::Consultar:
			break;
		case OpcionesArticulo::Lista:
			break;
		case OpcionesArticulo::salir:
			std::cout << "Se esta saliendo del menu de articulos." << std::endl;
			break;
		default:
			opcionArticulo = OpcionesArticulo::Ninguno;
			std::cout << "La opcion seleccionada no es valida" << std::endl;
			break;
		}

		TiempoEsperaPantalla();
	}
}