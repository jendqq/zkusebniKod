#include "BeznyUcet.h"
#include <iostream>

using namespace std;

BeznyUcet::BeznyUcet(std::string cisloUctu, double poplatek) : Ucet(cisloUctu){
            this->poplatek = poplatek;
        }
void BeznyUcet::vypisInfo() const
{
                Ucet::vypisInfo();
            cout << "Vyse poplatku: " << poplatek <<endl;
}

void BeznyUcet::analyzujUcet() const
{
    int count = 0;
                for (int i = 0; i < historieTransakci.size(); i++){
                    if (historieTransakci[i] < 0){
                        count++;
                    }
                }
                cout << " Celkovy pocet vyberu: " << count<<endl;
}

bool BeznyUcet::operator==(const BeznyUcet &d) const
{
         if (this->poplatek == d.poplatek){
                return true;
            }
            else{
                return false;
            }
}

BeznyUcet &BeznyUcet::operator+=(double castka)
{
      this->pridejTransakci(castka);
            return *this;
}


 ostream &operator<<(ostream &os, const BeznyUcet &d){
            os << "BeznyUcet: " << d.cisloUctu << " transakci: " << d.historieTransakci.size();
            return os;
        }
