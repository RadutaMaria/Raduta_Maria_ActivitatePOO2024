#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Cofetarie {
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

    string getSpecialitate() const {
        return specialitate;
    }

    void setSpecialitate(string specialitateNoua) {
        specialitate = specialitateNoua;
    }

    bool getOferaCatering() const {
        return oferaCatering;
    }

    void setOferaCatering(bool ofera) {
        oferaCatering = ofera;
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

    string getLocatieCurenta() const {
        return locatieCurenta;
    }

    void setLocatieCurenta(string locatieNoua) {
        locatieCurenta = locatieNoua;
    }

    int getKmParcursi() const {
        return kmParcursi;
    }

    void setKmParcursi(int kmNoi) {
        kmParcursi = kmNoi;
    }
};

int main() {
    CofetarieDeLux cofetarieDeLux("Royal Sweets", 10, true, 2022, 35.0, "Praline Gourmet", true);
    CofetarieMobila cofetarieMobila("Travel Treats", 5, false, 2021, 25.0, "Bucuresti", 120);

    Cofetarie* ptrDeLux = &cofetarieDeLux;
    Cofetarie* ptrMobila = &cofetarieMobila;

    cout << "Cofetarie de Lux: " << ptrDeLux->getNume() << endl;
    cout << "Cofetarie Mobila: " << ptrMobila->getNume() << endl;

    return 0;
}
