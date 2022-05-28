#pragma once
class Der
{
public:
	Der():Der(0){}
	Der(int i)
	{
		if (!i)
			throw "Can't create object Der";
	}
};

