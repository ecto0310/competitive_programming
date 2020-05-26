// URL: https://atcoder.jp/contests/abc059/submissions/2822711
// Date: Tue, 10 Jul 2018 22:00:01 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	double a, b;
	cin >> a >> b;
	if (a > b)
		cout << "GREATER" << endl;
	else if (a < b)
		cout << "LESS" << endl;
	else
		cout << "EQUAL" << endl;

	return 0;
}
