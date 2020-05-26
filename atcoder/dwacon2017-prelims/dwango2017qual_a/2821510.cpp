// URL: https://atcoder.jp/contests/dwacon2017-prelims/submissions/2821510
// Date: Tue, 10 Jul 2018 17:09:45 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	cout << max(0, a + b - n) << endl;

	return 0;
}
