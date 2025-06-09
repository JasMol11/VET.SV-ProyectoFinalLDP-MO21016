#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include <fstream>
using namespace std;

class Appointment {
private:
    int id;
    int patientId;
    string date;
    string time;
    string reason;

public:
    Appointment();
    Appointment(int, int, string, string, string);

    int getId() const;
    int getPatientId() const;
    string getDate() const;
    string getTime() const;
    string getReason() const;

    void setDate(const string&);
    void setTime(const string&);
    void setReason(const string&);

    void showData() const;

    void serialize(ostream&) const;
    void deserialize(istream&);
};

#endif
