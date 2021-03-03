#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string>
#include <set> 
using namespace std;

class Pet
{
	string _name;
	int _age;
	string _colour;

public:
	Pet()
	{
		_name = "Default";
		_age = 0;
		_colour = "Null";
	}
	Pet(string name, int age, string colour)
	{
		_name = name;
		_age = age;
		_colour = colour;
	}
	void print()
	{
		cout << _name << endl;
		cout << _age << endl;
		cout << _colour << endl;
	}

	void edit(string name, int age, string colour)
	{
		_name = name;
		_age = age;
		_colour = colour;
	}
};


class Dog : public Pet
{
public:
	Dog() :Pet::Pet() {}
	Dog(string name, int age, string colour) :Pet::Pet(name,age,colour) {}
	void bark()
	{
		cout << "Hav-hav";
	}
};

class Cat : public Pet
{
public:
	Cat() :Pet::Pet() {}
	Cat(string name, int age, string colour) :Pet::Pet(name, age, colour) {}
	void Meow()
	{
		cout << "meow";
	}
};

class Parrot : public Pet
{
	string _energy;
public:
	Parrot() :Pet::Pet() {}
	Parrot(string name, int age, string colour, string energy) :Pet::Pet(name, age, colour) { _energy = energy; }
	void feedParrot()
	{
		_energy = "Full";
	}
};


int main()
{
	Dog dog1;
	dog1.print();
	dog1.edit("Toplan", 2, "Black");
}
