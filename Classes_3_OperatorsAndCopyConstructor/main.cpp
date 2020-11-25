#include <iostream>

using namespace std;

class FudbalClub
{
	int currentScores;
	int maxScores;
	int* scores;

public:
	int numberOfThrophies;
	bool currentlyInSeason;

	FudbalClub() {}
	FudbalClub(int maxScores, int currScores, int scores[])
	{
		this->numberOfThrophies = 0;
		this->currentlyInSeason = false;
		this->maxScores = maxScores;
		this->currentScores = currScores;
		this->scores = new int[currentScores];

		for (int i = 0; i < this->currentScores; i++)
			this->scores[i] = scores[i];
	}

	// Copy constructor (used to initialize object with another instance of the same type object)s
	// Has class instance reference as a parameter
	// Should perform a deep copy of an object
	// If not specified, implicit by compiler BUT performs a shallow copy (bitwise copying)
	FudbalClub(const FudbalClub& fc)
	{
		// Deep copy (copy entire data from memory, not just pointers to the memory)
		this->currentlyInSeason = fc.currentlyInSeason;
		this->numberOfThrophies = fc.numberOfThrophies;

		this->maxScores = fc.maxScores;
		this->currentScores = fc.currentScores;
		this->scores = new int[this->currentScores];

		for (int i = 0; i < this->currentScores; i++)
			this->scores[i] = fc.scores[i];

		// Shallow copy (wrong - only pointers are copied, NOT actual data in memory)
		// this->scores = fc.scores;
	}

	~FudbalClub()
	{
		delete[] scores;
	}

	// Assignment operator overload (used to replace data of a PREVOUSLY INITIALIZED object)
	// If not specified, implicit by compiler BUT performs a bitwise copying (essentially a shallow copy)
	FudbalClub& operator=(const FudbalClub& fc)
	{
		// Same object instance check
		if (this == &fc)
			return *this;
		
		// Keep this values, do not replace them
		// this->currentlyInSeason = fc.currentlyInSeason;
		// this->numberOfThrophies = fc.numberOfThrophies;
		
		// Copy array (see if already greater than incoming array)
		this->currentScores = fc.currentScores; 

		if (this->maxScores >= fc.maxScores)
		{
			for (int i = 0; i < this->currentScores; i++)
				this->scores[i] = fc.scores[i];
		}
		else
		{
			delete[] this->scores;
			
			this->maxScores = fc.maxScores;

			this->scores = new int[this->maxScores];
			for (int i = 0; i < this->currentScores; i++)
				this->scores[i] = fc.scores[i];
		}
	}

	friend void wonChamptionship(FudbalClub& fc);
	//{
	//	// No `this` in friend functions
	//	fc.numberOfThrophies++;		
	//}

	// Input and output stream operators must be declared as NON member functions (therefore operator overloads must be declared as `friend`)
	friend ostream& operator<<(ostream& os, const FudbalClub& fc)
	{
		os << "FudbalClub\nThrophies: " << fc.numberOfThrophies << endl;

		for (int i = 0; i < fc.currentScores; i++)
			os << fc.scores[i] << " ";
			
		return os;
	}
		
	friend istream& operator>>(istream& is, FudbalClub& fc);
	
	void printScores()
	{
		for (int i = 0; i < this->currentScores; i++)
			cout << "Scores: " << this->scores[i] << endl;
	}
};

void wonChamptionship(FudbalClub& fc)
{
	// No `this` in friend functions
	fc.numberOfThrophies++; // public class attribute
	cout << "Total games played: " << fc.maxScores << endl; // private class attribute
}

// NOT a class member function
istream& operator>>(istream& is, FudbalClub& fc)
{
	cout << "Enter number of throphies for the club:" << endl;
	is >> fc.numberOfThrophies;
	return is;
}

int main()
{
	int maxScores = 10;
	int scores[5] = { 1, 0, 1, 3, 1 };
	int currentScores = sizeof(scores) / sizeof(int);

	FudbalClub fc(maxScores, currentScores, scores);
	fc.printScores();

	FudbalClub fc2(fc); // Copy constructor called
	fc2.printScores();

	FudbalClub fc3 = fc2; // Copy constructor called (still object initialization), NOT an assignment operator call

	FudbalClub fc4; // Default constructor called

	// Manipulate the object attributes
	fc4.currentlyInSeason = false;
	fc4.numberOfThrophies = 3;

	// Assignment operator= called
	fc4 = fc3;

	// NOT A CLASS MEMBER
	// fc4.wonChampionship();

	cout << "Num of throphies: " << fc4.numberOfThrophies << endl;
	wonChamptionship(fc4);
	cout << "Num of throphies: " << fc4.numberOfThrophies << endl;

	cout << fc4 << endl;
	cin >> fc4;
	cout << fc4 << endl;


	/// HOMEWORK
		// Study -> "D:\OOP\OOP RV04 Primeri\C0403"
		
		// class Radnik
			// private: ime, prezime
			// private: int ukupnoRadnihSati, int radniSati [] (radni sati po danu, [8, 8, 6, 6, 8 ...]). Cuvati u dinamickoj zoni memorije.
			
			// Podrazumevani konstruktor
			// Konstruktor koji postavlja sve atribute klase
			// Destruktor (sta se radi u desktruktoru??)
	
			// friend funkciju koja racuna srednju vrednost radnih sati u mesecu

			// Konstruktor za kopiranje (paznja na dinamicku memoriju)
			// Predefinisan operator dodele (operator=)
				// Obratiti paznju kada se poziva konstruktor za kopiranje, kada operator dodele.
			
			// Predefinisan operator[] - vraca element iz niza `radniSati`
			
			// Predefinisati >> i << operatore
			// Kreirati objekat `radnik1`, uneti sve podatke (koristeci operator >>)
			// Stampati sve podatke (koristeci operator <<)
			// Izracunati i odstampati srednju vrednost svih sati za `radnik1`
			
			// Kreirati `radnik2` uz pomoc konstruktora za kopiranje - kreirati ga u dinamickoj zoni memorije
			// Odstampati vrednosti `radnik2` objekta (treba da budu iste kao i `radnik1`)
			
			// Smanjiti sve radne sate za `radnik1` za 1(jedan sat)
			// Odstampati vrednosti `radnik2` objekta (treba da budu iste kao u trenutku kreiranja `radnik2` objekta)
			// Izracunati i odstampati srednju vrednost svih sati za `radnik2` (treba da bude razlicita od vrednosti za ``radnik1` objekat)

			// Osloboditi svu zauzetu dinamicku memoriju
}