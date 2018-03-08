
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>

using namespace std;

namespace MyLib {
    template <typename T>
    class MyAlloc {
      
      public:
      //typedef 
      typedef T         value_type;
      typedef T*        pointer;
      typedef const T*  const_pointer;  // required by list
      
      typedef T&        reference;
      typedef const T&  const_reference; // required by list
      typedef std::size_t size_type;
      
      /* constroctur and destructor 
        - nothing to do because the allocator has no state
      */
      MyAlloc()  { }
      MyAlloc(const MyAlloc&)  {  } //required by non-vector
        
      template <class U>
      MyAlloc (const MyAlloc<U>&)  {    }
      ~MyAlloc()  {    }
       
      //rebind allocator to type U 
      // handles cases like you allocate ListNode for type type T 
      // MyAlloc::rebind<ListNode>::other -> allocator for list node rather than its content T
      template <class U>
      struct rebind {
          typedef MyAlloc<U> other;
      };
      
      //allocator and deallocator
      // but don't initialize num elements of type T
      pointer allocate(size_type num, const void* k=0){
          std::cerr << "allocated " << num << " elements" << std::endl;
          pointer ret = (pointer)(::operator new(num*sizeof(T)));
          return ret;
      }
      
      void deallocate(pointer p, size_type num){
          ::operator delete((void *)p);
      }
      
      // constructor and detroy
      void construct(pointer p, const T& value){
          std::cerr << "constructing "  << std::endl;
          new ((void*)p) T(value);
      }
      void destroy(pointer p){
          p->~T();
      }
      
    };
}

int main()
{
    vector<int, MyLib::MyAlloc<int> > myvec;
    myvec.push_back(10);
    cout << myvec[0] << endl;
    myvec.reserve(30);
    cout << "after reserve" << endl;
    myvec.push_back(32); myvec.push_back(23);
    
    cout << "==============" << endl;
    deque<double, MyLib::MyAlloc<double> > mydeq;
    mydeq.push_back(15.5);
    cout <<*mydeq.begin() << endl;
    
    cout << "==============" << endl;
    list<float, MyLib::MyAlloc<float> > mylist;
    mylist.push_back(10.1f);
    
}




