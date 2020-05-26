// URL: https://atcoder.jp/contests/soundhound2018-summer-qual/submissions/2802509
// Date: Sat, 07 Jul 2018 21:02:26 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	int w;
	cin >> s >> w;
	for (int i = 0; i < s.size(); i += w)
		cout << s[i];
	cout << endl;

	return 0;
}
