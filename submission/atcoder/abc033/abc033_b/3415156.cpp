// URL: https://atcoder.jp/contests/abc033/submissions/3415156
// Date: Tue, 16 Oct 2018 00:30:16 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int m = -1, sum = 0;
	string ans;
	for (int i = 0; i < n; i++)
	{
		string s;
		int p;
		cin >> s >> p;
		sum += p;
		if (m < p)
		{
			m = p;
			ans = s;
		}
	}
	if (sum / 2 < m)
		cout << ans << endl;
	else
		cout << "atcoder" << endl;

	return 0;
}
