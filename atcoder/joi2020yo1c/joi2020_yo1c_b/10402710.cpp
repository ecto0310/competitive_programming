// URL: https://atcoder.jp/contests/joi2020yo1c/submissions/10402710
// Date: Sat, 29 Feb 2020 17:44:13 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  string s;
  cin >> n >> s;
  for (i64 i = 0; i < n - 2; i++)
    if (s.substr(i, 3) == "joi")
    {
      s[i] = 'J';
      s[i + 1] = 'O';
      s[i + 2] = 'I';
    }
  cout << s << endl;
  return 0;
}
