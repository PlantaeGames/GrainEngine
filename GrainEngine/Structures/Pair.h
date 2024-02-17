#pragma once

template<typename t_T1, typename t_T2>
struct Pair
{
	Pair(t_T1 x, t_T2 y)
	{
		this->x = x;
		this->y = y;
	}

	~Pair() {}

	t_T1 x;
	t_T2 y;
};