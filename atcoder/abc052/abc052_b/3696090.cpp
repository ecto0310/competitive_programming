// URL: https://atcoder.jp/contests/abc052/submissions/3696090
// Date: Sat, 01 Dec 2018 21:03:22 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	int ans = 0, x = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'I')
			x++;
		else
			x--;
		ans = max(ans, x);
	}
	cout << ans << endl;
	
	return 0;
}
