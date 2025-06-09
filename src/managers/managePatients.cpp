#include "managePatients.h"
#include "../entities/patient.h"
#include "../entities/owner.h"
#include "../managers/manageOwners.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const string patientFile = "data/patients.bin";
const string ownerFile = "data/owners.bin";

int generarIdPaciente() {
    ifstream file(patientFile, ios::binary);
    Patient p;
    int lastId = 0;

    while (true) {
        p.deserialize(file);
        if (file.eof()) break;
        lastId = p.getId();
    }

    return lastId + 1;
}

bool validarCamposPaciente(const string& name, const string& species, const string& breed, const string& ownerDUI, int age) {
    return !name.empty() && !species.empty() && !breed.empty() && !ownerDUI.empty() && age > 0;
}

bool verificarDuenoExistente(const string& dui) {
    ifstream file(ownerFile, ios::binary);
    if (!file) return false;

    Owner o;
    while (!file.eof()) {
        o.deserialize(file);
        if (file.eof()) break;

        if (o.getDUI() == dui) return true;
    }

    return false;
}

void agregarPaciente() {
    ofstream file(patientFile, ios::binary | ios::app);
    if (!file) {
        cerr << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cerr << "NO SE PUDO ABRIR EL ARCHIVO DE PACIENTES\n";
        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        return;
    }

    int id = generarIdPaciente();
    string name, species, breed, ownerDUI;
    int age;

    cout << "====================================\n";
    cout << "========= AGREGAR PACIENTE =========\n";
    cout << "====================================\n";

    cin.ignore();

    do {
        cout << "Ingrese DUI del dueño (########-#): ";
        getline(cin, ownerDUI);

        if (!validarDUI(ownerDUI)) {
            cout << "\n⚠️ Formato inválido - Intente de nuevo ⚠️ \n\n";
        }
    } while (!validarDUI(ownerDUI));

    if (!verificarDuenoExistente(ownerDUI)) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "⚠️ No existe un dueño registrado con ese DUI ⚠️\n";
        cout << "          Debe registrarlo primero\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return;
    }

    cout << "Ingrese nombre del paciente: ";
    getline(cin, name);

    cout << "Ingrese especie: ";
    getline(cin, species);

    cout << "Ingrese raza: ";
    getline(cin, breed);

    cout << "Ingrese edad: ";
    cin >> age;
    cin.ignore();

    if (!validarCamposPaciente(name, species, breed, ownerDUI, age)) {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "⚠️ Todos los campos deben estar completos ⚠️\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return;
    }

    Patient duplicado;
    if (buscarPacienteDuplicado(name, ownerDUI, duplicado)) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "⚠️ El paciente ya está registrado ⚠️\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        duplicado.showData();
        return;
    }

    Patient p(id, name, species, breed, age, ownerDUI);
    p.serialize(file);
    file.close();

    cout << "\n-------------------------------------\n";
    cout << "✅ PACIENTE AGREGADO CORRECTAMENTE ✅\n";
    cout << "-------------------------------------";
}

void buscarPaciente() {
    ifstream file(patientFile, ios::binary);
    if (!file) {
        cerr << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cerr << "❌ NO SE PUDO ABRIR EL ARCHIVO DE PACIENTES ❌\n";
        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return;
    }

    int idBuscado;
    cout << "===================================\n";
    cout << "========= BUSCAR PACIENTE =========\n";
    cout << "===================================\n";
    cout << "\nIngrese ID del paciente a buscar: ";
    cin >> idBuscado;

    Patient p;
    bool encontrado = false;

    while (!file.eof()) {
        p.deserialize(file);
        if (file.eof()) break;

        if (p.getId() == idBuscado) {
            p.showData();
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "\n---------------------------------------\n";
        cout << "❌❌❌❌ PACIENTE NO ENCONTRADO ❌❌❌❌\n";
        cout << "---------------------------------------";
    }

    file.close();
}

void editarPaciente() {
    fstream file(patientFile, ios::in | ios::out | ios::binary);
    if (!file) {
        cerr << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cerr << "❌ NO SE PUDO ABRIR EL ARCHIVO DE PACIENTES ❌\n";
        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return;
    }

    int idBuscado;
    cout << "===================================\n";
    cout << "========= EDITAR PACIENTE =========\n";
    cout << "===================================\n";
    cout << "\nIngrese ID del paciente a editar: ";
    cin >> idBuscado;

    Patient p;
    bool encontrado = false;
    streampos pos;

    while (!file.eof()) {
        pos = file.tellg();
        p.deserialize(file);
        if (file.eof()) break;

        if (p.getId() == idBuscado) {
            cout << "\n======================================\n";
            cout << "=========== DATOS ACTUALES ===========\n";
            cout << "======================================\n";
            p.showData();

            string name, species, breed, ownerDUI;
            int age;

            cout << "\n\n======================================\n";
            cout << "============ DATOS NUEVOS ============\n";
            cout << "======================================\n";
            cin.ignore();
            cout << "Ingrese nuevo nombre: ";
            getline(cin, name);
            cout << "Ingrese nueva especie: ";
            getline(cin, species);
            cout << "Ingrese nueva raza: ";
            getline(cin, breed);
            cout << "Ingrese nueva edad: ";
            cin >> age;
            cin.ignore();
            cout << "Ingrese nuevo DUI del dueño: ";
            getline(cin, ownerDUI);

            p.setName(name);
            p.setSpecies(species);
            p.setBreed(breed);
            p.setAge(age);
            p.setOwnerDUI(ownerDUI);

            file.seekp(pos);
            p.serialize(file);

            cout << "\n--------------------------------------\n";
            cout << "✅ PACIENTE EDITADO CORRECTAMENTE ✅\n";
            cout << "--------------------------------------";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "\n---------------------------------------\n";
        cout << "❌❌❌❌ PACIENTE NO ENCONTRADO ❌❌❌❌\n";
        cout << "---------------------------------------";
    }

    file.close();
}

bool pacienteExiste(const string& name, const string& ownerDUI) {
    ifstream file(patientFile, ios::binary);
    if (!file) return false;

    Patient p;
    while (!file.eof()) {
        p.deserialize(file);
        if (file.eof()) break;

        if (p.getName() == name && p.getOwnerDUI() == ownerDUI) {
            return true;
        }
    }

    return false;
}

bool buscarPacienteDuplicado(const string& name, const string& ownerDUI, Patient& encontrado) {
    ifstream file(patientFile, ios::binary);
    if (!file) return false;

    Patient p;
    while (!file.eof()) {
        p.deserialize(file);
        if (file.eof()) break;

        if (p.getName() == name && p.getOwnerDUI() == ownerDUI) {
            encontrado = p;
            return true;
        }
    }

    return false;
}
