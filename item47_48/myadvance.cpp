/*
traits allows you to get type information for a 
specific type - meta programming
*/
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d, std::random_access_iterator_tag){
    iter += d;
}

template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d, std::input_iterator_tag){
    while(d--)
        ++iter;
}

template<typename IterT, typename DistT>
void myadvance(IterT& iter, DistT d) {
    doAdvance(iter, d, typename std::iterator_traits<IterT>::iterator_category());
}

int main()
{
    std::vector<int> v{3,5,7,8,10};
    auto a = v.begin();
    myadvance(a, 2);
    cout << *a << endl;
    
    double b[10] = {10, 9.4, 8.3, 7.5, 100.3, 5};
    double *b_iter = b;
    myadvance(b_iter, 4);
    cout << *b_iter << endl;
}
