#include <iostream>
#include <vector>
#include <algorithm> // sort, unique, remove, remove_if, reverse, minmax_element
#include <numeric>   // accumulate, partial_sum
#include <cmath>     // abs, sqrt
#include <string>

using namespace std;

// Předpokládané hlavičky tříd pro ukázku polymorfismu (funkce 54)
// #include "Ucet.h"

// ============================================================================
// KATEGORIE 1: AGREGACE A EXTRÉMY (Vrací jedno číslo na základě pole)
// ============================================================================

// 1. Maximum
double getMaximum(const vector<double>& v) {
    if(v.empty()) return 0; 
    double max = v[0]; 
    for(double prvek : v) {
        if(prvek > max) max = prvek;
    }
    return max;
}

// 2. Minimum
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
    double sum = 0;
    for(double prvek : v) sum += prvek;
    return sum / v.size(); 
}

// 5. Počet kladných čísel
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

// 7. Index největšího prvku
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

// 8. Druhé největší číslo
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

// 9. Absolutní součet (ignoruje znaménka)
double absolutniSoucet(const vector<double>& v) {
    double sum = 0;
    for(double prvek : v) {
        sum += abs(prvek); 
    }
    return sum;
}

// 10. Suma sudých indexů
double sumaSudychIndexu(const vector<double>& v) {
    double sum = 0;
    for(int i = 0; i < v.size(); i += 2) {
        sum += v[i];
    }
    return sum;
}

// 11. Hledání extrému na určitém intervalu (od indexu A do B)
double maxVIntervalu(const vector<double>& v, int start, int end) {
    double max = v[start];
    for(int i = start; i <= end; i++) { 
        if(v[i] > max) max = v[i];
    }
    return max;
}


// ============================================================================
// KATEGORIE 2: VYHLEDÁVÁNÍ A KONTROLY (Logika, hledání indexů, vrací bool)
// ============================================================================

// 12. Obsahuje prvek (Contains)
bool obsahujePrvek(const vector<double>& v, double hledane) {
    for(double prvek : v) {
        if(prvek == hledane) return true; 
    }
    return false; 
}

// 13. Počet výskytů (Frekvence)
int pocetVyskytu(const vector<double>& v, double hledane) {
    int count = 0;
    for(double prvek : v) {
        if(prvek == hledane) count++;
    }
    return count;
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

// 18. Porovnání dvou polí (Dokončeno z tvého zadání)
bool jsouStejnaPoli(const vector<double>& v1, const vector<double>& v2) {
    if(v1.size() != v2.size()) return false; 
    for(int i = 0; i < v1.size(); i++) {
        if(v1[i] != v2[i]) return false;
    }
    return true;
}

// 19. Zda pole tvoří palindrom (Čte se zepředu i zezadu stejně)
bool jePalindrom(const vector<double>& v) {
    int n = v.size();
    for(int i = 0; i < n / 2; i++) {
        if(v[i] != v[n - 1 - i]) return false; 
    }
    return true;
}

// 20. Nejdelší řada stejných čísel
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

// 21. Počet přechodů nulou (Změna znaménka)
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
// KATEGORIE 3: TVORBA NOVÝCH POLÍ A FILTRACE (Vrací vector)
// ============================================================================

// 22. Všechna čísla nad prahovou hodnotu (Vrací nové pole)
vector<double> filtrujNadPrah(const vector<double>& v, double prah) {
    vector<double> vysledek;
    for(double prvek : v) {
        if(prvek > prah) vysledek.push_back(prvek);
    }
    return vysledek;
}

// 23. Unikátní prvky (Odstranění duplicit přes nový vektor)
vector<double> unikatniPrvky(const vector<double>& v) {
    vector<double> vysledek;
    for(double prvek : v) {
        if(!obsahujePrvek(vysledek, prvek)) {
            vysledek.push_back(prvek);
        }
    }
    return vysledek;
}

// 24. Kopírování pole pozpátku (Reverz do nového)
vector<double> reverzPole(const vector<double>& v) {
    vector<double> vysledek;
    for(int i = v.size() - 1; i >= 0; i--) {
        vysledek.push_back(v[i]);
    }
    return vysledek;
}

// 25. Rozdělení pole na dvě (Vklady a Výběry)
void rozdelPole(const vector<double>& zdroj, vector<double>& vklady, vector<double>& vybery) {
    for(double prvek : zdroj) {
        if(prvek > 0) vklady.push_back(prvek);
        else if(prvek < 0) vybery.push_back(prvek);
    }
}

// 26. Spojení dvou polí
vector<double> spojPoli(const vector<double>& v1, const vector<double>& v2) {
    vector<double> vysledek = v1; 
    for(double prvek : v2) {
        vysledek.push_back(prvek); 
    }
    return vysledek;
}

// 27. Výběr každého N-tého prvku
vector<double> kazdyNTyPrvek(const vector<double>& v, int N) {
    vector<double> vysledek;
    for(int i = 0; i < v.size(); i += N) {
        vysledek.push_back(v[i]);
    }
    return vysledek;
}

// 28. Sloučení sousedních čísel (Suma párů) do nového vektoru
vector<double> sectiSousedni(const vector<double>& v) {
    vector<double> vysledek;
    for(int i = 0; i < v.size() - 1; i += 2) {
        vysledek.push_back(v[i] + v[i+1]);
    }
    if(v.size() % 2 != 0) vysledek.push_back(v.back());
    return vysledek;
}

// 29. Průnik dvou množin (Najde čísla, která jsou v poli A i B)
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
// KATEGORIE 4: MODIFIKACE A PŘESUNY IN-PLACE (Obyčejná reference &v)
// ============================================================================

// 30. Výměna prvků (Swap) in-place
void vymenPrvky(vector<double>& v, int index1, int index2) {
    double temp = v[index1]; 
    v[index1] = v[index2];   
    v[index2] = temp;        
}

// 31. Otočení pole in-place (bez vytvoření nového vektoru)
void otoctPole(vector<double>& v) {
    int n = v.size();
    for(int i = 0; i < n / 2; i++) { 
        vymenPrvky(v, i, n - 1 - i); 
    }
}

// 32. Rotace pole doleva (posun prvků o 1 vlevo)
void rotaceDoleva(vector<double>& v) {
    if(v.empty()) return;
    double prvni = v[0]; 
    for(int i = 0; i < v.size() - 1; i++) {
        v[i] = v[i+1]; 
    }
    v[v.size() - 1] = prvni; 
}

// 33. Nahrazení (Find and Replace)
void nahradPrvek(vector<double>& v, double stareCislo, double noveCislo) {
    for(double& prvek : v) { 
        if(prvek == stareCislo) prvek = noveCislo;
    }
}

// 34. Oříznutí nadlimitních hodnot (Ořezávač / Clamp)
void orizniHodnoty(vector<double>& v, double maxLimit) {
    for(double& prvek : v) {
        if(prvek > maxLimit) prvek = maxLimit;
    }
}

// 35. Skalární násobek (Zvětšení všech čísel)
void vynasobPole(vector<double>& v, double nasobitel) {
    for(double& prvek : v) {
        prvek *= nasobitel;
    }
}

// 36. Třídění (Bubble sort od nejmenšího po největší)
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

// 37. Normování dat (Min-Max Scaling do rozsahu 0 až 1)
void normujData(vector<double>& v) {
    if(v.empty()) return;
    double min = getMinimum(v); 
    double max = getMaximum(v); 
    if(max - min == 0) return; 
    
    for(double& prvek : v) {
        prvek = (prvek - min) / (max - min);
    }
}

// 38. Plošný výpočet masky na pole (Aplikace Masky)
void aplikujMasku(vector<double>& v, const vector<int>& maska) {
    int delka = min(v.size(), maska.size());
    for(int i = 0; i < delka; i++) {
        if(maska[i] == 0) {
            v[i] = 0; 
        }
    }
}


// ============================================================================
// KATEGORIE 5: MATEMATIKA A ŠIFROVÁNÍ (Různé číselné a datové transformace)
// ============================================================================

// 39. Faktoriál (Iterativně)
long long faktorial(int n) {
    if(n <= 1) return 1;
    long long vysledek = 1;
    for(int i = 2; i <= n; i++) vysledek *= i;
    return vysledek;
}

// 40. Zjištění, zda je číslo prvočíslo
bool jePrvocislo(int cislo) {
    if(cislo <= 1) return false;
    for(int i = 2; i <= sqrt(cislo); i++) {
        if(cislo % i == 0) return false; 
    }
    return true;
}

// 41. Zjištění parity (Sudost/Lichost) operátorem Bitwise AND (Nejrychlejší)
bool jeSude(int cislo) {
    return (cislo & 1) == 0; 
}

// 42. Konverze desítkového čísla do binární reprezentace
vector<int> prevodDoBinarni(int cislo) {
    vector<int> binarni;
    if(cislo == 0) return {0};
    while(cislo > 0) {
        binarni.push_back(cislo % 2); 
        cislo = cislo / 2; 
    }
    reverse(binarni.begin(), binarni.end()); 
    return binarni;
}

// 43. Výpočet kontrolního součtu (Checksum modulu 256)
int spocitejChecksum(const vector<double>& v) {
    int soucet = 0;
    for(double prvek : v) {
        soucet += abs((int)prvek);
    }
    return soucet % 256; 
}

// 44. Caesarova šifra (posun znaků)
void caesarovaSifra(string& text, int klic) {
    for(char& znak : text) { 
        znak = znak + klic;
    }
}

// 45. XOR transformace nad polem (Základní symetrické šifrování dat)
void xorSifra(vector<double>& v, int klic) {
    for(double& prvek : v) {
        int celeCislo = (int)prvek; 
        prvek = celeCislo ^ klic;
    }
}


// ============================================================================
// KATEGORIE 6: ZMĚNA VELIKOSTI (Mazání, Erase, Vkládání)
// ============================================================================

// 46. Odstranění určité hodnoty (pomocí <algorithm> iteratorů) - PROFI
void odstranHodnotuProfi(vector<double>& v, double hodnota) {
    v.erase(remove(v.begin(), v.end(), hodnota), v.end());
}

// 47. Odstranění podle podmínky in-place (bez std::remove) - KLASICKY
void odstranZaporne(vector<double>& v) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i] < 0) {
            v.erase(v.begin() + i); 
            i--; 
        }
    }
}

// 48. Vložení nuly za každé záporné číslo
void vlozNuluZaZaporne(vector<double>& v) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i] < 0) {
            v.insert(v.begin() + i + 1, 0); 
            i++; 
        }
    }
}

// 49. Doplnění pole na požadovanou délku (Padding)
void dopinNaDelku(vector<double>& v, int pozadovanaDelka) {
    while(v.size() < pozadovanaDelka) {
        v.push_back(0); 
    }
}

// 50. Smazání drobných výběrů (Lambda funkce k zadání Účet)
void odstranMaleVybery(vector<double>& v) {
    v.erase(remove_if(v.begin(), v.end(), [](double hodnota){
        return hodnota > -50.0 && hodnota < 0.0;
    }), v.end());
}

// 51. Odstranění absolutních extrémů (Nejmenší a největší v historii)
void smazExtremy(vector<double>& v) {
    if (v.size() < 3) return; 
    auto minmax = minmax_element(v.begin(), v.end());
    auto prvniSmazat = minmax.first < minmax.second ? minmax.second : minmax.first;
    auto druheSmazat = minmax.first < minmax.second ? minmax.first : minmax.second;
    v.erase(prvniSmazat);
    v.erase(druheSmazat);
}

// 52. Odstranění těsně za sebou jdoucích duplicit
void smazZaSebouJdouciDuplicity(vector<double>& v) {
    v.erase(unique(v.begin(), v.end()), v.end());
}

// 53. Zkrácení historie (Ořezání na prvních N prvků)
void orezHistorii(vector<double>& v, size_t n) {
    if (v.size() > n) {
        v.erase(v.begin() + n, v.end()); 
    }
}

// 54. Smazání prázdného účtu v poli účtů (Polymorfismus na závěr)
// Předpokládá: vector<Ucet*> pole;
/* 
void smazPrazdneUcty(vector<Ucet*>& pole) {
    for(int i = 0; i < pole.size(); i++) {
        if(pole[i]->getHistory().empty()) {
            delete pole[i]; // NEJPRVE uvolníme paměť na haldě (Heap)
            pole.erase(pole.begin() + i); // PAK odstraníme ukazatel z vektoru
            i--;
        }
    }
}
*/
