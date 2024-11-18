#include <iostream>
#include <string>

using namespace std;

// Clasa Masina
class Masina {
private:
    string marca;
    string model;
    int an;
    static int numarMasini;
    const int idMasina;
    int* consum; // Pointer pentru consum

public:
    // Constructor 1
    Masina(string m, string mdl, int a, int id) : marca(m), model(mdl), an(a), idMasina(id) {
        consum = new int(0); // Alocare spa?iu în HEAP
        numarMasini++;
    }

    // Constructor 2
    Masina(string m, string mdl, int a) : Masina(m, mdl, a, ++numarMasini) {}

    // Constructor 3
    Masina() : marca("Unknown"), model("Unknown"), an(0), idMasina(++numarMasini) {
        consum = new int(0);
    }

    // Constructor de copiere
    Masina(const Masina& other) : marca(other.marca), model(other.model), an(other.an), idMasina(++numarMasini) {
        consum = new int(*(other.consum)); // Copierea valorii din HEAP
    }

    // Destructor
    ~Masina() {
        delete consum; // Eliberare memorie
        numarMasini--;
    }

    // Getteri ?i setteri
    string getMarca() const { return marca; }
    void setMarca(string m) { marca = m; }

    string getModel() const { return model; }
    void setModel(string mdl) { model = mdl; }

    int getAn() const { return an; }
    void setAn(int a) { an = a; }

    static int getNumarMasini() { return numarMasini; }
    int getIdMasina() const { return idMasina; }

    friend void afisareMasina(const Masina& m);
};

// Initializare atribut static
int Masina::numarMasini = 0;

// Clasa Bicicleta
class Bicicleta {
private:
    string tip;
    int vitezaMaxima;
    static int numarBiciclete;
    const int idBicicleta;
    float* greutate; // Pointer pentru greutate

public:
    // Constructor 1
    Bicicleta(string t, int v, int id) : tip(t), vitezaMaxima(v), idBicicleta(id) {
        greutate = new float(0.0); // Alocare spa?iu în HEAP
        numarBiciclete++;
    }

    // Constructor 2
    Bicicleta(string t, int v) : Bicicleta(t, v, ++numarBiciclete) {}

    // Constructor 3
    Bicicleta() : tip("Unknown"), vitezaMaxima(0), idBicicleta(++numarBiciclete) {
        greutate = new float(0.0);
    }

    // Constructor de copiere
    Bicicleta(const Bicicleta& other) : tip(other.tip), vitezaMaxima(other.vitezaMaxima), idBicicleta(++numarBiciclete) {
        greutate = new float(*(other.greutate)); // Copierea valorii din HEAP
    }

    // Destructor
    ~Bicicleta() {
        delete greutate; // Eliberare memorie
        numarBiciclete--;
    }

    // Getteri ?i setteri
    string getTip() const { return tip; }
    void setTip(string t) { tip = t; }

    int getVitezaMaxima() const { return vitezaMaxima; }
    void setVitezaMaxima(int v) { vitezaMaxima = v; }

    static int getNumarBiciclete() { return numarBiciclete; }
    int getIdBicicleta() const { return idBicicleta; }

    friend void afisareBicicleta(const Bicicleta& b);
};

// Initializare atribut static
int Bicicleta::numarBiciclete = 0;

// Clasa Motocicleta
class Motocicleta {
private:
    string marca;
    int cilindree;
    static int numarMotociclete;
    const int idMotocicleta;
    double* putere; // Pointer pentru putere

public:
    // Constructor 1
    Motocicleta(string m, int c, int id) : marca(m), cilindree(c), idMotocicleta(id) {
        putere = new double(0.0); // Alocare spa?iu în HEAP
        numarMotociclete++;
    }

    // Constructor 2
    Motocicleta(string m, int c) : Motocicleta(m, c, ++numarMotociclete) {}

    // Constructor 3
    Motocicleta() : marca("Unknown"), cilindree(0), idMotocicleta(++numarMotociclete) {
        putere = new double(0.0);
    }

    // Constructor de copiere
    Motocicleta(const Motocicleta& other) : marca(other.marca), cilindree(other.cilindree), idMotocicleta(++numarMotociclete) {
        putere = new double(*(other.putere)); // Copierea valorii din HEAP
    }

    // Destructor
    ~Motocicleta() {
        delete putere; // Eliberare memorie
        numarMotociclete--;
    }

    // Getteri ?i setteri
    string getMarca() const { return marca; }
    void setMarca(string m) { marca = m; }

    int getCilindree() const { return cilindree; }
    void setCilindree(int c) { cilindree = c; }

    static int getNumarMotociclete() { return numarMotociclete; }
    int getIdMotocicleta() const { return idMotocicleta; }

    friend void afisareMotocicleta(const Motocicleta& m);
};

// Initializare atribut static
int Motocicleta::numarMotociclete = 0;

// Func?ii globale prietene
void afisareMasina(const Masina& m) {
    cout << "Masina: " << m.getMarca() << " " << m.getModel() << ", An: " << m.getAn() << ", ID: " << m.getIdMasina() << endl;
}

void afisareBicicleta(const Bicicleta& b) {
    cout << "Bicicleta: " << b.getTip() << ", Viteza Maxima: " << b.getVitezaMaxima() << ", ID: " << b.getIdBicicleta() << endl;
}

void afisareMotocicleta(const Motocicleta& m) {
    cout << "Motocicleta: " << m.getMarca() << ", Cilindree: " << m.getCilindree() << ", ID: " << m.getIdMotocicleta() << endl;
}

int main() {
    // Crearea ?i ini?ializarea obiectelor Masina
    Masina masini[3] = {
        Masina("Toyota", "Corolla", 2020, 1),
        Masina("Honda", "Civic", 2019),
        Masina()
    };

    // Crearea ?i ini?ializarea obiectelor Bicicleta
    Bicicleta biciclete[3] = {
        Bicicleta("Montana", 30, 1),
        Bicicleta("Trekking", 25),
        Bicicleta()
    };

    // Crearea ?i ini?ializarea obiectelor Motocicleta
    Motocicleta motociclete[3] = {
        Motocicleta("Yamaha", 600, 1),
        Motocicleta("Kawasaki", 750),
        Motocicleta()
    };

    // Afi?area informa?iilor folosind func?iile prietene
    cout << "\nInformatii masini:\n";
    for (const auto& m : masini) {
        afisareMasina(m);
    }

    cout << "\nInformatii biciclete:\n";
    for (const auto& b : biciclete) {
        afisareBicicleta(b);
    }

    cout << "\nInformatii motociclete:\n";
    for (const auto& m : motociclete) {
        afisareMotocicleta(m);
    }

    cout << "\nNumar masini: " << Masina::getNumarMasini() << endl;
    cout << "Numar biciclete: " << Bicicleta::getNumarBiciclete() << endl;
    cout << "Numar motociclete: " << Motocicleta::getNumarMotociclete() << endl;

    return 0;
}