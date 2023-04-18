#pragma once

#include <StaticLibrary/Object.h>

class Parts : public Object
{
public:
	Parts();
	~Parts() {}

	Parts(const Parts& _ref) = delete;
	Parts(Parts&& _ref) noexcept = delete;
	Parts& operator=(const Parts& _ref) = delete;
	Parts& operator=(Parts&& _ref) noexcept = delete;
private:

};
