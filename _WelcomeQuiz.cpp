// Introduction (me, course planning)
// C znanje iz prethodne godine ? Polozen AIP ?
// Trenutna godina studija, da li prvi put vide C++ ili znaju ponesto, polagali su ispite ?
// C++ znanje / upoznavanje ?
// Razlike izmedju C i C++-a ? (C++ => OOP support, functional + object oriented driven, polymorphism, encapsulation, supports namespaces superset of C)

// Sta je kompajler ? Rezultat rada kompajlera ?
// Sta je linker ? Rezultat rada linkera ?
// http://oberon00.github.io/cpptutorial/proc/hello-world.html

// Sta je main funkcija ?
// Sta su pretprocesorske direktive ? Kada se izvrsava pretprocesiranje ?

// Da li je C++ case sensitive jezik ?
// Tipovi podataka u C++-u ? https://www.tutorialspoint.com/cplusplus/cpp_data_types.htm 
// Razlike u tipovima podataka odnosu na C ? Primitivni tipovi su "isti" u oba jezika. User defined data types (classes) u C++.

////// Operators

// Output from this ?
int y = 10;
int x = 11;
y = y-- + x++ + x++;
std::cout << "Y = " << y << std::endl;

// Output from this ?
y = 10;
x = 11;
y = --x - --y;
std::cout << "Y = " << y << std::endl;

// >> i << operatori ?
// C++ uses a convenient abstraction called streams to perform input and output operations
// A stream is an entity where a program can either insert or extract characters to/from

// Sta je ternarni operator ?

// Output sledece petlje ?
int i = 0;
while (i > 0)
{
	std::cout << i << std::endl;
	i++;
}
std::cout << i << std::endl;

////// Functions

// Kako se definise inline funkcija sa 'int' povratnim tipom, dva parametra float x i float y, gde je y ima defaultnu vrednost 10 ?
// Razlika izmedju prenosa po referenci i vrednosti ?

// Output:
int myFunc(int &x)
{
    return x % 2;
}

x = 15;
myFunc(x);
std::cout << x << std::endl;

// Output:
int myAddFunc(int a, int b)
{
    c = a + b;
    return c;
}

x = 10;
y = 10;
int result = myAddFunc(x, y);
std::cout << result << std::endl;

// Sta su prototipovi funkcija ?
// Koja je povratna vrednost funkcije main ?

// Da li funkcija moze pozvati samu sebe ?
// Output:
void callMe(int myNumber)
{
    if (myNumber != 0)
        callMe(--myNumber);
}

callMe(4);

// Sta su rekurzivne funkcije ?

////// Arrays

// How are arrays defined ?

// Output from:
int myIntArray [39] = { "111", "222" };
std::cout << myIntArray[1] << std::endl;

// Output from:
int myIntArray [39] = { 111, 222 };
std::cout << myIntArray[1] << " " << myIntArray[30] << std::endl;

// Output from:
int myIntArray [39];
std::cout << myIntArray[4] << " " << myIntArray[14] << std::endl;

////// Pointers

// Kako C++ program vidi RAM memoriju racunara ?
// Sta su pointeri ?
// & - operator, * - operator ?

// Output:
int x = 329;
int* myPointer;
myPointer = &x;
*myPointer = 4;
std::cout << x << std::endl;

// Da li su velicine sledecih promenljivi (pointera) iste ?
int* myIntPointer;
char* myCharPointer;
float* myFloatPointer;

// Output:
int x = 329;
int* p1, p2;

p1 = &x;
p2 = *p1;

x = 111;
std::cout << p2 << std::endl;

// Output:
int myIntArray[] = { 11, 12, 13, 14, 15, 16};
int* pointerToArray = myIntArray;
std::cout << *pointerToArray << std::endl;

// Output:
int myIntArray[] = { 11, 12, 13, 14, 15, 16};
int* pointerToArray = myIntArray;
pointerToArray += 4;
*pointerToArray = 444;
for (int i = 0; i < 6; i++)
	std::cout << myIntArray[i] << " ";

// Sta je NULL pointer ?

////// Dynamic memory

// Koliko memorije je zauzeto, kada je ona oslobodjena od strane programa ?
int myStaticArray[32];

// Sta je razlika izmedju sledece dve linije ?
int myInt;
int* dynamicInt = new int;

// Cemu sluze sledeci operatori
delete ptr;
delete [] myArrayPtr;

////// Classes basics

// Sta su klase, cemu sluze ?
// Sta su i koji specifikatori pristupa postoje ?
// Sintaksa deklaracije klase (pozdrazumevani specifikator pristupa) ?
// .cpp, .h fajlovi ? 

// Konstruktori, desktruktori ?
void ClassName(int param1, int param2); // Is this validly declared constructor for class `ClassName`

// Is the following a valid destruktor implementation ?
ClassName()
{
	delete this->name;
}

// Koliko konstruktora klasa moze da sadrzi, koliko podrazumevanih (default) konstruktora, sta se desi kada klasa ne deklarise podrazumevani konstruktor/destruktor ?
// Sta se desi ako nije definisan konstruktor za kopiranje unutar klase ?

class Vozilo { ... }
Vozilo v(); // Da li je ovo validno pozvan konstruktor za klasu Vozilo ? (ne, to je deklaracija funkcije ciji je povratni tip Vozilo)

// Konstruktori za kopiranje ?

// `this` pokazivac

// inline funkcije, inline kjucna rec ?

// Prenos po vrendosti, referenci, pokazivacu ?

void f(const T& a); // What does `const` indicate here ?

// Staticki atributi klase (polja i funkcije) ? (pripadnost klasi, a ne objektu)
// Deklaracija statickih atributa i koriscenje statickih atributa
static float max = 320.34f;
MyClass::max;

// friend funkcije, friend klase ?

////// Operator overloading

// Sta je predefinisanje operatora ?

// Koji operatori ne mogu biti predefinisani ?
// Operators ::  .  .*  ?: CANNOT be overloaded

// Sta nije moguce kod pisanja operatorskih funkcija ?
// Operators ::  .  .*  ?: CANNOT be overloaded
// New operators CANNOT be created
// Precedence, grouping or number of operator operands cannot be changed
// && and || lose short circut evaluation

// Da li su ovo validni nacini da se pozove predefinisan operator+ ?
a.operator+(b);
a + b

// Predefinisanje operatora dodele (operator=), sta ako ne postoji predefinisan ?
// Kakvo dodeljivanje vrsi operator= u slucaju da se generise od strane kompajlera ? (shallow copy)

// Razlika izmedju konstruktora za kopiranje i operator= ?
Vozilo v1;
Vozilo v2 = v1; // Da li ce ovde biti pozvan operator= ?

// Predefinisanje prefiks i postfix operatora ?

////// Classes inheritance

// TODO: cas9, 10, 11 and on ...
