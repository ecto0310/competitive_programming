// URL: https://atcoder.jp/contests/code-festival-2016-qualb/submissions/2821236
// Date: Tue, 10 Jul 2018 16:17:13 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin>>s;
	string ok="CODEFESTIVAL2016";
	int ans=0;
	for(int i=0;i<s.size();i++)
		if(s[i]!=ok[i])
			ans++;
	cout<< ans<< endl;

	return 0;
}
