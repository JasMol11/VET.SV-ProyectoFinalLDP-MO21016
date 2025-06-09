#ifndef MANAGE_PATIENTS_H
#define MANAGE_PATIENTS_H

#include <string>
#include "../entities/patient.h"

using namespace std;

void agregarPaciente();
void buscarPaciente();
void editarPaciente();

bool pacienteExiste(const string& name, const string& ownerDUI);
bool buscarPacienteDuplicado(const string& name, const string& ownerDUI, Patient& encontrado);

bool validarCamposPaciente(const string& name, const string& species, const string& breed, const string& ownerDUI, int age);
bool verificarDuenoExistente(const string& dui);

#endif
