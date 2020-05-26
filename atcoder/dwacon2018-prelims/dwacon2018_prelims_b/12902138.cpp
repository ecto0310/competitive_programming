// URL: https://atcoder.jp/contests/dwacon2018-prelims/submissions/12902138
// Date: Wed, 06 May 2020 22:50:14 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string s;
  cin >> s;
  for (i64 i = 1; i < s.size(); i++)
  {
    bool ok = true;
    i64 a = i, b = 0;
    for (char j : s)
      if (j == '2' && 0 < a)
      {
        a--;
        b++;
      }
      else if (j == '5' && 0 < b)
      {
        b--;
        a++;
      }
      else
        ok = false;
    if (b != 0)
      ok = false;
    if (ok)
    {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
