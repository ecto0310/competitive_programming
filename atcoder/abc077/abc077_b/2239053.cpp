// URL: https://atcoder.jp/contests/abc077/submissions/2239053
// Date: Wed, 21 Mar 2018 16:43:41 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin>> N;

  int ret=0;
  for(int i=0;;i++)
  {
    if(i*i>N)
    {
      ret=(i-1)*(i-1);
      break;
    }
  }
  cout<< ret<< endl;

  return 0;
}
