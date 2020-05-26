// URL: https://atcoder.jp/contests/tenka1-2016-qualb/submissions/2821502
// Date: Tue, 10 Jul 2018 17:08:29 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int f(int x)
{
	return (x *x + 4) / 8;
}

int main()
{
	cout << f(f(f(20))) << endl;

	return 0;
}
