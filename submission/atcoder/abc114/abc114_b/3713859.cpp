// URL: https://atcoder.jp/contests/abc114/submissions/3713859
// Date: Tue, 04 Dec 2018 01:28:13 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int ans = 1e9;
	for (int i = 0; i < s.size()-2; i++)
			ans = min(ans, abs(753 - stoi(s.substr(i, 3))));
	cout << ans << endl;

	return 0;
}
