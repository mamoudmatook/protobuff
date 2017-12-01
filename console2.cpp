// console2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

template <class T>
vector<unsigned char> nToB(T a);
vector <unsigned int> encodel(vector<unsigned char>);
template<class T>
vector<unsigned char> nToB2(T a);


unsigned long ByteToint(vector<unsigned char> v)
{
	unsigned long int a = 0;
	int s = v.size();
	for (int i = 0; i<s; i++)
	{
		a |= (v[s - 1 - i] << (8 * (s - i - 1)));

	}
	return a;
}
unsigned long int  decode(unsigned long long  int);




int main()
{
	
	cout << decode(24826331072);
	getchar();
	return 0;
}
template<class T>
vector<unsigned char> nToB2(T a)
{
	size_t l = sizeof(T);
	vector<unsigned char>v(l);
	for (int i = 0; i < l; i++)
	{
		v[i] = (a >> (i * 8));
	}
	return v;
}
template<class T>
vector<unsigned char>  nToB(T a)
{
	size_t l = sizeof(T);
	vector<unsigned char>v;
	v.push_back(0x08);

	for (int i = 0; i < l; i++)
	{
		v.push_back((a >> (i * 8)));
	}
	
	return v;
}
vector <unsigned int> encodel(vector<unsigned char> v1)
{
	vector<unsigned int > v2;
	for (int i = 0; i < v1.size(); )
	{
		if (i + 2 <= v1.size())
		{
			int tmp = v1[i++];

			if (tmp % 8 == 0)
				while (true)
				{
					if (i + 1 > v1.size()) break;
					tmp = v1[i++];
					if (tmp < 128)
					{
						v2.push_back((unsigned int)tmp);
						break;
					}
					else
					{
						int result = tmp & 0x7f;
						if ((tmp = v1[i++]) < 128)
						{
							result |= tmp << 7;
							v2.push_back((unsigned int)result);
							break;
						}
						else
						{
							result |= (tmp & 0x7f) << 7;
							if ((tmp = v1[i++]) < 128)
							{
								result |= tmp << 14;
								v2.push_back((unsigned int)result);
								break;
							}
							else
							{
								result |= (tmp & 0x7f) << 14;
								if ((tmp = v1[i++]) < 128)
								{
									result |= tmp << 21;
									v2.push_back((unsigned int)result);
									break;
								}
								else
								{
									result |= (tmp & 0x7f) << 21;
									result |= (tmp = v1[i++]) << 28;
									v2.push_back((unsigned int)result);
									break;
								}
							}
						}
					}
				}
		}
		else break;
	}
	return v2;

}
unsigned long int decode(unsigned long long int a)
{
	vector<unsigned int> v = encodel(nToB(a));
	vector<unsigned char> v3, v4;
	for (int i = 0; i < v.size(); i++)
	{

		v3 = nToB2(v[i]);
		for (int l = 0; l < v3.size(); l++)
			v4.push_back(v3[l]);
	}
	return ByteToint(v4);
}