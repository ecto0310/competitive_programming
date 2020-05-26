// URL: https://atcoder.jp/contests/code-festival-2017-qualc/submissions/2821369
// Date: Tue, 10 Jul 2018 16:43:12 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	bool ok = false;
	for (int i = 0; i < s.size() - 1; i++)
		if (s.substr(i, 2) == "AC")
			ok = true;
	if (ok)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
