// URL: https://atcoder.jp/contests/abc063/submissions/2818995
// Date: Mon, 09 Jul 2018 23:00:06 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	bool use[26] = {};
	bool ok = true;
	for (int i = 0; i < s.size(); i++)
	{
		if (use[s[i] - 'a'])
			ok = false;
		use[s[i] - 'a'] = true;
	}
	if (ok)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;
}
