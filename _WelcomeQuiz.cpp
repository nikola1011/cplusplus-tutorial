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

// Operatori ?

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

