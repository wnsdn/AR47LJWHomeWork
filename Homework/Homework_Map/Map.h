#pragma once

#include <vector>

template <typename Key, typename Value>
class Pair
{
public:
	Key first;
	Value second;

	Pair()
		: first(0)
		, second(0)
	{
	}
	Pair(const Key& _key, const Value& _value)
		: first(_key)
		, second(_value)
	{
	}
};

template <typename Key, typename Value>
class Map
{
public:
	class Node
	{
	public:
		friend Map;
		Node* Parent;
		Node* Left;
		Node* Right;
		Pair<Key, Value> P;

		void FirstOrder()
		{
			if (!this)
			{
				return;
			}

			Left->FirstOrder();
			Right->FirstOrder();
		}
		void MidOrder()
		{
			if (!this)
			{
				return;
			}

			Left->MidOrder();
			Right->MidOrder();
		}
		void LastOrder()
		{
			if (!this)
			{
				return;
			}

			Left->LastOrder();
			Right->LastOrder();
			delete this;
		}

		Node()
			: Parent(nullptr)
			, Left(nullptr)
			, Right(nullptr)
			, P()
		{
		}
	};
	class iterator
	{
	public:
		Node* Addr;

		bool operator!=(const iterator& _iter)
		{
			return Addr != _iter.Addr;
		}
		Pair<Key, Value>* operator->()
		{
			return &Addr->P;
		}
		iterator& operator++()
		{
			if (Addr->Right)
			{
				Addr = Addr->Right;

				while (Addr->Left)
				{
					Addr = Addr->Left;
				}
			}
			else if (Addr->Parent)
			{
				while (Addr == Addr->Parent->Right)
				{
					Addr = Addr->Parent;
				}
				Addr = Addr->Parent;
			}

			return *this;
		}

		iterator()
			: Addr(nullptr)
		{
		}
		iterator(Node* _Addr)
			: Addr(_Addr)
		{
		}
	};

	iterator begin()
	{
		return iterator(BeginNode(Root));
	}
	iterator end()
	{
		return iterator(End);
	}

	iterator find(Key _key)
	{
		Node* CurNode = Root;
		
		while (CurNode)
		{
			Pair<Key, Value>& CurPair = CurNode->P;
			if (CurPair.first == _key)
			{
				return iterator(CurNode);
			}
			else if (CurPair.first > _key)
			{
				if (CurNode->Left)
				{
					CurNode = CurNode->Left;
				}
				else
				{
					break;
				}
			}
			else if (CurPair.first < _key)
			{
				if (CurNode->Right)
				{
					CurNode = CurNode->Right;
				}
				else
				{
					break;
				}
			}
		}

		return nullptr;
	}
	void erase(const iterator& _iter)
	{
		Node* Erase = _iter.Addr;

		if (!Erase)
		{
			return;
		}

		bool IsLeft = false;
		if (Erase->Parent)
		{
			if (Erase->Parent->Left == Erase)
			{
				IsLeft = true;
			}
		}

		std::vector<Node*> NodeArr;
		Node* CurNode = BeginNode(Erase);
		while (true)
		{
			if (CurNode != Erase && CurNode != End)
			{
				NodeArr.push_back(CurNode);
			}

			if (CurNode == EndNode(Erase))
			{
				break;
			}

			CurNode = NextNode(CurNode);
		}

		if (!NodeArr.empty())
		{
			if (Erase->Parent)
			{
				if (IsLeft)
				{
					Erase->Parent->Left = NodeArr[0];
				}
				else
				{
					Erase->Parent->Right = NodeArr[0];
				}
			}
			else
			{
				Root = NodeArr[0];
			}

			NodeArr[0]->Parent = Erase->Parent;

			Node* Temp = NodeArr[0];
			for (int i = 1; i < NodeArr.size(); ++i)
			{
				NodeArr[i]->Parent = Temp;
				Temp->Right = NodeArr[i];
				Temp = NodeArr[i];
			}
		}
		else
		{
			if (Erase->Parent)
			{
				if (IsLeft)
				{
					Erase->Parent->Left = nullptr;
				}
				else
				{
					Erase->Parent->Right = nullptr;
				}
			}
			else
			{
				Root = nullptr;
			}
		}

		delete Erase;
	}
	bool insert(const Pair<Key, Value>& _p)
	{
		if (Root == nullptr)
		{
			Root = new Node;
			Root->P = _p;

			EndNode(Root)->Right = End;
			return true;
		}

		Node* CurNode = Root;
		Node* PreNode = nullptr;
		bool IsLeft = false;
		while (true)
		{
			if (!CurNode || CurNode == End)
			{
				CurNode = new Node;
				CurNode->Parent = PreNode;

				if (IsLeft)
				{
					PreNode->Left = CurNode;
				}
				else
				{
					PreNode->Right = CurNode;
				}

				CurNode->P = _p;

				EndNode(Root)->Right = End;
				return true;
			}
			else
			{
				const Pair<Key, Value>& CurPair = CurNode->P;

				if (CurPair.first > _p.first)
				{
					PreNode = CurNode;
					CurNode = CurNode->Left;
					IsLeft = true;
				}
				else if (CurPair.first < _p.first)
				{
					PreNode = CurNode;
					CurNode = CurNode->Right;
					IsLeft = false;
				}
				else if (CurPair.first == _p.first)
				{
					return false;
				}
			}
		}
	}

	Map()
		: Root(nullptr)
		, End(new Node)
	{
	}
	~Map()
	{
		Root->LastOrder();
	}
private:
	Node* Root;
	Node* End;

	Node* BeginNode(Node* _Root)
	{
		while (_Root->Left)
		{
			_Root = _Root->Left;
		}

		return _Root;
	}
	Node* EndNode(Node* _Root)
	{
		while (_Root->Right && _Root->Right != End)
		{
			_Root = _Root->Right;
		}

		return _Root;
	}

	Node* NextNode(Node* _CurNode)
	{
		if (_CurNode->Right)
		{
			_CurNode = _CurNode->Right;

			while (_CurNode->Left)
			{
				_CurNode = _CurNode->Left;
			}
		}
		else if (_CurNode->Parent)
		{
			while (_CurNode == _CurNode->Parent->Right)
			{
				_CurNode = _CurNode->Parent;
			}
			_CurNode = _CurNode->Parent;
		}

		return _CurNode;
	}
};