#include "Ucet.h"
#include <iostream>

using namespace std;

Ucet::Ucet(string cisloUctu)
{
      this->cisloUctu = cisloUctu;
            pocetObjektu++;
}

int Ucet::getPocet()
{
    return pocetObjektu;
}

void Ucet::pridejTransakci(double hodnota)
{
    historieTransakci.push_back(hodnota);
}

void Ucet::pridejTransakce(const vector<double> &hodnoty)
{
       for (int i = 0; i < hodnoty.size(); i++){
                historieTransakci.push_back(hodnoty[i]);
            }
}

vector<double> &Ucet::getHistory()
{
     return historieTransakci;
}

Ucet::~Ucet()
{
    pocetObjektu--;
}

void Ucet::vypisInfo() const
{
    cout << " Cislo uctu: " << cisloUctu << " transakci zaznamenano: " << historieTransakci.size() <<endl;
}

int Ucet::pocetObjektu = 0;
