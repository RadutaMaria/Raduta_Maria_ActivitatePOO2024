#include<iostream>
#include<vector>
#include<string>
using namespace std;

class CofetarieAbstracta {
public:
    virtual void afiseazaInformatii() const = 0; // Metoda pur virtuala
    virtual ~CofetarieAbstracta() {} // Destructor virtual
};

class Cofetarie : public CofetarieAbstracta {
private:
    string nume;
    int nrAngajati;
    float* salarii;
    bool esteVegana;
    const int anDeschidere;
    float adaos;
    static int TVA;
public:
    Cofetarie() :adaos(30), anDeschidere(2024) {
        this->nume = "Delice";
        this->nrAngajati = 0;
        this->esteVegana = true;
        this->salarii = NULL;
    }

    Cofetarie(string nume, int nrAngajati, bool esteVegana, int an, float adaos) :anDeschidere(an) {
        this->nume = nume;
        this->nrAngajati = nrAngajati;
        this->esteVegana = esteVegana;
        this->adaos = adaos;
        this->salarii = new float[nrAngajati];
        for (int i = 0; i < nrAngajati; i++) {
            this->salarii[i] = 1000 + i * 100;
        }
    }

    Cofetarie(const Cofetarie& c) :anDeschidere(c.anDeschidere) {
        this->nume = c.nume;
        this->nrAngajati = c.nrAngajati;
        this->salarii = new float[c.nrAngajati];
        for (int i = 0; i < c.nrAngajati; i++)
            this->salarii[i] = c.salarii[i];
        this->esteVegana = c.esteVegana;
        this->adaos = c.adaos;
    }

    ~Cofetarie() {
        if (this->salarii != NULL) {
            delete[]this->salarii;
        }
    }

    string getNume() const {
        return this->nume;
    }

    int getNrAngajati() const {
        return this->nrAngajati;
    }

    float* getSalarii() const {
        return this->salarii;
    }

    void afiseazaInformatii() const override {
        cout << "Cofetarie: " << nume << ", Angajati: " << nrAngajati << ", Vegana: " << (esteVegana ? "Da" : "Nu") << endl;
    }

    static void modificaTVA(int noulTVA) {
        if (noulTVA > 0)
            Cofetarie::TVA = noulTVA;
    }

    static int TVA;
};

int Cofetarie::TVA = 9;

class CofetarieDeLux : public Cofetarie {
private:
    string specialitate;
    bool oferaCatering;
public:
    CofetarieDeLux() : Cofetarie(), specialitate("Torturi de lux"), oferaCatering(false) {}

    CofetarieDeLux(string nume, int nrAngajati, bool esteVegana, int an, float adaos, string specialitate, bool oferaCatering)
        : Cofetarie(nume, nrAngajati, esteVegana, an, adaos), specialitate(specialitate), oferaCatering(oferaCatering) {}

    void afiseazaInformatii() const override {
        Cofetarie::afiseazaInformatii();
        cout << "Specialitate: " << specialitate << ", Ofera catering: " << (oferaCatering ? "Da" : "Nu") << endl;
    }
};

class CofetarieMobila : public Cofetarie {
private:
    string locatieCurenta;
    int kmParcursi;
public:
    CofetarieMobila() : Cofetarie(), locatieCurenta("Necunoscuta"), kmParcursi(0) {}

    CofetarieMobila(string nume, int nrAngajati, bool esteVegana, int an, float adaos, string locatieCurenta, int kmParcursi)
        : Cofetarie(nume, nrAngajati, esteVegana, an, adaos), locatieCurenta(locatieCurenta), kmParcursi(kmParcursi) {}

    void afiseazaInformatii() const override {
        Cofetarie::afiseazaInformatii();
        cout << "Locatie curenta: " << locatieCurenta << ", Km parcursi: " << kmParcursi << endl;
    }
};

int main() {
    vector<CofetarieAbstracta*> cofetarii;

    cofetarii.push_back(new Cofetarie("Sweet Treats", 5, true, 2021, 25.5));
    cofetarii.push_back(new CofetarieDeLux("Royal Sweets", 10, true, 2022, 35.0, "Praline Gourmet", true));
    cofetarii.push_back(new CofetarieMobila("Travel Treats", 5, false, 2021, 25.0, "Bucuresti", 120));

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            cofetarii.push_back(new Cofetarie("Cofetarie Generica", i + 1, i % 3 == 0, 2020 + i, 20.0 + i));
        }
        else {
            cofetarii.push_back(new CofetarieDeLux("Delicii Luxoase", i + 2, true, 2021 + i, 30.0 + i, "Macarons", false));
        }
    }

    for (const auto& cofetarie : cofetarii) {
        cofetarie->afiseazaInformatii();
    }

    for (auto& cofetarie : cofetarii) {
        delete cofetarie;
    }

    return 0;
}
