// URL: https://atcoder.jp/contests/abc068/submissions/2799611
// Date: Sat, 07 Jul 2018 15:03:46 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int ans=1;
	while(ans*2<=n)ans*=2;
	cout<< ans<< endl;

	return 0;
}
