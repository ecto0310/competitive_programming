// URL: https://atcoder.jp/contests/nikkei2019-final/submissions/4813814
// Date: Wed, 03 Apr 2019 19:16:33 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> a(n),b(m);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	if(n<m)
		cout<<"X"<<endl;
	else if(m<n)
		cout<<"Y"<<endl;
	else
	{
		for(int i=0;i<n;i++)
			if(a[i]<b[i])
			{
				cout<<"X"<<endl;
				return 0;
			}
			else if(b[i]<a[i])
			{
				cout<<"Y"<< endl;
				return 0;
			}
		cout<<"Same"<<endl;
	}

	return 0;
}
