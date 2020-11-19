// URL: https://atcoder.jp/contests/abc122/submissions/4688558
// Date: Sun, 24 Mar 2019 21:07:31 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<(int)s.size();i++)
	{
		int cnt=0;
		for(;i+cnt<(int)s.size();cnt++)
			if(s[i+cnt]!='A'&&s[i+cnt]!='C'&&s[i+cnt]!='G'&&s[i+cnt]!='T')
				break;
				ans=max(ans,cnt);
	}
	cout<< ans<< endl;

  return 0;
}
