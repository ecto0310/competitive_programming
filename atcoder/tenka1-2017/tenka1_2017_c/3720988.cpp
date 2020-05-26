// URL: https://atcoder.jp/contests/tenka1-2017/submissions/3720988
// Date: Wed, 05 Dec 2018 16:11:09 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int ni;
	cin >> ni;
	for (int h = 1; h <= 3500; h++)
		for (int n = 1; n <= 3500; n++)
		{
			long long t = (long long)ni * h * n, d = (long long)4 * h * n - ni * h - ni * n;
			if (0 < d && t % d == 0)
			{
				cout << h << " " << n << " " << t / d << endl;
				return 0;
			}
		}
}
