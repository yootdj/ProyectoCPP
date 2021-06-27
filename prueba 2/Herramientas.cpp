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
void TiempoEsperaPantalla()
{
	system("pause");
}

ModeloUsuario* ConvertirUsuarioApuntador(ModeloUsuario usuario)
{
	ModeloUsuario* usuarioapuntador = new ModeloUsuario();
	usuarioapuntador->nombre = usuario.nombre;
	usuarioapuntador->apellidoPaterno = usuario.apellidoPaterno;
	usuarioapuntador->apellidoMaterno = usuario.apellidoMaterno;
	usuarioapuntador->alias = usuario.alias;
	usuarioapuntador->aniodenacimiento = usuario.aniodenacimiento;
	usuarioapuntador->mesdenacimiento = usuario.mesdenacimiento;
	usuarioapuntador->diadenacimiento = usuario.diadenacimiento;
	usuarioapuntador->correoElectronico = usuario.correoElectronico;
	usuarioapuntador->password = usuario.password;
	return usuarioapuntador;
}

ModeloUsuario ConvertirUsuarioObjeto(ModeloUsuario* usuario)
{
	ModeloUsuario usuarioObjeto;
	usuarioObjeto.nombre = usuario->nombre;
	usuarioObjeto.apellidoPaterno = usuario->apellidoPaterno;
	usuarioObjeto.apellidoMaterno = usuario->apellidoMaterno;
	usuarioObjeto.alias = usuario->alias;
	usuarioObjeto.aniodenacimiento = usuario->aniodenacimiento;
	usuarioObjeto.mesdenacimiento = usuario->mesdenacimiento;
	usuarioObjeto.diadenacimiento = usuario->diadenacimiento;
	usuarioObjeto.correoElectronico = usuario->correoElectronico;
	usuarioObjeto.password = usuario->password;

	return usuarioObjeto;
}

std::locale ConfigurarCaracteres()
{
	// return std::locale::global(std::locale("Spanish.UTF-8"));
	return std::locale();
}

void limpiarCin()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}