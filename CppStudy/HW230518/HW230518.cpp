#include <iostream>

int StringCount(char* _Arr)
{
	if (nullptr == _Arr)
	{
		return -1;
	}

	int cnt = 0;
	while (_Arr[cnt] != 0)
	{
		++cnt;
	}
	return cnt;
}


void ChangeCh(char* _Arr, char _PrevCh, char _NextCh)
{
	for (int i = 0; _Arr[i] != 0; i++)
	{
		if (_Arr[i] == _PrevCh)
		{
			_Arr[i] = _NextCh;
		}
	}
	return;
}

int main()
{
	//한글x

	{
		char Arr[100] = "12345";
		int Result = StringCount(Arr);

		int a = 0;
	}

	{
		char Arr[100] = "aaa bbb ccc";
		ChangeCh(Arr, 'c', 'd');

		int a = 0;
	}

}
