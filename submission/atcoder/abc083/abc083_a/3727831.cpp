// URL: https://atcoder.jp/contests/abc083/submissions/3727831
// Date: Thu, 06 Dec 2018 21:01:21 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << (a + b > c + d ? "Left" : (a + b == c + d ? "Balanced" : "Right")) << endl;

	return 0;
}
