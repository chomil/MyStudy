#include "Global.h"

int StringCount(const char* _Arr)
{
	int ChCount = 0;
	while (_Arr[ChCount])
	{
		++ChCount;
	}

	return ChCount;
}
