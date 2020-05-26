// URL: https://atcoder.jp/contests/abc042/submissions/2853203
// Date: Sun, 15 Jul 2018 23:39:18 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, k, d[10];
	cin >> n >> k;
	for (int i = 0; i < k; i++)
		cin >> d[i];
	for (int i = n;; i++)
	{
		bool ok = true;
		int now = i;
		while (now)
		{
			for (int j = 0; j < k; j++)
				if (now % 10 == d[j])
					ok = false;
			now /= 10;
		}
		if (ok)
		{
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}
