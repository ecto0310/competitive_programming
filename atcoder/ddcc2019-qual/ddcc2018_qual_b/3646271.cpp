// URL: https://atcoder.jp/contests/ddcc2019-qual/submissions/3646271
// Date: Fri, 23 Nov 2018 21:08:07 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = n % 2;
	for (int i = 1; i < n / 2; i++)
		ans += i * 4;
	cout << ans << endl;

	return 0;
}
