// URL: https://atcoder.jp/contests/abc028/submissions/3566856
// Date: Fri, 09 Nov 2018 11:20:07 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int ans[26] = {};
	for (int i = 0; i < s.size();i++)
		ans[s[i] - 'A']++;
	cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4] << " " << ans[5] << endl;

	return 0;
}
