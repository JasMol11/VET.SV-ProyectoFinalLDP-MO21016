#ifndef MANAGE_OWNERS_H
#define MANAGE_OWNERS_H

#include <string>
#include "../entities/owner.h"

using namespace std;

void agregarDueno();
void buscarDueno();
void editarDueno();
bool duenoExiste(const string& dui, Owner& encontrado);
bool validarDUI(const string& dui);
bool validarTelefono(const string& phone);

#endif
