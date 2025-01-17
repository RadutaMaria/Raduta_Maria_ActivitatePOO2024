#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Franciza {
private:
    string locatie;
    vector<Cofetarie> cofetarii; // Vector de obiecte Cofetarie
    float profitAnual;

public:
    // Constructor implicit
    Franciza() {
        locatie = "Necunoscuta";
        profitAnual = 0.0f;
    }

    // Constructor cu parametri
    Franciza(string locatie, float profitAnual, vector<Cofetarie> cofetarii)
        : locatie(locatie), profitAnual(profitAnual), cofetarii(cofetarii) {}

    // Destructor
    ~Franciza() {
        // Curata vectorul, daca este necesar
        cofetarii.clear();
    }

    // Getters
    string getLocatie() const {
        return locatie;
    }

    float getProfitAnual() const {
        return profitAnual;
    }

    vector<Cofetarie> getCofetarii() const {
        return cofetarii;
    }

    // Setters
    void setLocatie(string locatieNoua) {
        if (!locatieNoua.empty()) {
            locatie = locatieNoua;
        }
    }

    void setProfitAnual(float profitNou) {
        if (profitNou >= 0) {
            profitAnual = profitNou;
        }
    }

    void adaugaCofetarie(const Cofetarie& cofetarie) {
        cofetarii.push_back(cofetarie);
    }

    // Supraincarcarea operatorilor

    // Operatorul += pentru a adauga o cofetarie in franciza
    Franciza& operator+=(const Cofetarie& cofetarie) {
        cofetarii.push_back(cofetarie);
        return *this;
    }

    // Operatorul << pentru afisare
    friend ostream& operator<<(ostream& out, const Franciza& franchise) {
        out << "Franciza localizata in: " << franchise.locatie << endl;
        out << "Profit anual: " << franchise.profitAnual << endl;
        out << "Numar de cofetarii: " << franchise.cofetarii.size() << endl;
        for (size_t i = 0; i < franchise.cofetarii.size(); i++) {
            out << "Cofetaria " << i + 1 << ": " << franchise.cofetarii[i].getNume() << endl;
        }
        return out;
    }

    // Operatorul == pentru comparare
    bool operator==(const Franciza& other) const {
        return locatie == other.locatie && profitAnual == other.profitAnual && cofetarii.size() == other.cofetarii.size();
    }

    // Metoda de afisare a detaliilor francizei
    void afisare() const {
        cout << *this;
    }
};

int main() {
    // Crearea unor obiecte Cofetarie
    Cofetarie c1("Sweet Treats", 5, true, 2021, 25.5);
    Cofetarie c2("Choco Heaven", 8, false, 2019, 30.0);

    // Crearea unui vector de Cofetarii
    vector<Cofetarie> listaCofetarii = { c1, c2 };

    // Crearea unei francize
    Franciza franciza("Bucuresti", 50000.0, listaCofetarii);

    // Adaugarea unei noi cofetarii
    Cofetarie c3("Vanilla Bliss", 10, true, 2020, 28.0);
    franciza += c3;

    // Afisarea francizei
    franciza.afisare();

    // Compararea francizei cu o alta franciza
    Franciza franciza2("Bucuresti", 50000.0, listaCofetarii);
    if (franciza == franciza2) {
        cout << "Francizele sunt identice." << endl;
    }
    else {
        cout << "Francizele sunt diferite." << endl;
    }

    return 0;
}
