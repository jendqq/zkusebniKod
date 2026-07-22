#pragma once
#include <iostream>
#include <string>
#include <vector>

class Ucet{
    protected:
        std::string cisloUctu;
        std::vector<double> historieTransakci;
        static int pocetObjektu;
    public:
        Ucet(std::string cisloUctu);
        static int getPocet();
        void pridejTransakci(double hodnota);
        void pridejTransakce(const std::vector<double> &hodnoty);
        std::vector<double> &getHistory();
        virtual ~Ucet();
        virtual void analyzujUcet() const= 0;
        virtual void vypisInfo() const;
};

