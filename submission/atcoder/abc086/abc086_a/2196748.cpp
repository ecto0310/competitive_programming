// URL: https://atcoder.jp/contests/abc086/submissions/2196748
// Date: Mon, 12 Mar 2018 21:31:51 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int a,b;
  cin>> a>> b;

  string ret="Even";
  if(a*b%2)ret="Odd";
  cout<< ret<< endl;

  return 0;
}
