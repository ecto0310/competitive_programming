// URL: https://atcoder.jp/contests/abc110/submissions/3732712
// Date: Fri, 07 Dec 2018 21:03:30 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;
	bool ok = true;
	map<char, char> st, tt;
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		if (0 < st.count(s[i]) && st[s[i]] != t[i])
			ok = false;
		if (0 < tt.count(t[i]) && tt[t[i]] != s[i])
			ok = false;
		st[s[i]] = t[i];
		tt[t[i]] = s[i];
	}
	cout << (ok ? "Yes" : "No") << endl;

	return 0;
}
