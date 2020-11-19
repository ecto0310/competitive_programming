// URL: https://atcoder.jp/contests/abc164/submissions/12344642
// Date: Sun, 26 Apr 2020 21:04:44 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 A, B, C, D;
  cin >> A >> B >> C >> D;
  for(i64 i=0;;i++)
    if(i%2==0)
    {
      C-=B;
      if(C<=0)
      {
        cout<<"Yes"<<endl;
        return 0;
      }
    }
    else
    {
      A-=D;
      if(A<=0)
      {
        cout<<"No"<<endl;
        return 0;
      }
    }
  return 0;
}
