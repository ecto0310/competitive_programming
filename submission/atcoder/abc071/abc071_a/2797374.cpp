// URL: https://atcoder.jp/contests/abc071/submissions/2797374
// Date: Fri, 06 Jul 2018 21:31:06 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int x, a, b;
	cin >> x >> a >> b;
	if (abs(x - a) > abs(x - b))
		cout << "B" << endl;
	else
		cout << "A" << endl;

	return 0;
}
