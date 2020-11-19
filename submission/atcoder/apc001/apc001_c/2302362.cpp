// URL: https://atcoder.jp/contests/apc001/submissions/2302362
// Date: Wed, 04 Apr 2018 20:05:02 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>> N;
	int l=0,r=N-1;
	string s,t;
	cout<< 0<< endl;
	cin>> t;
	if(t=="Vacant")return 0;
	while(l!=r)
	{
		int i=(l+r+1)/2;
		cout<< i<< endl;
		cin>> s;
		if(s=="Vacant")return 0;
		if((t==s&&i%2)||(t!=s&&!(i%2)))r=i-1;
		else l=i;
	}

	return 0;
}
