/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

template <typename T, typename U>
struct is_same_2
{
    enum{ value = false };
};

template <typename T>
struct is_same_2<T, T>
{
    enum { value = true };
};


template <class A, class B>
bool IsSameClass() {
    return is_same_2<A, B>::value;
}

class Foo {};
class Bar: public Foo {};
class Unknown;

int main()
{
    cout << IsSameClass<Foo, Bar>() << endl;
    cout << IsSameClass<Foo, Foo>() << endl;
}

