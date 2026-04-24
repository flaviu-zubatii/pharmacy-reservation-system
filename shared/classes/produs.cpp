#include "produs.h"
using namespace std;

Produs::Produs() : nume(""), cantitate(0), pret(0) {}

Produs::Produs(const string &n, int c, float p) : nume(n), cantitate(c), pret(p) {}

string Produs::getNume() const { return nume; }

int Produs::getCantitate() const { return cantitate; }

float Produs::getPret() const { return pret; }

void Produs::setCantitate(int c) { cantitate = c; }

string Produs::toString() const
{
    ostringstream o;
    o << nume << " - " << pret << " RON (" << cantitate << " buc)";
    return o.str();
}

string Produs::toCsv() const { return nume + "," + to_string(cantitate) + "," + to_string(pret); }

Produs Produs::fromCsv(const string &csv)
{
    istringstream s(csv);
    string n;
    int c;
    float p;
    getline(s, n, ',');
    s >> c;
    s.ignore(1);
    s >> p;
    return {n, c, p};
}

ostream &operator<<(ostream &os, const Produs &p)
{
    os << p.toString();
    return os;
}