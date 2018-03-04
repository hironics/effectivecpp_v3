

#include <iostream>
#include <vector>


namespace WidgetStuff {
class WidgetImpl {
    
    private:
    int a, b, c;
    std::vector<int> v;
};

class Widget {
  public:
    Widget(int n): pimpl(new WidgetImpl){
        std::cout << "constructor " <<n << std::endl; 
    }
    Widget(const Widget& rhs)  ;
    Widget& operator=(const Widget& rhs){
        *pimpl = *(rhs.pimpl);
    };
    
    void swap(Widget& other){
        using std::swap;
        std::cout << "public swap interface" << std::endl;
        swap(pimpl, other.pimpl);
    }
  private:
    WidgetImpl *pimpl;
};

void swap(Widget& a, Widget& b){
    std::cout << "web swap" << std::endl;
    a.swap(b);
}

} // end of namespace

namespace std {
    template<>
    void swap<WidgetStuff::Widget>(WidgetStuff::Widget& a, WidgetStuff::Widget& b){
        //swap(a.pimpl, b.pimpl); // compile error: trying to access private member
        cout << "std swap" << endl;
        a.swap(b);
    }
}

template<typename T>
void doSwap(T& obj1, T& obj2){
    using std::swap;
    swap(obj1, obj2);
}

int main()
{
    WidgetStuff::Widget w(0) ;
    WidgetStuff::Widget y(1) ;
    doSwap(w, y);
}

