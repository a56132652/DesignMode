/*
    对象的继承关系是在编译时就定义好了，所以无法在运行时改变从父类继承的实现。
    子类的实现与他的父类有非常紧密的依赖关系，以至于父类实现中的任何变化必然会导致子类发生变化。
    当你需要复用子类时，如果继承下来的实现不适合解决新的问题，则父类必须重写或者被其他更适合的类替换。
    这种依赖关系限制了灵活性并最终限制了复用性

    在面向对象设计中，有一个很重要的设计原则，那就是合成/聚合复用原则，即优先使用对象合成/聚合，而不是类继承

    聚合表示一种 弱 的“拥有”关系，体现的是A对象可以包含B对象，但 B对象不是A对象的一部分
    合成表示一种 强 的“拥有”关系，体现了严格的部分和整体的关系，部分和整体的生命周期一样，继承便是一种合成关系

    例如，一只大雁和它自己的翅膀拥有一样的生命周期，是整体和部分的关系，因此是 合成关系
    每只大雁都有它所属的雁群，大雁和其所属的雁群是聚合关系

    合成-聚合原则：优先使用对象的合成/聚合有助于你保持每个类被封装，并被集中在单个任务上。这样类和继承层次会保持较小规模，并且不太可能增长为不可控制的庞然大物。

    桥接模式————将抽象部分与它的实现部分分离，使他们都可以独立地变化
    实现系统可能有多角度分类，每一种分类都有可能变化，那么就把这种多角度分离出来让他们独立变化，减少他们之间的耦合


*/

#include<iostream>
using namespace std;

//Implementor类
class Implementor
{
public:
    virtual void Operation();
};
//派生类ImplementorA
class ImplementorA : public Implementor
{
public:
    virtual void Operation()
    {
        cout << "具体实现类A的方法执行" << endl;
    }
};
//派生类ImplementorB
class ImplementorB : public Implementor
{
public:
    virtual void Operation()
    {
        cout << "具体实现类B的方法执行" << endl;
    }
};

//类Abstraction
class Abstraction
{
protected:
    //包含一个Implementor类的指针，使Abstraction类与Implementor类成为弱耦合关系，即聚合关系
    Implementor* implementor;
public:
    void SetImplementor(Implementor* implementor)
    {
        this->implementor = implementor;
    }

    virtual void Operation()
    {
        implementor->Operation();
    }
};
//派生类RefinedAbstraction
class RefinedAbstraction : public Abstraction
{
public:
    virtual void Operation()
    {
        implementor->Operation();
    }
};

int main()
{
    Abstraction* ab = new RefinedAbstraction();

    ab->SetImplementor(new ImplementorA());
    ab->Operation();

    ab->SetImplementor(new ImplementorB());
    ab->Operation();

    cin.get();
    return 0;
}
