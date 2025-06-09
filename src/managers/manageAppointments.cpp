#include "manageAppointments.h"
#include "../entities/appointment.h"
#include "../entities/patient.h"
#include <fstream>
#include <iostream>
using namespace std;

const string appointmentFile = "data/appointments.bin";
const string patientFile = "data/patients.bin";

int generarIdCita() {
    ifstream file(appointmentFile, ios::binary);
    Appointment a;
    int lastId = 0;

    while (!file.eof()) {
        a.deserialize(file);
        if (file.eof()) break;
        lastId = a.getId();
    }

    return lastId + 1;
}

bool validarFecha(const string& fecha) {
    return fecha.size() == 10 && fecha[2] == '-' && fecha[5] == '-';
}

bool validarHora(const string& hora) {
    return hora.size() == 5 && hora[2] == ':';
}

bool pacienteExistePorId(int patientId) {
    ifstream file(patientFile, ios::binary);
    if (!file) return false;

    Patient p;
    while (!file.eof()) {
        p.deserialize(file);
        if (file.eof()) break;

        if (p.getId() == patientId) return true;
    }

    return false;
}

void agregarCita() {
    ofstream file(appointmentFile, ios::binary | ios::app);
    if (!file) {
        cerr << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cerr << "❌ NO SE PUDO ABRIR EL ARCHIVO DE CITAS ❌\n";
        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cerr << "❌ No se pudo abrir el archivo de citas.\n";
        return;
    }

    int id = generarIdCita();
    int patientId;
    string date, time, reason;

    cout << "\n================================\n";
    cout << "========= AGREGAR CITA =========\n";
    cout << "================================\n";

    cout << "Ingrese ID del paciente: ";
    cin >> patientId;
    cin.ignore();

    if (!pacienteExistePorId(patientId)) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "⚠️ NO SE ENCONTRÓ PACIENTE CON ESE ID ⚠️\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return;
    }

    do {
        cout << "Ingrese fecha (DD-MM-AAAA): ";
        getline(cin, date);
        if (!validarFecha(date)) {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "⚠️ FECHA INVÁLIDA - INTENTE DE NUEVO ⚠️\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        }
    } while (!validarFecha(date));

    do {
        cout << "Ingrese hora (HH:MM): ";
        getline(cin, time);
        if (!validarHora(time)) {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "⚠️ HORA INVÁLIDA - INTENTE DE NUEVO ⚠️\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        }
    } while (!validarHora(time));

    cout << "Ingrese motivo: ";
    getline(cin, reason);

    Appointment a(id, patientId, date, time, reason);
    a.serialize(file);

    file.close();
    cout << "\n===================================\n";
    cout << "✅ CITA REGISTRADA CORRECTAMENTE ✅\n";
    cout << "===================================\n";
}

void buscarCita() {
    ifstream file(appointmentFile, ios::binary);
    if (!file) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "❌ NO SE PUDO ABRIR EL ARCHIVO DE CITAS ❌\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return;
    }

    int idBuscado;
    cout << "====================================\n";
    cout << "=========== BUSCAR CITAS ===========\n";
    cout << "====================================\n";
    cout << "Ingrese ID de la cita a buscar: ";
    cin >> idBuscado;

    Appointment a;
    bool encontrada = false;

    while (!file.eof()) {
        a.deserialize(file);
        if (file.eof()) break;

        if (a.getId() == idBuscado) {
            a.showData();
            encontrada = true;
            break;
        }
    }

    if (!encontrada) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "⚠️ CITA NO ENCONTRADA ⚠️\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    }

    file.close();
}

void editarCita() {
    fstream file(appointmentFile, ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cerr << "❌ NO SE PUDO ABRIR EL ARCHIVO DE CITAS ❌\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return;
    }

    int idBuscado;
    cout << "\n===================================\n";
    cout << "=========== EDITAR CITA ===========\n";
    cout << "===================================\n";
    cout << "Ingrese ID de la cita a editar: ";
    cin >> idBuscado;

    Appointment a;
    bool encontrada = false;
    streampos pos;

    while (!file.eof()) {
        pos = file.tellg();
        a.deserialize(file);
        if (file.eof()) break;

        if (a.getId() == idBuscado) {
            cout << "\n======================================\n";
            cout << "=========== DATOS ACTUALES ===========\n";
            cout << "======================================\n";
            a.showData();

            string date, time, reason;
            
            cout << "\n\n======================================\n";
            cout << "============ DATOS NUEVOS ============\n";
            cout << "======================================\n";
            
            cin.ignore();

            do {
                cout << "Nueva fecha (DD-MM-AAAA): ";
                getline(cin, date);
            } while (!validarFecha(date));

            do {
                cout << "Nueva hora (HH:MM): ";
                getline(cin, time);
            } while (!validarHora(time));

            cout << "Nuevo motivo: ";
            getline(cin, reason);

            a.setDate(date);
            a.setTime(time);
            a.setReason(reason);

            file.seekp(pos);
            a.serialize(file);

            cout << "\n====================================\n";
            cout << "✅ CITA ACTUALIZADA CORRECTAMENTE ✅\n";
            cout << "====================================\n";
            encontrada = true;
            break;
        }
    }

    if (!encontrada) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "❌ CITA NO ENCONTRADA ❌\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~\n";
    }

    file.close();
}
