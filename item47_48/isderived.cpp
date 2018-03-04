/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

template<typename B, typename D>
class isDerivedHelper {
    class No {};
    class Yes { No no[10];};
    
    static Yes test(B*);
    static No test(...);
    public:
    enum {Is = sizeof(test(static_cast<D*>(0)))==sizeof(Yes)};
};

template<typename B, typename D>
bool isDerivedFrom()
{
    return isDerivedHelper<B,D>::Is;
}

class Foo {};
class Bar: public Foo {};
class Unknown;

int main()
{
    cout << isDerivedFrom<Foo, Bar>() << endl;
    cout << isDerivedFrom<Foo, Unknown>() << endl;
}

