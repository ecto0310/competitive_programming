// URL: https://atcoder.jp/contests/abc010/submissions/4812091
// Date: Wed, 03 Apr 2019 15:53:32 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int xa,ya,xb,yb,t,v,n;
	cin>>xa>>ya>>xb>>yb>>t>>v>>n;
	vector<int> x(n),y(n);
	for(int i=0;i<n;i++)
		cin>>x[i]>>y[i];
	bool ans=false;
	for(int i=0;i<n;i++)
		if(sqrt(pow(xa-x[i],2)+pow(ya-y[i],2))+sqrt(pow(x[i]-xb,2)+pow(y[i]-yb,2))<=t*v)
			ans=true;
	if(ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	return 0;
}
