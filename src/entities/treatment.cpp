#include "treatment.h"

Treatment::Treatment() : id(0), patientId(0) {
    strcpy(medicine, "");
    strcpy(dosage, "");
    strcpy(period, "");
}

Treatment::Treatment(int id, int patientId, const char* medicine, const char* dosage, const char* period)
    : id(id), patientId(patientId) {
    strncpy(this->medicine, medicine, sizeof(this->medicine));
    this->medicine[sizeof(this->medicine) - 1] = '\0';

    strncpy(this->dosage, dosage, sizeof(this->dosage));
    this->dosage[sizeof(this->dosage) - 1] = '\0';

    strncpy(this->period, period, sizeof(this->period));
    this->period[sizeof(this->period) - 1] = '\0';
}

int Treatment::getId() const { return id; }
int Treatment::getPatientId() const { return patientId; }
const char* Treatment::getMedicine() const { return medicine; }
const char* Treatment::getDosage() const { return dosage; }
const char* Treatment::getPeriod() const { return period; }

void Treatment::setMedicine(const char* m) {
    strncpy(medicine, m, sizeof(medicine));
    medicine[sizeof(medicine) - 1] = '\0';
}

void Treatment::setDosage(const char* d) {
    strncpy(dosage, d, sizeof(dosage));
    dosage[sizeof(dosage) - 1] = '\0';
}

void Treatment::setPeriod(const char* p) {
    strncpy(period, p, sizeof(period));
    period[sizeof(period) - 1] = '\0';
}

void Treatment::showData() const {
    cout << "\n-------------------------------\n";
    cout << "--------- TRATAMIENTO ---------\n";
    cout << "-------------------------------\n";
    cout << "ID_Tratamiento: " << id << endl;
    cout << "ID_Paciente: " << patientId << endl;
    cout << "Medicamento: " << medicine << endl;
    cout << "Dosis: " << dosage << endl;
    cout << "Periodo: " << period << endl;
    cout << "-------------------------------\n";
}


void Treatment::serialize(std::ostream& out) const {
    out.write(reinterpret_cast<const char*>(&id), sizeof(id));
    out.write(reinterpret_cast<const char*>(&patientId), sizeof(patientId));
    out.write(medicine, sizeof(medicine));
    out.write(dosage, sizeof(dosage));
    out.write(period, sizeof(period));
}

void Treatment::deserialize(std::istream& in) {
    in.read(reinterpret_cast<char*>(&id), sizeof(id));
    in.read(reinterpret_cast<char*>(&patientId), sizeof(patientId));
    in.read(medicine, sizeof(medicine));
    in.read(dosage, sizeof(dosage));
    in.read(period, sizeof(period));
}
