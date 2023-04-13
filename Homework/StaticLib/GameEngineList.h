#pragma once

template<typename DataType>
class GameEngineList
{
private:
	class ListNode
	{
	public:
		ListNode* Prev;
		ListNode* Next;
		DataType Value;

		ListNode()
			: Prev(nullptr)
			, Next(nullptr)
			, Value(0)
		{
		}
		~ListNode()
		{
		}
	};

public:
	class iterator
	{
	public:
		bool operator!=(const iterator& _Other)
		{
			return CurNode != _Other.CurNode;
		}

		iterator& operator++()
		{
			CurNode = CurNode->Next;

			return *this;
		}

		DataType& operator*()
		{
			return CurNode->Value;
		}

		iterator()
			: CurNode(nullptr)
		{
		}
		iterator(ListNode* _CurNode)
			: CurNode(_CurNode)
		{
		}
		~iterator()
		{
		}
	private:
		friend GameEngineList;

		ListNode* CurNode;
	};

	ListNode* begin()
	{
		return StartNode->Next;
	}
	ListNode* end()
	{
		return EndNode;
	}

	ListNode* erase(iterator& _DeleteNode)
	{
		ListNode* DeleteNode = _DeleteNode.CurNode;
		++_DeleteNode;

		ListNode* PrevNode = DeleteNode->Prev;
		ListNode* NextNode = DeleteNode->Next;

		PrevNode->Next = NextNode;
		NextNode->Prev = PrevNode;

		if (nullptr != DeleteNode)
		{
			delete DeleteNode;
		}

		return NextNode;
	}

	void push_back(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode;
		ListNode* PrevNode = EndNode->Prev;

		PrevNode->Next = NewNode;
		NewNode->Prev = PrevNode;

		NewNode->Next = EndNode;
		EndNode->Prev = NewNode;

		NewNode->Value = _Data;
	}

	void push_front(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode;
		ListNode* NextNode = StartNode->Next;

		StartNode->Next = NewNode;
		NewNode->Prev = StartNode;

		NewNode->Next = NextNode;
		NextNode->Prev = NewNode;

		NewNode->Value = _Data;
	}

	GameEngineList()
		: StartNode(new ListNode)
		, EndNode(new ListNode)
	{
		StartNode->Next = EndNode;
		EndNode->Prev = StartNode;
	}
	~GameEngineList()
	{
		while (nullptr != StartNode)
		{
			ListNode* NextNode = StartNode->Next;

			delete StartNode;

			StartNode = NextNode;
		}

		StartNode = nullptr;
		EndNode = nullptr;
	}
private:
	ListNode* StartNode;
	ListNode* EndNode;
};
