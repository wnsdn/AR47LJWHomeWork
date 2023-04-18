#include <iostream>
#include <bitset>

class iPoint
{
private:
	int x;
	int y;
public:
	iPoint()
		: x(0)
		, y(0)
	{

	}
	iPoint(int _x, int _y)
		: x(_x)
		, y(_y)
	{

	}

	//Group2
	iPoint operator++(int)
	{
		iPoint temp = iPoint(x, y);
		++x;
		++y;

		return temp;
	}
	iPoint operator--(int)
	{
		iPoint temp = iPoint(x, y);
		--x;
		--y;

		return temp;
	}

	//Group3
	iPoint operator++()
	{
		++x;
		++y;

		return *this;
	}
	iPoint operator--()
	{
		--x;
		--y;

		return *this;
	}
	iPoint operator~()
	{
		std::bitset<32> bitX = x;
		std::bitset<32> bitY = y;
		x = (int)~bitX.to_ulong();
		y = (int)~bitY.to_ulong();

		return *this;
	}
	bool operator!()
	{
		return x || y ? false : true;
	}
	iPoint operator-()
	{
		x = -x;
		y = -y;

		return *this;
	}
	iPoint operator+()
	{
		return *this;
	}

	//Group5
	iPoint operator*(iPoint _pt)
	{
		iPoint temp = iPoint(x * _pt.x, y * _pt.y);

		return temp;
	}
	iPoint operator/(iPoint _pt)
	{
		iPoint temp = iPoint(x / _pt.x, y / _pt.y);

		return temp;
	}
	iPoint operator%(iPoint _pt)
	{
		iPoint temp = iPoint(x % _pt.x, y % _pt.y);

		return temp;
	}

	//Group6
	iPoint operator+(iPoint _pt)
	{
		iPoint temp = iPoint(x + _pt.x, y + _pt.y);

		return temp;
	}
	iPoint operator-(iPoint _pt)
	{
		iPoint temp = iPoint(x - _pt.x, y - _pt.y);

		return temp;
	}

	//Group7
	iPoint operator<<(int _i)
	{
		iPoint temp;
		std::bitset<32> bitX = x;
		std::bitset<32> bitY = y;
		temp.x = (int)(bitX << _i).to_ulong();
		temp.y = (int)(bitY << _i).to_ulong();

		return temp;
	}
	iPoint operator>>(int _i)
	{
		iPoint temp;
		std::bitset<32> bitX = x;
		std::bitset<32> bitY = y;
		temp.x = (int)(bitX >> _i).to_ulong();
		temp.y = (int)(bitY >> _i).to_ulong();

		return temp;
	}

	//Group8
	int operator<(iPoint _pt)
	{
		if (x < _pt.x && y < _pt.y)
		{
			return 1;
		}
		else if ((x < _pt.x && y >= _pt.y)
			|| (x >= _pt.x && y < _pt.y))
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
	int operator>(iPoint _pt)
	{
		if (x > _pt.x && y > _pt.y)
		{
			return 1;
		}
		else if ((x > _pt.x && y <= _pt.y)
			|| (x <= _pt.x && y > _pt.y))
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
	int operator<=(iPoint _pt)
	{
		if (x <= _pt.x && y <= _pt.y)
		{
			return 1;
		}
		else if ((x <= _pt.x && y > _pt.y)
			|| (x > _pt.x && y <= _pt.y))
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
	int operator>=(iPoint _pt)
	{
		if (x >= _pt.x && y >= _pt.y)
		{
			return 1;
		}
		else if ((x >= _pt.x && y < _pt.y)
			|| (x < _pt.x && y >= _pt.y))
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}

	//Group9
	bool operator==(iPoint _pt)
	{
		if (x == _pt.x && y == _pt.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(iPoint _pt)
	{
		if (x == _pt.x && y == _pt.y)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	//Group10
	iPoint operator&(iPoint _pt)
	{
		iPoint temp;

		std::bitset<32> bitX1 = x;
		std::bitset<32> bitY1 = y;
		std::bitset<32> bitX2 = _pt.x;
		std::bitset<32> bitY2 = _pt.y;

		temp.x = (int)(bitX1 & bitX2).to_ulong();
		temp.y = (int)(bitY1 & bitY2).to_ulong();

		return temp;
	}

	//Group11
	iPoint operator^(iPoint _pt)
	{
		iPoint temp;

		std::bitset<32> bitX1 = x;
		std::bitset<32> bitY1 = y;
		std::bitset<32> bitX2 = _pt.x;
		std::bitset<32> bitY2 = _pt.y;

		temp.x = (int)(bitX1 ^ bitX2).to_ulong();
		temp.y = (int)(bitY1 ^ bitY2).to_ulong();

		return temp;
	}

	//Group12
	iPoint operator|(iPoint _pt)
	{
		iPoint temp;

		std::bitset<32> bitX1 = x;
		std::bitset<32> bitY1 = y;
		std::bitset<32> bitX2 = _pt.x;
		std::bitset<32> bitY2 = _pt.y;

		temp.x = (int)(bitX1 | bitX2).to_ulong();
		temp.y = (int)(bitY1 | bitY2).to_ulong();

		return temp;
	}

	//Group13
	bool operator&&(iPoint _pt)
	{
		if ((x || y) && (_pt.x || _pt.y))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//Group14
	bool operator||(iPoint _pt)
	{
		if ((x || y) || (_pt.x || _pt.y))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//Group15
	void operator=(iPoint _pt)
	{
		x = _pt.x;
		y = _pt.y;
	}
	void operator*=(iPoint _pt)
	{
		x *= _pt.x;
		y *= _pt.y;
	}
	void operator/=(iPoint _pt)
	{
		x /= _pt.x;
		y /= _pt.y;
	}
	void operator%=(iPoint _pt)
	{
		x %= _pt.x;
		y %= _pt.y;
	}
	void operator+=(iPoint _pt)
	{
		x += _pt.x;
		y += _pt.y;
	}
	void operator-=(iPoint _pt)
	{
		x -= _pt.x;
		y -= _pt.y;
	}
	void operator=(int _i)
	{
		x = _i;
		y = _i;
	}
	void operator*=(int _i)
	{
		x *= _i;
		y *= _i;
	}
	void operator/=(int _i)
	{
		x /= _i;
		y /= _i;
	}
	void operator%=(int _i)
	{
		x %= _i;
		y %= _i;
	}
	void operator+=(int _i)
	{
		x += _i;
		y += _i;
	}
	void operator-=(int _i)
	{
		x -= _i;
		y -= _i;
	}
	void operator<<=(int _i)
	{
		*this = *this << _i;
	}
	void operator>>=(int _i)
	{
		*this = *this >> _i;
	}
	void operator&=(iPoint _pt)
	{
		*this = *this & _pt;
	}
	void operator^=(iPoint _pt)
	{
		*this = *this ^ _pt;
	}
	void operator|=(iPoint _pt)
	{
		*this = *this | _pt;
	}

	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}

	void Print()
	{
		std::cout << x << ", " << y << "\n";
	}
};

int main()
{
	iPoint Result;
	iPoint A(17, 23);
	iPoint B(3, 5);

	return 0;
}
