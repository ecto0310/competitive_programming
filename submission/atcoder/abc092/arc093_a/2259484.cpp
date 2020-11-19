// URL: https://atcoder.jp/contests/abc092/submissions/2259484
// Date: Sun, 25 Mar 2018 21:51:19 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int A[100000];
int f[100001];

int main()
{
  int N;
  cin>> N;
  for(int i=0;i<N;i++)cin>> A[i];

  f[0]=abs(A[0]);
  for(int i=1;i<N;i++)f[i]=f[i-1]+abs(A[i]-A[i-1]);
  f[N]=f[N-1]+abs(A[N-1]);
  for(int i=0;i<N;i++)
  {
    int ret=f[N]-f[i+1];
    if(i==0)
    {
      ret+=abs(A[i+1]);
    }
    else
    {
      ret+=f[i-1]+abs(A[i+1]-A[i-1]);
    }
    cout<< ret<< endl;
  }

  return 0;
}
