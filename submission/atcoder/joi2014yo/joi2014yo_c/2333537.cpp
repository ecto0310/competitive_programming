// URL: https://atcoder.jp/contests/joi2014yo/submissions/2333537
// Date: Tue, 10 Apr 2018 22:56:47 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int W,H,N;
	int X[1000],Y[1000];
	cin>> W>> H>> N;
	for(int i=0;i<N;i++)cin>> X[i]>> Y[i];

	int ret=0;
	for(int i=1;i<N;i++)
	{
		int dx=X[i]-X[i-1];
		int dy=Y[i]-Y[i-1];
		if(dx*dy>0)ret+=max(abs(dx),abs(dy));
		else ret+=abs(dx)+abs(dy);
	}
	cout<< ret<< endl;

	return 0;
}
