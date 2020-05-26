// URL: https://atcoder.jp/contests/abc106/submissions/3037743
// Date: Sat, 18 Aug 2018 22:17:31 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	long long k;
	cin >> s >> k;
	for (int i = 0; i < k; i++)
		if (s[i] != '1')
		{
			cout << s[i] << endl;
			return 0;
		}
	cout << 1 << endl;

	return 0;
}
