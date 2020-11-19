// URL: https://atcoder.jp/contests/nomura2020/submissions/13717390
// Date: Sat, 30 May 2020 21:03:46 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string T;
  cin >> T;
  for (char &i : T)
    if (i == '?')
      i = 'D';
  cout << T << endl;
  return 0;
}
