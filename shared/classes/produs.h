#ifndef PRODUS_H
#define PRODUS_H
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class Produs
{
private:
    string nume;
    int cantitate;
    float pret;

public:
    Produs();
    Produs(const string &, int, float);
    string getNume() const;
    int getCantitate() const;
    float getPret() const;
    void setCantitate(int);
    string toString() const;
    string toCsv() const;
    static Produs fromCsv(const string &);
    friend ostream &operator<<(ostream &, const Produs &);
};
#endif