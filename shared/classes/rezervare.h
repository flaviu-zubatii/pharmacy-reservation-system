#ifndef REZERVARE_H
#define REZERVARE_H
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class Rezervare
{
private:
    string nume;
    int cant;

public:
    Rezervare();
    Rezervare(const string &, int);
    string getNume() const;
    int getCantitate() const;
    string toCsv() const;
    static Rezervare fromCsv(const string &);
    friend ostream &operator<<(ostream &, const Rezervare &);
};
#endif