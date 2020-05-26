// URL: https://atcoder.jp/contests/abc123/submissions/4857121
// Date: Sat, 06 Apr 2019 22:03:40 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int x,y,z,k;
	cin>>x>>y>>z>>k;
	vector<long long> a(x),b(y),c(y);
	for(long long &i:a)
		cin>>i;
	for(long long &i:b)
		cin>>i;
	for(long long &i:c)
		cin>>i;
	sort(a.begin(),a.end(),greater<long long>());
	sort(b.begin(),b.end(),greater<long long>());
	sort(c.begin(),c.end(),greater<long long>());
	vector<long long> tmp(x*y);
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			tmp[x*i+j]=a[i]+b[j];
	sort(tmp.begin(),tmp.end(),greater<long long>());
	priority_queue<long long> ans;
	for(int i=0;i<min(k,x*y);i++)
		for(int j=0;j<z;j++)
			ans.push(tmp[i]+c[j]);
	for(int i=0;i<k;i++)
	{
		cout<<ans.top()<<endl;
		ans.pop();
	}

	return 0;
}
