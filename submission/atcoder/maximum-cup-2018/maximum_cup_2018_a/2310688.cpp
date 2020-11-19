// URL: https://atcoder.jp/contests/maximum-cup-2018/submissions/2310688
// Date: Sat, 07 Apr 2018 14:03:48 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>> N;
	
	int ret=0;
	for(int i=0;i<N;i++)
	{
		int t,d,m;
		cin>> t>> d>> m;
		if(t+10<=d)ret+=m;
	}
	cout<< ret<< endl;
	
	return 0;
}
