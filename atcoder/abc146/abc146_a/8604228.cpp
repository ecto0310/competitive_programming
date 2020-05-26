// URL: https://atcoder.jp/contests/abc146/submissions/8604228
// Date: Sun, 24 Nov 2019 21:01:57 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  if (s == "SUN")
    cout << 7 << endl;
  else if (s == "MON")
    cout << 6 << endl;
  else if (s == "TUE")
    cout << 5 << endl;
  else if (s == "WED")
    cout << 4 << endl;
  else if (s == "THU")
    cout << 3 << endl;
  else if (s == "FRI")
    cout << 2 << endl;
  else
    cout << 1 << endl;
  return 0;
}
