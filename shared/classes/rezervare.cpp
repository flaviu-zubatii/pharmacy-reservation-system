#include "rezervare.h"
using namespace std;

Rezervare::Rezervare() : nume(""), cant(0) {}

Rezervare::Rezervare(const string &n, int c) : nume(n), cant(c) {}

string Rezervare::getNume() const { return nume; }

int Rezervare::getCantitate() const { return cant; }

string Rezervare::toCsv() const { return nume + "," + to_string(cant); }

Rezervare Rezervare::fromCsv(const string &csv)
{
    istringstream s(csv);
    string n;
    int c;
    getline(s, n, ',');
    s >> c;
    return {n, c};
}

ostream &operator<<(ostream &os, const Rezervare &r)
{
    os << r.nume << " (" << r.cant << " buc)";
    return os;
}
