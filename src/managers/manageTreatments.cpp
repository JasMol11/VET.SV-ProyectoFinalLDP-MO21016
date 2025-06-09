#include "manageTreatments.h"
#include "../entities/treatment.h"
#include "../entities/patient.h"
#include "../entities/owner.h"
#include "managePatients.h"
#include "manageOwners.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <cstring>

using namespace std;

const string treatmentFile = "data/treatments.bin";
const string patientFile = "data/patients.bin";

int generarIdTratamiento() {
    ifstream file(treatmentFile, ios::binary);
    Treatment t;
    int lastId = 0;

    while (file) {
        t.deserialize(file);
        if (file) lastId = t.getId();
    }

    return lastId + 1;
}

bool pacienteExiste(int idBuscado, Patient& encontrado) {
    ifstream file(patientFile, ios::binary);
    if (!file) return false;

    Patient p;
    while (file) {
        p.deserialize(file);
        if (file && p.getId() == idBuscado) {
            encontrado = p;
            return true;
        }
    }
    return false;
}

bool buscarPacientePorId(int id, Patient& encontrado) {
    ifstream file(patientFile, ios::binary);
    if (!file) return false;

    Patient p;
    while (file) {
        p.deserialize(file);
        if (file && p.getId() == id) {
            encontrado = p;
            return true;
        }
    }

    return false;
}

void agregarTratamiento() {
    ofstream file(treatmentFile, ios::binary | ios::app);
    if (!file) {
        cerr << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cerr << "❌ NO SE PUDO ABRIR EL ARCHIVO DE TRATAMIENTOS ❌\n";
        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return;
    }

    int id = generarIdTratamiento();
    int patientId;
    string medicamento, dosis, periodo;

    cout << "\n=====================================\n";
    cout << "========= AGREGAR TRATAMIENTO =======\n";
    cout << "=====================================\n";
    cout << "Ingrese ID del paciente: ";
    cin >> patientId;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Patient p;
    if (!buscarPacientePorId(patientId, p)) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "⚠️ NO SE ENCONTRÓ PACIENTE CON ESE ID ⚠️\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        return;
    }
    p.showData();

    cout << "\n-------------------------------------------\n";
    cout << "---------- DATOS DEL TRATAMIENTO ----------\n";
    cout << "-------------------------------------------\n";

    cout << "\nIngrese Nombre del Medicamento: ";
    getline(cin, medicamento);
    cout << "Ingrese Dosis (ej: 1 tableta cada 8h): ";
    getline(cin, dosis);
    cout << "Ingrese Período (ej. 7 días): ";
    getline(cin, periodo);

    cout << "\n-----------------------------------------\n";
    cout << "¿Desea guardar este tratamiento? (s/n): ";
    char confirm;
    cin >> confirm;
    cin.ignore();

    if (tolower(confirm) != 's') {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "❌ REGISTRO CANCELADO POR EL USUARIO ❌\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return;
    }

    Treatment t(id, patientId, medicamento.c_str(), dosis.c_str(), periodo.c_str());
    t.serialize(file);
    file.close();

    cout << "\n==========================================\n";
    cout << "✅ TRATAMIENTO REGISTRADO CORRECTAMENTE ✅\n";
    cout << "==========================================\n";
}

void buscarTratamientosPorPaciente() {
    ifstream file(treatmentFile, ios::binary);
    if (!file) {
        cerr << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cerr << "❌ NO SE PUDO ABRIR EL ARCHIVO DE TRATAMIENTOS ❌\n";
        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return;
    }

    int idPaciente;
    cout << "\n===================================================\n";
    cout << "================ BUSCAR TRATAMIENTOS ==============\n";
    cout << "===================================================\n";
    cout << "Ingrese ID del paciente para buscar tratamientos: ";
    cin >> idPaciente;

    Treatment t;
    bool encontrado = false;

    while (file) {
        t.deserialize(file);
        if (file && t.getPatientId() == idPaciente) {
            t.showData();
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "⚠️ NO SE ENCONTRARON TRATAMIENTOS PARA ESTE PACIENTE ⚠️\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    }

    file.close();
}

void editarTratamiento() {
    fstream file(treatmentFile, ios::in | ios::out | ios::binary);
    if (!file) {
        cerr << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cerr << "❌ NO SE PUDO ABRIR EL ARCHIVO DE TRATAMIENTOS ❌\n";
        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return;
    }

    int idBuscar;
    cout << "\n===================================================\n";
    cout << "================ EDITAR TRATAMIENTOS ==============\n";
    cout << "===================================================\n";
    cout << "Ingrese ID del tratamiento a editar: ";
    cin >> idBuscar;
    cin.ignore();

    Treatment t;
    streampos pos;
    bool encontrado = false;

    while (!file.eof()) {
        pos = file.tellg();
        t.deserialize(file);
        if (!file) break;

        if (t.getId() == idBuscar) {
            cout << "Tratamiento encontrado:\n";
            t.showData();

            string medicine, dosage, period;
            cout << "\nIngrese Nombre del Medicamento: ";
            getline(cin, medicine);
            cout << "Ingrese Dosis (ej: 1 tableta cada 8h): ";
            getline(cin, dosage);
            cout << "Ingrese Período (ej. 7 días): ";
            getline(cin, period);

            if (medicine.empty() || dosage.empty() || period.empty()) {
                cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "⚠️ TODOS LOS CAMPOS DEBEN ESTAR COMPLETOS ⚠️\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                return;
            }

            t.setMedicine(medicine.c_str());
            t.setDosage(dosage.c_str());
            t.setPeriod(period.c_str());

            file.seekp(pos);
            t.serialize(file);

            cout << "\n======================================\n";
            cout << "✅ TRATAMIENTO EDITADO CORRECTAMENTE ✅\n";
            cout << "======================================\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "❌ TRATAMIENTO NO ENCONTRADO ❌\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    }

    file.close();
}
