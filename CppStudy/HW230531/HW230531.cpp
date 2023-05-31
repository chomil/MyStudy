#include <iostream>
#include <vector>


// 숙제 => HVector의 leak을 없애기
//         대입연산자를 사용하면 터지는걸 정상으로 돌리기
//		   템플릿으로 바꾸기


template <typename T>
class HVector
{
public:
	T& operator[](size_t _Index)
	{
		return ArrPtr[_Index];
	}

	HVector& operator=(const HVector& _Other)
	{
		delete[] ArrPtr;
		ArrPtr = nullptr;

		reserve(_Other.capacityValue);
		sizeValue = _Other.sizeValue;
		for (size_t i = 0; i < _Other.sizeValue; i++)
		{
			ArrPtr[i] = _Other.ArrPtr[i];
		}

		return *this;
	}

	size_t size()
	{
		return sizeValue;
	}
	size_t capacity()
	{
		return capacityValue;
	}

	void push_back(const T& _Data)
	{
		if (sizeValue + 1 > capacityValue)
		{
			reserve((int)((capacityValue * 1.5) + 1));
		}

		ArrPtr[sizeValue] = _Data;
		sizeValue += 1;
	}

	void reserve(size_t _capacity)
	{
		T* PrevPtr = ArrPtr;

		ArrPtr = new T[_capacity];

		if (nullptr != PrevPtr)
		{
			for (size_t i = 0; i < sizeValue; i++)
			{
				ArrPtr[i] = PrevPtr[i];
			}

			delete[] PrevPtr;
		}

		capacityValue = (int)_capacity;
	}

	~HVector()
	{
		if (nullptr != ArrPtr)
		{
			delete ArrPtr;
			ArrPtr = nullptr;
		}
	}

private:
	int sizeValue = 0;
	int capacityValue = 0;
	T* ArrPtr = nullptr;
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	{
		HVector<int> Arr;

		for (int i = 0; i < 10; i++)
		{
			Arr.push_back(i);
		}

		for (size_t i = 0; i < Arr.size(); i++)
		{
			std::cout << Arr[i] << std::endl;
		}


		HVector<int> Arr0;

		Arr0 = Arr;

		for (size_t i = 0; i < Arr0.size(); i++)
		{
			std::cout << Arr0[i] << std::endl;
		}
	}



}
