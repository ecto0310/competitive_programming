// URL: https://atcoder.jp/contests/s8pc-5/submissions/2691250
// Date: Sun, 17 Jun 2018 02:11:50 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n, t;
	cin >> n >> t;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		ans = (ans <= ans / t * t + a ? ans / t * t + a : (ans / t + 1)*t + a);
	}
	cout << ans << endl;

	return 0;
}
