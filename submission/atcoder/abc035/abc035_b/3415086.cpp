// URL: https://atcoder.jp/contests/abc035/submissions/3415086
// Date: Tue, 16 Oct 2018 00:13:25 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	int t;
	cin >> s >> t;
	int cnt = 0, x = 0, y = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == 'L')
			x--;
		else if (s[i] == 'R')
			x++;
		else if (s[i] == 'U')
			y++;
		else if (s[i] == 'D')
			y--;
		else
			cnt++;
	if (t == 1)
		cout << abs(x) + abs(y) + cnt << endl;
	else if (abs(x) + abs(y) > cnt)
		cout << abs(x) + abs(y) - cnt << endl;
	else
		cout << abs(abs(x) + abs(y) - cnt) % 2 << endl;

	return 0;
}
