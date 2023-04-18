#pragma once

#include <StaticLibrary/Object.h>

class Item : public Object
{
public:
	void Update() override;

	Item();
	~Item() {}

	Item(const Item& _ref) = delete;
	Item(Item&& _ref) noexcept = delete;
	Item& operator=(const Item& _ref) = delete;
	Item& operator=(Item&& _ref) noexcept = delete;
private:

};
