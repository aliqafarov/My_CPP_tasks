#include <iostream>
#include <windows.h>
using namespace std;

static int countTeacher = 0;
char enter[2];
int studentId = 0;


void colourFunc(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

class Person
{
public:
	string _name;
	string _surname;
	string _field;
	int _age;
	int _id;
};

class Student : public Person
{

public:
	Student(){}
	Student(int id, string name, string surname, int age, string field)
	{
		_id = id;
		_name = name;
		_surname = surname;
		_age = age;
		_field = field;
	}
	
};

class Group
{
	
public:
	Student* studentList = new Student[100];
	string _name;
	int _countOfStudent;
	Group() {};
	Group(string name, int countOfStudent) : _name(name), _countOfStudent(countOfStudent){}
	void addStudent(string name, string surname, string field, int age)
	{
		studentList[studentId]._id = studentId+1;
		studentList[studentId]._age = age;
		studentList[studentId]._name = name;
		studentList[studentId]._field = field;
		studentList[studentId]._surname =surname;
		studentId++;

	}

	void deleteStudent(int studentsID)
	{
		if (studentId==0) cout << "List is empty" << endl;
		else
		{
			for (int i = 0; i < studentId; i++)
			{
				studentList[studentId]._id = studentsID;
			}
		}
		
	}
	~Group() { delete[] studentList; }
};


class Teacher:public Person
{
public:
	Group* _group= new Group();
};

class EducationStaff
{
	
public:
	Teacher teacher[100];
	
	void addTeacher(string name, string surname, string field, int age)
	{
		teacher[countTeacher]._name = name;
		teacher[countTeacher]._surname = surname;
		teacher[countTeacher]._field = field;
		teacher[countTeacher]._age = age;
		teacher[countTeacher]._id = countTeacher+1;
		countTeacher++;
	}

	void addGroup(string groupName)
	{
		
		int id;
		cout << "Please enter Teacher id number" << endl;
		cin >> id;
		if (id >= countTeacher&& countTeacher==0)
		{
			cout << "Teacher cannot find!" << endl;
			Sleep(3000);

		}
		else
		{
			teacher[id-1]._group->_name = groupName;
		}
		
	}

	void editGroup(string groupName, int teacherId)
	{
		if (countTeacher >= teacherId)teacher[teacherId - 1]._group->_name = groupName;
		else cout << "Teacher not exits ";
	}

	void deleteGroup(int teacherId)
	{
		if (countTeacher >= teacherId) delete teacher[teacherId]._group;
		else cout << "Teacher not exits ";
	}
	
	void printGroupStudent(int teacherId)
	{
		for (int i = 0; i < studentId; i++)
		{
			cout<<"ID: "<<teacher[teacherId]._group->studentList[i]._id<<endl;
			cout<<"Name: "<<teacher[teacherId]._group->studentList[i]._name << endl;
			cout<<"Surname: "<<teacher[teacherId]._group->studentList[i]._surname << endl;
			cout<<"Age: "<<teacher[teacherId]._group->studentList[i]._age << endl;
			cout<<"Field: "<<teacher[teacherId]._group->studentList[i]._field << endl << endl;
		}
	}

	void printTeacherList()
	{
		for (int i = 0; i < countTeacher; i++)
		{
			cout <<"ID: "<<teacher[i]._id << endl;
			cout <<"Name: "<<teacher[i]._name << endl;
			cout <<"Surname: "<<teacher[i]._surname << endl;
			cout <<"Field: "<<teacher[i]._field << endl;
			cout <<"Age: "<<teacher[i]._age << endl<<endl;
		}
	}

}e1;

class Main
{
public:
	void firstPage()
	{
		system("cls");
		colourFunc(11); cout << "\t\t\t" << "STEP IT PORTAL" << endl;
		while (true)
		{
			colourFunc(14); cout << "1"; colourFunc(12); cout << ")  "; colourFunc(7); cout << "Teacher Interface" << endl;
			colourFunc(14); cout << "2"; colourFunc(12); cout << ")  "; colourFunc(7); cout << "Student Interface" << endl;
			colourFunc(14); cout << "3"; colourFunc(12); cout << ")  "; colourFunc(7); cout << "Education Staff" << endl;
			colourFunc(14); cout << "0"; colourFunc(12); cout << ")  "; colourFunc(7); cout << "Exit" << endl << endl;
			colourFunc(3); cout << "Enter the number of the operation you want to perform: ";
			colourFunc(15); cin >> enter;
			if (enter[0] == '1' && enter[1] == '\0')
			{
				EnterAccount(1);
			}
			else if (enter[0] == '0' && enter[1] == '\0')
			{
				exit(1);
			}
			else if (enter[0] == '2' && enter[1] == '\0')
			{
				EnterAccount(2);
			}
			else if (enter[0] == '3' && enter[1] == '\0')
			{
				EnterAccount(3);
			}
			else
			{
				system("cls");
				colourFunc(12); cout << endl << "Your choice is incorrect. Please try again" << endl << endl;
			}
		}
	}

	void EnterAccount(int num)
	{
		system("cls");
		string adminUserName;
		string adminPassword;
		int teacherid;
		if (num==3)
		{
			while (true)
			{
				colourFunc(14); cout << "Username:";
				colourFunc(11); cin >> adminUserName;
				colourFunc(14); cout << "Password:";
				colourFunc(11); cin >> adminPassword;
				if (adminUserName == "Admin" && adminPassword == "Admin")
				{
					system("cls");
					EducationList(e1);
				}
				else
				{
					system("cls");
					colourFunc(12); cout << "Username or Password is incorrect. Please try again!" << endl;
				}
			}
		}
		else if(num==2)
		{
			colourFunc(14); cout << "Name:";
			colourFunc(11); cin >> adminUserName;
			colourFunc(14); cout << "Surname:";
			colourFunc(11); cin >> adminPassword;
			colourFunc(14); cout << "teacher id:";
			colourFunc(11); cin >> teacherid;
			for (int i = 0; i < studentId; i++)
			{
				if (adminUserName.compare(e1.teacher[teacherid]._group->studentList[i]._name) == 0 && adminPassword.compare(e1.teacher[teacherid]._group->studentList[i]._surname) == 0)
				{
					e1.printGroupStudent(teacherid);
					break;
				}
			}
			
		}
		else if (num == 1)
		{
			colourFunc(14); cout << "Name:";
			colourFunc(11); cin >> adminUserName;
			colourFunc(14); cout << "Surname:";
			colourFunc(11); cin >> adminPassword;
			for (int i = 0; i < countTeacher; i++)
			{
				if (adminUserName.compare(e1.teacher[i]._name) == 0 && adminPassword.compare(e1.teacher[i]._surname) == 0)
				{
					e1.printGroupStudent(teacherid);
					break;
				}
			}
		}
	}

	void EducationList(EducationStaff e1)
	{
		while (true)
		{
			colourFunc(14); cout << "1"; colourFunc(12); cout << ")  "; colourFunc(7); cout << "Add Teacher" << endl;
			colourFunc(14); cout << "2"; colourFunc(12); cout << ")  "; colourFunc(7); cout << "Add Group" << endl;
			colourFunc(14); cout << "3"; colourFunc(12); cout << ")  "; colourFunc(7); cout << "Edit Group" << endl;
			colourFunc(14); cout << "4"; colourFunc(12); cout << ")  "; colourFunc(7); cout << "Delete Group" << endl;
			colourFunc(14); cout << "5"; colourFunc(12); cout << ")  "; colourFunc(7); cout << "Print Teacher List" << endl;
			colourFunc(14); cout << "6"; colourFunc(12); cout << ")  "; colourFunc(7); cout << "Add student" << endl;
			colourFunc(14); cout << "0"; colourFunc(12); cout << ")  "; colourFunc(7); cout << "Exit" << endl << endl;
			colourFunc(3); cout << "Enter the number of the operation you want to perform: ";
			colourFunc(15); cin >> enter;
			if (enter[0] == '1' && enter[1] == '\0')
			{
				system("cls");
				Person* p1 = new Person();
				cout << "Enter teacher name:";
				cin >> p1->_name;
				cout << "Enter teacher surname:";
				cin >> p1->_surname;
				cout << "Enter teacher age:";
				cin >> p1->_age;
				cout << "Enter teacher field:";
				cin >> p1->_field;
				e1.addTeacher(p1->_name, p1->_surname, p1->_field, p1->_age);
				delete p1;
				EducationList(e1);
			}
			else if (enter[0] == '0' && enter[1] == '\0')
			{
				firstPage();
			}
			else if (enter[0] == '2' && enter[1] == '\0')
			{
				system("cls");
				cout << "Enter group name:";
				string name;
				cin >> name;
				e1.addGroup(name);
				EducationList(e1);
			}
			else if (enter[0] == '3' && enter[1] == '\0')
			{
				system("cls");
				cout << "Enter group's new name:";
				string name;
				int teacherid;
				cin >> name;
				cout << "Enter Teacher's id:";
				cin >> teacherid;
				e1.editGroup(name,teacherid);
				EducationList(e1);
			}
			else if (enter[0] == '4' && enter[1] == '\0')
			{
				system("cls");
				int teacherid;
				cout << "Enter Teacher's id:";
				cin >> teacherid;
				e1.deleteGroup(teacherid);
				EducationList(e1);
			}
			else if (enter[0] == '5' && enter[1] == '\0')
			{
				system("cls");
				if (countTeacher!=0)
				{
					e1.printTeacherList();
				}
				else
				{
					cout << "List is empty";
					Sleep(3000);
					EducationList(e1);
				}

			}
			else if (enter[0] == '6' && enter[1] == '\0')
			{
				system("cls");
				int teacherid;
				cout << "Enter Teacher's id:";
				cin >> teacherid;
				Person* p1 = new Person();
				cout << "Enter Student's name:";
				cin >> p1->_name;
				cout << "Enter Student's surname:";
				cin >> p1->_surname;
				cout << "Enter Student's age:";
				cin >> p1->_age;
				cout << "Enter Student's field:";
				cin >> p1->_field;
				if (countTeacher != 0)
				{
					e1.teacher[teacherid]._group->addStudent(p1->_name, p1->_surname, p1->_field, p1->_age);
				}
				else
				{
					cout << "Teacher or Group  does not  exits";
					Sleep(3000);
					EducationList(e1);
				}

			}
			else
			{
				system("cls");
				colourFunc(12); cout << endl << "Your choice is incorrect. Please try again" << endl << endl;
			}
		}
	}
};

int main()
{
	Main obj;
	obj.firstPage();
}
