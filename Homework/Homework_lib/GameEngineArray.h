#pragma once

#include "GameEngineDebug.h"

template <typename DataType>
class GameEngineArray
{
public:
	int Size() const
	{
		return m_Size;
	}

	void Resize(int _size)
	{
		if (0 == _size)
		{
			MessageBoxAssert("0 크기의 배열은 만들 수 없습니다.");
		}

		DataType* NewData = new DataType[_size];

		if (nullptr != m_Data)
		{
			int Size = m_Size > _size ? _size : m_Size;
			for (int i = 0; i < Size; ++i)
			{
				NewData[i] = m_Data[i];
			}

			delete[] m_Data;
		}

		m_Data = NewData;
		NewData = nullptr;
		m_Size = _size;
	}

	DataType& operator[](const int _index) const
	{
		return m_Data[_index];
	}

	GameEngineArray& operator=(const GameEngineArray& _ref)
	{
		int Size = _ref.Size();

		Resize(Size);

		for (int i = 0; i < Size; ++i)
		{
			m_Data[i] = _ref[i];
		}

		return *this;
	}

	GameEngineArray()
		: m_Data(nullptr)
		, m_Size(0)
	{

	}
	GameEngineArray(const int _size)
		: m_Data(nullptr)
		, m_Size(_size)
	{
		Resize(_size);
	}
	~GameEngineArray()
	{
		if (nullptr != m_Data)
		{
			delete[] m_Data;
			m_Data = nullptr;
		}
	}
private:
	DataType* m_Data;
	int m_Size;
};

