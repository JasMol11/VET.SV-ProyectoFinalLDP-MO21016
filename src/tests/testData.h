#ifndef TEST_DATA_H
#define TEST_DATA_H

#include <vector>
#include "../entities/owner.h"
#include "../entities/patient.h"
#include "../entities/treatment.h"
#include "../entities/appointment.h"

using namespace std;

vector<Owner> generarOwnersDePrueba();
vector<Patient> generarPatientsDePrueba(const vector<Owner>& owners);
vector<Treatment> generarTreatmentsDePrueba(const vector<Patient>& patients);
std::vector<Appointment> generarAppointmentsDePrueba(const std::vector<Patient>& patients);

#endif
