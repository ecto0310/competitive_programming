// URL: https://atcoder.jp/contests/abc078/submissions/2232625
// Date: Mon, 19 Mar 2018 22:09:36 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int X,Y,Z;
  cin>> X>> Y>> Z;

  int ret=(X-Z)/(Y+Z);
  cout<< ret<< endl;

  return 0;
}
