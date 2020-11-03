#include <iostream>

using namespace std;

int main()
{
    ///
    /// Operators
    ///
    
    // Assignment operator =
    int x = 192389;
    int y;
    y = x; // y <- x (from right to left).
    cout << "Y = " << y << endl;

    x = 5;
    y = 10 + (x = 20); // y <- 10 + (x <- 10); y <- 30
    cout << "Y = " << y << endl;

    int z = x = y = 0; // z <- x <- y <- 0

    /*
        + addition
        - subtraction
        * multiplication
        / division
        % modulo
    */

    int moduo = 2392 % 10; // 2392 = 239 * 10 + 2
    cout << "Moduo is : " << moduo << endl;
    
    moduo = 3 % 6;
    // cout << "Moduo is : " << moduo << endl;
    moduo = 1 % 76;
    // cout << "Moduo is : " << moduo << endl;
    moduo = 0 % 76;
    // cout << "Moduo is : " << moduo << endl;

    x = 9;
    x = x + 12;
    cout << "X = " << x << endl;

    x += 9;
    cout << "X = " << x << endl;

    /*
        compound assignment
        +=
        -=
        *=
        /=
        %=
    */
    
    x *= 2;
    cout << "X = " << x << endl;

    // Increment and decrement
    // ++
    // --

    x = 10;
    x++; // x = x + 1
    x--; // x = x - 1
    x++; // x = x + 1
    cout << "X = " << x << endl;

    x = 3;
    y = ++x;
    // x contains 4, y contains 4
    cout << "Y = " << y << " X = " << x << endl;

    x = 3;
    y = x++;
    // x contains 4, y contains 3
    cout << "Y = " << y << " X = " << x << endl;

    // In the case that the increase operator is used as a prefix(++x) of the value, 
    // the expression evaluates to the final value of x, 
    // once it is already increased.On the other hand, 
    // in case that it is used as a suffix(x++), the value is also increased, 
    // but the expression evaluates to the value that x had before being increased

    y = 10;
    x = 11;
    y = y-- + x++ + x++;
    cout << "Y = " << y << endl;

    /* 
        relational and comparison operators
        ==      equal 
        !=      not equal
        >       greater than
        <       less than
        >=      greater or equal than
        <=      less or equal than
    */

    cout << (7 == 5) << endl;
    cout << (5 > 4) << endl;
    cout << (3 != 2) << endl;
    cout << (6 >= 6) << endl;
    cout << (5 < 5) << endl;
    

    /*
        logical operators
        !
        &&
        ||
    */
    x = 10;
    cout << !(x == 5) << endl;
    cout << !(x >= 5) << endl;
    cout << !true << !false << !x << endl;

    cout << (x == 10 && x > 5) << endl;
    // If the left-hand side expression is false, the combined result is false (the right-hand side expression is never evaluated).
    cout << (x != 10 || x > 5) << endl;
    // If the left - hand side expression is true, the combined result is true (the right - hand side expression is never evaluated).

    // Precendence of operators

    x = 5 + 7 % 2; // x = 0 or x = 6 ??
    // cout << "X = " << x << endl;
    // HINT: Use parenthensis '()'
    x = 5 + (7 % 2);
    x = (5 + 7) % 2;


    /*
    Level	Precedence group	Operator	Description	Grouping
    1	Scope::scope qualifier	Left - to - right
    2	Postfix(unary)++ --postfix increment / decrement	Left - to - right
    ()	functional forms
    []	subscript
    .->member access
    3	Prefix(unary)++ --prefix increment / decrement	Right - to - left
    ~!bitwise NOT / logical NOT
    + -unary prefix
    & *reference / dereference
    new delete	allocation / deallocation
    sizeof	parameter pack
    (type)	C - style type - casting
    4	Pointer - to - member	.*->*access pointer	Left - to - right
    5	Arithmetic: scaling * / % multiply, divide, modulo	Left - to - right
    6	Arithmetic : addition + -addition, subtraction	Left - to - right
    7	Bitwise shift	<< >>	shift left, shift right	Left - to - right
    8	Relational	< > <= >=	comparison operators	Left - to - right
    9	Equality	== !=	equality / inequality	Left - to - right
    10	And & bitwise AND	Left - to - right
    11	Exclusive or ^ bitwise XOR	Left - to - right
    12	Inclusive or	|	bitwise OR	Left - to - right
    13	Conjunction && logical AND	Left - to - right
    14	Disjunction || logical OR	Left - to - right
    15	Assignment - level expressions = *= /= %= += -=
    >>= <<= &= ^= |= assignment / compound assignment	Right - to - left
    ? : conditional operator
    16	Sequencing, comma separator	Left - to - right
    */
}
