#include "appointment.h"
#include <iostream>
using namespace std;

Appointment::Appointment() : id(0), patientId(0), date(""), time(""), reason("") {}

Appointment::Appointment(int id, int patientId, string date, string time, string reason)
    : id(id), patientId(patientId), date(date), time(time), reason(reason) {}

int Appointment::getId() const { return id; }
int Appointment::getPatientId() const { return patientId; }
string Appointment::getDate() const { return date; }
string Appointment::getTime() const { return time; }
string Appointment::getReason() const { return reason; }

void Appointment::setDate(const string& d) { date = d; }
void Appointment::setTime(const string& t) { time = t; }
void Appointment::setReason(const string& r) { reason = r; }

void Appointment::showData() const {
    cout << "\n-----------------------------\n";
    cout << "-------- CITA MÉDICA --------\n";
    cout << "-----------------------------\n";
    cout << "ID Cita: " << id << endl;
    cout << "ID Paciente: " << patientId << endl;
    cout << "Fecha: " << date << endl;
    cout << "Hora: " << time << endl;
    cout << "Motivo: " << reason << endl;
    cout << "-----------------------------\n";
}

void Appointment::serialize(ostream& out) const {
    out.write(reinterpret_cast<const char*>(&id), sizeof(id));
    out.write(reinterpret_cast<const char*>(&patientId), sizeof(patientId));

    size_t len;

    len = date.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(date.c_str(), len);

    len = time.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(time.c_str(), len);

    len = reason.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(reason.c_str(), len);
}

void Appointment::deserialize(istream& in) {
    in.read(reinterpret_cast<char*>(&id), sizeof(id));
    in.read(reinterpret_cast<char*>(&patientId), sizeof(patientId));

    size_t len;

    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    date.resize(len);
    in.read(&date[0], len);

    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    time.resize(len);
    in.read(&time[0], len);

    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    reason.resize(len);
    in.read(&reason[0], len);
}
