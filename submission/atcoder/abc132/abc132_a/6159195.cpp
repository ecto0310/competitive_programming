// URL: https://atcoder.jp/contests/abc132/submissions/6159195
// Date: Sat, 29 Jun 2019 21:02:49 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  map<char, i64> m;
  for (i64 i = 0; i < 4; i++)
    m[s[i]]++;
  bool ans = true;
  for (pair<char, i64> i : m)
    if (i.second != 2)
      ans = false;
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
