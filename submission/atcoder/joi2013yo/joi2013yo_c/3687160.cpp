// URL: https://atcoder.jp/contests/joi2013yo/submissions/3687160
// Date: Fri, 30 Nov 2018 02:02:00 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	string name;
	cin >> n >> name;
	vector<string> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		bool ok = false;
		for (int j = 0; j < s[i].size(); j++)
			for (int k = 1; k < s[i].size(); k++)
			{
				string tmp;
				for (int l = 0; j + k * l < s[i].size() && l < name.size(); l++)
					tmp += s[i][j + k * l];
				if (name == tmp)
					ok = true;
			}
		if (ok)
			ans++;
	}
	cout << ans << endl;

	return 0;
}
