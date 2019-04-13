// URL: https://atcoder.jp/contests/abs/submissions/4937065
// Date: Sat, 13 Apr 2019 19:46:14 +0900
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
