#ifndef TREATMENT_H
#define TREATMENT_H

#include <cstring>
#include <iostream>
using namespace std;

class Treatment {
private:
    int id;
    int patientId;
    char medicine[50];
    char dosage[50];
    char period[30];

public:
    Treatment();
    Treatment(int, int, const char*, const char*, const char*);

    int getId() const;
    int getPatientId() const;
    const char* getMedicine() const;
    const char* getDosage() const;
    const char* getPeriod() const;

    void setMedicine(const char*);
    void setDosage(const char*);
    void setPeriod(const char*);

    void showData() const;

    void serialize(std::ostream& out) const;
    void deserialize(std::istream& in);
};

#endif
