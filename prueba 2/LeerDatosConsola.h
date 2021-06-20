#pragma once
#include <iostream>
#include <string>

#include "Herramientas.h"
#include "Base64.h"

void LeerDatoConsola(std::string mensaje, std::string& dato, bool esBase64);

void LeerDatoConsola(std::string mensaje, short& dato);
