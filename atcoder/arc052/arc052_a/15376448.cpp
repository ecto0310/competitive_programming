// URL: https://atcoder.jp/contests/arc052/submissions/15376448
// Date: Thu, 23 Jul 2020 20:20:04 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string S;
  cin>>S;
  for (char i : S)
    if ('0' <= i && i <= '9')
      cout << i;
  cout << endl;
  return 0;
}
