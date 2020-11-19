// URL: https://atcoder.jp/contests/code-thanks-festival-2018-open/submissions/3663602
// Date: Sun, 25 Nov 2018 12:33:55 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int ans = 1, size = s.size();
	char now = s[0];
	for (int i = 1; i < size; i++)
		if (s[i] <= now)
		{
			now = s[i];
			ans++;
		}
	cout << ans << endl;

	return 0;
}
