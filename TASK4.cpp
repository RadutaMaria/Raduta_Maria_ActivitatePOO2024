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

    // Operatorul de atribuire
    Masina& operator=(const Masina& other) {
        if (this != &other) { // Verific?m auto-atribuirea
            marca = other.marca;
            model = other.model;
            an = other.an;
            *consum = *(other.consum); // Copiem valoarea consumului
        }
        return *this;
    }

    // Operatorul de comparare ==
    bool operator==(const Masina& other) const {
        return (marca == other.marca && model == other.model && an == other.an);
    }

    // Operatorul de comparare !=
    bool operator!=(const Masina& other) const {
        return !(*this == other);
    }

    // Operatorul []
    int& operator[](int index) {
        if (index == 0) {
            return *consum;  // Returneaz? referin?a la consum
        }
        throw out_of_range("Index invalid");
    }

    // Incrementarea
    Masina& operator++() {
        ++an;  // Increment?m anul
        return *this;
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

    // Supraincarcarea operatorului <<
    friend ostream& operator<<(ostream& os, const Masina& m) {
        os << "Masina: " << m.marca << " " << m.model << ", An: " << m.an << ", ID: " << m.idMasina;
        return os;
    }

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

    // Operatorul de atribuire
    Bicicleta& operator=(const Bicicleta& other) {
        if (this != &other) { // Verific?m auto-atribuirea
            tip = other.tip;
            vitezaMaxima = other.vitezaMaxima;
            *greutate = *(other.greutate); // Copiem valoarea greut??ii
        }
        return *this;
    }

    // Operatorul de comparare ==
    bool operator==(const Bicicleta& other) const {
        return (tip == other.tip && vitezaMaxima == other.vitezaMaxima);
    }

    // Operatorul de comparare !=
    bool operator!=(const Bicicleta& other) const {
        return !(*this == other);
    }

    // Supraincarcarea operatorului <<
    friend ostream& operator<<(ostream& os, const Bicicleta& b) {
        os << "Bicicleta: " << b.tip << ", Viteza Maxima: " << b.vitezaMaxima << ", ID: " << b.idBicicleta;
        return os;
    }

    // Incrementarea vitezei maxime
    Bicicleta& operator++() {
        ++vitezaMaxima;  // Increment?m viteza maxim?
        return *this;
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

    // Operatorul de atribuire
    Motocicleta& operator=(const Motocicleta& other) {
        if (this != &other) { // Verific?m auto-atribuirea
            marca = other.marca;
            cilindree = other.cilindree;
            *putere = *(other.putere);
        }
        return *this;
    }

    // Operatorul de comparare ==
    bool operator==(const Motocicleta& other) const {
        return (marca == other.marca && cilindree == other.cilindree);
    }

    // Operatorul de comparare !=
    bool operator!=(const Motocicleta& other) const {
        return !(*this == other);
    }

    // Supraincarcarea operatorului <<
    friend ostream& operator<<(ostream& os, const Motocicleta& m) {
        os << "Motocicleta: " << m.marca << ", Cilindree: " << m.cilindree << ", ID: " << m.idMotocicleta;
        return os;
    }

    // Incrementarea cilindreei
    Motocicleta& operator++() {
        ++cilindree;  // Increment?m cilindreea
        return *this;
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

// Func?ii prietene
void afisareMasina(const Masina& m) {
    cout << m << endl;
}

void afisareBicicleta(const Bicicleta& b) {
    cout << b << endl;
}

void afisareMotocicleta(const Motocicleta& m) {
    cout << m << endl;
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

    // Apelarea operatorilor supraincarcati

    // Supraincarcarea operatorului =
    Masina masinaNoua = masini[0];
    cout << "\nMasina dupa atribuire: " << masinaNoua << endl;

    Bicicleta bicicletaNoua = biciclete[0];
    cout << "\nBicicleta dupa atribuire: " << bicicletaNoua << endl;

    Motocicleta motocicletaNoua = motociclete[0];
    cout << "\nMotocicleta dupa atribuire: " << motocicletaNoua << endl;

    // Operatorul de comparare ==
    cout << "\nComparare masini: " << (masini[0] == masini[1] ? "Egale" : "Different") << endl;
    cout << "Comparare biciclete: " << (biciclete[0] == biciclete[1] ? "Egale" : "Different") << endl;
    cout << "Comparare motociclete: " << (motociclete[0] == motociclete[1] ? "Egale" : "Different") << endl;

    // Incrementarea valorilor
    cout << "\nMasina dupa incrementare: " << ++masini[0] << endl;
    cout << "Bicicleta dupa incrementare: " << ++biciclete[0] << endl;
    cout << "Motocicleta dupa incrementare: " << ++motociclete[0] << endl;

    // Accesul prin operatorul []
    try {
        cout << "\nConsum masina: " << masini[0][0] << endl;
        masini[0][0] = 10;  // Modific?m consumul
        cout << "Consum masina dupa modificare: " << masini[0][0] << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    // Afi?area num?rului de obiecte
    cout << "\nNumar masini: " << Masina::getNumarMasini() << endl;
    cout << "Numar biciclete: " << Bicicleta::getNumarBiciclete() << endl;
    cout << "Numar motociclete: " << Motocicleta::getNumarMotociclete() << endl;

    return 0;
}



                
