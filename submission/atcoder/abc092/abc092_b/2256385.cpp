// URL: https://atcoder.jp/contests/abc092/submissions/2256385
// Date: Sun, 25 Mar 2018 21:09:29 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;


int A[100];

int main()
{
  int N,D,X;
  cin>> N>> D>> X;
  for(int i=0;i<N;i++)cin>> A[i];

  int ret=X;
  for(int i=0;i<N;i++)
  {
    ret+=D/A[i]+(D%A[i]?1:0);
  }
  cout<< ret<< endl;
  
  return 0;
}
