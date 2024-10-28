#include<iostream>

using namespace std;

class Cofetarie
{
public:
	string nume;
	int nrAngajati;
	bool esteVegana;
	const int anDeschidere;
	float adaos;
	static int TVA;

	Cofetarie() :adaos(30), anDeschidere(2024) {
		this->nume = "Delice";
		this->nrAngajati = 3;
		this->esteVegana = true;
		//this->andeschidere=2024; nu merge pt ca aici intra doar valorile care se pot modifica, asta ramane la fel; sepune la inceput
		//tva- static si nu tine de obiect
	}
	//orice val care NU se modifica niciodata ex. adaos an deschidere, se pune fix dupa lista de parametrii:
	Cofetarie(string nume, int nrAngajati, bool esteVegana, int an, float adaos) :anDeschidere(an)
	{
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->esteVegana = esteVegana;
		this->adaos = adaos;

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
	//puteam face si functie statica si globala, mergea in ambele feluri
	static int calculareNrTotalAngajati(int nrCofetarii, Cofetarie* vector)
	{
		int suma = 0;
		for (int i = 0; i < nrCofetarii; i++)
			suma += vector[i].nrAngajati;
		return suma;
	}
};
//Tva e intializat aici
int Cofetarie::TVA = 9;
//ori asa ori scrii direct la afisare cout<<"TVA"<<Cofetarie::TVA<<endl;

int main()
{
	Cofetarie c1;
	c1.afisare();
	Cofetarie::modificaTVA(-19);
	Cofetarie c2("DolceVita", 6, true, 2019, 10);
	c2.afisare();

	Cofetarie* pointer;
	pointer = new Cofetarie("Ana State", 3, false, 2020, 20);
	//(*pointer).afisare();   -- merge si asa
	//-> - deferentiere + accesare
	pointer->afisare();
	//eliberam memoria
	delete pointer;

	int nrCofetarii = 3;
	Cofetarie* vector;
	vector = new Cofetarie[nrCofetarii];
	//se va apela constructorul fara parametrii
	for (int i = 0; i < nrCofetarii; i++)
	{
		//deplasare+dereferentiere+accesare
		//[]- deplasre+ deferentiere
		vector[i].afisare();
	}
	cout << "Nr total angajati: " << Cofetarie::calculareNrTotalAngajati(nrCofetarii, vector);
	delete[]vector;

}