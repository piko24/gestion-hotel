#include "Reservation.h"
#include <iostream>
#include <sstream>
#include <ctime>
//66
Reservation::Reservation() : code(""), nombreChambres(0), etat(false), dateDebut(""), dateFin("") {}

void Reservation::saisir() {
    cout << "Entrez le code de la r�servation : ";
    cin >> code;
    cout << "Entrez la date de d�but (format : jj/mm/aaaa) : ";
    cin >> dateDebut;
    cout << "Entrez la date de fin (format : jj/mm/aaaa) : ";
    cin >> dateFin;

    client.saisir();

    cout << "Combien de chambres voulez-vous r�server ? ";
    cin >> nombreChambres;

    for (int i = 0; i < nombreChambres; i++) {
        Chambre chambre;
        chambre.saisir();
        if (!ajouterChambre(chambre)) {
            cout << "Impossible d'ajouter la chambre (elle est d�j� r�serv�e ou d�passe le nombre autoris�)." << endl;
        }
    }
}

void Reservation::afficher() const {
    cout << "Code de r�servation : " << code << endl;
    cout << "Date de d�but : " << dateDebut << endl;
    cout << "Date de fin : " << dateFin << endl;
    client.afficher();
    cout << "Chambres r�serv�es :" << endl;
    for (int i = 0; i < chambresReservees.size(); i++) {
        chambresReservees[i].afficher();
    }
    cout << "�tat de la r�servation : " << (etat ? "Valid�e" : "Annul�e") << endl;
}

bool Reservation::verifierChambreReservee(int idChambre) const {
    for (int i = 0; i < chambresReservees.size(); i++) {
        if (chambresReservees[i].getId() == idChambre) {
            return true;
        }
    }
    return false;
}

bool Reservation::ajouterChambre(const Chambre& chambre) {
    if (verifierChambreReservee(chambre.getId())) {
        return false;
    }
    chambresReservees.push_back(chambre);
    return true;
}

bool Reservation::supprimerChambre(int idChambre) {
    for (int i = 0; i < chambresReservees.size(); ++i) {
        if (chambresReservees[i].getId() == idChambre) {
            chambresReservees.erase(chambresReservees.begin() + i);
            return true;
        }
    }
    return false;
}

void Reservation::validerReservation() {
    etat = true;
}

void Reservation::annulerReservation() {
    etat = false;
}

int Reservation::calculerDuree() const {
    int jourDebut, moisDebut, anneeDebut;
    int jourFin, moisFin, anneeFin;

    // Extraction des dates
    istringstream issDebut(dateDebut);
    istringstream issFin(dateFin);

    char sep;
    issDebut >> jourDebut >> sep >> moisDebut >> sep >> anneeDebut;
    issFin >> jourFin >> sep >> moisFin >> sep >> anneeFin;

    struct tm debut = {0, 0, 0, jourDebut, moisDebut - 1, anneeDebut - 1900};
    struct tm fin = {0, 0, 0, jourFin, moisFin - 1, anneeFin - 1900};

    time_t timeDebut = mktime(&debut);
    time_t timeFin = mktime(&fin);

    return static_cast<int>(difftime(timeFin, timeDebut) / (
60 * 60 * 24)); }
string Reservation::getCode() const { return code; }


