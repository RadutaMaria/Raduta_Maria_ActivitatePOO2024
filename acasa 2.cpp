#include <iostream>
#include <vector>
using namespace std;

class Elev {
private:
	string nume;
	int varsta;
public:
	Elev() {
		this->nume = "Anonim";
		this->varsta = 18;
	}

	Elev(string nume, int varsta)
	{
		this->nume = nume;
		this->varsta = varsta;
	}

	string getNume() {
		return this->nume;
	}

	int getVarsta() {
		return this->varsta;
	}

	void setNume(string nume) {
		this->nume = nume;
	}

	void setVarsta(int varsta) {
		this->varsta = varsta;
	}

	friend ostream& operator << (ostream& os, Elev& elev) {
		os << "Nume: " << elev.getNume() << endl << "Varsta: " << elev.getVarsta()
			<< endl;
		return os;
	}

	friend istream& operator >> (istream& is, Elev& elev) {
		cout << "Numele elevului: " << endl;
		is >> elev.nume;
		cout << "Varsta elevului: " << endl;
		is >> elev.varsta;
		return is;
	}

	bool operator == (Elev& elev) {
		return this->nume == elev.nume && this->varsta == elev.varsta;
	}
};

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

template <typename T> class ContainerGeneric {
private:
	T* elemente;
	int lungime;
public:
	ContainerGeneric() {
		this->elemente = new T[0];
		this->lungime = 0;
	}
	~ContainerGeneric() {
		delete[] this->elemente;
	}

	void Adauga(T element) {
		T* copie = new T[this->lungime + 1];
		for (int i = 0; i < this->lungime; i++)
			copie[i] = this->elemente[i];

		copie[this->lungime] = element;
		delete[] this->elemente;
		this->elemente = copie;
		this->lungime++;
	}

	friend ostream& operator << (ostream& os, const ContainerGeneric& c) {
		for (int i = 0; i < c.lungime; i++)
		{
			os << *c.elemente[i];
		}
		return os;
	}
};

template <typename T> class SuperContainerGeneric {
private:
	vector<T> elemente;
public:
	void Adauga(T element) {
		this->elemente.push_back(element);
	}

	friend ostream& operator << (ostream& os, const SuperContainerGeneric& c) {
		for (auto i = c.elemente.begin(); i != c.elemente.end(); i++)
		{
			os << *i;
		}
		return os;
	}

	void Remove(T element) {
		auto found = std::find(this->elemente.begin(), elemente.end(), element);
		elemente.erase(found);
	}
};

int main()
{
	Elev* e1 = new Elev("Mirel", 22);
	Elev* e2 = new Elev();
	//cout << e1 << endl;

	//cin >> e2;
	//cout << e2 << endl;

	Masina* m1 = new Masina("Honda", "X");
	//cout << m1;
	Masina m2;

	Masina* m3 = new Masina("Porche", "XYZ");
	//cin >> m2;
	//cout << m2;

	ContainerGeneric<Elev*> c1;
	c1.Adauga(e1);
	c1.Adauga(e2);
	ContainerGeneric<Masina*> c2;
	c2.Adauga(m1);
	/*cout << c1 << endl;
	cout << c2 << endl;*/

	SuperContainerGeneric<Masina*> garaj;
	garaj.Adauga(m1);
	garaj.Adauga(m3);
	garaj.Remove(m1);
	cout << garaj  << endl;
}