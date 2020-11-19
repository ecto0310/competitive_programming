// URL: https://atcoder.jp/contests/abc079/submissions/2208016
// Date: Thu, 15 Mar 2018 17:36:53 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin>> N;

  long long ret;
  long long L[87];
  L[0]=2;
  L[1]=1;
  for(int i=2;i<=N;i++)
  {
    L[i]=L[i-1]+L[i-2];
  }
  ret=L[N];
  cout<< ret<< endl;

  return 0;
}
