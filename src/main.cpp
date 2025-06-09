#include <iostream>
// Incluir headers de cada módulo de manejo
#include "managers/managePatients.h"
#include "managers/manageOwners.h"
#include "managers/manageTreatments.h"
#include "managers/manageAppointments.h"
#include "managers/manageReports.h"

using namespace std;

// Prototipos
void mostrarMenuPrincipal();
void gestionarPacientes();
void gestionarDuenos();
void gestionarTratamientos();
void gestionarCitas();
void mostrarReportes();

int main() {
    mostrarMenuPrincipal();
    return 0;
}

void mostrarMenuPrincipal() {
    int opcion;

    do {
        system("clear"); // Usar "cls" si estás en Windows
        cout << "=============================================\n";
        cout << "  🐾 SISTEMA DE GESTIÓN - CLÍNICA VET.SV 🐾\n";
        cout << "=============================================\n";
        cout << "1. Gestión de Dueños\n";
        cout << "2. Gestión de Pacientes\n";
        cout << "3. Gestión de Tratamientos\n";
        cout << "4. Gestión de Citas\n";
        cout << "5. Reportes\n";
        cout << "0. Salir\n";
        cout << "---------------------------------------------\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                system("clear");
                gestionarDuenos();
                break;
            case 2:
                system("clear");
                gestionarPacientes();
                break;
            case 3:
                system("clear");
                gestionarTratamientos();
                break;
            case 4:
                system("clear");
                gestionarCitas();
                break;
            case 5:
                system("clear");
                mostrarReportes();
                break;
            case 0:
                system("clear");
                cout << "\n\n==========================\n";
                cout << "⚠️ Saliendo del sistema ⚠️\n";
                cout << "   🐾 ¡Hasta pronto! 🐾\n";
                cout << "==========================\n\n\n";
                break;
            default:
                cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "⚠️ Opción inválida - Intente nuevamente ⚠️\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        }

    } while (opcion != 0);
}

// === GESTIÓN DE DUEÑOS ===
void gestionarDuenos() {
    int opcion;
    bool repetir = true;

    do {
        cout << "===============================\n";
        cout << "====== GESTIÓN DE DUEÑOS ======\n";
        cout << "===============================\n";
        cout << "1. Agregar dueño\n";
        cout << "2. Buscar dueño\n";
        cout << "3. Editar dueño\n";
        cout << "0. Volver al menú principal\n";
        cout << "-------------------------------\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                system("clear");
                agregarDueno();
                break;
            case 2:
                system("clear");
                buscarDueno();
                break;
            case 3:
                system("clear");
                editarDueno();
                break;
            case 0:
                system("clear");
                repetir = false;
                break;
            default:
                cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "⚠️ Opción inválida - Intente nuevamente ⚠️\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        }

        if (opcion >= 1 && opcion <= 3) {
            int respuesta;
            cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "¿Desea realizar otra gestión de Dueños?\n";
            cout << "1. Sí\n";
            cout << "2. No, volver al menú principal\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "Seleccione una opción: ";
            cin >> respuesta;

            if (respuesta == 1) {
                system("clear");
                repetir = true;
            } else {
                repetir = false;
            }
        }

    } while (repetir);
}

// === GESTIÓN DE PACIENTES ===
void gestionarPacientes() {
    int opcion;
    bool repetir = true;

    do {
        cout << "==============================\n";
        cout << "==== GESTIÓN DE PACIENTES ====\n";
        cout << "==============================\n";
        cout << "1. Agregar paciente\n";
        cout << "2. Buscar paciente\n";
        cout << "3. Editar paciente\n";
        cout << "0. Volver al menú principal\n";
        cout << "----------------------------\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                system("clear");
                agregarPaciente();
                break;
            case 2:
                system("clear");
                buscarPaciente();
                break;
            case 3:
                system("clear");
                editarPaciente();
                break;
            case 0:
                system("clear");
                repetir = false;
                break;
            default:
                cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "⚠️ Opción inválida - Intente nuevamente ⚠️\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        }

        if (opcion >= 1 && opcion <= 3) {
            int respuesta;
            cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "¿Desea realizar otra gestión de Pacientes?\n";
            cout << "1. Sí\n";
            cout << "2. No, volver al menú principal\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "Seleccione una opción: ";
            cin >> respuesta;

            if (respuesta == 1) {
                system("clear");
                repetir = true;
            } else {
                repetir = false;
            }
        }

    } while (repetir);
}

// === GESTIÓN DE TRATAMIENTOS ===
void gestionarTratamientos() {
    int opcion;
    bool repetir = true;

    do {
        cout << "=================================\n";
        cout << "==== GESTIÓN DE TRATAMIENTOS ====\n";
        cout << "=================================\n";
        cout << "1. Agregar tratamiento\n";
        cout << "2. Buscar tratamiento\n";
        cout << "3. Editar tratamiento\n";
        cout << "0. Volver al menú principal\n";
        cout << "---------------------------------\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                system("clear");
                agregarTratamiento();
                break;
            case 2:
                system("clear");
                buscarTratamientosPorPaciente();
                break;
            case 3:
                system("clear");
                editarTratamiento();
                break;
            case 0:
                system("clear");
                repetir = false;
                break;
            default:
                cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "⚠️ Opción inválida - Intente nuevamente ⚠️\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        }

        if (opcion >= 1 && opcion <= 3) {
            int respuesta;
            cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "¿Desea realizar otra gestión de Tratamientos?\n";
            cout << "1. Sí\n";
            cout << "2. No, volver al menú principal\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "Seleccione una opción: ";
            cin >> respuesta;

            if (respuesta == 1) {
                system("clear");
                repetir = true;
            } else {
                repetir = false;
            }
        }

    } while (repetir);
}

// === GESTIÓN DE CITAS ===
void gestionarCitas() {
    int opcion;
    bool repetir = true;

    do {
        cout << "==============================\n";
        cout << "====== GESTIÓN DE CITAS ======\n";
        cout << "==============================\n";
        cout << "1. Agendar cita\n";
        cout << "2. Buscar cita\n";
        cout << "3. Editar cita\n";
        cout << "0. Volver al menú principal\n";
        cout << "------------------------------\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                system("clear");
                agregarCita();
                break;
            case 2:
                system("clear");
                buscarCita();
                break;
            case 3:
                system("clear");
                editarCita();
                break;
            case 0:
                system("clear");
                repetir = false;
                break;
            default:
                cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "⚠️ Opción inválida - Intente nuevamente ⚠️\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        }

        if (opcion >= 1 && opcion <= 3) {
            int respuesta;
            cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "¿Desea realizar otra gestión de Citas?\n";
            cout << "1. Sí\n";
            cout << "2. No, volver al menú principal\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "Seleccione una opción: ";
            cin >> respuesta;

            if (respuesta == 1) {
                system("clear");
                repetir = true;
            } else {
                repetir = false;
            }
        }

    } while (repetir);
}

// === REPORTES ===
void mostrarReportes() {
    int opcion;
    bool repetir = true;

    do {
        cout << "================================\n";
        cout << "====== GESTIÓN DE REPORTES =====\n";
        cout << "================================\n";
        cout << "1. Dueños Registrados\n";
        cout << "2. Mascotas Registradas\n";
        cout << "3. Citas Programadas\n";
        cout << "4. Citas por Paciente\n";
        cout << "5. Citas por Rangos de Fechas\n";
        cout << "6. Tratamientos Registrados\n";
        cout << "0. Volver al menú principal\n";
        cout << "--------------------------------\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                system("clear");
                reporteDueno();
                break;
            case 2:
                system("clear");
                reportePacientes();
                break;
            case 3:
                system("clear");
                reporteCitas();
                break;
            case 4:
                system("clear");
                citasPorDueno();
                break;
            case 5:
                system("clear");
                reporteCitasPorFecha();
                break;
            case 6:
                system("clear");
                reporteTratamientos();
                break;
            case 0:
                system("clear");
                repetir = false;
                break;
            default:
                cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "⚠️ Opción inválida - Intente nuevamente ⚠️\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        }

        if (opcion >= 1 && opcion <= 7) {
            int respuesta;
            cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "¿Desea realizar otra gestión de Reportes?\n";
            cout << "1. Sí\n";
            cout << "2. No, volver al menú principal\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "Seleccione una opción: ";
            cin >> respuesta;

            if (respuesta == 1) {
                system("clear");
                repetir = true;
            } else {
                repetir = false;
            }
        }

    } while (repetir);
}
