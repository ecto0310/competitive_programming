// URL: https://atcoder.jp/contests/abc025/submissions/3593775
// Date: Tue, 13 Nov 2018 16:44:21 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	int pos = 0;
	for (int i = 0; i < n; i++)
	{
		string s;
		int d;
		cin >> s >> d;
		if (s == "East")
			pos += min(b, max(a, d));
		else
			pos -= min(b, max(a, d));
	}
	if (pos == 0)
		cout << 0 << endl;
	else if (0 < pos)
		cout << "East " << pos << endl;
	else
		cout << "West " << abs(pos) << endl;

	return 0;
}
