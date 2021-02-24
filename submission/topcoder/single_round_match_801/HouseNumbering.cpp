#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

class HouseNumbering
{
public:
	vector<int> prepareDigits(int firstHouse, int numberOfHouses)
	{
		vector<int> ret(10);
		for (i64 i = 0; i < numberOfHouses; i++)
		{
			int tmp = firstHouse + 2 * i;
			while (tmp)
			{
				ret[tmp % 10]++;
				tmp /= 10;
			}
		}
		return ret;
	}
};

// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
