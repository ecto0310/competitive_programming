// URL: https://atcoder.jp/contests/abc076/submissions/2670465
// Date: Fri, 15 Jun 2018 20:47:49 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int ans = 1;
	for(int i = 0; i < n; i++)ans = min(ans * 2, ans + k);
	cout << ans << endl;

	return 0;
}
