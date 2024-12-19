#ifndef CHAMBRE_H
#define CHAMBRE_H

#include <string>
//55
using namespace std;

class Chambre {
private:
    int id;
    string telephone;

public:
    Chambre(); 
    Chambre(int id, const string& telephone);

    void saisir(); 
    void afficher() const; 

    int getId() const;
    string getTelephone() const;

    void setId(int id);
    void setTelephone(const string& telephone);

    bool comparer(const Chambre& autre) const;
};

#endif
