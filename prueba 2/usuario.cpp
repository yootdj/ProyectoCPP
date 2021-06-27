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
	ConfigurarCaracteres();

	ModeloUsuario* nuevoUsuario = CrearUsuario();
	listaUsuarios.push_back(nuevoUsuario);

	LeerDatoConsola("ingrese el nombre de usuario: ", nuevoUsuario->nombre, false);

	LeerDatoConsola("ingrese el apellido paterno: ", nuevoUsuario->apellidoPaterno, false);

	LeerDatoConsola("ingrese el apellido materno: ", nuevoUsuario->apellidoMaterno, false);

	LeerDatoConsola("ingrese el alias: ", nuevoUsuario->alias, false);

	LeerDatoConsola("ingrese su año de nacimiento: ", nuevoUsuario->aniodenacimiento);

	LeerDatoConsola("ingrese su mes de nacimiento: ", nuevoUsuario->mesdenacimiento);

	LeerDatoConsola("ingrese su dia de nacimiento: ", nuevoUsuario->diadenacimiento);

	LeerDatoConsola("ingrese su correo electronico: ", nuevoUsuario->correoElectronico, false);

	LeerDatoConsola("ingrese su contraseña: ", nuevoUsuario->password, true);
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

		limpiarCin();

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
	ConfigurarCaracteres();

	ModeloUsuario* usuarioEditar = ConsultarUsuario();
	if (usuarioEditar != NULL)
	{
		LeerDatoConsola("ingrese el nombre de usuario: ", usuarioEditar->nombre, false);

		LeerDatoConsola("ingrese el apellido paterno: ", usuarioEditar->apellidoPaterno, false);

		LeerDatoConsola("ingrese el apellido materno: ", usuarioEditar->apellidoMaterno, false);

		LeerDatoConsola("ingrese el alias: ", usuarioEditar->alias, false);

		LeerDatoConsola("ingrese su año de nacimiento: ", usuarioEditar->aniodenacimiento);

		LeerDatoConsola("ingrese su mes de nacimiento: ", usuarioEditar->mesdenacimiento);

		LeerDatoConsola("ingrese su dia de nacimiento: ", usuarioEditar->diadenacimiento);

		LeerDatoConsola("ingrese su correo electronico: ", usuarioEditar->correoElectronico, false);

		LeerDatoConsola("ingrese su contraseña: ", usuarioEditar->password, true);

		std::cout << "se edit exitosamente." << std::endl;
	}
	else
	{
		std::cout << "el usuario no existe" << std::endl;
	}
}

void Usuario::GuardarUsuarios()
{
	// todo este returnal es temporal
	return;
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
	return;
	if (std::filesystem::exists("usuarios.data") && !listaUsuarios.empty())
	{
		std::ifstream archivousuarios;
		archivousuarios.open("usuarios.data", std::istream::binary);

		while (!archivousuarios.eof())
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
		}

		//cerramos el archivo
		archivousuarios.close();
	}
}
std::list<ModeloUsuario*> Usuario::listaUsuarios = std::list <ModeloUsuario*>();