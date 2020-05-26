// URL: https://atcoder.jp/contests/joi2020yo1b/submissions/10402692
// Date: Sat, 29 Feb 2020 17:43:38 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  reverse(s.begin() + a - 1, s.begin() + b);
  cout << s << endl;
}
