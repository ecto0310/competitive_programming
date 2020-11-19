// URL: https://atcoder.jp/contests/abc141/submissions/7519050
// Date: Sun, 15 Sep 2019 21:05:31 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  bool ans = true;
  for (i64 i = 0; i < s.size(); i++)
    if (i % 2 == 0 && s[i] == 'L')
      ans = false;
    else if (i % 2 == 1 && s[i] == 'R')
      ans = false;
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
