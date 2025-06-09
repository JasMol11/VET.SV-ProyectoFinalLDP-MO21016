#include "testData.h"
#include <fstream>
#include <iostream>

using namespace std;

const string ownerFile = "data/owners.bin";
const string patientFile = "data/patients.bin";
const string treatmentFile = "data/treatments.bin";
const string appointmentFile = "data/appointments.bin";

int main() {
    // OWNERS
    vector<Owner> owners = generarOwnersDePrueba();
    ofstream file(ownerFile, ios::binary | ios::trunc);
    if (!file) {
        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cerr << "❌ ERROR AL ABRIR EL ARCHIVO DE DUEÑOS ❌\n";
        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return 1;
    }
    for (const auto& owner : owners) {
        owner.serialize(file);
    }
    file.close();
    cout << "====================================================================\n";
    cout << "✅ DUEÑOS DE PRUEBA GUARDADOS CORRECTAMENTE EN: '" << ownerFile << "' ✅\n";
    cout << "====================================================================\n\n";

    // PATIENTS
    vector<Patient> patients = generarPatientsDePrueba(owners);
    ofstream patientFileOut(patientFile, ios::binary | ios::trunc);
    if (!patientFileOut) {
        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cerr << "❌ ERROR AL ABRIR EL ARCHIVO DE PACIENTES ❌\n";
        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return 1;
    }
    for (const auto& patient : patients) {
        patient.serialize(patientFileOut);
    }
    patientFileOut.close();
    cout << "=========================================================================\n";
    cout << "✅ PACIENTES DE PRUEBA GUARDADOS CORRECTAMENTE EN: '" << patientFile << "' ✅\n";
    cout << "=========================================================================\n\n";

    // TREATMENTS
    vector<Treatment> treatments = generarTreatmentsDePrueba(patients);
    ofstream treatmentFileOut(treatmentFile, ios::binary | ios::trunc);
    if (!treatmentFileOut) {
        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cerr << "❌ ERROR AL ABRIR EL ARCHIVO DE TRATAMIENTOS ❌\n";
        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return 1;
    }
    for (const auto& treatment : treatments) {
        treatment.serialize(treatmentFileOut);
    }
    treatmentFileOut.close();
    cout << "==============================================================================\n";
    cout << "✅ TRATAMIENTOS DE PRUEBA GUARDADOS CORRECTAMENTE EN: '" << treatmentFile << "' ✅\n";
    cout << "==============================================================================\n\n";

    // APPOINTMENTS
    vector<Appointment> appointments = generarAppointmentsDePrueba(patients);
    ofstream appointmentFileOut(appointmentFile, ios::binary | ios::trunc);
    if (!appointmentFileOut) {
        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cerr << "❌ ERROR AL ABRIR EL ARCHIVO DE CITAS ❌\n";
        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return 1;
    }
    for (const auto& appointment : appointments) {
        appointment.serialize(appointmentFileOut);
    }
    appointmentFileOut.close();
    cout << "=========================================================================\n";
    cout << "✅ CITAS DE PRUEBA GUARDADAS CORRECTAMENTE EN: '" << appointmentFile << "' ✅\n";
    cout << "=========================================================================\n\n";

    return 0;
}