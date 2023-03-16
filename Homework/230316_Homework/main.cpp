#include <iostream>

void VariableArgumentFunction(int _reps, ...)
{
	int reps = _reps;
	int* ptr = &_reps;
	int Value = 0;
	int i = 1;

	while (reps--)
	{
		Value = ptr[i * 2];
		++i;
	}
}

int main()
{
	VariableArgumentFunction(3, 10, 20, 30);
	VariableArgumentFunction(2, -20, 74);

	return 0;
}