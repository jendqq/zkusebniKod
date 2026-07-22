class DatabazovyServer : public Server {
    private:
        double nosnost;
    public:
        // Konstruktor atd...

        // 1. Operátor += (Vrací referenci na sebe sama)
        DatabazovyServer& operator+=(double castka);

        // 2. Operátor == (Nemění objekt, proto je na konci const)
        bool operator==(const DatabazovyServer &d) const;

        // 3. Operátor << (Musí mít friend a std:: před ostream)
        friend std::ostream& operator<<(std::ostream &os, const DatabazovyServer &d);
        class DatabazovyServer : public Server {
    private:
        double nosnost;
    public:
        // Konstruktor atd...

        // 4. Operátor + (Vrací NOVÝ objekt. Metoda je const, protože nemění původní objekt)
        DatabazovyServer operator+(const DatabazovyServer &druhy) const;
};
};

// 1. Operátor += (Využití metody z předka/vlastní třídy)
DatabazovyServer& DatabazovyServer::operator+=(double castka) {
    this->pridejZaznam(castka); // Volání getteru/metody uvnitř operátoru
    return *this;               // Nutné! Vrací samotný objekt
}

// 2. Operátor == 
bool DatabazovyServer::operator==(const DatabazovyServer &d) const {
    if (this->nosnost == d.nosnost) {
        return true;
    } else {
        return false;
    }
}

// 3. Operátor << (BEZ DatabazovyServer:: a BEZ slova friend)
std::ostream& operator<<(std::ostream &os, const DatabazovyServer &d) {
    os << "SPZ: " << d.spz << " transakci: " << d.historieZarizeni.size();
    return os; // Nutné! Vrací stream pro řetězení cout

    // 4. Operátor + (Sečte nosnosti dvou serverů a vytvoří nový, třetí server)
DatabazovyServer DatabazovyServer::operator+(const DatabazovyServer &druhy) const {
    // 1. Spočítáme novou hodnotu (např. sečteme nosnosti)
    double novaNosnost = this->nosnost + druhy.nosnost;
    
    // 2. Vytvoříme ÚPLNĚ NOVÝ objekt s touto novou hodnotou
    // (Jako SPZ můžeme dát třeba nějaký default nebo spojit původní)
    DatabazovyServer vysledek("SOUCET", novaNosnost);
    
    // 3. Vrátíme tento nový objekt (NE vracíme referenci!)
    return vysledek;
}
}

int main() {
    // Vytvoření testovacích objektů na zásobníku
    DatabazovyServer server1("AAA-111", 6.7);
    DatabazovyServer server2("BBB-222", 6.7);

    // ==========================================
    // 1. TEST OPERÁTORU +=
    // ==========================================
    server1 += 500.5;   // Přidá hodnotu (v pozadí zavolá pridejZaznam)
    server1 += -100.0;
    
    // ==========================================
    // 2. TEST OPERÁTORU ==
    // ==========================================
    if (server1 == server2) {
        cout << "Operátor == funguje: Maji stejnou nosnost." << endl;
    } else {
        cout << "Operátor == funguje: Nemaji stejnou nosnost." << endl;
    }

    // ==========================================
    // 3. TEST OPERÁTORU <<
    // ==========================================
    // Vypíše objekt přímo do konzole pomocí naší vlastní logiky
    cout << "Operátor << funguje: " << server1 << endl;

    int main() {
    // Vytvoření testovacích objektů na zásobníku
    DatabazovyServer server1("AAA-111", 5.0);
    DatabazovyServer server2("BBB-222", 3.5);

    // ==========================================
    // 4. TEST OPERÁTORU +
    // ==========================================
    // Sečtením server1 a server2 vznikne úplně nový objekt, který uložíme do server3
    DatabazovyServer server3 = server1 + server2;
    
    // Očekáváme, že server3 bude mít nosnost 8.5
    cout << "Operátor + funguje: Soucet je " << server3 << endl;

    return 0;
}

    return 0;
}
