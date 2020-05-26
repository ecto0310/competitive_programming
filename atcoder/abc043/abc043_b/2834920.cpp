// URL: https://atcoder.jp/contests/abc043/submissions/2834920
// Date: Fri, 13 Jul 2018 20:41:16 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	string ans;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')
			ans += "0";
		else if (s[i] == '1')
			ans += "1";
		else if (ans.size() != 0)
			ans.pop_back();
	}
	cout << ans << endl;

	return 0;
}
