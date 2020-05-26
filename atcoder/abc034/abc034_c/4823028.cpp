// URL: https://atcoder.jp/contests/abc034/submissions/4823028
// Date: Thu, 04 Apr 2019 19:31:34 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

const int MOD=1e9+7;

long long powmod(long long x,long long y)
{
	if(y==0)
		return 1;
	else if(y%2==0)
		return powmod(x*x%MOD,y/2);
	else
		return x*powmod(x,y-1)%MOD;
}

int main()
{
	int h,w;
	cin>>h>>w;
	long long ans=1;
	for(int i=h;i<=h+w-2;i++)
		ans=ans*i%MOD;
	long long tmp=1;
	for(int i=1;i<=w-1;i++)
		tmp=tmp*i%MOD;
	ans=ans*powmod(tmp,MOD-2)%MOD;
	cout<<ans<<endl;

	return 0;
}
