// URL: https://atcoder.jp/contests/abc090/submissions/2185605
// Date: Sun, 11 Mar 2018 21:15:04 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N,M;
  cin>> N>> M;

  long long ret=abs((long long)(N-2)*(M-2));
  cout<< ret<< endl;

  return 0;
}
