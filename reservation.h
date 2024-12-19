#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <vector>
#include "Chambre.h"
#include "Client.h"
//777
using namespace std;

class Reservation {
private:
    string code;
    int nombreChambres;
    vector<Chambre> chambresReservees;
    Client client;
    bool etat; 
    string dateDebut;
    string dateFin;

public:
    Reservation(); 

    void saisir();
    void afficher() const; 

    bool verifierChambreReservee(int idChambre) const; 
    bool ajouterChambre(const Chambre& chambre); 
    bool supprimerChambre(int idChambre);

    void validerReservation();
    int calculerDuree() const; // Calcule la durée de la réservation
    void annulerReservation(); 

    string getCode() const; 
};

#endif
