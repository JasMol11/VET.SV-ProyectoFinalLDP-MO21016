#include "testData.h"

// OWNERS
std::vector<Owner> generarOwnersDePrueba() {
    return {
        Owner(1, "Ana López", "Calle El Mirador #123", "12345678-9", "70112233"),
        Owner(2, "Carlos Pérez", "Av. Independencia #45", "87654321-0", "78901234"),
        Owner(3, "Laura Ramírez", "Col. Escalón, Casa 12", "10293847-1", "74561238"),
        Owner(4, "Jorge Torres", "Barrio San Miguel, Casa 78", "11223344-5", "76543210"),
        Owner(5, "María Méndez", "Residencial El Trebol, #98", "99887766-2", "73456789"),
        Owner(6, "Luis González", "Zona Rosa, Apartamento 3B", "22334455-6", "71234567"),
        Owner(7, "Lucía Martínez", "Santa Tecla, Casa 34", "33445566-7", "70123456"),
        Owner(8, "Raúl Gutiérrez", "Soyapango, Col. San José", "44556677-8", "79876543"),
        Owner(9, "Isabel Rivas", "San Marcos, Pasaje 2", "55667788-9", "75553311"),
        Owner(10, "José Castillo", "Mejicanos, Calle Central", "66778899-0", "79998877")
    };
}


// PATIENTS
std::vector<Patient> generarPatientsDePrueba(const std::vector<Owner>& owners) {
    std::vector<Patient> patients;
    int id = 1;

    patients.push_back(Patient(id++, "Max", "Perro", "Labrador", 5, owners[0].getDUI()));
    patients.push_back(Patient(id++, "Luna", "Gato", "Siamés", 3, owners[0].getDUI()));

    patients.push_back(Patient(id++, "Rocky", "Perro", "Bulldog", 4, owners[1].getDUI()));
    patients.push_back(Patient(id++, "Misha", "Gato", "Persa", 2, owners[1].getDUI()));

    patients.push_back(Patient(id++, "Bobby", "Perro", "Pug", 6, owners[2].getDUI()));
    patients.push_back(Patient(id++, "Kira", "Gato", "Bengala", 1, owners[2].getDUI()));

    patients.push_back(Patient(id++, "Toby", "Perro", "Golden Retriever", 3, owners[3].getDUI()));
    patients.push_back(Patient(id++, "Nala", "Gato", "Maine Coon", 5, owners[3].getDUI()));

    patients.push_back(Patient(id++, "Chispa", "Perro", "Chihuahua", 7, owners[4].getDUI()));
    patients.push_back(Patient(id++, "Milo", "Gato", "Angora", 4, owners[4].getDUI()));

    patients.push_back(Patient(id++, "Zeus", "Perro", "Doberman", 2, owners[5].getDUI()));
    patients.push_back(Patient(id++, "Cleo", "Gato", "Ragdoll", 6, owners[5].getDUI()));

    return patients;
}


// TREATMENTS
std::vector<Treatment> generarTreatmentsDePrueba(const std::vector<Patient>& patients) {
    std::vector<Treatment> treatments;
    int id = 1;

    treatments.push_back(Treatment(id++, patients[0].getId(), "Antibiótico A", "1 tableta cada 12h", "7 días"));
    treatments.push_back(Treatment(id++, patients[1].getId(), "Antiinflamatorio B", "2 gotas cada 8h", "5 días"));
    treatments.push_back(Treatment(id++, patients[2].getId(), "Vitaminas C", "1 cápsula diaria", "14 días"));
    treatments.push_back(Treatment(id++, patients[3].getId(), "Antiparasitario D", "1 ml cada 24h", "3 días"));
    treatments.push_back(Treatment(id++, patients[4].getId(), "Analgésico E", "1 tableta cada 8h", "4 días"));
    treatments.push_back(Treatment(id++, patients[5].getId(), "Antibiótico F", "1 ml cada 6h", "10 días"));

    return treatments;
}


// APPOINTMENTS
std::vector<Appointment> generarAppointmentsDePrueba(const std::vector<Patient>& patients) {
    std::vector<Appointment> appointments;
    int id = 1;

    appointments.push_back(Appointment(id++, patients[0].getId(), "01-06-2025", "10:00", "Vacunación anual"));
    appointments.push_back(Appointment(id++, patients[1].getId(), "02-06-2025", "11:30", "Revisión de rutina"));
    appointments.push_back(Appointment(id++, patients[2].getId(), "03-06-2025", "09:00", "Consulta por alergias"));
    appointments.push_back(Appointment(id++, patients[3].getId(), "04-06-2025", "13:00", "Desparasitación"));
    appointments.push_back(Appointment(id++, patients[4].getId(), "05-06-2025", "14:30", "Control postoperatorio"));
    appointments.push_back(Appointment(id++, patients[5].getId(), "06-06-2025", "12:00", "Chequeo dental"));

    return appointments;
}
