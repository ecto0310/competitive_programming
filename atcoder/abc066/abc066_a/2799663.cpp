// URL: https://atcoder.jp/contests/abc066/submissions/2799663
// Date: Sat, 07 Jul 2018 15:13:46 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<< a+b+c-max({a,b,c})<<endl;

	return 0;
}
