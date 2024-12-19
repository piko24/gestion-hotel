#ifndef CLIENT_H
#define CLIENT_H

#include <string>
//33
using namespace std;

class Client {
private:
    int identifiant;
    string nom;
    string prenom;
    string adresse;

public:
    Client(); 
    Client(int identifiant, const string& nom, const string& prenom, const string& adresse);

    void saisir(); 
    void afficher() const; 

    int getIdentifiant() const;
    string getNom() const;
    string getPrenom() const;
    string getAdresse() const;

    void setIdentifiant(int identifiant);
    void setNom(const string& nom);
    void setPrenom(const string& prenom);
    void setAdresse(const string& adresse);
};

#endif

