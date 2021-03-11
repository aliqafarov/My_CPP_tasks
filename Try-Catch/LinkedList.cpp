class Node
{
public:
	Node* next{};
	int _data;
	Node(int num)
	{
		next = NULL;
		_data = num;
	}
};

class LinkedList
{
	Node* head{};
	int _count{};

public:
	void popback()
	{
		if (head==NULL)
		{
			try
			{
				throw exception("list is empty");
			}
			catch (const std::exception& a)
			{
				cerr << a.what();
			}
		}
		else if (head->next==NULL)
		{
			delete head;
			head = NULL;
			_count--;
		}
		else
		{
			Node* prev = head;
			Node* current = head->next;
			while (current->next!=NULL)
			{
				prev = current;
				current = current->next;
			}
			prev->next=NULL;
			delete current;
			_count--;
		}
		
	}

	void popfront()
	{
		Node* temp = head;
		if (temp == NULL)
		{
			try
			{
				throw exception("list is empty");
			}
			catch (const std::exception& a)
			{
				cerr << a.what();
			}
		}
		else if (head->next == NULL)
		{
			delete head;
			head = NULL;
			_count--;
		}
		else
		{
			head = temp->next;
			_count--;
		}
	}

	int size()
	{
		return _count;
	}

	void pushback(int num)
	{
		Node* temp= new Node(num);
		if (head ==NULL)
		{
			temp->next = NULL;
			head = temp;
			_count++;
		}

		else
		{
			Node* newTemp = head;
			while (newTemp->next!=NULL)
			{
				newTemp = newTemp->next;
			}
			newTemp->next = temp;
			temp->next = NULL;
			_count++;
		}
	}

	void pushfront(int num)
	{
		Node* temp = new Node(num);
		if (head=NULL)
		{
			temp->next = NULL;
			head = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
		_count++;
	}
};