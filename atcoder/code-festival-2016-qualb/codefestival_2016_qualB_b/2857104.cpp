// URL: https://atcoder.jp/contests/code-festival-2016-qualb/submissions/2857104
// Date: Mon, 16 Jul 2018 23:02:17 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	int cntp = 0, cntb = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'a')
		{
			if (cntp < a + b)
			{
				cout << "Yes" << endl;
				cntp++;
			}
			else
				cout << "No" << endl;
		}
		else if (s[i] == 'b')
		{
			if (cntp < a + b && cntb < b)
			{
				cout << "Yes" << endl;
				cntp++;
				cntb++;
			}
			else
				cout << "No" << endl;
		}
		else
			cout << "No" << endl;
	}

	return 0;
}
