	string  data;
	ifstream fin("encrypted.txt");
	getline(fin,data);
	int size = data.length();
	char* arr = new char[size+1];

	for (int i = 0; i <size; i++)
	{
		if (data[i]=='a'|| data[i] == 'b'||data[i] == 'c' || data[i] == 'A' || data[i] == 'B' || data[i] == 'C')
		{
			arr[i] = data[i] + 23;
		}
		else if (data[i] == ' '|| data[i] == '.')
		{
			arr[i] = data[i];
		}
		else
		{
			arr[i] = data[i] - 3;
		}
		arr[i + 1] = '\0';
	}
	cout << arr << endl;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 'a' || arr[i] == 'b' || arr[i] == 'c' || arr[i] == 'd' || arr[i] == 'A' || arr[i] == 'B' || arr[i] == 'C' || arr[i] == 'D' )
		{
			arr[i] = arr[i] + 22;
		}
		else if (arr[i] == ' ' || arr[i] == '.')
		{
			arr[i] = arr[i];
		}
		else
		{
			arr[i] = arr[i] - 4;
		}
	}
	cout << endl << arr;

	ofstream fout("Decrpting.txt");
	fout << arr;