// URL: https://atcoder.jp/contests/abc013/submissions/4813193
// Date: Wed, 03 Apr 2019 18:07:58 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	long long n,h,a,b,c,d,e;
	cin>>n>>h>>a>>b>>c>>d>>e;
	long long ans=1e18;
	for(int i=0;i<=n;i++)
	{
		long long j=max(0LL,(long long)((double)((n-i)*e-h-b*i)/(d+e)+1));
		if(i+j<=n)
			ans=min(ans,(long long)i*a+j*c);
	}
	cout<<ans<<endl;

	return 0;
}
