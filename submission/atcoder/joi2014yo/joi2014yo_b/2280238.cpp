// URL: https://atcoder.jp/contests/joi2014yo/submissions/2280238
// Date: Fri, 30 Mar 2018 20:55:15 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N,M;
	int A[1000],B[1000];
	cin>> N>> M;
	for(int i=0;i<N;i++)cin>> A[i];
	for(int i=0;i<M;i++)cin>> B[i];

	int ret;
	int vote[1000]={0};
	for(int i=0;i<M;i++)
	for(int j=0;j<N;j++)
	{
		if(A[j]<=B[i])
		{
			vote[j]++;
			break;
		}
	}
	int v=0;
	for(int i=0;i<N;i++)
	{
		if(vote[i]>v)
		{
			ret=i+1;
			v=vote[i];
		}
	}
	cout<< ret<< endl;

	return 0;
}
