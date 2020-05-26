// URL: https://atcoder.jp/contests/abc115/submissions/3739892
// Date: Sat, 08 Dec 2018 21:13:27 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	sort(p.begin(), p.end(), greater<int>());
	p[0] /= 2;
	int ans = 0;
	for (int tmp : p)
		ans += tmp;
	cout << ans << endl;

	return 0;
}
