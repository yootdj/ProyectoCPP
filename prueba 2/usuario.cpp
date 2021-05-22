#include "usuario.h"

//metodo

//con este metodo mostraremos la opciones de usuario
void Usuario::MostrarMenuUsuarios()
{
	CargarUsuarios();
	//crearemos la variable para guardar la opcion seleccionada y la inizializemos en ninguno
	OpcionesUsuario opcionUsuario = OpcionesUsuario::Ninguno;

	ModeloUsuario* usuario = NULL;

	//mostraremos el menu de usuarioasta seleccionar la opcion salur
	while (opcionUsuario != OpcionesUsuario::salir)
	{
		limpiarPantalla();

		std::cout << "1- agregar usuario nuevo" << std::endl;
		std::cout << "2- editar usuario" << std::endl;
		std::cout << "3- consultar usuario" << std::endl;
		std::cout << "4- mostrar lista de usuarios" << std::endl;
		std::cout << "7- salir  del menu usuarios" << std::endl;

		std::cin >> opcionUsuario;

		switch (opcionUsuario)
		{
		case OpcionesUsuario::Agregar:
			AgregarUsuario();
			break;
		case OpcionesUsuario::Editar:
			EditarUsuario();
			break;
		case OpcionesUsuario::Consultar:
			usuario = ConsultarUsuario();
			if (usuario != NULL)
			{
				std::cout << usuario->toString() << std::endl;
			}
			else
			{
				std::cout << "No se encontro el usuario." << std::endl;
			}
			break;
		case OpcionesUsuario::Lista:
			MostrarListaUsuarios();
			break;
		case OpcionesUsuario::salir:
			GuardarUsuarios();
			std::cout << "Se esta saliendo del menu de usuarios." << std::endl;
			break;
		default:
			opcionUsuario = OpcionesUsuario::Ninguno;
			std::cout << "La opcion seleccionada no es valida" << std::endl;
			break;
		}

		TiempoEsperaPantalla();
	}
}

ModeloUsuario* Usuario::CrearUsuario()
{
	return new ModeloUsuario();
}

void Usuario::AgregarUsuario()
{
	ModeloUsuario* nuevoUsuario = CrearUsuario();
	listaUsuarios.push_back(nuevoUsuario);

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Ingrese el nombre del usuario: " << std::endl;
	getline(std::cin, nuevoUsuario->nombre);

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Ingrese el apellido paterno: " << std::endl;
	getline(std::cin, nuevoUsuario->apellidoPaterno);

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Ingrese el apellido materno: " << std::endl;
	getline(std::cin, nuevoUsuario->apellidoMaterno);

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Ingrese su alias: " << std::endl;
	getline(std::cin, nuevoUsuario->alias);

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "ingrese su año de nacimiento: " << std::endl;
	std::cin >> nuevoUsuario->aniodenacimiento;

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "ingrese su mes de nacimiento: " << std::endl;
	std::cin >> nuevoUsuario->mesdenacimiento;

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "ingrese su dia de nacimiento: " << std::endl;
	std::cin >> nuevoUsuario->diadenacimiento;

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "ingrese su correo electronico: " << std::endl;
	getline(std::cin, nuevoUsuario->correoElectronico);

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "ingrese su contraseña: " << std::endl;
	getline(std::cin, nuevoUsuario->password);

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void Usuario::MostrarListaUsuarios()
{
	if (listaUsuarios.size() == 0)
	{
		std::cout << "no se encontraron usuarios para mostrar." << std::endl;
	}
	else
	{
		for (auto usuario : listaUsuarios)
		{
			std::cout << usuario->toString() << std::endl;
		}
	}
}
ModeloUsuario* Usuario::ConsultarUsuario()
{
	//si la lista esta vacia mostraremos el mensaje de que no hay
	if (Usuario::listaUsuarios.empty())
	{
		return NULL;
	}
	else
	{
		std::string nombreCompleto;

		std::cout << "ingrese el nombre completo del usuario a consultar incluyendo espacios";

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		getline(std::cin, nombreCompleto);

		for (auto usuario : listaUsuarios)
		{
			std::string nombreConsulta = usuario->nombre + " " +
				usuario->apellidoPaterno + " " +
				usuario->apellidoMaterno;

			if (nombreCompleto == nombreConsulta)
			{
				return usuario;
			}
		}

		return NULL;
	}
}
void Usuario::EditarUsuario()
{
	ModeloUsuario* usuarioEditar = ConsultarUsuario();
	if (usuarioEditar != NULL)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Ingrese el nombre del usuario: " << std::endl;
		getline(std::cin, usuarioEditar->nombre);

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Ingrese el apellido paterno: " << std::endl;
		getline(std::cin, usuarioEditar->apellidoPaterno);

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Ingrese el apellido materno: " << std::endl;
		getline(std::cin, usuarioEditar->apellidoMaterno);

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Ingrese su alias: " << std::endl;
		getline(std::cin, usuarioEditar->alias);

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "ingrese su año de nacimiento: " << std::endl;
		std::cin >> usuarioEditar->aniodenacimiento;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "ingrese su mes de nacimiento: " << std::endl;
		std::cin >> usuarioEditar->mesdenacimiento;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "ingrese su dia de nacimiento: " << std::endl;
		std::cin >> usuarioEditar->diadenacimiento;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "ingrese su correo electronico: " << std::endl;
		getline(std::cin, usuarioEditar->correoElectronico);

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "ingrese su contraseña: " << std::endl;
		getline(std::cin, usuarioEditar->password);

		std::cout << "se edit exitosamente." << std::endl;
	}
	else
	{
		std::cout << "el usuario no existe" << std::endl;
	}
}
void Usuario::GuardarUsuarios()
{
	//variable para utilizar un archivo
	std::ofstream archivoUsuarios;
	//detectamos si el archivo exista para borrarlo
	if (std::filesystem::exists("usuarios.data"))
	{
		//borramos el archivo
		std::filesystem::remove("usuarios.data");
	}

	//se crea o se abre el archivo para guardar datos en binario
	archivoUsuarios.open("usuarios.data", std::ostream::binary | std::ostream::app);

	//se recorre la lista de usuarios
	for (ModeloUsuario* usuario : listaUsuarios)
	{
		ModeloUsuario usuarioObjeto = ConvertirUsuarioObjeto(usuario);
		//se guarda cada uno de los usuarios en el archivo
		// (char*)& usuario se convierte el usuario a texto para guardarlo
		//size of (usuario) obtiene ewl tamaño del objeto apra saber cuanto espacio se va atomar  en el archivo
		archivoUsuarios.write(reinterpret_cast<char*>(&usuarioObjeto), sizeof(ModeloUsuario));
	}

	//se cierra el archivo
	archivoUsuarios.close();
}

void Usuario::CargarUsuarios()
{
	if (std::filesystem::exists("usuarios.data"))
	{
		std::ifstream archivousuarios;
		archivousuarios.open("usuarios.data", std::istream::binary);

		while (true)
		{
			//creamos una variable para guardar el usuario leido
			ModeloUsuario usuarioArchivo;
			//leemos el usuario para guardarlo en la variable usuario archivo
			archivousuarios.read(reinterpret_cast<char*>(&usuarioArchivo), sizeof(ModeloUsuario));

			if (!usuarioArchivo.nombre.empty())
			{
				//guardamos el ususuario leido del archivo en la lista de usuarios
				listaUsuarios.push_back(ConvertirUsuarioApuntador(usuarioArchivo));
			}
			else
			{
				break;
			}
		}

		//cerramos el archivo
		archivousuarios.close();
	}
}
std::list<ModeloUsuario*> Usuario::listaUsuarios = std::list <ModeloUsuario*>();