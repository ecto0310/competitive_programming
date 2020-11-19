// URL: https://atcoder.jp/contests/abc123/submissions/4863451
// Date: Sat, 06 Apr 2019 22:47:29 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	long long n,a,b,c,d,e;
	cin>>n>>a>>b>>c>>d>>e;
	cout<<(n+min({a,b,c,d,e})-1)/min({a,b,c,d,e})+4<<endl;

	return 0;
}
