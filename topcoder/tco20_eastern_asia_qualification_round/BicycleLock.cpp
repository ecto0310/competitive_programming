#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

class BicycleLock
{
public:
	string makeDistinct(vector<int> dials)
	{
		string ret;
		i64 N = dials.size();
		for (i64 i = 0; i < N; i++)
		{
			if (i < dials[i])
				ret += string(abs(i - dials[i]), '-');
			else
				ret += string(abs(i - dials[i]), '+');
			if (i + 1 != N)
				ret += ">";
		}
		return ret;
	}
};

// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
