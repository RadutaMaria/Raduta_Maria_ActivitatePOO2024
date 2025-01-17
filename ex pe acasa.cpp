#include <iostream>
#include <vector>
using namespace std;

//Clase
class Animal {
private:
	char* nume;
	unsigned int picioare;
	unsigned int varsta;
	bool areMicrocip;
	//Exemple de statici: salariul total pe departamente, id, sa numeri cate instante ai
	static int varsta_totala;
public:
	//Constructori
	Animal() {
		this->nume = new char[1];
		strcpy_s(nume, 1, "");
		this->picioare = 0;
		this->varsta = 0;
		this->varsta_totala += varsta;
		this->areMicrocip = false;
	}

	Animal(const char* nume, unsigned int picioare, unsigned int varsta, bool areMicrocip) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->picioare = picioare;
		this->varsta = varsta;
		this->areMicrocip = areMicrocip;
		this->varsta_totala += varsta;
	}

	//Getteri - returneaza
	unsigned int get_picioare() {
		return this->picioare;
	}

	char* get_nume() {
		return this->nume;
	}

	int get_varsta_totala()
	{
		return this->varsta_totala;
	}

	//Setteri - nu returneaza
	void set_picioare(unsigned int picioare) {
		this->picioare = picioare;
	}

	//Supraincacarea <<
	friend ostream& operator << (ostream& os, const Animal& animal) {
		os << "Nume: " << animal.nume << "\nPicioare: " << animal.picioare <<
			"\nVarsta: " << animal.varsta << "\nMicrocip: " << animal.areMicrocip << endl;
		return os;
	}

	//Supraincarcarea >>
	friend istream& operator >> (istream& is, Animal& animal) {
		is >> animal.picioare;
		is >> animal.varsta;
		is >> animal.areMicrocip;
		return is;
	}

	// Equality operator
	bool operator==(const Animal& other) const {
		return (this->nume == other.nume &&
			this->picioare == other.picioare &&
			this->varsta == other.varsta &&
			this->areMicrocip == other.areMicrocip);
	}

	//Destructori
	~Animal() {
		delete[] this->nume;
		//cout << "A murit animalu!" << endl;
	}
};

int Animal::varsta_totala = 0;

class Masina {
private:
	string marca;
	string model;
public:
	Masina() : marca("unknown"), model("totunknown") {}
	Masina(const string marca, const string model) {
		this->marca = marca;
		this->model = model;
	}

	string getMarca() {
		return this->marca;
	}

	string getModel() {
		return this->model;
	}

	void setMarca(string marca) {
		this->marca = marca;
	}

	void setModel(string model) {
		this->model = model;
	}

	friend ostream& operator << (ostream& os, Masina& masina) {
		os << "Marca: " << masina.getMarca() << endl << "Model: " << masina.getModel()
			<< endl;
		return os;
	}

	friend ostream& operator << (ostream& os, Masina* masina) {
		os << *masina;
		return os;
	}

	friend istream& operator >> (istream& is, Masina& masina) {
		cout << "Marca masinii: " << endl;
		is >> masina.marca;
		cout << "Modelul masinii: " << endl;
		is >> masina.model;
		return is;
	}

	bool operator == (Masina& masina) {
		return this->marca == masina.getMarca() && this->model == masina.getModel();
	}

};

class Zoo {
private:
	vector <Animal*> animale;
public:
	Zoo& operator += (Animal* animal) {
		this->animale.push_back(animal);
		return *this;
	}

	friend ostream& operator<<(ostream& os, Zoo& zoo) {
		for (int i = 0; i < zoo.animale.size(); i++) {
			os << *(zoo.animale[i]) << endl;
		}

		return os;
	}

};

template <typename T> class Container {
public:
	vector <T> elemente;

	void Adauga(T element) {
		this->elemente.push_back(element);
	}

	void Sterge(T element) {
		auto element_gasit = std::find(this->elemente.begin(), elemente.end(), element);
		elemente.erase(element_gasit);
	}
};

int main() {
	//Obiect
	Animal* a1 = new Animal("Soarece", 4, 2, false);
	/*cout << a1;*/
	Animal a2;
	/*cin >> a2;*/
	/*cout << a2;*/

	Animal a3("Elefant", 4, 10, true);
	/*cout << a3.get_varsta_totala() << endl;*/

	Zoo z1;
	z1 += a1;

	Container<Animal> c1;
	c1.Adauga(*a1);
	c1.Adauga(a2);
	c1.Sterge(*a1);

	//cout << z1;

	
	return 0;
}