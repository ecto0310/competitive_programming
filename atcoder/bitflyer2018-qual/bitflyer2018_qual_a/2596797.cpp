// URL: https://atcoder.jp/contests/bitflyer2018-qual/submissions/2596797
// Date: Sat, 02 Jun 2018 21:01:37 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int ans = b;
	while(ans + b <= a)ans += b;
	cout << ans << endl;

	return 0;
}
