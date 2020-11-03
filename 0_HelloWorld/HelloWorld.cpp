/* 
* Linije koje pocinju sa # su pretprocesorske direktive.
* Evaluiraju se od strane pretprocesora pre faze kompajliranja.
* */
#include <iostream> // Pretprocesor ukljucuje <iostream> biblioteku za obavljanje standardnog ulaza i izlaza (citanja sa tastature i ispisa na ekran, respektivno)

// cout je dao standardne biblioteke
// svi elementi standardne C++ biblioteke su deklarisani unutar namespace-a
// u ovom slucaju taj namespace je 'std' (skraceno od standard)

// using namespace std;
// Koristeci prethodnu deklaraciju omogucava se koriscene elemenata standardne biblioteke bez prethodnog prefiksa 'std'::'

// Deklaracija funkcije
// 'main' je glavna funkcija programa. Izvrsenje programa pocinje i zavrsava se sa 'main' funkcijom.
// Svaka deklaracija funkcije ima povratni tip, naziv funkcije, ()  , i telo funkcije tj. blok naredbi.
int main()
{ // Pocetak bloka

    // std - STandarD
    // cout - Character OUTput
    // << operator
    // "Hello World!\n" je string literal
    std::cout << "Hello World!\n"; // Svaka naredba se zavrsava sa ;
    int m;
    std::cin >> m;
} // Kraj bloka

// Ovo je komentar. Sadrzaj napisan u komentarima se ne kompajlira niti izvrsava.
// Svaki komentar u jednom redu pocinje sa //

/* pocetak komentara
 Komentar
 u vise
 redova.

 kraj komentara
*/ 

/// I ovo je komentar

///////////////////////////// Jos jedan komentar

