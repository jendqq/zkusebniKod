#include "SporiciUcet.h"
#include <iostream>

using namespace std;

SporiciUcet::SporiciUcet(string cisloUctu, double urokovaSazba): Ucet(cisloUctu){
            this->urokovaSazba = urokovaSazba;
        }

void SporiciUcet::vypisInfo() const
{
                Ucet::vypisInfo();
            cout << "Vyse uroku: " <<urokovaSazba<<endl;
}

void SporiciUcet::analyzujUcet() const
{
         double avg = 0;
            double sum = 0; 
            int count = 0;
            for (int i = 0; i < historieTransakci.size(); i++){
                if (historieTransakci[i] > 0){
                    sum+=historieTransakci[i];
                    count++;
                }
            }
            if (count > 0){
                avg = sum / count;
                cout << "Prumerna vyse je: " << avg<<endl;
            }
            else{
                cout << "zadny vklad"<<endl;
            }
        }
