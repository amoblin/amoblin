#include <iostream>
using namespace std;

class Base {
    public:
        Base() {}
        Base(int c):count(c){}
        virtual void print() const=0;
    private:
        int count;
};

class B {
};

class Derived: public Base {
    public:
        Derived():Base(0) {}
        Derived(int c):Base(c) {}
        void print() const {cout<<"Derived"<<endl;}
    private:
        static B m_flag;
};

B Derived::m_flag;

namespace C {
    B b2;
}

int main()
{
    int hex=8;
    cout<<hex<<16<<"Hello"<<", world!\n"<<endl;

    B b1;

    Derived d(10);
    Base *pb = &d;
    Base &cb = d;
//    Derived dd = *pb;
//    Derived &cd = cb;
//    Base bb = d;
    return 0;
}
