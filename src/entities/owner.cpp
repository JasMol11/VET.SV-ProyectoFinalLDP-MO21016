#include "owner.h"
#include <iostream>
using namespace std;

Owner::Owner() : id(0), name(""), address(""), dui(""), phone("") {}

Owner::Owner(int id, string name, string address, string dui, string phone)
    : id(id), name(name), address(address), dui(dui), phone(phone) {}

int Owner::getId() const { return id; }
string Owner::getName() const { return name; }
string Owner::getAddress() const { return address; }
string Owner::getDUI() const { return dui; }
string Owner::getPhone() const { return phone; }

void Owner::setName(const string& n) { name = n; }
void Owner::setAddress(const string& a) { address = a; }
void Owner::setDUI(const string& d) { dui = d; }
void Owner::setPhone(const string& p) { phone = p; }

void Owner::showData() const {
    cout << "\n-------------------------------\n";
    cout << "------- DATOS DEL DUEÑO -------\n";
    cout << "-------------------------------\n";
    cout << "ID_Dueño: " << id << endl;
    cout << "DUI: " << dui << endl;
    cout << "Nombre: " << name << endl;
    cout << "Dirección: " << address << endl;
    cout << "Teléfono: " << phone << endl;
    cout << "-------------------------------";
}

void Owner::serialize(ostream& out) const {
    out.write(reinterpret_cast<const char*>(&id), sizeof(id));

    size_t len;

    len = name.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(name.c_str(), len);

    len = address.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(address.c_str(), len);

    len = dui.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(dui.c_str(), len);

    len = phone.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(phone.c_str(), len);
}


void Owner::deserialize(istream& in) {
    in.read(reinterpret_cast<char*>(&id), sizeof(id));

    size_t len;

    // Nombre
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    name.resize(len);
    in.read(&name[0], len);

    // Dirección
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    address.resize(len);
    in.read(&address[0], len);

    // DUI
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    dui.resize(len);
    in.read(&dui[0], len);

    // Teléfono
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    phone.resize(len);
    in.read(&phone[0], len);
}
