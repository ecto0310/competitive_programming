// URL: https://atcoder.jp/contests/abc104/submissions/2953996
// Date: Sun, 05 Aug 2018 21:21:34 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	bool ok = true, c = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (i == 0)
		{
			if (s[i] != 'A')
				ok = false;
		}
		else
		{
			if (s[i] == 'C')
			{
				if (c || 2 > i || i == s.length() - 1)
					ok = false;
				c = true;
			}
			else if (s[i] < 'a' || 'z' < s[i])
				ok = false;
		}
	}
	if (ok && c)
		cout << "AC" << endl;
	else
		cout << "WA" << endl;

	return 0;
}
