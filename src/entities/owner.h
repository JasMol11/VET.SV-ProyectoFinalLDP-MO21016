#ifndef OWNER_H
#define OWNER_H

#include <string>
#include <fstream>
using namespace std;

class Owner {
private:
    int id;
    string name;
    string address;
    string dui;
    string phone;

public:
    Owner();
    Owner(int, string, string, string, string);

    int getId() const;
    string getName() const;
    string getAddress() const;
    string getDUI() const;
    string getPhone() const;

    void setName(const string&);
    void setAddress(const string&);
    void setDUI(const string&);
    void setPhone(const string&);

    void showData() const;

    void serialize(ostream&) const;
    void deserialize(istream&);

};

#endif
