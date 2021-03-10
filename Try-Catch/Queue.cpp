class Queue
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
				throw exception(" Queue is full");
			}
			catch (const exception& arr)
			{
				 cerr << arr.what() << endl;
			}
		}
		else
		{
			if (_count==0)
			{
				_arr[0] = num;
				_count++;
			}
			else
			{
				for (int i = _count - 1; i != -1; i++)
				{
					_arr[i + 1] = _arr[i];
				}
				_arr[0] = num;
				_count++;
			}
		}

	}
	
	void pop()
	{
		try
		{
			if (_count == 0) throw("Queue is empty");
			else
			{
				_arr[_count - 1] = 0;
				_count--;
			}
		}
		catch (const char* arr)
		{
			cerr << arr << endl;;
		}
	}
};


int main()
{
	Queue q1;
	q1.pop();
}
