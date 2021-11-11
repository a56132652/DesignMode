/*
    适配器模式---将一个类的接口转换成客户希望的另外一个接口。Adapter模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作
    适配器模式主要应用于希望服用一些现存的类，但是接口又与复用环境要求不一致的情况
*/
#include <iostream>
using namespace std;

//客户所期待的接口
class Target
{
public:
    virtual void Request()
    {
        cout << "普通请求"<< endl;
    }
};

//需要适配的类
class Adaptee
{
public:
    void SpecificRequest()
    {
        cout << "特殊请求" <<endl;
    }
};

//适配器Adapter ———— 通过在内部包装一个Adaptee对象，把原接口转换成目标接口
class Adapter : public Target
{
private:
    //建立一个私有的Adaptee对象
    Adaptee* adaptee = new Adaptee();
public:
    virtual void Request()
    {
        adaptee->SpecificRequest();
    }

};

int main()
{
    //对于用户而言，调用的就是Target的Request()接口
    Target* target = new Adapter();
    target->Request();

    cin.get();
    return 0;
}

