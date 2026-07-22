#include <iostream>
#include <algorithm>
#include <numeric>
#include "Ucet.h"
#include "SporiciUcet.h"
#include "BeznyUcet.h"

using namespace std;

void nejdelsiVklad(Ucet *ucet){
    int count = 0; 
    int max = 0;
    vector<double> &test = ucet->getHistory();
        for (int i = 0; i < test.size(); i++){
            if (test[i] > 0){
                count++;
            }
            if (count > max){
                max = count;
        
            }
            else if(test[i] < 0){
                count = 0;
            }
        }
        cout << "delka nejdelsi rady je: " << max<<endl;
}

void odstranMale(Ucet *ucet){
    vector<double> &test = ucet->getHistory();
    test.erase(remove_if(test.begin(), test.end(), [](double hodnota){
        return hodnota > -50.0 && hodnota < 0.0;
    }),test.end());
    
}   



int main(){

   cout << " Pocatecni pocet: " << Ucet::getPocet()<<endl;

   vector<Ucet*>seznam;
   seznam.push_back(new BeznyUcet("12547", 9.7));
   seznam.push_back(new BeznyUcet("25425", 9.7));
   seznam.push_back(new SporiciUcet("58620", 2.7));

   seznam[0]->pridejTransakci(8500);
   seznam[0]->pridejTransakci(500);
   seznam[0]->pridejTransakci(-2500);
   seznam[0]->pridejTransakci(2500);
   seznam[0]->pridejTransakci(8500);
   seznam[0]->pridejTransakci(500);
   seznam[0]->pridejTransakci(-2500);
   seznam[0]->pridejTransakci(2500);

    seznam[1]->pridejTransakci(8500);
   seznam[1]->pridejTransakci(500);
   seznam[1]->pridejTransakci(-2500);
   seznam[1]->pridejTransakci(2500);

    seznam[2]->pridejTransakci(8500);
   seznam[2]->pridejTransakci(507);
   seznam[2]->pridejTransakci(-1500);
   seznam[2]->pridejTransakci(2500);

   for (int i = 0; i < seznam.size(); i++){
        seznam[i]->vypisInfo();
        seznam[i]->analyzujUcet();
   }

   nejdelsiVklad(seznam[0]);

   odstranMale(seznam[1]);

   {BeznyUcet ucet1("1258", 6.7);
   BeznyUcet ucet2("1488", 6.7);

   if (ucet1 == ucet2){
        cout << "stejne";
   }
   else{
    cout << "jine";
   }
   ucet1 += 500;

   cout << ucet1;}


   for (int i = 0; i < seznam.size(); i++){
        delete seznam[i];
   }

    cout << " Pocatecni pocet: " << Ucet::getPocet()<<endl;

    return 0;
}
