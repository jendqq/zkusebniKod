#include <iostream>
#include <vector>
#include <algorithm> // sort, unique, remove, remove_if, reverse, minmax_element
#include <numeric>   // accumulate, partial_sum
#include <cmath>     // abs, sqrt
#include <string>

using namespace std;

// ============================================================================
// KATEGORIE 1: AGREGACE A EXTRÉMY (Čtení dat, vrací jedno číslo)
// Algoritmy pro výpočet jedné konkrétní hodnoty na základě celého pole.
// ============================================================================

// 1. Maximum (Největší prvek)
double getMaximum(const vector<double>& v) {
    if(v.empty()) return 0;
    double max = v[0];
    for(double prvek : v) {
        if(prvek > max) max = prvek;
    }
    return max;
}

// 2. Minimum (Nejmenší prvek)
double getMinimum(const vector<double>& v) {
    if(v.empty()) return 0;
    double min = v[0];
    for(double prvek : v) {
        if(prvek < min) min = prvek;
    }
    return min;
}

// 3. Součet (Suma)
double getSoucet(const vector<double>& v) {
    double sum = 0;
    for(double prvek : v) sum += prvek;
    return sum;
}

// 4. Průměr
double getPrumer(const vector<double>& v) {
    if(v.empty()) return 0;
    return getSoucet(v) / v.size();
}

// 5. Počet kladných čísel (Vklady)
int pocetKladnych(const vector<double>& v) {
    int count = 0;
    for(double prvek : v) {
        if(prvek > 0) count++;
    }
    return count;
}

// 6. Rozptyl (Amplituda) - rozdíl mezi maximem a minimem
double getRozptyl(const vector<double>& v) {
    if(v.empty()) return 0;
    return getMaximum(v) - getMinimum(v);
}

// 7. Druhé největší číslo
double getDruheMaximum(const vector<double>& v) {
    double max1 = getMaximum(v);
    double max2 = -999999;
    for(double prvek : v) {
        if(prvek > max2 && prvek < max1) {
            max2 = prvek;
        }
    }
    return max2;
}

// 8. Absolutní součet (ignoruje znaménka - Celkový obrat)
double absolutniSoucet(const vector<double>& v) {
    double sum = 0;
    for(double prvek : v) {
        sum += abs(prvek);
    }
    return sum;
}

// 9. Suma sudých indexů
double sumaSudychIndexu(const vector<double>& v) {
    double sum = 0;
    for(int i = 0; i < v.size(); i += 2) {
        sum += v[i];
    }
    return sum;
}

// 10. Výpočet kontrolního součtu (Checksum modulu 256)
int spocitejChecksum(const vector<double>& v) {
    int soucet = 0;
    for(double prvek : v) {
        soucet += abs((int)prvek);
    }
    return soucet % 256;
}


// ============================================================================
// KATEGORIE 2: VYHLEDÁVÁNÍ A ANALÝZA (Čtení dat, vrací index nebo bool)
// Zjišťování vlastností pole a hledání specifických prvků.
// ============================================================================

// 11. Obsahuje prvek (Contains)
bool obsahujePrvek(const vector<double>& v, double hledane) {
    for(double prvek : v) {
        if(prvek == hledane) return true;
    }
    return false;
}

// 12. Počet výskytů (Frekvence)
int pocetVyskytu(const vector<double>& v, double hledane) {
    int count = 0;
    for(double prvek : v) {
        if(prvek == hledane) count++;
    }
    return count;
}

// 13. Index největšího prvku
int getIndexMaxima(const vector<double>& v) {
    if(v.empty()) return -1;
    double max = v[0];
    int maxIdx = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] > max) {
            max = v[i];
            maxIdx = i;
        }
    }
    return maxIdx;
}

// 14. První záporný prvek
double prvniZaporny(const vector<double>& v) {
    for(double prvek : v) {
        if(prvek < 0) return prvek;
    }
    return 0;
}

// 15. Poslední záporný prvek (Cyklus odzadu)
double posledniZaporny(const vector<double>& v) {
    for(int i = v.size() - 1; i >= 0; i--) {
        if(v[i] < 0) return v[i];
    }
    return 0;
}

// 16. Zjištění, zda je pole rostoucí
bool jeRostouci(const vector<double>& v) {
    if(v.size() < 2) return true;
    for(int i = 0; i < v.size() - 1; i++) {
        if(v[i] > v[i+1]) return false;
    }
    return true;
}

// 17. Jsou všechny prvky kladné?
bool jsouVsechnyKladne(const vector<double>& v) {
    for(double prvek : v) {
        if(prvek <= 0) return false;
    }
    return true;
}

// 18. Zda pole tvoří palindrom (Čte se zepředu i zezadu stejně)
bool jePalindrom(const vector<double>& v) {
    int n = v.size();
    for(int i = 0; i < n / 2; i++) {
        if(v[i] != v[n - 1 - i]) return false;
    }
    return true;
}

// 19. Nejdelší řada stejných čísel
int nejdelsiRadaStejnych(const vector<double>& v) {
    if(v.empty()) return 0;
    int maxSerie = 1, aktualniSerie = 1;
    for(int i = 1; i < v.size(); i++) {
        if(v[i] == v[i-1]) {
            aktualniSerie++;
        } else {
            if(aktualniSerie > maxSerie) maxSerie = aktualniSerie;
            aktualniSerie = 1;
        }
    }
    if(aktualniSerie > maxSerie) maxSerie = aktualniSerie;
    return maxSerie;
}

// 20. Počet přechodů nulou (Změna znaménka z + na - nebo naopak)
int prechodyNulou(const vector<double>& v) {
    int count = 0;
    for(int i = 1; i < v.size(); i++) {
        if((v[i] > 0 && v[i-1] < 0) || (v[i] < 0 && v[i-1] > 0)) {
            count++;
        }
    }
    return count;
}


// ============================================================================
// KATEGORIE 3: FILTRACE A TVORBA NOVÝCH POLÍ (Čtení dat, vrací nový vektor)
// ============================================================================

// 21. Všechna čísla nad prahovou hodnotu
vector<double> filtrujNadPrah(const vector<double>& v, double prah) {
    vector<double> vysledek;
    for(double prvek : v) {
        if(prvek > prah) vysledek.push_back(prvek);
    }
    return vysledek;
}

// 22. Unikátní prvky (Odstranění duplicit bez poškození originálu)
vector<double> unikatniPrvky(const vector<double>& v) {
    vector<double> vysledek;
    for(double prvek : v) {
        if(!obsahujePrvek(vysledek, prvek)) {
            vysledek.push_back(prvek);
        }
    }
    return vysledek;
}

// 23. Kopírování pole pozpátku (Reverz do nového)
vector<double> reverzPole(const vector<double>& v) {
    vector<double> vysledek;
    for(int i = v.size() - 1; i >= 0; i--) {
        vysledek.push_back(v[i]);
    }
    return vysledek;
}

// 24. Spojení dvou polí
vector<double> spojPoli(const vector<double>& v1, const vector<double>& v2) {
    vector<double> vysledek = v1;
    for(double prvek : v2) {
        vysledek.push_back(prvek);
    }
    return vysledek;
}

// 25. Sloučení sousedních čísel (Suma párů) do nového vektoru
vector<double> sectiSousedni(const vector<double>& v) {
    vector<double> vysledek;
    for(int i = 0; i < v.size() - 1; i += 2) {
        vysledek.push_back(v[i] + v[i+1]);
    }
    if(v.size() % 2 != 0) vysledek.push_back(v.back());
    return vysledek;
}

// 26. Průnik dvou množin (Najde čísla, která jsou v poli A i B)
vector<double> prunikMnozin(const vector<double>& a, const vector<double>& b) {
    vector<double> vysledek;
    for(double prvek : a) {
        if(obsahujePrvek(b, prvek) && !obsahujePrvek(vysledek, prvek)) {
            vysledek.push_back(prvek);
        }
    }
    return vysledek;
}


// ============================================================================
// KATEGORIE 4: MODIFIKACE A MATEMATIKA (Upravuje data in-place, NEMAŽE velikost)
// Všechny tyto funkce přijímají referenci vector<double>&
// ============================================================================

// 27. Výměna prvků (Swap)
void vymenPrvky(vector<double>& v, int index1, int index2) {
    double temp = v[index1];
    v[index1] = v[index2];
    v[index2] = temp;
}

// 28. Otočení pole in-place (bez vytvoření nového vektoru)
void otocPole(vector<double>& v) {
    int n = v.size();
    for(int i = 0; i < n / 2; i++) {
        vymenPrvky(v, i, n - 1 - i);
    }
}

// 29. Rotace pole doleva (posun prvků o 1 vlevo)
void rotaceDoleva(vector<double>& v) {
    if(v.empty()) return;
    double prvni = v[0];
    for(int i = 0; i < v.size() - 1; i++) {
        v[i] = v[i+1];
    }
    v[v.size() - 1] = prvni;
}

// 30. Nahrazení (Find and Replace)
void nahradPrvek(vector<double>& v, double stareCislo, double noveCislo) {
    for(double& prvek : v) {
        if(prvek == stareCislo) prvek = noveCislo;
    }
}

// 31. Oříznutí nadlimitních hodnot (Ořezávač / Clamp)
void orizniHodnoty(vector<double>& v, double maxLimit, double minLimit) {
    for(double& prvek : v) {
        if(prvek > maxLimit) prvek = maxLimit;
        if(prvek < minLimit) prvek = minLimit;
    }
}

// 32. Skalární násobek (Zvětšení všech čísel)
void vynasobPole(vector<double>& v, double nasobitel) {
    for(double& prvek : v) {
        prvek *= nasobitel;
    }
}

// 33. Normování dat (Min-Max Scaling do rozsahu 0 až 1)
void normujData(vector<double>& v) {
    if(v.empty()) return;
    double min = getMinimum(v);
    double max = getMaximum(v);
    if(max - min == 0) return; 
    
    for(double& prvek : v) {
        prvek = (prvek - min) / (max - min);
    }
}

// 34. XOR transformace nad polem (Základní symetrické šifrování dat)
void xorSifra(vector<double>& v, int klic) {
    for(double& prvek : v) {
        int celeCislo = (int)prvek; 
        prvek = celeCislo ^ klic;
    }
}

// 35. Třídění (Bubble sort od nejmenšího po největší)
void bubbleSort(vector<double>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                vymenPrvky(v, j, j+1);
            }
        }
    }
}

// 36. Caesarova šifra (posun znaků ve stringu - extra ukázka)
void caesarovaSifra(string& text, int klic) {
    for(char& znak : text) {
        znak = znak + klic;
    }
}

// 37. Zjištění, zda je číslo prvočíslo (Pomocná matematická funkce)
bool jePrvocislo(int cislo) {
    if(cislo <= 1) return false;
    for(int i = 2; i <= sqrt(cislo); i++) {
        if(cislo % i == 0) return false;
    }
    return true;
}


// ============================================================================
// KATEGORIE 5: MAZÁNÍ A VKLÁDÁNÍ (Mění velikost vektoru in-place)
// Tyto algoritmy fyzicky odebírají nebo přidávají data do vektoru.
// ============================================================================

// 38. Odstranění určité hodnoty (Pomocí <algorithm> - PROFI PŘÍSTUP)
void odstranHodnotuProfi(vector<double>& v, double hodnota) {
    v.erase(remove(v.begin(), v.end(), hodnota), v.end());
}

// 39. Odstranění všech drobných výběrů (-50 až 0) pomocí lambda funkce
void odstranMaleVybery(vector<double>& v) {
    v.erase(remove_if(v.begin(), v.end(), [](double hodnota){
        return hodnota > -50.0 && hodnota < 0.0;
    }), v.end());
}

// 40. Odstranění podle podmínky in-place (bez std::remove - KLASICKÝ PŘÍSTUP)
void odstranZaporneKlasicky(vector<double>& v) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i] < 0) {
            v.erase(v.begin() + i); 
            i--; // Musíme couvnout iterátorem, abychom nepřeskočili posunutý prvek
        }
    }
}

// 41. Odstranění absolutních extrémů (nejnižší a nejvyšší hodnota)
void smazExtremy(vector<double>& v) {
    if (v.size() < 3) return; 
    auto minmax = minmax_element(v.begin(), v.end());
    // Musíme smazat prvek dál od začátku první, aby se nerozbily indexy
    auto prvniSmazat = minmax.first < minmax.second ? minmax.second : minmax.first;
    auto druheSmazat = minmax.first < minmax.second ? minmax.first : minmax.second;
    v.erase(prvniSmazat);
    v.erase(druheSmazat);
}

// 42. Smazání duplicitních transakcí jdoucích bezprostředně po sobě
void smazZaSebouJdouciDuplicity(vector<double>& v) {
    v.erase(unique(v.begin(), v.end()), v.end());
}

// 43. Zkrácení historie pouze na prvních N transakcí
void orezHistorii(vector<double>& v, size_t n) {
    if (v.size() > n) {
        v.erase(v.begin() + n, v.end()); 
    }
}

// 44. Vložení nuly za každé záporné číslo
void vlozNuluZaZaporne(vector<double>& v) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i] < 0) {
            v.insert(v.begin() + i + 1, 0); 
            i++; // Přeskočíme vloženou nulu
        }
    }
}

// 45. Doplnění pole na požadovanou délku (Padding - naplnění nulami)
void dopinNaDelku(vector<double>& v, int pozadovanaDelka) {
    while(v.size() < pozadovanaDelka) {
        v.push_back(0); 
    }
}
