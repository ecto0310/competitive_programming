// URL: https://atcoder.jp/contests/colopl2018-qual/submissions/2280176
// Date: Fri, 30 Mar 2018 20:40:58 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N,X;
	string S;
	cin>> N>> X>> S;
	int T[1000];
	for(int i=0;i<N;i++)cin>> T[i];

	long long ret=0;
	for(int i=0;i<N;i++)
	{
		if(S[i]=='0')ret+=T[i];
		else ret+=min(T[i],X);
	}
	cout<< ret<< endl;

	return 0;
}
