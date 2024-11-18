#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definirea structurii Bloc
struct Bloc {
    string strada;
    int numarScari;
    int numarApartamente;
    int etaje;
    string tipConstructie;
};

// Functie pentru citirea valorilor pentru un bloc
void citireBloc(Bloc& b) {
    cout << "Introduceti strada: ";
    getline(cin, b.strada);
    cout << "Introduceti numarul de scari: ";
    cin >> b.numarScari;
    cout << "Introduceti numarul total de apartamente: ";
    cin >> b.numarApartamente;
    cout << "Introduceti numarul de etaje: ";
    cin >> b.etaje;
    cin.ignore(); // Ignorarea caracterului newline
    cout << "Introduceti tipul de constructie: ";
    getline(cin, b.tipConstructie);
}

// Functie pentru afisarea detaliilor unui bloc
void afisareBloc(const Bloc& b) {
    cout << "Blocul de pe strada " << b.strada
        << ", are " << b.numarScari
        << " scari si un numar total de " << b.numarApartamente
        << " apartamente, " << b.etaje
        << " etaje si este o constructie de tip " << b.tipConstructie << ".\n";
}

int main() {
    const int NUM_BLOCURI = 10;
    vector<Bloc> blocuri(NUM_BLOCURI);

    // Citirea datelor pentru fiecare bloc
    for (int i = 0; i < NUM_BLOCURI; ++i) {
        cout << "Introduceti date pentru blocul " << (i + 1) << ":\n";
        citireBloc(blocuri[i]);
    }

    // Afisarea detaliilor fiecarui bloc
    cout << "\nDetalii despre blocuri:\n";
    for (const auto& b : blocuri) {
        afisareBloc(b);
    }

    // Vector de pointeri la Bloc
    vector<Bloc*> pointeriBlocuri(NUM_BLOCURI);
    for (int i = 0; i < NUM_BLOCURI; ++i) {
        pointeriBlocuri[i] = &blocuri[i]; // Pointeri la blocuri
    }

    // Afisarea detaliilor folosind pointerii
    cout << "\nDetalii despre blocuri folosind pointeri:\n";
    for (const auto& bPtr : pointeriBlocuri) {
        afisareBloc(*bPtr);
    }

    return 0;
}
