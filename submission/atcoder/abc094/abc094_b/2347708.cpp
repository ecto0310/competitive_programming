// URL: https://atcoder.jp/contests/abc094/submissions/2347708
// Date: Sat, 14 Apr 2018 21:15:37 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,M,X;
	int A[100];
	cin>> N>> M>> X;
	for(int i=0;i<M;i++)cin>> A[i];

	int to0=0,toN=0;
	for(int i=0;i<M;i++)
	{
		if(A[i]<X)to0++;
		else toN++;
	}
	cout<< min(to0,toN)<< endl;

	return 0;
}
