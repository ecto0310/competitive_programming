// URL: https://atcoder.jp/contests/agc006/submissions/3410456
// Date: Mon, 15 Oct 2018 00:27:58 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	string s, t;
	cin >> n >> s >> t;
	for (int i = 0; i < n; i++)
	{
		bool ok = true;
		for (int j = 0; j + i < n; j++)
			if (s[i + j] != t[j])
				ok = false;
		if (ok)
		{
			cout << i + n << endl;
			return 0;
		}
	}
	cout << n * 2 << endl;
	return 0;
}
