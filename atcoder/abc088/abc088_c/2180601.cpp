// URL: https://atcoder.jp/contests/abc088/submissions/2180601
// Date: Sun, 11 Mar 2018 01:27:12 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int c[3][3];
  for(int i=0;i<3;i++)for(int j=0;j<3;j++)cin>> c[i][j];

  string ret="No";
  for(int a1=0;a1<=max({c[0][0],c[0][1],c[0][2]});a1++)
  for(int a2=0;a2<=max({c[1][0],c[1][1],c[2][2]})-a1;a2++)
  for(int a3=0;a3<=max({c[2][0],c[2][1],c[1][2]});a3++)
  {
    int b1=c[0][0]-a1;
    int b2=c[1][1]-a2;
    int b3=c[2][2]-a3;
    if(a1+b2==c[0][1]&&a1+b3==c[0][2]&&a2+b1==c[1][0]&&a2+b3==c[1][2]&&a3+b1==c[2][0]&&a3+b2==c[2][1])
    {
      ret="Yes";
      break;
    }
  }
  cout<< ret<< endl;

  return 0;
}
