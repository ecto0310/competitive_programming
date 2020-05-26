// URL: https://atcoder.jp/contests/abc075/submissions/2670357
// Date: Fri, 15 Jun 2018 20:19:48 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if(a == b)cout << c << endl;
	else if(a == c)cout << b << endl;
	else if(b == c)cout << a << endl;

		return 0;
}
