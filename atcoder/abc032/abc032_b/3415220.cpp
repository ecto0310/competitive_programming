// URL: https://atcoder.jp/contests/abc032/submissions/3415220
// Date: Tue, 16 Oct 2018 00:47:28 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	int k;
	cin >> s >> k;
	set<string> se;
	if (s.size() < k)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < s.size() - k + 1; i++)
		se.insert(s.substr(i, k));
	cout << se.size() << endl;

	return 0;
}
