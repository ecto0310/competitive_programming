// URL: https://atcoder.jp/contests/abs/submissions/4937052
// Date: Sat, 13 Apr 2019 19:45:17 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int A,B,C,X;
  cin>> A>> B>> C>> X;

  int ret=0;
  for(int i=0;i<=A;i++)
  for(int j=0;j<=B;j++)
  for(int k=0;k<=C;k++)
  {
    if(500*i+100*j+50*k==X)ret++;
  }
  cout<< ret<< endl;

  return 0;
}
