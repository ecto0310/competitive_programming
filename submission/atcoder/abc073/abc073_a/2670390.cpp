// URL: https://atcoder.jp/contests/abc073/submissions/2670390
// Date: Fri, 15 Jun 2018 20:29:41 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if(n % 10 == 9 || n / 10 == 9)cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
