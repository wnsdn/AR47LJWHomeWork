//2023.03.16 목 - 가변인자 접근 숙제

#include <iostream>
using namespace std;

void VariableArgumentFunction(int _reps, ...)
{
	int reps = _reps;
	int* ptr = &_reps;
	int Value = 0;

	int i = 1;
	while (reps--)
	{
		Value = ptr[2 * i];
		++i;
	}
}

int main()
{
	VariableArgumentFunction(3, 1, 2, 3);

	VariableArgumentFunction(7, 10, 20, 30, 40, 50, 60, 70);

	return 0;
}
