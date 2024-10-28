#include<iostream>
using namespace std;

struct farmacie {
	char* nume;
	string adresa;
	int nrMedicamente;
	float* preturi;

};

farmacie citirefarmacie()
{
	farmacie f;
	cout << "La ce adresa este: ";
	cin >> f.adresa;
	cout << "Numele farmaciei";
	char buffer[100];
	cin >> buffer;
	f.nume = new char[strlen(buffer) + 1];
	strcpy_s(f.nume, strlen(buffer) + 1, buffer);
	cout << "nr medicamente: ";
	cin >> f.nrMedicamente;
	cout << "Preturi ";
	f.preturi = new float[f.nrMedicamente];
	for (int i = 0; i < f.nrMedicamente; i++)
		cin >> f.preturi[i];
	return f;

}

void afisarefarmacie(farmacie f)
{
	cout << "nume: " << f.nume << endl;
	cout << "Adresa: " << f.adresa << endl;
	cout << "Nr medicamente: " << f.nrMedicamente << endl;
	cout << "Preturi: ";
	for (int i = 0; i < f.nrMedicamente; i++)
		cout << f.preturi[i] << ", ";

}


int main()
{
	farmacie* pointer;
	pointer = new farmacie();
	pointer->adresa = "Romana";
	pointer->nume = new char[strlen("Catena") + 1];
	strcpy_s(pointer->nume, strlen("Catena") + 1, "Catena");
	pointer->nrMedicamente = 5;
	pointer->preturi = new float[pointer->nrMedicamente];
	for (int i = 0; i < pointer->nrMedicamente; i++)
		pointer->preturi[i] = i + 1;

	afisarefarmacie(*pointer);

	int nrfarmacii = 3;
	int* v;
	farmacie* vector;
	vector = new farmacie[nrfarmacii];
	for (int i = 0; i < nrfarmacii; i++)
	{
		vector[i] = citirefarmacie();
	}

	for (int i = 0; i < nrfarmacii; i++)
		afisarefarmacie(vector[i]);

	//farmacie** pointeri
	//pointeri = new farmacie * [4];

	return 0;
}