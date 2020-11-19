// URL: https://atcoder.jp/contests/abc028/submissions/2860503
// Date: Tue, 17 Jul 2018 21:45:56 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n < 60)
		cout << "Bad" << endl;
	else if (n < 90)
		cout << "Good" << endl;
	else if (n < 100)
		cout << "Great" << endl;
	else
		cout << "Perfect" << endl;

	return 0;
}
