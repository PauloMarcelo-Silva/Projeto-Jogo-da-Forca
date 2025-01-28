#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
using namespace std;

class Administrator {
protected:
    string admin;
    string senhaAdmin;

public:
    void setNomeAdmin(const string& admin);
    void setSenhaAdmin(const string& senhaAdmin);
};

#endif // ADMINISTRATOR_H

