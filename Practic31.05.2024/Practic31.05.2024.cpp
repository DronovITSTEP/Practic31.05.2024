#include <iostream>
#include "DynArray.h"

using namespace std;

DynArray arrayFactory(int arrSize) {
    DynArray arr{ arrSize };
    arr.randomize();
    return arr;
}

int max(int a, int b) {
    return a > b ? a : b;
}



void funA(int& val) { cout << "funA() called for int&\n"; }
void funA(const int& val) { cout << "funA() called for const int&\n"; }
void funA(int&& val) { cout << "funA() called for int&&\n"; }
void funB(int& val) { cout << "funB() called for int&\n"; }
void funB(const int& val) { cout << "funB() called for const int\n"; }

int main()
{
    /*DynArray arr1{ 10 };
    arr1.randomize();
    cout << "arr1 elements: ";
    arr1.print();

    DynArray arr2{ arr1 };
    cout << "arr2 elements: ";
    arr2.print();

    DynArray arr3{ 5 };
    cout << "arr3 elements: ";
    arr3.print();

    arr3 = arr2;
    cout << "arr3 elements: ";
    arr3.print();*/

    DynArray arr1{ move(arrayFactory(10)) };
    cout << "arr1 elements: ";
    arr1.print();
    cout << "\n";

    arr1 = arrayFactory(5);
    cout << "arr1 elements: ";
    arr1.print();

    //int x{ 34 };
    //int& refX{ x }; // lValue - ссылка
    //int&& refV{ 34 };// rValue - ссылка

    //const int& cRefX{ x }; // lValue
    //const int& cRefXX{ x+5 };

    //cout << x << endl;
    //cout << refX << endl;
    //cout << cRefX << endl;
    //cout << cRefXX << endl;

    /*int&& rvalRef{ 2 + 3 };
    rvalRef += 3;
    cout << rvalRef << "\n";

    int&& res{ max(3,5) };
    res += max(4,7);
    cout << res;*/

    //int x{ 43 };
    ////int&& rvalBad{ x };
    //int rvalRef2{ move(x) };
    ////int&& rvalBad2{ res };

    //int& lvalref{ res };
    //cout << lvalref << "\n";


    /*int x{ 33 };
    const int cVal{ 25 };

    funA(x);
    funA(cVal);
    funA(80+1);
    funA(move(x));
    cout << endl;
    funB(x);
    funB(cVal);
    funB(80 + 1);
    funB(move(x));*/

}
