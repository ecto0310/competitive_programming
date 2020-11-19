// URL: https://atcoder.jp/contests/abc090/submissions/2183741
// Date: Sun, 11 Mar 2018 21:03:39 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int A,B;
  cin>> A>> B;

  int ret=0;
  for(int i=A;i<=B;i++)
  {
    string str=to_string(i);
    if(str[0]==str[4]&&str[1]==str[3])ret++;
  }
  cout<< ret<< endl;

  return 0;
}
