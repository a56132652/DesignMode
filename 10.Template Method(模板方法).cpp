/*
    模板方法：
    既然用了继承，并且肯定这个继承有意义，就应该要成为子类的模板，所有重复的代码都应该要上升到父类去，而不是让每个子类都去重复
    当我们要完成在某一细节层次一致的一个过程或一系列步骤，但其个别步骤在更详细的层次上的实现可能不同时，我们通常考虑使用模板方法模式来处理
    ------定义一个操作中的算法的骨架，而将一些步骤延迟到子类中。模板方法使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤
    将不变方法搬移到父类，去除子类中的重复代码来体现其优势
*/
#include <iostream>
using namespace std;

class AbstractClass
{
public:
    //一些抽象行为，放到子类去实现
    virtual void Operation1() = 0;
    virtual void Operation2() = 0;

    //模板方法，给出了逻辑的骨架，而逻辑的组成是一些相应的抽象操作，他们都推迟到了子类去实现
    void TemplateMethod(){
        Operation1();
        Operation2();
    }
};
//子类A重写方法1 2
class ConcreteClassA : public AbstractClass
{
public:
    virtual void Operation1(){
        cout << "具体类A方法1实现"<<endl;
    }
    
    virtual void Operation2(){
        cout << "具体类A方法2实现"<<endl;
    }
};
//子类B重写方法1 2
class ConcreteClassB : public AbstractClass
{
public:
    virtual void Operation1(){
        cout << "具体类B方法1实现"<<endl;
    }
    
    virtual void Operation2(){
        cout << "具体类B方法2实现"<<endl;
    }
};

int main()
{
    AbstractClass* c;

    c = new ConcreteClassA();
    c->TemplateMethod();

    c = new ConcreteClassB();
    c->TemplateMethod();

    cin.get();
    return 0;
}