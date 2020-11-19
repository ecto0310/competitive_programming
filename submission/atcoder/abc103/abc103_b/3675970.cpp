// URL: https://atcoder.jp/contests/abc103/submissions/3675970
// Date: Tue, 27 Nov 2018 17:36:03 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;
	bool ok = false;
	int size = s.size();
	for (int i = 0; i < size; i++)
		if (s.substr(i, size - i) + s.substr(0, i) == t)
			ok = true;
	cout << (ok ? "Yes" : "No") << endl;

	return 0;
}
