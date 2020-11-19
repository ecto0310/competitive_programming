// URL: https://atcoder.jp/contests/abc087/submissions/2195353
// Date: Mon, 12 Mar 2018 15:39:57 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{

  int N,A[100][2];
  cin>> N;
  for(int i=0;i<N;i++)cin>> A[i][0];
  for(int i=0;i<N;i++)cin>> A[i][1];

  int ret=0;
  int sum[100][2];
  sum[0][0]=A[0][0];
  sum[N-1][1]=A[N-1][1];
  for(int i=1;i<N;i++)
  {
    sum[i][0]=sum[i-1][0]+A[i][0];
    cerr<< sum[i][0]<< " "<< endl;
  }
  cerr<< endl;
  for(int i=N-2;i>-1;i--)
  {
    sum[i][1]=sum[i+1][1]+A[i][1];
    cerr<< sum[i][1]<< " "<< endl;
  }
  cerr<< endl;
  for(int i=0;i<N;i++)
  {
    ret=max(ret,sum[i][0]+sum[i][1]);
    cerr<< sum[i][0]+sum[i][1]<< endl;
  }
  cout<< ret<< endl;

  return 0;
}
