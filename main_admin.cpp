#include <iostream>
#include <string>
#include "shared/classes/repository.h"
#include "shared/classes/produs.h"
#include "shared/classes/rezervare.h"
#include "shared/classes/admin.h"

using namespace std;
void usageAdmin() { cout << "Comenzile fisierului main_admin:\n  afisare_produse\n  adaugare_produs <nume> <cant> <pret>\n  stergere_produs <nume>\n  cautare_produs <nume>\n  rezervare <nume> <cant>\n  afisare_rezervari\n"; }
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        usageAdmin();
        return 1;
    }
    Repository<Produs> rp("shared/files/produse.csv");
    Repository<Rezervare> rr("shared/files/rezervari.csv");
    Administrator a(rp, rr);
    string c = argv[1];
    if (c == "afisare_produse")
        a.afisareProduse();
    else if (c == "adaugare_produs" && argc == 5)
        a.adaugareProdus(Produs(argv[2], stoi(argv[3]), stof(argv[4])));
    else if (c == "stergere_produs" && argc == 3)
        a.stergereProdus(argv[2]);
    else if (c == "cautare_produs" && argc == 3)
        a.cautareProdus(argv[2]);
    else if (c == "rezervare" && argc == 4)
        a.rezervare(argv[2], stoi(argv[3]));
    else if (c == "afisare_rezervari")
        a.afisareRezervari();
    else
    {
        usageAdmin();
        return 1;
    }
    return 0;
}
