#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Ucet.h"

class SporiciUcet : public Ucet{
    private:
        double urokovaSazba;
    public:
        SporiciUcet(std::string cisloUctu, double urokovaSazba);
        void vypisInfo()const override;
        void analyzujUcet()const override;
};
