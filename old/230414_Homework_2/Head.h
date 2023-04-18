#pragma once

#include <StaticLib/Object.h>

class Head : public Object
{
public:
	static bool IsGameUpdate;

	static bool Win;
	static int GameWinCount;

	void Update() override;
	void Delete() override;

	struct Parts
	{
		Parts* prev;
		Parts* next;
		Point pt;
		Point PrevPt;

		Parts()
			: prev(nullptr)
			, next(nullptr)
			, pt()
			, PrevPt()
		{}
		~Parts() {}
	};

	bool IsItem(const Point& _pt) const;

	Head();
	~Head();

	Head(const Head& _ref) = delete;
	Head(Head&& _ref) noexcept = delete;
	Head& operator=(const Head& _ref) = delete;
	Head& operator=(Head&& _ref) noexcept = delete;
private:
	Parts* m_Head;
	Parts* m_Tail;
};