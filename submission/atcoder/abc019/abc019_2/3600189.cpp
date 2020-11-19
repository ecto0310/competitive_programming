// URL: https://atcoder.jp/contests/abc019/submissions/3600189
// Date: Wed, 14 Nov 2018 22:57:56 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	s += "-";
	string ans;
	int cnt = 0;
	for (int i = 0; i < s.size() - 1; i++)
		if (s[i] != s[i + 1])
		{
			ans += s[i] + to_string(cnt + 1);
			cnt = 0;
		}
		else
			cnt++;
	cout << ans << endl;

	return 0;
}
