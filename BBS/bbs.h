#pragma once

#include <cmath>

#include<iostream>



class BBS

{

private:

	unsigned long p, q, n, x0, decryptionExp;



public:

	BBS();

	~BBS();

	BBS(long p, long q, long seed);



	void setP(long p);

	void setQ(long q);

	void setSeed(long seed);

	long getRandBit();

	long getRandNum();

	void setParams(long p, long q, long seed);

};
