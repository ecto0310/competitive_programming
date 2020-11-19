#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

class Parabola
{
public:
	i64 calc(vector<int> Y, i64 A, i64 B, i64 C)
	{
		i64 ret = 0;
		i64 size = Y.size();
		for (i64 i = 0; i < size; i++)
			ret += abs(A * i * i + B * i + C - Y[i]);
		return ret;
	}

	vector<int> estimate(vector<int> Y)
	{
		vector<int> ret(3);
		i64 minBad = 1e18;
		for (i64 A = 1; A <= 50; A++)
			for (i64 B = -50; B <= 50; B++)
			{
				i64 left = -1e9, right = 1e9;
				i64 cnt = 100;
				while (cnt--)
				{
					i64 c1 = (left * 2 + right) / 3;
					i64 c2 = (left + right * 2) / 3;
					if (calc(Y, A, B, c2) < calc(Y, A, B, c1))
						left = c1;
					else
						right = c2;
				}
				i64 leftClac = calc(Y, A, B, left), rightCalc = calc(Y, A, B, right);
				for (i64 i = left - 5; i <= right + 5; i++)
				{
					i64 tmpCalc = calc(Y, A, B, i);
					if (tmpCalc < minBad)
					{
						minBad = tmpCalc;
						ret = {(int)A, (int)B, (int)i};
					}
				}
			}
		return ret;
	}
};

// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
