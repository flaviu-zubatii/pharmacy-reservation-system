#include <iostream>
#include <string>
#include "shared/classes/repository.h"
#include "shared/classes/produs.h"
#include "shared/classes/rezervare.h"
#include "shared/classes/utilizator.h"

using namespace std;

void usage() { cout << "Comenzile fisierului main_user: \n  afisare_produse\n  cautare_produs <nume>\n  rezervare <nume> <cant>\n  afisare_rezervari\n"; }
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        usage();
        return 1;
    }
    Repository<Produs> rp("shared/files/produse.csv");
    Repository<Rezervare> rr("shared/files/rezervari.csv");
    Utilizator u(rp, rr);
    string c = argv[1];
    if (c == "afisare_produse")
        u.afisareProduse();
    else if (c == "cautare_produs" && argc == 3)
        u.cautareProdus(argv[2]);
    else if (c == "rezervare" && argc == 4)
        u.rezervare(argv[2], stoi(argv[3]));
    else if (c == "afisare_rezervari")
        u.afisareRezervari();
    else
    {
        usage();
        return 1;
    }
    return 0;
}
