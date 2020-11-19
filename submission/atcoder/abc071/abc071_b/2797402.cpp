// URL: https://atcoder.jp/contests/abc071/submissions/2797402
// Date: Fri, 06 Jul 2018 21:39:51 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	map<char, bool> m;
	int size = s.size();
	for (int i = 0; i < size; i++)
		m[s[i]] = true;
	for (int i = 0; i < 26; i++)
		if (!m['a' + i])
		{
			cout << (char)('a' + i) << endl;
			return 0;
		}
	cout << "None" << endl;

	return 0;
}
