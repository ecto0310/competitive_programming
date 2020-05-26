// URL: https://atcoder.jp/contests/tenka1-2018-beginner/submissions/3479065
// Date: Sat, 27 Oct 2018 21:04:53 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, k;
	cin >> a >> b >> k;
	for (int i = 0; i < k; i++)
	{
		if (i % 2 == 0)
		{
			if (a % 2 == 1)
				a--;
			b += a / 2;
			a /= 2;
		}
		else
		{
			if (b % 2 == 1)
				b--;
			a += b / 2;
			b /= 2;
		}
	}
	cout << a << " " << b << endl;

	return 0;
}
