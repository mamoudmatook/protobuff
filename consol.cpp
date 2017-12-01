// consol.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define _SECURE_SCL_DEPRECATE 0
#include <iostream>

#include <list>
#include<vector>
#include<algorithm>
using namespace std;
template<class T>
vector<unsigned char>  nToB(T );
unsigned long ByteToint(vector<unsigned char> v)
{
	unsigned long int a = 0;
	int s = v.size();
	for (int i = 0; i<s ; i++)
	{
		a |= (v[s - 1 - i] << (8 * (s - i - 1)));

	}
	return a;
}
static unsigned  long  int  Encode7Bits(unsigned long int);



int main()
{
	
	cout << Encode7Bits(1352772081);
	
	
	getchar();

	return 0;
}



static unsigned  long  int  Encode7Bits( unsigned long int x)
{
	
	vector<unsigned char> Result;

	do
	{
		unsigned long  int tmp = x & 0x7f;
		x = x >> 7;
		if (x > 0)
			tmp |= 0x80;        
		Result.push_back((unsigned char )tmp);
	} while (x > 0);
	
		 
	
	return ByteToint(Result);
}

