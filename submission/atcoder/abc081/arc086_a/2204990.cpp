// URL: https://atcoder.jp/contests/abc081/submissions/2204990
// Date: Wed, 14 Mar 2018 21:20:37 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int A[200000];
int cou[200000];

int main()
{
  int N,K;
  cin>> N>> K;
  for(int i=0;i<N;i++)cin>> A[i];

  int ret=0;
  for(int i=0;i<=N;i++)cou[i]=0;
  for(int i=0;i<N;i++)cou[A[i]]++;
  for(int i=0;i<=N;i++)cerr<< ":"<< i<< " "<< cou[i]<< endl;;
  sort(cou,cou+N,greater<int>());
  for(int i=K;i<=N;i++)ret+=cou[i];
  cout<< ret<< endl;

  return 0;
}
