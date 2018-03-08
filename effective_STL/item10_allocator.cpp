
#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

namespace MyLib {
    template <typename T>
    class MyAlloc {
      
      public:
      //typedef 
      typedef T      value_type;
      typedef T*     pointer;
      typedef T&     reference;
      typedef std::size_t size_type;
      
      //rebind allocator to type U 
      template <class U>
      struct rebind {
          typedef MyAlloc<U> other;
      };
      
      //allocator and deallocator
      pointer allocate(size_type num, const void* k=0){
          pointer ret = (pointer)(::operator new(num*sizeof(T)));
          return ret;
      }
      
      void deallocate(pointer p, size_type num){
          ::operator delete((void *)p);
      }
      
    };
}

int main()
{
    vector<int, MyLib::MyAlloc<int> > myvec;
    myvec.push_back(10);
    cout << myvec[0] << endl;
    
    /*
    deque<double, MyLib::MyAlloc<double> > mydeq;
    mydeq.push_back(15.5);
    cout <<*mydeq.begin() << endl;
    */
}




