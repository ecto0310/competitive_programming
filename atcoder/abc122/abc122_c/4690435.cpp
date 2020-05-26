// URL: https://atcoder.jp/contests/abc122/submissions/4690435
// Date: Sun, 24 Mar 2019 21:13:37 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n,q;
	string s;
	cin>>n>>q>>s;
	vector<int> cnt(1e5+1);
	for(int i=0;i<(int)s.size()-1;i++)
	{
		if(s.substr(i,2)=="AC")
			cnt[i+1]++;
			cnt[i+1]+=cnt[i];
	}
	for(int i=0;i<q;i++)
	{
		int l,r;
		cin>>l>>r;
		cout<< cnt[r-1]-(l-1<0?0:cnt[l-1])<< endl;
	}

  return 0;
}
