#include <iostream>
#include <list>
#include <vector>
#include <assert.h>

// 1. Push_front를 만들어보세요.
// 2. leak 잡으세요


using DataType = int;


class HList
{
private:
	class ListNode
	{
	public:
		DataType Value;
		ListNode* Prev = nullptr;
		ListNode* Next = nullptr;
	};


public:
	class iterator
	{
		friend HList;

	private:
		ListNode* CurNode = nullptr;

	public:
		iterator()
		{

		}

		iterator(ListNode* _Node)
			: CurNode(_Node)
		{

		}

		bool operator !=(const iterator& _Other)
		{
			return CurNode != _Other.CurNode;
		}

		iterator& operator ++()
		{
			CurNode = CurNode->Next;
			return *this;
		}

		DataType& operator*()
		{
			return CurNode->Value;
		}
	};

	HList()
	{
		StartNode = new ListNode();
		EndNode = new ListNode();

		StartNode->Next = EndNode;
		EndNode->Prev = StartNode;
	}

	~HList()
	{
		clear();
		delete StartNode;
		delete EndNode;
	}

	void clear()
	{
		iterator StartIter = begin();
		iterator EndIter = end();

		for (; StartIter != EndIter;)
		{
			StartIter = erase(StartIter);
		}
	}

	void push_back(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode();
		NewNode->Value = _Data;

		ListNode* PrevNode = EndNode->Prev;

		PrevNode->Next = NewNode;
		EndNode->Prev = NewNode;

		NewNode->Next = EndNode;
		NewNode->Prev = PrevNode;
	}


	void push_front(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode();
		NewNode->Value = _Data;

		ListNode* NextNode = StartNode->Next;

		StartNode->Next = NewNode;
		NextNode->Prev = NewNode;

		NewNode->Next = NextNode;
		NewNode->Prev = StartNode;
	}

	iterator erase(const iterator& _Iter)
	{
		ListNode* Node = _Iter.CurNode;

		if (StartNode == Node
			|| EndNode == Node)
		{
			assert(false);
			return iterator(EndNode);
		}

		ListNode* NextNode = Node->Next;
		ListNode* PrevNode = Node->Prev;

		PrevNode->Next = NextNode;
		NextNode->Prev = PrevNode;

		if (nullptr != Node)
		{
			delete Node;
		}

		return iterator(NextNode);
	}

	iterator begin()
	{
		return iterator(StartNode->Next);
	}

	iterator end()
	{
		return iterator(EndNode);
	}

private:
	ListNode* StartNode;
	ListNode* EndNode;
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	{
		HList NewList;

		for (int i = 0; i < 10; i++)
		{
			NewList.push_back(i);
		}

		HList::iterator EraseIter = NewList.begin();

		++EraseIter;
		++EraseIter;
		++EraseIter;
		++EraseIter;
		++EraseIter;

		EraseIter = NewList.erase(EraseIter);

		NewList.push_front(9);
		NewList.push_front(-1);

		HList::iterator StartIter = NewList.begin();
		HList::iterator EndIter = NewList.end();

		for (; StartIter != EndIter; ++StartIter)
		{
			std::cout << (*StartIter) << std::endl;
		}
	}

}
