#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "utilizator.h"
using namespace std;
class Administrator : public Utilizator
{
public:
    Administrator(Repository<Produs> &p, Repository<Rezervare> &r) : Utilizator(p, r) {}
    void adaugareProdus(const Produs &p)
    {
        repoP.add(p);
        cout << "Adaugare ok\n";
    }
    void stergereProdus(const string &n)
    {
        repoP.remove_if([&](auto &x)
                        { return x.getNume() == n; });
        cout << "Stergere ok\n";
    }
};
#endif