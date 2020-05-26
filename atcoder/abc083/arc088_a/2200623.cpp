// URL: https://atcoder.jp/contests/abc083/submissions/2200623
// Date: Tue, 13 Mar 2018 21:31:57 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  long long X,Y;
  cin>> X>> Y;

  int ret=0;
  long long now=X;
  while(now<=Y)
  {
    now*=2;
    ret++;
  }
  cout<< ret<< endl;

  return 0;
}
