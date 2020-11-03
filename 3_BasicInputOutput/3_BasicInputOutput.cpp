#include <iostream>

using namespace std;

int main()
{
    // C++ uses a convenient abstraction called streams to perform input and output operations
    // A stream is an entity where a program can either insert or extract characters to/from

    /*
        cin	    standard input stream
        cout	standard output stream
        cerr	standard error(output) stream
        clog	standard logging(output) stream
    */

    // The << operator inserts the data that follows it into the stream that precedes it.
    cout << "Hello! " << "I am a computer program" << endl;
    cout << "Hello again!" << endl << "I am in new line" << endl;

    int yourLuckyNumber;
    cout << "Enter your lucky number:\n";
    cin >> yourLuckyNumber; // standard input, by default, is the keyboard
    cout << "Your lucky number is: " << yourLuckyNumber << endl;

    string yourStory;
    cout << "Tell me a story..." << endl;
    cin >> yourStory;
    cout << "Ok. Cool story bro.";

}