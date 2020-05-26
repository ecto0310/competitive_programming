// URL: https://atcoder.jp/contests/abc077/submissions/2239048
// Date: Wed, 21 Mar 2018 16:41:27 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  string C[2];
  cin>> C[0]>> C[1];

  string ret="NO";
  if(C[0][0]==C[1][2]&&C[0][1]==C[1][1]&&C[0][2]==C[1][0])ret="YES";
  cout<< ret<< endl;

  return 0;
}
