// URL: https://atcoder.jp/contests/arc070/submissions/2856605
// Date: Mon, 16 Jul 2018 21:18:34 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int x;
	cin >> x;
	for (long long i = 0;; i++)
	{
		if (i * (i + 1) / 2 >= x)
		{
			cout << i << endl;
			break;
		}
	}

	return 0;
}
