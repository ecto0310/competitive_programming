// URL: https://atcoder.jp/contests/summerfes2018-div2/submissions/3069283
// Date: Sat, 25 Aug 2018 14:47:11 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	int d = -1, k = n;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'D')
			d = i;
		if (s[n - i - 1] == 'K')
			k = n - i - 1;
	}
	if (d > k)
		cout << 0 << endl;
	else
		cout << k - d << endl;

	return 0;
}
