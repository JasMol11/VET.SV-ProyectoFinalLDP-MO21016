#include "patient.h"
#include <iostream>
using namespace std;

Patient::Patient() : id(0), name(""), species(""), breed(""), age(0), ownerDUI("") {}

Patient::Patient(int id, string name, string species, string breed, int age, string ownerDUI)
    : id(id), name(name), species(species), breed(breed), age(age), ownerDUI(ownerDUI) {}

int Patient::getId() const { return id; }
string Patient::getName() const { return name; }
string Patient::getSpecies() const { return species; }
string Patient::getBreed() const { return breed; }
int Patient::getAge() const { return age; }
string Patient::getOwnerDUI() const { return ownerDUI; }

void Patient::setName(const string& n) { name = n; }
void Patient::setSpecies(const string& s) { species = s; }
void Patient::setBreed(const string& b) { breed = b; }
void Patient::setAge(int a) { age = a; }
void Patient::setOwnerDUI(const string& d) { ownerDUI = d; }

void Patient::showData() const {
    cout << "\n----------------------------\n";
    cout << "---- DATOS DEL PACIENTE ----\n";
    cout << "----------------------------\n";
    cout << "ID_Paciente: " << id << endl;
    cout << "Nombre: " << name << endl;
    cout << "Especie: " << species << endl;
    cout << "Raza: " << breed << endl;
    cout << "Edad: " << age << " años\n";
    cout << "DUI_Dueño: " << ownerDUI << endl;
    cout << "----------------------------\n";
}


void Patient::serialize(std::ostream& os) const {
    os.write(reinterpret_cast<const char*>(&id), sizeof(id));

    size_t len;

    len = name.size();
    os.write(reinterpret_cast<const char*>(&len), sizeof(len));
    os.write(name.c_str(), len);

    len = species.size();
    os.write(reinterpret_cast<const char*>(&len), sizeof(len));
    os.write(species.c_str(), len);

    len = breed.size();
    os.write(reinterpret_cast<const char*>(&len), sizeof(len));
    os.write(breed.c_str(), len);

    os.write(reinterpret_cast<const char*>(&age), sizeof(age));

    len = ownerDUI.size();
    os.write(reinterpret_cast<const char*>(&len), sizeof(len));
    os.write(ownerDUI.c_str(), len);
}

void Patient::deserialize(std::istream& is) {
    is.read(reinterpret_cast<char*>(&id), sizeof(id));

    size_t len;
    char buffer[1024];

    is.read(reinterpret_cast<char*>(&len), sizeof(len));
    is.read(buffer, len);
    name.assign(buffer, len);

    is.read(reinterpret_cast<char*>(&len), sizeof(len));
    is.read(buffer, len);
    species.assign(buffer, len);

    is.read(reinterpret_cast<char*>(&len), sizeof(len));
    is.read(buffer, len);
    breed.assign(buffer, len);

    is.read(reinterpret_cast<char*>(&age), sizeof(age));

    is.read(reinterpret_cast<char*>(&len), sizeof(len));
    is.read(buffer, len);
    ownerDUI.assign(buffer, len);
}
