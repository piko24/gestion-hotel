#include "Chambre.h"
#include <iostream>
//44
Chambre::Chambre() : id(0), telephone("") {}

Chambre::Chambre(int id, const string& telephone) : id(id), telephone(telephone) {}

void Chambre::saisir() {
    cout << "Entrez l'ID de la chambre : ";
    cin >> id;
    cout << "Entrez le num�ro de t�l�phone : ";
    cin.ignore();
    getline(cin, telephone);
}

void Chambre::afficher() const {
    cout << "Chambre ID : " << id << ", T�l�phone : " << telephone << endl;
}

int Chambre::getId() const {
    return id;
}

string Chambre::getTelephone() const {
    return telephone;
}

void Chambre::setId(int id) {
    this->id = id;
}

void Chambre::setTelephone(const string& telephone) {
    this->telephone = telephone;
}

bool Chambre::comparer(const Chambre& autre) const {
    return id == autre.id;
}
