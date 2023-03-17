#include <iostream>

int StringCount(const char* _String)
{
	int length = 0;

	while (*_String != '\0')
	{
		++_String;
		++length;
	}

	return length;
}

void TrimDelete(char* _String)
{
	while (true)
	{
		if (*_String == ' ')
		{
			char* ptr = _String;
			while (*ptr == ' ')
			{
				++ptr;
			}
			*_String = *ptr;
			*ptr = ' ';
		}

		if (*_String == '\0')
		{
			break;
		}

		++_String;
	}
}

int StringToInt(const char* _String)
{
	int Value = 0;

	while (true)
	{
		Value += *_String - '0';
		++_String;

		if (*_String == '\0')
		{
			break;
		}
		else
		{
			Value *= 10;
		}
	}

	return Value;
}

int main()
{
	int Return0 = StringCount("aaaa");
	int Return1 = StringCount("aaaa ggg sss");

	char Arr0[1024] = "a b c d e\n";
	char Arr1[1024] = "a    b c    d    e \n";
	char Arr2[1024] = "ab    cde    \n";

	TrimDelete(Arr0);
	printf_s(Arr0);
	TrimDelete(Arr1);
	printf_s(Arr1);
	TrimDelete(Arr2);
	printf_s(Arr2);

	int RValue0 = StringToInt("1111");
	int RValue1 = StringToInt("432");
	int RValue2 = StringToInt("4523312");
	int RValue3 = StringToInt("432231");

	return 0;
}