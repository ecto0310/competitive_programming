// URL: https://atcoder.jp/contests/abc103/submissions/2892851
// Date: Sun, 22 Jul 2018 18:19:51 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;
	bool ok = false;
	for (int i = 0; i < s.size(); i++)
		if (s == t.substr(i, s.size() - i) + t.substr(0, i))
			ok = true;
	if (ok)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
