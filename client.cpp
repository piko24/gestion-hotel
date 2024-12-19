#include "Client.h"
#include <iostream>
//22
Client::Client() : identifiant(0), nom(""), prenom(""), adresse("") {}

Client::Client(int identifiant, const string& nom, const string& prenom, const string& adresse)
    : identifiant(identifiant), nom(nom), prenom(prenom), adresse(adresse) {}

void Client::saisir() {
    cout << "Entrez l'identifiant du client : ";
    cin >> identifiant;
    cin.ignore();
    cout << "Entrez le nom : ";
    getline(cin, nom);
    cout << "Entrez le prénom : ";
    getline(cin, prenom);
    cout << "Entrez l'adresse : ";
    getline(cin, adresse);
}

void Client::afficher() const {
    cout << "Client ID : " << identifiant << ", Nom : " << nom
         << ", Prénom : " << prenom << ", Adresse : " << adresse << endl;
}

int Client::getIdentifiant() const {
    return identifiant;
}

string Client::getNom() const {
    return nom;
}

string Client::getPrenom() const {
    return prenom;
}

string Client::getAdresse() const {
    return adresse;
}

void Client::setIdentifiant(int identifiant) {
    this->identifiant = identifiant;
}

void Client::setNom(const string& nom) {
    this->nom = nom;
}

void Client::setPrenom(const string& prenom) {
    this->prenom = prenom;
}

void Client::setAdresse(const string& adresse) {
    this->adresse = adresse;
}

