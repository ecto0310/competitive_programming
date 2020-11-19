// URL: https://atcoder.jp/contests/abc066/submissions/2814581
// Date: Sun, 08 Jul 2018 20:15:20 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 2; i < s.size() - 1; i += 2)
	{
		int length = i / 2;
		if (s.substr(0, length) == s.substr(length, length))
			ans = i;
	}
	cout << ans << endl;

	return 0;
}
