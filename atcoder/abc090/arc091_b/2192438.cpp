// URL: https://atcoder.jp/contests/abc090/submissions/2192438
// Date: Sun, 11 Mar 2018 22:50:32 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  long long N,K;
  cin>> N>> K;

  long long ret=0;  
  for(int i=K+1;i<=N;i++)
  {
    ret+=(N/i)*(i-K);
    if(N%i>=K)ret+=N%i-K+1;  
    cerr<< i<< ": "<< ret<< endl;
  }
  if(K==0)ret=N*N;
  cout<< ret<< endl;

  return 0;
}
