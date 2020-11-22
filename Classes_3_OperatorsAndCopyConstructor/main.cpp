// TODO:
//
//operatori
//istream& operator>>
//ostream & operator<<
//
//proucite -> "D:\OOP\OOP RV04 Primeri\C0403"


// Fudbal club example

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
		delete[] this->scores;

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

	void printScores()
	{
		for (int i = 0; i < this->currentScores; i++)
			cout << "Scores: " << this->scores[i] << endl;
	}
};

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


}