// URL: https://atcoder.jp/contests/abc058/submissions/2822735
// Date: Tue, 10 Jul 2018 22:02:59 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string o, e;
	cin >> o >> e;
	for (int i = 0; i < e.size(); i++)
		cout << o[i] << e[i];
	if (o.size() != e.size())
		cout << o[o.size() - 1];
	cout << endl;

	return 0;
}
