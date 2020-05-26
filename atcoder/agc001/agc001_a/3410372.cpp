// URL: https://atcoder.jp/contests/agc001/submissions/3410372
// Date: Mon, 15 Oct 2018 00:12:37 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> l(n * 2);
	for (int i = 0; i < n * 2; i++)
		cin >> l[i];
	sort(l.begin(), l.end());
	int ans = 0;
	for (int i = 0; i < n * 2; i += 2)
		ans += l[i];
	cout << ans << endl;

	return 0;
}
