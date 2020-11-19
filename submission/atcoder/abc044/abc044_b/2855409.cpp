// URL: https://atcoder.jp/contests/abc044/submissions/2855409
// Date: Mon, 16 Jul 2018 16:47:44 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string w;
	cin >> w;
	map<char, int> m;
	for (int i = 0; i < w.size(); i++)
		m[w[i]]++;
	bool ok = true;
	for (int i = 0; i < 26; i++)
		if (m['a' + i] % 2 != 0)
			ok = false;
	if (ok)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
