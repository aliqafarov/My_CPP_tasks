#include <iostream>
#include <list>
using namespace std;

template <class T>
class Node
{
	T _data{};
	Node* _next{};

	template <class T>
	friend class LinkedList;

public:
	Node(T data) : _data(data), _next(NULL) { }
};


template <class T>

class LinkedList
{
	Node<T>* _head{};
	int _count{};

public:
	LinkedList() : _head(NULL) { }

	void push_back(T data)
	{
		Node<T>* newNode = new Node<T>(data);

		if (_head == NULL)
		{
			newNode->_next = NULL;
			_head = newNode;
		}
		else
		{
			Node<T>* temp = _head;
			while (temp->_next != NULL)
			{
				temp = temp->_next;
			}
			temp->_next = newNode;
			newNode->_next = NULL;
		}
		_count++;
	}

	void emplace_back(T obj)
	{
		T data =  obj;
		Node<T>* newNode = new Node<T>(data);
		if (_head == NULL)
		{
			newNode->_next = NULL;
			_head = newNode;
		}
		else
		{
			Node<T>* temp = _head;
			while (temp->_next != NULL)
			{
				temp = temp->_next;
			}
			temp->_next = newNode;
			newNode->_next = NULL;
		}
		_count++;
	}
	void push_front(T data)
	{
		Node<T>* newNode = new Node<T>(data);
		if (_head == NULL)
		{
			newNode->_next = NULL;
			_head = newNode;
		}
		else
		{
			newNode->_next = _head;
			_head = newNode;
		}
		_count++;
	}

	void emplace_front(T obj)
	{
		T data = obj;
		Node<T>* newNode = new Node<T>(data);
		if (_head == NULL)
		{
			newNode->_next = NULL;
			_head = newNode;
		}
		else
		{
			newNode->_next = _head;
			_head = newNode;
		}
		_count++;
	}

	void insert(int index, T data)
	{
		while (index)
		{
			push_front(data);
			index--;
		}
	}
	void pop_back()
	{
		if (_count == 0) return;
		else if (_count == 1)
		{
			delete _head;
			_head = NULL;
		}
		else
		{
			Node<T>* prev = _head;
			Node<T>* current = _head->_next;

			while (current->_next != NULL)
			{
				prev = current;
				current = current->_next;
			}
			prev->_next = NULL;
			delete current;
			_count--;
		}
	}
	void pop_front()
	{
		if (_count == 0) return;
		else if (_count == 1)
		{
			delete _head;
			_head = NULL;
		}
		else
		{
			Node<T>* newHead = _head->_next;
			delete _head;
			_head = newHead;
		}
		_count--;
	}

	void remove(T number)
	{
		Node<T>* prev = NULL;
		Node<T>* temp = NULL;
		if (_head != NULL)
		{
			prev = _head;
			if (_head->_next != NULL)
				temp = _head->_next;
		}
		if (prev != NULL && prev->_data == number)
		{
			pop_front();
			return;
		}
		while (temp != NULL && temp->_data != number)
		{
			prev = temp;
			temp = temp->_next;
		}
		if (temp != NULL && temp->_data == number)
		{
			prev->_next = temp->_next;
			delete temp;
		}
	}

	void removeAll(T number)
	{
		bool check = false;
		while (check==false)
		{
			Node<T>* prev = NULL;
			Node<T>* temp = NULL;
			if (_head != NULL)
			{
				prev = _head;
				if (_head->_next != NULL)
					temp = _head->_next;
			}
			if (prev != NULL && prev->_data == number)
			{
				pop_front();
				continue;
			}
			while (temp != NULL && temp->_data != number)
			{
				check = true;
				prev = temp;
				temp = temp->_next;
			}
			if (temp != NULL && temp->_data == number)
			{
				check = false;
				prev->_next = temp->_next;
				delete temp;
			}
		}
		
	}

	T begin()
	{
		if (_head!=NULL)
		{
			return _head->_data;
		}
	}

	T end()
	{
		if (_head->_data!=NULL)
		{
			Node<T>* temp = _head;
			while (temp->_next!=NULL)
			{
				temp = temp->_next;
			}
			return temp->_data;
		}
	}
	void clear()
	{
		for (int i = 0; i < _count; i++)
		{
			pop_front();
		}
		_count = 0;
	}
	void printList()
	{
		Node<T>* temp = _head;
		while (temp != NULL)
		{
			cout << temp->_data << endl;
			temp = temp->_next;
		}
	}
	int size() { return _count; }
};

int main()
{
	LinkedList<int> list1;
	list1.push_front(5);
	list1.insert(3, 3);
	list1.insert(3, 23);
	list1.printList();
	cout << list1.size()<<endl;
	cout << list1.end()<<endl;
	cout << list1.begin()<<endl;
	list1.removeAll(23);
	cout << list1.size() << endl;
}
