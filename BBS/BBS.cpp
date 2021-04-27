
#include <iostream>
#include "bbs.h"
#include<array>
using namespace std;

//default constructor
BBS::BBS()
{
	//default insecure params
	this->p = 11;
	this->q = 19;
	//seed
	this->x0 = 4;
	//product of P & Q
	this->n = p * q;
}
void BBS::setParams(long p, long q, long seed)
{
	//choose p and q such that gcd(p, q) = 1
	this->p = p;
	this->q = q;
	//random seed should be netween 1 & n-1
	this->x0 = seed;
	//blum integer
	this->n = p * q;
}
BBS::BBS(long p, long q, long seed)
{
	this->setParams(p, q, seed);
}
long BBS::getRandNum()
{
	long nextRandNum = (this->x0 * this->x0) % this->n;
	this->x0 = nextRandNum;
	return nextRandNum;
}
long BBS::getRandBit()
{
	return this->getRandNum() % 2;
}
void BBS::setP(long p)
{
	this->p = p;
}

void BBS::setQ(long q)
{
	this->q = q;
}

void BBS::setSeed(long seed)
{
	this->x0 = seed;
}

BBS::~BBS() {}
int main()
{
    std::cout << "Hello World!\n"; 
	const long P = 9133;
	const long Q = 7333;
	const long seed = 1276837;
	int x;
	char contain[20000];
	BBS bbs(P, Q, seed);


	for (int i = 0; i < 20000; i++)
	{
		x = bbs.getRandBit();
		cout << x << " ";
		contain[i] = x;
	}
	x = 0;
	//test pojedyńczych bitów
	cout << "liczba bitow o wartości 1: ";
	for (int i = 0; i < 20000; i++) {
		if (contain[i] == 1) {
			x++;
		}
	}
	cout << x << endl;
	//test liczby serii
	int old=contain[0];
	int now;
	int test=0;
	array<int, 7> v{0,0,0,0,0,0,0};
	x = 1;
	for (int i = 1; i < 20000; i++) {
		//now = contain[i];
		if (now != old) {
			old = now;
			if (x > 6) {
				if (x > 25) {
					test = 1;
				}
				x = 6;
			}
			v[x] = v[x]+1;
			x = 1;
		}
		else {
			x++;
		}
	}
	for (int i = 1; i < v.size();i++) {
		cout << "liczba ciagow o dlugosci " << i << ": " << v[i] << endl;
	}
	//test długiej serii
	if (test == 1) {
		cout << "ZNALEZIONO dluga serie" << endl;
	}
	else {
		cout << "NIE znaleziono dlugiej serii" << endl;
	}
	//test pokerowy
	char poker[4];
	int temp=0;
	array<int, 16> num{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 20000; i+=4) {
		x = 0;
		temp = 0;
		poker[0] = contain[i];
		poker[1] = contain[i+1];
		poker[2] = contain[i+2];
		poker[3] = contain[i+3];
		for (int j = 3; j > -1; j--) {
			temp = temp + (poker[j] * pow(2, x));
			x++;
		}
		num[temp] = num[temp] + 1;
	}
	long casino=0;
	for (int i = 0; i < num.size(); i++) {
		cout << "liczba " << i << " wystapila: " << num[i] << endl;
		casino = casino + (pow(num[i], 2));
	}
	
	casino = ((casino/ 5000)*16)-5000;
	cout << "Wynik testu pokerowego: " << casino;
	if (2.16 < casino < 46.17) {
		cout << " jest pozytywny";
	}
	else {
		cout << " jest negatywny";
	}
	return 0;
}

