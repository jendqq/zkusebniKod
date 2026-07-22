#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Ucet.h"

class BeznyUcet : public Ucet{
    private:
        double poplatek;
    public:
        BeznyUcet(std::string cisloUctu, double poplatek);
        void vypisInfo()const override;
        void analyzujUcet()const override;
        bool operator==(const BeznyUcet &d)const;
        BeznyUcet &operator+=(double castka);
        friend std::ostream &operator<<(std::ostream &os, const BeznyUcet &d);

};

