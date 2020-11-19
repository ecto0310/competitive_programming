// URL: https://atcoder.jp/contests/abc045/submissions/2855563
// Date: Mon, 16 Jul 2018 17:16:06 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s[3];
	cin >> s[0] >> s[1] >> s[2];
	int now = 0;
	while (true)
	{
		if (s[now].length() == 0)
			break;
		int tmp = s[now][0] - 'a';
		s[now].erase(0, 1);
		now = tmp;
	}
	cout << (char)('A' + now) << endl;

	return 0;
}
