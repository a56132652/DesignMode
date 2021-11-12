/*
    原型模式：
        用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象

    在GOF的《设计模式：可复用面向对象软件的基础》中是这样说的：
        用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象，该定义中的重点就是“拷贝”，而拷贝又分为深拷贝和浅拷贝。

        浅拷贝：就是给对象中的每个成员变量进行复制，就是把A1类中的变量直接赋给A2类中变量，属于值传递，但是涉及到有new之类内存分配的地方，他们却是共享内存的。
        深拷贝：就是不仅使用值传递，而是要每个变量都有自己一份独立的内存空间，互不干扰。

    具体实现：
        原型类会提供一个clone()接口，该接口的具体实现由派生类完成，而实现原型模式的重点就在于这个clone接口的实现。

        ConcretePrototype1类和ConcretePrototype2类继承自Prototype类，并实现Clone接口，实现克隆自身的操作；同时，在ConcretePrototype1类
    和ConcretePrototype2类中需要重写默认的复制构造函数，供Clone函数调用，Clone就是通过在内部调用重写的复制构造函数实现的。在后续的编码过程中，
    如果某个类需要实现Clone功能，就只需要继承Prototype类，然后重写自己的默认复制构造函数就好了。

    使用场景：
    1.使用拷贝模式比直接new一个对象的开销要小的多。
    2.可以在程序运行时（对象属性发生了变化），得到一份内容相同的实例，但之间还不会相互干扰。
*/

#include <iostream>
#include <string>
#include <memory>
using namespace std;
class Person
{
public:
	string name;
	int age;
	Person(string _name, int _age) :name(_name), age(_age) {}
	virtual ~Person() {}
	virtual void showMe()
	{
		cout << "I am " << name << ", and " << age << endl;
	}
	virtual Person *clone()
	{
		return new Person(*this);
	}
};
 
class Boy :public Person
{
public:
	Boy(string _name, int _age):Person(_name, _age)
	{}
	~Boy() {}
	virtual void showMe() override
	{
		Person::showMe();
		cout << "I am a boy" << endl;
	}
	virtual Person *clone() override
	{
		return new Boy(*this);
	}
};
class Girl :public Person
{
public:
	Girl(string _name, int _age) :Person(_name, _age)
	{}
	~Girl() {}
	virtual void showMe() override
	{
		Person::showMe();
		cout << "I am a Girl" << endl;
	}
	virtual Person *clone() override
	{
		return new Girl(*this);
	}
};
 
int main()
{
	//创建一个boy  a
	Person *a = new Boy(string("Ming"), 28);
	a->showMe();
	//创建一个Girl  b
	Person *b = new Girl(string("Li"), 28);
	b->showMe();
 
	//克隆a--不使用原型模式的写法
	shared_ptr<Person> cloneA(new Boy(*dynamic_cast<Boy *>(a)));
	cloneA->showMe();
 
	//克隆b--使用原型模式的写法
	shared_ptr<Person> cloneB(b->clone());
	cloneB->showMe();
 
	delete b;
	delete a;
 
	return 0;
}