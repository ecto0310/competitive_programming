// URL: https://atcoder.jp/contests/abc078/submissions/2232604
// Date: Mon, 19 Mar 2018 22:06:05 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  string X,Y;
  cin>> X>> Y;

  string ret="=";
  if(X>Y)ret=">";
  else if(X<Y)ret="<";
  cout<< ret<< endl;

  return 0;
}
