#include <iostream>
using namespace std;

class Base {
    public:
        /*
        Base() {}
        Base(int c):count(c){}
        */

        /* 虚函数 */
        virtual void print() const=0;
    private:
        int count;
};

class B {
};

class Derived: public Base {
    public:
        /*
        Derived():Base(0) {}
        Derived(int c):Base(c) {}
        */

        /* 多态性的体现. 前提是公有派生. */
        void print() const {cout<<"Derived"<<endl;}
    private:
        /* 静态数据成员 */
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

    Base b;
    Derived d(10);

    /* 动态联编: 基对象指针调用虚函数 */
    Base *pb = &d;
    pb->print();

    Base &cb = d;
//    Derived dd = *pb;
//    Derived &cd = cb;
//    Base bb = d;
    return 0;
}
