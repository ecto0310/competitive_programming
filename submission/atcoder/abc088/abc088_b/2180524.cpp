// URL: https://atcoder.jp/contests/abc088/submissions/2180524
// Date: Sun, 11 Mar 2018 00:47:16 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  int a[100];
  cin>> N;
  for(int i=0;i<N;i++)cin>> a[i];

  int ret=0;
  sort(a,a+N,greater<int>());
  for(int i=0;i<N;i++)
  {
    if(i%2==0)ret+=a[i];
    else ret-=a[i];
  }
  cout<< ret<< endl;
  
  return 0;
}
