#pragma once

typedef int DataType;

class GameEngineArray
{
public:
	GameEngineArray(const GameEngineArray& _Other) = delete;
	GameEngineArray(GameEngineArray&& _Other) noexcept = delete;
	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;

	GameEngineArray(int _Value)
		: ArrPtr(new DataType[_Value])
		, ArrCount(_Value)
	{
	}

	~GameEngineArray()
	{
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

	GameEngineArray& operator=(const GameEngineArray& _Other)
	{
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
		}

		ArrPtr = new DataType[_Other.ArrCount];
		ArrCount = _Other.ArrCount;

		for (int i = 0; i < ArrCount; i++)
		{
			ArrPtr[i] = _Other.ArrPtr[i];
		}

		return *this;
	}

	DataType& operator[](int _Index)
	{
		return ArrPtr[_Index];
	}

	int Count() 
	{
		return ArrCount;
	}

	void Resize(int _Value) 
	{
		DataType* TmpPtr = new DataType[_Value];
		int Size = ArrCount > _Value ? _Value : ArrCount;

		for (int i = 0; i < Size; i++)
		{
			TmpPtr[i] = ArrPtr[i];
		}
		ArrCount = _Value;

		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
		}

		ArrPtr = TmpPtr;
		TmpPtr = nullptr;
	}

protected:

private:
	int ArrCount;
	DataType* ArrPtr = nullptr;
};

