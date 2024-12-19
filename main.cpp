#include <iostream>
#include <vector>
#include "Chambre.h"
#include "Client.h"
#include "Reservation.h"

using namespace std;
//1

vector<Chambre> chambres;
vector<Client> clients;
vector<Reservation> reservations;


void menuChambres();
void menuClients();
void menuReservations();

int main() {
    int choix;
    do {
        cout << "\n--- Gestion d'Hotel ---" << endl;
        cout << "1. Gerer les Chambres" << endl;
        cout << "2. Gerer les Clients" << endl;
        cout << "3. Gerer les Reservations" << endl;
        cout << "4. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1: menuChambres(); break;
            case 2: menuClients(); break;
            case 3: menuReservations(); break;
            case 4: cout << "Au revoir !" << endl; break;
            default: cout << "Choix invalide, ressayez !" << endl; break;
        }
    } while (choix != 4);

    return 0;
}

// sous menu
void menuChambres() {
    int choix;
    cout << "\n--- Gestion des Chambres ---" << endl;
    cout << "1. Ajouter une chambre" << endl;
    cout << "2. Afficher toutes les chambres" << endl;
    cout << "Votre choix : ";
    cin >> choix;

    if (choix == 1) {
        Chambre chambre;
        chambre.saisir();
        chambres.push_back(chambre);
        cout << "Chambre ajoutée avec succès !" << endl;
    } else if (choix == 2) {
        cout << "\nListe des chambres :" << endl;
        for (size_t i = 0; i < chambres.size(); ++i) {
            chambres[i].afficher();
        }
    } else {
        cout << "Choix invalide !" << endl;
    }
}


void menuClients() {
    int choix;
    cout << "\n--- Gestion des Clients ---" << endl;
    cout << "1. Ajouter un client" << endl;
    cout << "2. Afficher tous les clients" << endl;
    cout << "Votre choix : ";
    cin >> choix;

    if (choix == 1) {
        Client client;
        client.saisir();
        clients.push_back(client);
        cout << "Client ajouté avec succès !" << endl;
    } else if (choix == 2) {
        cout << "\nListe des clients :" << endl;
        for (size_t i = 0; i < clients.size(); ++i) {
            clients[i].afficher();
        }
    } else {
        cout << "Choix invalide !" << endl;
    }
}


void menuReservations() {
    int choix;
    cout << "\n--- Gestion des Réservations ---" << endl;
    cout << "1. Ajouter une réservation" << endl;
    cout << "2. Afficher toutes les réservations" << endl;
    cout << "Votre choix : ";
    cin >> choix;

    if (choix == 1) {
        Reservation reservation;
        reservation.saisir();
        reservations.push_back(reservation);
        cout << "Réservation ajoutée avec succès !" << endl;
    } else if (choix == 2) {
        cout << "\nListe des réservations :" << endl;
        for (size_t i = 0; i < reservations.size(); ++i) {
            reservations[i].afficher();
        }
    } else {
        cout << "Choix invalide !" << endl;
    }
}
