// URL: https://atcoder.jp/contests/abc055/submissions/2831206
// Date: Thu, 12 Jul 2018 22:26:28 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	long long ans=1;
	for(int i=0;i<n;i++)
		ans=ans*(i+1)%1000000007;
	cout<< ans<< endl;
	
	return 0;
}
