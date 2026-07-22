#include <iostream>
#include <vector>
#include <algorithm> // pro sort, unique, remove_if, max
#include <numeric>   // pro accumulate

using namespace std;

// ============================================================================
// SKUPINA 1: HLEDÁNÍ A POČÍTÁNÍ (Čtení dat, const reference)
// Používáme obyčejné for cykly přes indexy (nebo range-based for).
// ============================================================================

// 1. Nalezení bankrotu (Upravená verze tvé ukázky)
void najdiBankrot(const vector<double>& transakce) {
    double zustatek = 0;
    bool bankrot = false;
    for (size_t i = 0; i < transakce.size(); i++) {
        zustatek += transakce[i];
        if (zustatek < 0) {
            cout << "K bankrotu doslo na indexu " << i << " (zustatek: " << zustatek << ")" << endl;
            bankrot = true;
            break; // Ukončíme cyklus, našli jsme první bankrot
        }
    }
    if (!bankrot) cout << "K bankrotu nedoslo." << endl;
}

// 2. Nejdelší řada vkladů za sebou (Zadání: Bankovní účty)
void nejdelsiRadaVkladu(const vector<double>& transakce) {
    int maxRada = 0;
    int aktualniRada = 0;
    for (size_t i = 0; i < transakce.size(); i++) {
        if (transakce[i] > 0) { // Je to vklad
            aktualniRada++;
            if (aktualniRada > maxRada) {
                maxRada = aktualniRada;
            }
        } else { // Je to výběr, resetujeme počítadlo
            aktualniRada = 0;
        }
    }
    cout << "Nejdelsi rada vkladu za sebou: " << maxRada << endl;
}

// 3. Detekce skoků zátěže (Zadání: ServerNode)
void detekujSkoky(const vector<double>& zatez, double hranice) {
    int pocetSkoku = 0;
    // Začínáme od indexu 1, abychom mohli porovnávat s předchozím (i - 1)
    for (size_t i = 1; i < zatez.size(); i++) {
        double rozdil = zatez[i] - zatez[i - 1];
        if (rozdil > hranice) {
            cout << "Skok na indexu " << i << ": z " << zatez[i-1] << " na " << zatez[i] << endl;
            pocetSkoku++;
        }
    }
    cout << "Celkem detekovano skoku: " << pocetSkoku << endl;
}

// 4. Počet nadprůměrných transakcí (Využití std::accumulate)
void pocetNadprumernych(const vector<double>& v) {
    if (v.empty()) return;
    // std::accumulate(zacatek, konec, pocatecni_hodnota)
    double suma = accumulate(v.begin(), v.end(), 0.0);
    double prumer = suma / v.size();
    
    int pocet = 0;
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] > prumer) pocet++;
    }
    cout << "Prumer je " << prumer << ", nadprumernych hodnot: " << pocet << endl;
}

// 5. Největší propad mezi dvěma měřeními (hledáme největší snížení zátěže)
void nejvetsiPropad(const vector<double>& zatez) {
    if (zatez.size() < 2) return;
    double maxPropad = 0;
    for (size_t i = 1; i < zatez.size(); i++) {
        // Pokud je aktuální menší než předchozí, došlo k propadu
        if (zatez[i] < zatez[i - 1]) {
            double propad = zatez[i - 1] - zatez[i];
            if (propad > maxPropad) {
                maxPropad = propad;
            }
        }
    }
    cout << "Nejvetsi zaznamenany propad mezi sousedy: " << maxPropad << endl;
}


// ============================================================================
// SKUPINA 2: MAZÁNÍ A ÚPRAVA DAT (Změna vektoru, posíláme referenci &)
// Používáme tvůj požadovaný idiom erase(remove_if, end) a základní sorty.
// ============================================================================

// 6. Odstranění nul (Tvoje ukázka)
void odstranNuly(vector<double>& v) {
    v.erase(remove_if(v.begin(), v.end(), [](double hodnota) {
        return hodnota == 0.0;
    }), v.end());
}

// 7. Odstranění drobných výběrů (Zadání: Bankovní účty)
void odstranDrobneVybery(vector<double>& v) {
    // Drobný výběr je v rozmezí (-50; 0)
    v.erase(remove_if(v.begin(), v.end(), [](double hodnota) {
        return (hodnota > -50.0 && hodnota < 0.0);
    }), v.end());
}

// 8. Odstranění duplicitních hodnot (Zadání: ServerNode)
void odstranDuplicity(vector<double>& v) {
    // 1. Krok: Setřídit (aby stejné hodnoty byly vedle sebe)
    sort(v.begin(), v.end());
    // 2. Krok: unique posune duplicity na konec, erase je fyzicky smaže
    v.erase(unique(v.begin(), v.end()), v.end());
}

// 9. Nahrazení záporných hodnot nulou (oprava chybných měření)
// Tady se nic nemaže, jen modifikujeme existující prvky.
void nahradZaporneNulou(vector<double>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] < 0) {
            v[i] = 0;
        }
    }
}

// 10. Smazání konkrétního prvku podle indexu (např. pokud je index vadný)
// Při mazání přes index se nepoužívá remove_if, ale přímo metoda erase a posun.
void smazPrvekNaIndexu(vector<double>& v, int indexKterySmazat) {
    if (indexKterySmazat >= 0 && indexKterySmazat < v.size()) {
        // v.begin() + index udělá iterátor ukazující přesně na ten prvek
        v.erase(v.begin() + indexKterySmazat);
    }
}

#include <iostream>
#include <vector>
#include <algorithm> // pro sort, unique, remove_if, max, minmax_element, atd.
#include <numeric>   // pro accumulate, partial_sum
#include <cmath>     // pro abs

// Hlavičky tvých tříd
#include "Ucet.h"
#include "SporiciUcet.h"
#include "BeznyUcet.h"

using namespace std;

// ============================================================================
// SKUPINA 1: HLEDÁNÍ A POČÍTÁNÍ (Pouze čtení dat)
// ============================================================================

// Zjištění, zda jsou všechny transakce na účtu pouze vklady
void vsechnyJsouKladne(Ucet *ucet) {
    const vector<double> &v = ucet->getHistory();
    bool vseKladne = all_of(v.begin(), v.end(), [](double x) { return x > 0; });
    cout << (vseKladne ? "Vsechny transakce jsou vklady." : "Nektere transakce jsou vybery.") << endl;
}

// Detekce, zda na účtu proběhl nějaký extrémně velký výběr
void existujeVelkyVyber(Ucet *ucet, double limit = -10000.0) {
    const vector<double> &v = ucet->getHistory();
    bool nalezit = any_of(v.begin(), v.end(), [limit](double x) { return x <= limit; });
    cout << (nalezit ? "Varovani: Zaznamenan velky vyber!" : "Vsechny vybery jsou v norme.") << endl;
}

// Spočítání počtu transakcí, které spadají do určitého rozmezí
void pocetTransakciVRozmezi(Ucet *ucet, double min, double max) {
    const vector<double> &v = ucet->getHistory();
    int pocet = count_if(v.begin(), v.end(), [min, max](double x) { return x >= min && x <= max; });
    cout << "Pocet transakci mezi " << min << " a " << max << " je: " << pocet << endl;
}

// Nalezení hodnoty nejmenší a největší transakce (min a max)
void vypisMinMax(Ucet *ucet) {
    const vector<double> &v = ucet->getHistory();
    if (v.empty()) return;
    auto minmax = minmax_element(v.begin(), v.end());
    cout << "Nejmensi transakce: " << *minmax.first << ", Nejvetsi transakce: " << *minmax.second << endl;
}

// Zjištění celkového obratu (všechny vklady a výběry v absolutní hodnotě sečtené dohromady)
void celkovyObrat(Ucet *ucet) {
    const vector<double> &v = ucet->getHistory();
    double obrat = 0;
    for (double hodnota : v) {
        obrat += abs(hodnota); 
    }
    cout << "Celkovy obrat uctu: " << obrat << endl;
}

// Výpočet mediánu (prostřední hodnota seřazených transakcí)
void vypoctiMedian(Ucet *ucet) { 
    // Zde neděláme referenci, ale KOPII, abychom si neseřadili originální data v účtu!
    vector<double> v = ucet->getHistory(); 
    if (v.empty()) return;
    
    sort(v.begin(), v.end());
    size_t stred = v.size() / 2;
    double median = v.size() % 2 == 0 ? (v[stred - 1] + v[stred]) / 2.0 : v[stred];
    cout << "Median transakci je: " << median << endl;
}

// Nejdelší řada bezprostředně po sobě jdoucích vkladů (Tvoje původní upravená)
void nejdelsiVklad(Ucet *ucet) {
    int count = 0; 
    int max = 0;
    const vector<double> &v = ucet->getHistory();
    for (int i = 0; i < v.size(); i++){
        if (v[i] > 0){
            count++;
            if (count > max){
                max = count;
            }
        }
        else {
            count = 0;
        }
    }
    cout << "Delka nejdelsi rady vkladu je: " << max << endl;
}


// ============================================================================
// SKUPINA 2: MAZÁNÍ DAT Z ÚČTU (Mění velikost vektoru)
// ============================================================================

// Odstranění všech drobných výběrů (-50 až 0)
void odstranMale(Ucet *ucet) {
    vector<double> &v = ucet->getHistory();
    v.erase(remove_if(v.begin(), v.end(), [](double hodnota){
        return hodnota > -50.0 && hodnota < 0.0;
    }), v.end());
}

// Smazání úplně všech nulových transakcí (pokud byly zadány omylem)
void odstranNuly(Ucet *ucet) {
    vector<double> &v = ucet->getHistory();
    v.erase(remove_if(v.begin(), v.end(), [](double hodnota) {
        return hodnota == 0.0;
    }), v.end());
}

// Odstranění duplicitních transakcí (dvě zcela stejné částky těsně za sebou)
void smazZaSebouJdouciDuplicity(Ucet *ucet) {
    vector<double> &v = ucet->getHistory();
    v.erase(unique(v.begin(), v.end()), v.end());
}

// Zkrácení historie účtu tak, že zůstane jen prvních N transakcí
void orezHistorii(Ucet *ucet, size_t n) {
    vector<double> &v = ucet->getHistory();
    if (v.size() > n) {
        v.erase(v.begin() + n, v.end()); 
    }
}

// Smazání extrémních hodnot (nejnižší výběr a nejvyšší vklad z celé historie)
void smazExtremy(Ucet *ucet) {
    vector<double> &v = ucet->getHistory();
    if (v.size() < 3) return; 
    auto minmax = minmax_element(v.begin(), v.end());
    // Mažeme nejprve ten prvek, který je dál od začátku, aby se neposunuly indexy
    auto prvniSmazat = minmax.first < minmax.second ? minmax.second : minmax.first;
    auto druheSmazat = minmax.first < minmax.second ? minmax.first : minmax.second;
    v.erase(prvniSmazat);
    v.erase(druheSmazat);
}


// ============================================================================
// SKUPINA 3: MODIFIKACE A PŘESUNY (Hodnoty se mění, ale nemažou)
// ============================================================================

// Nahrazení chybových dat (např. -999.0 se přepíše na 0)
void nahradChybneData(Ucet *ucet) {
    vector<double> &v = ucet->getHistory();
    replace_if(v.begin(), v.end(), [](double x) { return x == -999.0; }, 0.0);
}

// Omezení rozsahu transakcí - cokoliv nad limit se ořízne přesně na limit
void omezRozsah(Ucet *ucet, double maxVyber, double maxVklad) {
    vector<double> &v = ucet->getHistory();
    for (double &hodnota : v) {
        if (hodnota < maxVyber) hodnota = maxVyber;
        if (hodnota > maxVklad) hodnota = maxVklad;
    }
}

// Přeskládání vektoru: Všechny kladné transakce půjdou na začátek, výběry na konec
void rozdelKladneAZaporne(Ucet *ucet) {
    vector<double> &v = ucet->getHistory();
    partition(v.begin(), v.end(), [](double x) { return x >= 0; });
}

// Přepíše celou historii účtu tak, že místo transakcí ukazuje průběžný zůstatek
void preepisNaZustatek(Ucet *ucet) {
    vector<double> &v = ucet->getHistory();
    if (v.empty()) return;
    partial_sum(v.begin(), v.end(), v.begin());
}

#include <iostream>
#include <vector>
#include <algorithm> // pro remove_if, reverse

using namespace std;

// ============================================================================
// SEKCE 1: JEDNODUCHÉ HLEDÁNÍ A POČÍTÁNÍ (Obyčejné cykly, parametr je const &)
// Tyto úlohy nevyužívají žádné složité funkce, jen for cyklus a if.
// ============================================================================

// 1. Součet všech vkladů (sečte pouze kladná čísla)
void soucetVsechVkladu(const vector<double>& v) {
    double suma = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 0) suma += v[i];
    }
    cout << "1. Soucet vsech vkladu je: " << suma << endl;
}

// 2. Počet všech výběrů (spočítá, kolikrát proběhl výběr)
void pocetVyberu(const vector<double>& v) {
    int pocet = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < 0) pocet++;
    }
    cout << "2. Pocet vyberu je: " << pocet << endl;
}

// 3. Průměrná hodnota vkladů (obdoba toho, co má dělat SporiciUcet)
void prumerVkladu(const vector<double>& v) {
    double suma = 0;
    int pocet = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 0) {
            suma += v[i];
            pocet++;
        }
    }
    if (pocet > 0) cout << "3. Prumer vkladu je: " << suma / pocet << endl;
    else cout << "3. Zadne vklady nebyly nalezeny." << endl;
}

// 4. Zjištění konečného zůstatku (sečte úplně všechny transakce)
void konecnyZustatek(const vector<double>& v) {
    double zustatek = 0;
    for (int i = 0; i < v.size(); i++) {
        zustatek += v[i];
    }
    cout << "4. Konecny zustatek na uctu je: " << zustatek << endl;
}

// 5. Nalezení největšího vkladu (klasické hledání maxima přes cyklus)
void nejvetsiVkladCyklus(const vector<double>& v) {
    if (v.empty()) return;
    double maxVklad = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > maxVklad) {
            maxVklad = v[i];
        }
    }
    cout << "5. Nejvetsi nalezeny vklad je: " << maxVklad << endl;
}

// 6. Nalezení největšího výběru (hledáme nejmenší záporné číslo)
void nejvetsiVyberCyklus(const vector<double>& v) {
    if (v.empty()) return;
    double maxVyber = 0; // 0 funguje jako strop, hledáme čísla menší než 0
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < maxVyber) {
            maxVyber = v[i];
        }
    }
    cout << "6. Nejvetsi vyber byl v hodnote: " << maxVyber << endl;
}

// 7. Zjištění indexu první transakce nad 1000 Kč
void indexPrvnihoVelkehoVkladu(const vector<double>& v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 1000.0) {
            cout << "7. Prvni vklad nad 1000 je na indexu: " << i << endl;
            return; // Ukončíme funkci, našli jsme první
        }
    }
    cout << "7. Zadne vklady nad 1000 nebyly nalezeny." << endl;
}

// 8. Hledání odzadu: Kdy proběhl úplně poslední výběr?
void indexPoslednihoVyberu(const vector<double>& v) {
    // Cyklus jde odzadu (od velikosti - 1 až do 0)
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] < 0) {
            cout << "8. Posledni vyber je na indexu: " << i << endl;
            return;
        }
    }
    cout << "8. Na uctu neni zadny vyber." << endl;
}

// 9. Počet případů, kdy proběhl vklad a hned po něm výběr (i a i+1)
void pocetVkladAPakVyber(const vector<double>& v) {
    int pocet = 0;
    // Jdeme jen do v.size() - 1, abychom při v[i+1] nespadli mimo vektor
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] > 0 && v[i + 1] < 0) {
            pocet++;
        }
    }
    cout << "9. Situace vklad a hned vyber nastala: " << pocet << "x" << endl;
}

// 10. Výpis každé druhé transakce (indexy 0, 2, 4...)
void vypisKazdouDruhou(const vector<double>& v) {
    cout << "10. Kazda druha transakce: ";
    for (int i = 0; i < v.size(); i += 2) { // i se zvyšuje o 2
        cout << v[i] << " ";
    }
    cout << endl;
}


// ============================================================================
// SEKCE 2: ÚPRAVY HODNOT (Mění čísla, ale nemaže je, parametr je obyčejná &)
// ============================================================================

// 11. Přičtení bankovního bonusu ke všem vkladům (např. 10 % navíc ke vkladu)
void pridejBonusKeVkladum(vector<double>& v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 0) {
            v[i] = v[i] * 1.10; // Zvětší vklad o 10 %
        }
    }
    cout << "11. Vklady byly navyseny o bonus 10 %." << endl;
}

// 12. Stržení poplatku z každého výběru (pokud vybereš, banka strhne dalších 5)
void zavedPoplatekZaVyber(vector<double>& v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < 0) {
            v[i] -= 5.0; // Odečte 5 (číslo bude ještě více záporné)
        }
    }
    cout << "12. Z kazdeho vyberu byl strzen poplatek 5." << endl;
}

// 13. Vynulování všech výběrů (všechna záporná čísla se přepíšou na 0)
void vynulujVybery(vector<double>& v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < 0) {
            v[i] = 0.0;
        }
    }
    cout << "13. Vsechny vybery byly prepsany na nulu." << endl;
}

// 14. Obrácení všech znamének (z vkladů udělá výběry a z výběrů vklady)
void otocZnamenka(vector<double>& v) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = v[i] * -1.0; 
    }
    cout << "14. Vsechna znamenka byla prevracena." << endl;
}


// ============================================================================
// SEKCE 3: MAZÁNÍ A PŘESUNY (Zkracují vektor, parametr je obyčejná &)
// ============================================================================

// 15. Smazání úplně všech výběrů (zůstanou jen vklady)
void smazVsechnyVybery(vector<double>& v) {
    v.erase(remove_if(v.begin(), v.end(), [](double hodnota){
        return hodnota < 0.0; // Pokud je záporné, smaž ho
    }), v.end());
    cout << "15. Vsechny vybery smazany." << endl;
}

// 16. Smazání úplně všech vkladů (zůstanou jen výběry)
void smazVsechnyVklady(vector<double>& v) {
    v.erase(remove_if(v.begin(), v.end(), [](double hodnota){
        return hodnota > 0.0; // Pokud je kladné, smaž ho
    }), v.end());
    cout << "16. Vsechny vklady smazany." << endl;
}

// 17. Smazání transakcí v přesném rozmezí (např. mezi 100 a 500)
void smazTransakceVRozmezi(vector<double>& v) {
    v.erase(remove_if(v.begin(), v.end(), [](double hodnota){
        return hodnota >= 100.0 && hodnota <= 500.0;
    }), v.end());
    cout << "17. Transakce mezi 100 a 500 byly smazany." << endl;
}

// 18. Bezpečné smazání úplně poslední transakce (pokud účet není prázdný)
void smazPosledniTransakci(vector<double>& v) {
    if (!v.empty()) {
        v.pop_back(); // pop_back jednoduše smaže poslední prvek
        cout << "18. Posledni transakce byla smazana." << endl;
    }
}

// 19. Smazání všech transakcí, které jsou přesně rovny jedné hodnotě (např. chyba 50)
void smazKonkretniHodnotu(vector<double>& v) {
    v.erase(remove_if(v.begin(), v.end(), [](double hodnota){
        return hodnota == 50.0; 
    }), v.end());
    cout << "19. Vsechny transakce s hodnotou 50.0 byly smazany." << endl;
}

// 20. Kompletní otočení historie (poslední transakce bude první a naopak)
void otocHistoriiUctu(vector<double>& v) {
    // std::reverse jednoduše převrátí celý vektor
    reverse(v.begin(), v.end());
    cout << "20. Historie uctu byla prevracena (odzadu dopredu)." << endl;
}


// ============================================================================
// MAIN - Otestování algoritmů
// ============================================================================
int main() {
    cout << "--- TEST HLEDACICH ALGORITMU ---" << endl;
    vector<double> ucet = {500, -200, -400, 100, 200, 300, -50, 50, 150};
    
    najdiBankrot(ucet);
    nejdelsiRadaVkladu(ucet);
    pocetNadprumernych(ucet);
    
    cout << "\n--- TEST DETEKCE SERVERU ---" << endl;
    vector<double> zatez = {20, 25, 80, 85, 30, 95};
    detekujSkoky(zatez, 40.0); // Hledáme skoky větší než 40%
    nejvetsiPropad(zatez);

    cout << "\n--- TEST MAZACICH ALGORITMU ---" << endl;
    vector<double> data = {10, -20, 0, 50, -45, 10, -100, 0, 10, 50};
    
    cout << "Puvodni velikost dat: " << data.size() << endl;
    
    odstranNuly(data);
    cout << "Po smazani nul: " << data.size() << endl;
    
    odstranDrobneVybery(data); // -20 a -45 zmizí, -100 zůstane
    cout << "Po smazani drobnych vyberu: " << data.size() << endl;
    
    odstranDuplicity(data);
    cout << "Po smazani duplicit (a setrideni): " << data.size() << endl;

    // Kontrolní výpis zbytku vektoru
    cout << "Zbytek vektoru: ";
    for(size_t i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
