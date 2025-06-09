#include "manageOwners.h"
#include "../entities/owner.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <limits>

using namespace std;

const string ownerFile = "data/owners.bin";

bool validarDUI(const string& dui) {
    regex formatoDUI("^\\d{8}-\\d$");
    return regex_match(dui, formatoDUI);
}

bool validarTelefono(const string& phone) {
    regex formatoTel("^\\d{8}$");
    return regex_match(phone, formatoTel);
}

bool duenoExiste(const string& dui, Owner& encontrado) {
    ifstream file(ownerFile, ios::binary);
    if (!file) return false;

    while (file.peek() != EOF) {
        Owner o;
        o.deserialize(file);
        if (o.getDUI() == dui) {
            encontrado = o;
            return true;
        }
    }

    return false;
}

int generarIdDueno() {
    ifstream file(ownerFile, ios::binary);
    Owner o;
    int lastId = 0;

    while (file.peek() != EOF) {
        o.deserialize(file);
        lastId = o.getId();
    }

    return lastId + 1;
}

void agregarDueno() {
    ofstream file(ownerFile, ios::binary | ios::app);
    if (!file) {
        cerr << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cerr << "❌ NO SE PUDO ABRIR EL ARCHIVO DE DUEÑOS ❌ \n";
        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return;
    }

    int id = generarIdDueno();
    string name, address, dui, phone;

    cout << "=================================\n";
    cout << "========= AGREGAR DUEÑO =========\n";
    cout << "=================================\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    do {
        cout << "Ingrese DUI (########-#): ";
        getline(cin, dui);
        if (!validarDUI(dui)) {
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "⚠️ FORMATO INVÁLIDO - INTENTE DE NUEVO ⚠️\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        }
    } while (!validarDUI(dui));

    Owner duplicado;
    if (duenoExiste(dui, duplicado)) {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "⚠️ YA EXISTE UN DUEÑO CON ESE DUI ⚠️\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        duplicado.showData();
        return;
    }

    cout << "Ingrese Nombre y Apellido: ";
    getline(cin, name);

    do {
        cout << "Ingrese Teléfono (########): ";
        getline(cin, phone);
        if (!validarTelefono(phone)) {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "⚠️ TELÉFONO INVÁLIDO - INTENTE DE NUEVO ⚠️\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        }
    } while (!validarTelefono(phone));

    cout << "Ingrese Dirección: ";
    getline(cin, address);

    Owner o(id, name, address, dui, phone);
    o.serialize(file);
    file.close();

    cout << "\n===================================\n";
    cout << "✅ DUEÑO AGREGADO CORRECTAMENTE ✅\n";
    cout << "===================================\n";

}

void buscarDueno() {
    ifstream file(ownerFile, ios::binary);
    if (!file) {
        cerr << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cerr << "❌ NO SE PUDO ABRIR EL ARCHIVO DE DUEÑOS ❌ \n";
        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return;
    }

    int idBuscado;

    cout << "================================\n";
    cout << "========= BUSCAR DUEÑO =========\n";
    cout << "================================\n";

    cout << "Ingrese ID del dueño a buscar: ";
    cin >> idBuscado;

    Owner o;
    bool encontrado = false;

    while (file.peek() != EOF) {
        o.deserialize(file);
        if (o.getId() == idBuscado) {
            o.showData();
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cerr << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "❌ DUEÑO NO ENCONTRADO ❌\n";
        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~";
    }

    file.close();
}

void editarDueno() {
    fstream file(ownerFile, ios::in | ios::out | ios::binary);
    if (!file) {
        cerr << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cerr << "NO SE PUDO ABRIR EL ARCHIVO DE DUEÑOS\n";
        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return;
    }

    int idBuscado;

    cout << "================================\n";
    cout << "========= EDITAR DUEÑO =========\n";
    cout << "================================\n";

    cout << "\nIngrese ID del Dueño a Editar: ";
    cin >> idBuscado;

    Owner o;
    bool encontrado = false;
    streampos pos;

    while (file.peek() != EOF) {
        pos = file.tellg();
        o.deserialize(file);

        if (o.getId() == idBuscado) {
            cout << "\n======================================\n";
            cout << "=========== DATOS ACTUALES ===========\n";
            cout << "======================================\n";

            o.showData();

            string name, address, dui, phone;

            cout << "\n\n======================================\n";
            cout << "============ DATOS NUEVOS ============\n";
            cout << "======================================\n";
            cin.ignore();
            cout << "Nuevo Nombre: ";
            getline(cin, name);
            cout << "Nueva Dirección: ";
            getline(cin, address);
            cout << "Nuevo DUI: ";
            getline(cin, dui);
            cout << "Nuevo Teléfono: ";
            getline(cin, phone);

            o.setName(name);
            o.setAddress(address);
            o.setDUI(dui);
            o.setPhone(phone);

            file.seekp(pos);
            o.serialize(file);

            cout << "\n==================================\n";
            cout << "✅ DUEÑO EDITADO CORRECTAMENTE ✅\n";
            cout << "==================================\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cerr << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "❌ DUEÑO NO ENCONTRADO ❌\n";
        cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~";
    }

    file.close();
}
