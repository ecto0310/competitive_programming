// URL: https://atcoder.jp/contests/abc076/submissions/2816172
// Date: Mon, 09 Jul 2018 06:46:26 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;
	vector<string> ans;
	if (s.size() < t.size())
	{
		cout << "UNRESTORABLE" << endl;
		return 0;
	}
	for (int i = 0; i <= s.size() - t.size(); i++)
	{
		bool ok = true;
		for (int j = 0; j < t.size(); j++)
			if (s[i + j] != '?' && s[i + j] != t[j])
				ok = false;
		if (ok)
		{
			string tmp = s;
			for (int j = 0; j < t.size(); j++)
				tmp[i + j] = t[j];
			for (int j = 0; j < s.size(); j++)
				if (tmp[j] == '?')
					tmp[j] = 'a';
			ans.push_back(tmp);
		}
	}

	if (ans.size() == 0)
		cout << "UNRESTORABLE" << endl;
	else
	{
		sort(ans.begin(), ans.end());
		cout << ans[0] << endl;
	}

	return 0;
}
