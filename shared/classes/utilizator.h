#ifndef UTILIZATOR_H
#define UTILIZATOR_H
#include "repository.h"
#include "produs.h"
#include "rezervare.h"
#include <iostream>
using namespace std;
class Utilizator
{
protected:
    Repository<Produs> &repoP;
    Repository<Rezervare> &repoR;

public:
    Utilizator(Repository<Produs> &p, Repository<Rezervare> &r) : repoP(p), repoR(r) {}
    virtual void afisareProduse() const
    {
        repoP.for_each([](auto &x)
                       { cout << x << "\n"; });
    }
    virtual void cautareProdus(const string &n) const
    {
        bool f = false;
        repoP.for_each([&](auto &x)
                       {if(x.getNume()==n){cout<<x<<"\n";f=true;} });
        if (!f)
            cout << "Produs negasit\n";
    }
    virtual void rezervare(const string &n, int c)
    {
        bool f = false;
        auto &v = const_cast<vector<Produs> &>(repoP.getAll());
        for (auto &x : v)
            if (x.getNume() == n)
            {
                f = true;
                if (c > x.getCantitate())
                    cout << "Stoc insuficient\n";
                else
                {
                    x.setCantitate(x.getCantitate() - c);
                    repoR.add(Rezervare(n, c));
                    repoP.saveAll();
                    cout << "Rezervare efectuata\n";
                }
                break;
            }
        if (!f)
            cout << "Produs negasit\n";
    }
    virtual void afisareRezervari() const
    {
        repoR.for_each([](auto &x)
                       { cout << x << "\n"; });
    }
    virtual ~Utilizator() {}
};
#endif