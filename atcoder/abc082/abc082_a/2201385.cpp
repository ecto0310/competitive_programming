// URL: https://atcoder.jp/contests/abc082/submissions/2201385
// Date: Wed, 14 Mar 2018 00:31:52 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int a,b;
  cin>> a>> b;

  int ret=(a+b)/2+((a+b)%2?1:0);
  cout<< ret<< endl;

  return 0;
}
