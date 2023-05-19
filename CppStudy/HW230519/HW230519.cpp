#include <iostream>

int ChCount(const char* const _string, char Ch)
{
	if (nullptr == _string)
	{
		return -1;
	}

	int Cnt = 0;
	for (int i = 0; _string[i] != 0; i++)
	{
		if (_string[i] == Ch)
		{
			++Cnt;
		}
	}

	return Cnt;
}


void TrimDelete(char* _string)
{
	if (nullptr == _string)
	{
		return;
	}

	char TmpString[256] = {};

	int iTmp = 0;
	for (int i = 0; _string[i] != 0; i++)
	{
		if (_string[i] != ' ')
		{
			TmpString[iTmp++] = _string[i];
		}
	}
	TmpString[iTmp] = 0;


	iTmp = 0;
	while (TmpString[iTmp] != 0)
	{
		_string[iTmp] = TmpString[iTmp];
		++iTmp;
	}
	_string[iTmp] = 0;

	return;
}


int DigitsCount(int _Number)
{
	if (_Number < 0)
	{
		_Number = -_Number;
	}

	int Cnt = 0;
	do
	{
		++Cnt;
		_Number /= 10;
	} while (_Number > 0);

	return Cnt;
}


void StrCopy(const char* const _Left, char* _Right)
{
	if (nullptr == _Left || nullptr == _Right)
	{
		return;
	}

	int i = 0;
	while (_Left[i] != 0)
	{
		_Right[i] = _Left[i];
		++i;
	}
	_Right[i] = 0;
}


void NumberToString(int _Number, char* _Right)
{
	if (nullptr == _Right)
	{
		return;
	}

	int Cnt = DigitsCount(_Number);
	bool CheckMinus = false;
	if (_Number < 0)
	{
		_Number = -_Number;
		++Cnt;
		CheckMinus = true;
	}

	_Right[Cnt] = 0;

	for (int i = Cnt - 1; i >= 0; i--)
	{
		if (i == 0 && CheckMinus == true)
		{
			_Right[0] = '-';
		}
		else
		{
			_Right[i] = '0' + _Number % 10;
			_Number /= 10;
		}
	}
	return;
}


int main()
{

	{
		int Result = ChCount("ab aaa ccc ddd eee", 'b');

		int a = 0;
	}

	{
		char Arr[256] = " aa  b  c dd ee ";

		TrimDelete(Arr);

		int a = 0;
	}

	{
		int Result = DigitsCount(1230);

		int a = 0;
	}

	{
		char ArrCopyText[256] = {};

		StrCopy("aaa bbb ccc", ArrCopyText);

		int a = 0;
	}

	{
		char Result[256] = {};

		NumberToString(-12345, Result);

		int a = 0;
	}
}
