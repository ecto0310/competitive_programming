// URL: https://atcoder.jp/contests/abc067/submissions/2799643
// Date: Sat, 07 Jul 2018 15:10:04 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		int l;
		cin>>l;
		v.push_back(l);
	}
	sort(v.begin(),v.end());
	int ans=0;
	for(int i=0;i<k;i++)ans+=v[n-i-1];
	cout<< ans<<endl;

	return 0;
}
