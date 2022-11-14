#ifndef _SINGLETON_H
#define _SINGLETON_H

class Log
{
public:

  //静态成员函数,用来初始化该单例模式对象，且只能创建一个
  static Log *initLog();

private:
  //构造/析构函数,私有属性使得在类外无法创建对象
  Log();

  //成员变量

  //静态成员变量,使得只能在类内通过接口访问指向的这个单例模式对象
  static Log *ptrLog_;
};

#endif //_SINGLETON_H