// URL: https://atcoder.jp/contests/abc123/submissions/4846137
// Date: Sat, 06 Apr 2019 21:10:12 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	int ans=((a+9)/10+(b+9)/10+(c+9)/10+(d+9)/10+(e+9)/10);
	cout<<min({(ans-(a+9)/10)*10+a,(ans-(b+9)/10)*10+b,(ans-(c+9)/10)*10+c,(ans-(d+9)/10)*10+d,(ans-(e+9)/10)*10+e})<<endl;

	return 0;
}
