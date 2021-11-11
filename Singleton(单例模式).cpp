#include<iostream>

//写法一
class A
{
public:
    static A& getInstance(){ return a; }
    void setup() { std::cout<<"Singleton"<<std::endl; }
private:
    A();
    A(const A& rhs);
    static A a;
};

//写法二
class A
{
public:
    static A& getInstance();
private:
    A();
    A(const A& rhs);
};
//只有有人调用该函数，静态对象才会被创建，若没有人使用该单例，则该单例不存在，节省了空间
A& A::getInstance()
{
    static A a;
    return a;
}
