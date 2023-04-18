#include <iostream>
#include "GameEngineArray.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	{
		//숙제 1, 2 : Resize함수 구현
		GameEngineArray Array0(10);

		for (int i = 0; i < Array0.Count(); ++i)
		{
			Array0[i] = i;
		}

		Array0.Resize(15);

		for (int i = 0; i < Array0.Count(); ++i)
		{
			printf_s("%d\n", Array0[i]);
		}
	}

	putchar('\n');

	{
		// 숙제 3 : 왜 터지는지 이해하고 고쳐라.
		GameEngineArray Array0(10);
		GameEngineArray Array1(5);

		Array1 = Array0;
	}

	{
	    GameEngineArray Array0(10);
	    GameEngineArray Array1(5);

	    for (int i = 0; i < Array0.Count(); i++)
	    {
	        Array0[i] = i;
	    }

	    // 숙제4 완전히 동일한 배열이 되게 만들어주세요.
	    // Array1 10개 짜리 배열이 되고 0 1 2 3 4 5 6 7 8 9
	    Array1 = Array0;

	    for (int i = 0; i < Array1.Count(); i++)
	    {
	        printf_s("%d\n", Array1[i]);
	    }
	}
}
