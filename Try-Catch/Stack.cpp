class Stack
{
	int _arr[100]{};
	int _count{};

public:
	void push(int num)
	{
		if (_count == 100)
		{
			try
			{
				throw exception(" Stack is full");
			}
			catch (const exception& arr)
			{
				 cerr << arr.what() << endl;
			}
		}
		else
		{
			_arr[_count] = num;
			_count++;
		}

	}
	
	void pop()
	{
			try
			{
				if (_count==0) throw exception(" There is not element in stack");
				else
				{
					_arr[_count - 1] = NULL;
					_count--;
				}
			}
			catch (const exception & arr)
			{
				 cerr << arr.what()<< endl;
			}
	}
};


int main()
{
	Stack s1;
	s1.push(7);
	s1.pop();
	s1.pop();
	
}
