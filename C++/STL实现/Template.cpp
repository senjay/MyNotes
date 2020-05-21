#include<iostream>
using namespace std;

//函数模板化    
template<typename T>
T add(const T lval,const T rval)
{
    T ans = lval + rval;
    return ans; 
}

//*******************************************//
//类模板
template<class T>
class Myclass
{
    T a;
    public:
        T add(const T lval, const T rval);
};
template <class T>
T Myclass <T>::add(const T lval, const T rval)
{
    a = lval + rval;
    return a;
}
//*****************************************//
//成员模板
template<class T>
class Mylove
{
    public:
        T a;
        template <typename type_1, typename type_2>
        type_1 add(const type_1 lval, const type_2 rval);
};
template <class T>
template <typename type_1, typename type_2>
type_1 Mylove<T>::add(const type_1 lval, const type_2 rval)
{
    a = lval + rval;
    return a;
}
//*****************************************//
//嵌套类模板
template<class T>
class Mylife
{
    public:
        T a;
        template <class type_3>
        class Mystory;//先声明，在外部定义
        Mystory<T> mystory;//用T实例化
};
template<class T>
    template<class type_3>
        class Mylife<T>::Mystory
        {
            public:
                type_3 c;
                type_3 add(const type_3 lval, const type_3 rval) 
                {
                    c = lval + rval;
                    return c;
                };
        };
//*****************************************//
int main()
{
    //函数模板
    cout << add(1, 2) << endl;
    cout << add(2.1, 1.2) << endl;//使用add(2, 1.2)会报错,因为变成了add(int,double)

    //类模板
    Myclass<double> myclass;
    cout << myclass.add(1.2, 3.3) << endl;

    //成员模板函数
    Mylove<double> mylove;
    cout << mylove.add(0, 20.2) << endl; //答案为20，因为该函数返回为第一个参数相同,该过程为int+double=double,但最终返回int

    //嵌套类模板
    Mylife<double> mylife;
    cout << mylife.mystory.add(1, 1.1) << endl;
    return 0;
}
