/*
Item 19, equivalance and equality

The order set/map etc container to decide the order
of items are:
1. using key_comp
2. which by default use less<T>
3. which by default use operator< 
*/
#include <iostream>
#include <string>
#include <set> // set 
#include <functional> // binary_function
#include <algorithm> // find

using namespace std;

bool ciStrCompare(const string& lhs, const string& rhs){
    return false;
}

struct CiStrCompare: public binary_function
    <string, string, bool> {
        bool operator()(const string& lhs, const string& rhs){
            cout << "comparing " << lhs << " " << rhs << endl;
            return ciStrCompare(lhs, rhs);
        }
    };
    
/*
specialized version of less functor
*/
namespace std {
    
    template<>
    struct less<int> {
      bool operator()(int a, int b) const{
          cout << "my less version " << endl;
          return a<b;
      }  
    };
}

int main()
{
    set<string, CiStrCompare> ciss;
    ciss.insert("Person");
    ciss.insert("person");
    
    if(ciss.find("person")!=ciss.end()){
        cout << "can find with set's find " << endl;
    }
    
    if(std::find(ciss.begin(), ciss.end(), "person")!=ciss.end()){
        cout << "this equal test will fail" << endl;
    }
    // provoke comparison function 
    set<string, CiStrCompare>::key_compare it = ciss.key_comp();
    cout << it("a", "b") << endl;
    
    set<int> iset;
    iset.insert(22);
    iset.insert(23);
    for(auto i: iset)
        cout << i << endl;
    cout << "end" << endl;

}



