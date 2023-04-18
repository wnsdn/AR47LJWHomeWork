#include <iostream>

using ll = long long;

class Player
{
private:
	ll a;
	int b;
	short c;
	ll d;
public:
	void PrintAddress()
	{
		std::cout << (ll)&a << '\n';
		std::cout << (ll)&b << '\n';
		std::cout << (ll)&c << '\n';
		std::cout << (ll)&d << '\n';
	}
};

int main()
{
	Player player;

	player.PrintAddress();

	return 0;
}
