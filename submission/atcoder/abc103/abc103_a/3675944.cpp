// URL: https://atcoder.jp/contests/abc103/submissions/3675944
// Date: Tue, 27 Nov 2018 17:32:48 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	vector<int> a(3);
	cin >> a[0] >> a[1] >> a[2];
	sort(a.begin(), a.end());
	cout << a[2] - a[0] << endl;

	return 0;
}
