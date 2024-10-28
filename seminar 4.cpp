#include<iostream>

using namespace std;

class Cofetarie
{
private:
	string nume;//
	int nrAngajati;//
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
		//avand in ved ca nr angajati este 0, salariile e NULL, n are adresa
		this->salarii = NULL;
	}


	Cofetarie(string nume, int nrAngajati, bool esteVegana, int an, float adaos) :anDeschidere(an)
	{
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->esteVegana = esteVegana;
		this->adaos = adaos;
		//alocam spatiu salariilor
		this->salarii = new float[nrAngajati];
		//valoriile salariilor:
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 1000 + i * 100;
		}
	}
	//CONSTTRUCTOR DE COPIERE
	//lista de initializari a constructorului(an deschidere)
	Cofetarie(const Cofetarie& c) :anDeschidere(c.anDeschidere) {
		//string nume;

		this->nume = c.nume;

		//int nrAngajati;

		this->nrAngajati = c.nrAngajati;

		//float* salarii;

		this->salarii = new float[c.nrAngajati];
		for (int i = 0; i < c.nrAngajati; i++)
			this->salarii[i] = c.salarii[i];

		//bool esteVegana;

		this->esteVegana = c.esteVegana;

		//float adaos;

		this->adaos = c.adaos;
	}

	//DECONSTRUCTOR: ELIBERARI DIN MEMORIE HEAP:
	~Cofetarie()
	{
		if (this->salarii != NULL) {
			delete[]this->salarii;
		}
	}


	//functiile set si get:

	string getNume()
	{
		return this->nume;
	}

	void setNume(string nume)
	{
		if (nume.length() > 1) {
			//setam atributul nume
			this->nume = nume;
		}
	}
	int getNrAngajati() {
		return this->nrAngajati;
	}
	/*void setNrAngajati(int nrAngajati)
	{
	if (nrAngajati > 0) {
	this->nrAngajati = nrAngajati;

	}
	}
	*/

	// modificam functia pentru  adauga si salariile noilor angajati in cazul adaugarii unor pers
	//il obligam atunci cand adaugam nr angajati sa ne face si vectorul de salarii
	void setNrAngajati(int nrAngajati, float* salarii)
	{
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL)
				delete[]this->salarii;
			this->salarii = new float[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}

	float* getSalarii()
	{
		return this->salarii;
	}

	//getter pentru a lua valoarea mai jos
	//vom returna doar float pt ca vrem doar o valoare, nu vrem adresa:

	float getSalariu(int index)
	{
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}



	void afisare()
	{
		cout << "Nume: " << this->nume << endl;
		cout << "Nr. angajati: " << this->nrAngajati << endl;
		cout << "E vegana?: " << (this->esteVegana ? "da" : "nu") << endl;
		cout << "An deschidere: " << this->anDeschidere << endl;
		cout << "Adaos: " << this->adaos << endl;
		cout << "TVA: " << this->TVA << endl;
	}
	//functie de modificare TVA:
	//este in interiorul clasei, dar e functie pt ca nu tine de obiect deci nu o sa ai nimic cu this( this e fol doar la metode, doar la non-statice)
	static void modificaTVA(int noulTVA)
	{
		if (noulTVA > 0)
			Cofetarie::TVA = noulTVA;
		//cand vrem sa accesam prin intermediul clasei avem ::
		//asa se initializeaza avand in vedere ca e static -- poti si cu this dar transmite si adresa->nu are sens - eficienta/util memorie
	}

	static int calculareNrTotalAngajati(int nrCofetarii, Cofetarie* vector)
	{
		int suma = 0;
		for (int i = 0; i < nrCofetarii; i++)
			suma += vector[i].nrAngajati;
		return suma;
	}

};

int Cofetarie::TVA = 9;

void f(Cofetarie c) {

}

int main()
{

	Cofetarie c;
	//afisare de functiile set si get setate pt atributele nume si nr angajati
	cout << c.getNume() << endl;
	c.setNume("");
	cout << c.getNume() << endl;
	c.setNume("Alt nume");
	cout << c.getNume() << endl;
	//initializare inline:
	c.setNrAngajati(4, new float[4] { 2, 6, 4, 9 });//data viit- sa stii de ce nu e bn sa init asa


	/*
	cout << c.getNrAngajati() << endl;
	c.setNrAngajati(0);
	cout << c.getNrAngajati() << endl;
	c.setNrAngajati(4);
	cout << c.getNrAngajati() << endl;
	*/
	// am schimbat functia in asa fel incat sa actualizeze vectorul salarii odata cu nr angajati


	Cofetarie c2("Minimal", 3, false, 2020, 10);
	//deplasare + diferentiere- []  INDEXARE
	cout << c2.getSalarii()[1] << endl;
	cout << c2.getSalariu(1) << endl; //acelasi lucru ca cea de sus, diferenta e la apel


	c2.setNrAngajati(5, new float[5] {1, 2, 3, 4, 5});
	cout << c2.getSalariu(3);
	//deconstructoru se apeleaza cand nu mai avem nevoie de atr resp SAU cand durata de viata a lor s a terminat
	// in cadrul functiei care nu interact cu consola(ex. deconstructoru) NU avem afisari and shit

	Cofetarie c3(c2);
	Cofetarie c4 = c2;
	f(c4);
}