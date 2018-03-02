
#include <iostream>

using namespace std;

template<unsigned n>
struct Factor
{
    enum { value = n*Factor<n-1>::value};
};

template<>
struct Factor<0>
{
    enum { value = 1};
};

int main()
{
    cout<<"Hello World";
    cout << Factor<10>::value;
    return 0;
}



