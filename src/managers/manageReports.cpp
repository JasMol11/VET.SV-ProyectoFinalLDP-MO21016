#include "manageReports.h"
#include "../entities/owner.h"
#include "../entities/patient.h"
#include "../entities/appointment.h"
#include "../entities/treatment.h"


#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

const string ownerFile = "data/owners.bin";
const string patientFile = "data/patients.bin";
const string appointmentFile = "data/appointments.bin";
const string treatmentFile = "data/treatments.bin";


// === REPORTE 1: TODOS LOS DUEÑOS ===
void reporteDueno() {
    ifstream file(ownerFile, ios::binary);
    if (!file) {
        cerr << "\n❌ No se pudo abrir el archivo de dueños\n";
        return;
    }

    cout << "\n====================================\n";
    cout << "==== REPORTE DE TODOS LOS DUEÑOS ===\n";
    cout << "====================================\n";

    Owner o;
    int contador = 0;
    while (file.peek() != EOF) {
        o.deserialize(file);
        o.showData();
        cout << endl;
        contador++;
    }

    if (contador == 0) {
        cout << "⚠️ No hay registros de dueños\n";
    }

    file.close();
}

// === REPORTE 2: PACIENTES REGISTRADOS ===
void reportePacientes() {
    ifstream file(patientFile, ios::binary);
    if (!file) {
        cerr << "\n❌ No se pudo abrir el archivo de pacientes\n";
        return;
    }

    cout << "\n=======================================\n";
    cout << "==== REPORTE DE TODOS LOS PACIENTES ===\n";
    cout << "=======================================\n";

    Patient p;
    int contador = 0;
    while (file.peek() != EOF) {
        p.deserialize(file);
        p.showData();
        cout << endl;
        contador++;
    }

    if (contador == 0) {
        cout << "⚠️ No hay registros de pacientes\n";
    }

    file.close();
}

// === REPORTE 3: CITAS PROGRAMADAS ===
void reporteCitas() {
    ifstream file(appointmentFile, ios::binary);
    if (!file) {
        cerr << "❌ No se pudo abrir el archivo de citas\n";
        return;
    }

    cout << "\n====================================\n";
    cout << "==== REPORTE DE TODAS LAS CITAS ===\n";
    cout << "====================================\n";

    Appointment a;
    int contador = 0;
    while (!file.eof()) {
        a.deserialize(file);
        if (file.eof()) break;

        a.showData();
        contador++;
    }

    if (contador == 0) {
        cout << "⚠️ No hay citas registradas\n";
    }

    file.close();
}

// === REPORTE 4: CITAS POR DUEÑO ===
void citasPorDueno() {
    int pacienteId;
    cout << "Ingrese ID del paciente (mascota): ";
    cin >> pacienteId;

    ifstream file(appointmentFile, ios::binary);
    if (!file) {
        cerr << "❌ No se pudo abrir el archivo de citas.\n";
        return;
    }

    cout << "\n========================================\n";
    cout << "==== REPORTE DE CITAS POR PACIENTE ====\n";
    cout << "========================================\n";

    Appointment a;
    int contador = 0;
    while (!file.eof()) {
        a.deserialize(file);
        if (file.eof()) break;

        if (a.getPatientId() == pacienteId) {
            a.showData();
            contador++;
        }
    }

    if (contador == 0) {
        cout << "⚠️ No hay citas para el paciente con ID " << pacienteId << ".\n";
    }

    file.close();
}

// === REPORTE 5: CITAS POR RANGO DE FECHAS ===
string convertirFechaComparable(const string& fecha) {
    if (fecha.size() != 10) return "";
    return fecha.substr(6, 4) + fecha.substr(3, 2) + fecha.substr(0, 2);  // AAAAMMDD
}

void reporteCitasPorFecha() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer
    string fechaInicio, fechaFin;

    cout << "Ingrese fecha de inicio (DD-MM-AAAA): ";
    getline(cin, fechaInicio);
    cout << "Ingrese fecha de fin (DD-MM-AAAA): ";
    getline(cin, fechaFin);

    string inicio = convertirFechaComparable(fechaInicio);
    string fin = convertirFechaComparable(fechaFin);

    if (inicio.empty() || fin.empty()) {
        cerr << "❌ Formato de fecha no válido.\n";
        return;
    }

    ifstream file(appointmentFile, ios::binary);
    if (!file) {
        cerr << "❌ No se pudo abrir el archivo de citas.\n";
        return;
    }

    cout << "\n=============================================\n";
    cout << "==== CITAS ENTRE " << fechaInicio << " Y " << fechaFin << " ====\n";
    cout << "=============================================\n";

    Appointment a;
    int contador = 0;
    while (!file.eof()) {
        a.deserialize(file);
        if (file.eof()) break;

        string fechaCita = convertirFechaComparable(a.getDate());
        if (fechaCita >= inicio && fechaCita <= fin) {
            a.showData();
            contador++;
        }
    }

    if (contador == 0) {
        cout << "⚠️ No hay citas en ese rango de fechas.\n";
    }

    file.close();
}

// === REPORTE 6: TODOS LOS TRATAMIENTOS ===
void reporteTratamientos() {
    ifstream file(treatmentFile, ios::binary);
    if (!file) {
        cerr << "\n❌ No se pudo abrir el archivo de tratamientos.\n";
        return;
    }

    cout << "\n===========================================\n";
    cout << "==== REPORTE DE TODOS LOS TRATAMIENTOS ====\n";
    cout << "===========================================\n";

    Treatment t;
    int contador = 0;
    while (!file.eof()) {
        t.deserialize(file);
        if (file.eof()) break;

        t.showData();
        cout << endl;
        contador++;
    }

    if (contador == 0) {
        cout << "⚠️ No hay tratamientos registrados.\n";
    }

    file.close();
}
