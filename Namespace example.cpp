#include <iostream>

using namespace std;

namespace n1
{
	class Base;
	class Derived;
}

class n1::Base
{
	int _num{};

public:
	Base() {};

	Base(int num) :_num(num) {};

	int getNum()
	{
		return _num;
	}
};

class n1::Derived :Base
{
	int _dnum;

public:

	Derived(int dnum) :Base(dnum)
	{
		_dnum = dnum;
	}

	void print()
	{
		cout << _dnum << endl;
		cout << getNum() << endl;
	}
};

namespace Test
{
	int value;
}


int main()
{
	int value = 5;
	n1::Derived d1(12);
	d1.print();

	Test::value = 40;
	cout <<"Namespace value:"<< Test::value << endl;
	cout << "Main value:" << value;
}