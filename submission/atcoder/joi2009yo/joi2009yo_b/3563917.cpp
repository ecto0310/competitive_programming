// URL: https://atcoder.jp/contests/joi2009yo/submissions/3563917
// Date: Thu, 08 Nov 2018 19:30:53 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	vector<int> w(10), k(10);
	for (int i = 0; i < 10; i++)
		cin >> w[i];
	for (int i = 0; i < 10; i++)
		cin >> k[i];
	sort(w.begin(), w.end());
	sort(k.begin(), k.end());
	int ans[2] = {};
	for (int i = 0; i < 3; i++)
	{
		ans[0] += w[9 - i];
		ans[1] += k[9 - i];
	}
	cout << ans[0] << " " << ans[1] << endl;

	return 0;
}
