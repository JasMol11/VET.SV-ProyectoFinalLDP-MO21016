#ifndef MANAGE_APPOINTMENTS_H
#define MANAGE_APPOINTMENTS_H

#include <string>
using namespace std;

void agregarCita();
void buscarCita();
void editarCita();

int generarIdCita();
bool validarFecha(const string& fecha);
bool validarHora(const string& hora);
bool pacienteExistePorId(int patientId);

#endif
