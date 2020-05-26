// URL: https://atcoder.jp/contests/abc085/submissions/2280125
// Date: Fri, 30 Mar 2018 20:25:20 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	int d[100];
	cin>> N;
	for(int i=0;i<N;i++)cin>> d[i];

	int ret=1;
	sort(d,d+N);
	for(int i=1;i<N;i++)
	{
		if(d[i]!=d[i-1])ret++;
	}
	cout<< ret<< endl;

	return 0;
}
