#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct ciocolata {
	int gramaj;
	float pret;
	string nume;
	bool esteAmaruie;
};

void afisareCiocolata(ciocolata c) {
	cout << "Nume ciocolata: " << c.nume << endl;
	cout << "Pret: " << c.pret << endl;
	cout << "Gramaj: " << c.gramaj << endl;
	cout << "Este Amaruie: " << (c.esteAmaruie ? "Da" : "Nu") << endl;

	//if(c.esteAmaruie){
	//cout<<"da";
	//else cout<<"nu";
	//conditie?DacaEadevarat:DacaEfals
}

//int a=40;
//int* pa=&a;

void ModificarePret(ciocolata* c, float pretNou)
{
	(*c).pret = pretNou;
	//echivalentul la c->pret=pretNou;
}

void modificaPretRef(ciocolata& c, float pretNou)
{
	c.pret = pretNou;
}

ciocolata initializareCiocolata(int gramaj, float pret, string nume, bool amaruie)
{
	ciocolata c;
	c.gramaj = gramaj;
	c.pret = pret;
	c.nume = nume;
	c.esteAmaruie = amaruie;
	return c;
}

int main()
{
	ciocolata c1;
	c1.gramaj = 50;
	c1.pret = 7;
	c1.nume = "Milka";
	c1.esteAmaruie = false;
	afisareCiocolata(c1);

	ciocolata c2;
	cout << "Introduceti numele: ";
	cin >> c2.nume;

	cout << "Introduceti gramajul: ";
	cin >> c2.gramaj;

	cout << "Introduceti pretul: ";
	cin >> c2.pret;

	cout << "Este Amaruie: ";
	cin >> c2.esteAmaruie;

	afisareCiocolata(c2);
	ModificarePret(&c2, 40);
	modificaPretRef(c2, 60);
	afisareCiocolata(c2);

	return 0;
}