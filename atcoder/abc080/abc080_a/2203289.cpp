// URL: https://atcoder.jp/contests/abc080/submissions/2203289
// Date: Wed, 14 Mar 2018 16:01:48 +0900
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N,A,B;
  cin>> N>> A>>B;

  int ret=min(A*N,B);
  cout<< ret<< endl;
  
  return 0;
}
