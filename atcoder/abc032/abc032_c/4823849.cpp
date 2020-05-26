// URL: https://atcoder.jp/contests/abc032/submissions/4823849
// Date: Thu, 04 Apr 2019 21:16:39 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> s(n);
	for(int i=0;i<n;i++)
		cin>>s[i];
	int ans=0,j=0;
	long long tmp=1;
	for(int i=0;i<n;i++)
	{
		if(s[i]==0)
		{
			cout<<n<<endl;
			return 0;
		}
		while(j<n&&tmp*s[j]<=k)
		{
			tmp*=s[j];
			j++;
		}
		ans=max(ans,j-i);
		if(i==j)
			j++;
		else
			tmp/=s[i];
	}
	cout<<ans<<endl;

	return 0;
}
