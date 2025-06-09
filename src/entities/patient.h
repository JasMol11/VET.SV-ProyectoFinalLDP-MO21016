#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <iostream>
using namespace std;

class Patient {
private:
    int id;
    string name;
    string species;
    string breed;
    int age;
    string ownerDUI;

public:
    Patient();
    Patient(int, string, string, string, int, string);

    int getId() const;
    string getName() const;
    string getSpecies() const;
    string getBreed() const;
    int getAge() const;
    string getOwnerDUI() const;

    void setName(const string&);
    void setSpecies(const string&);
    void setBreed(const string&);
    void setAge(int);
    void setOwnerDUI(const string&);

    void showData() const;

    void serialize(std::ostream& os) const;
    void deserialize(std::istream& is);
};

#endif
