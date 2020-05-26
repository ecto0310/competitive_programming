// URL: https://atcoder.jp/contests/abc131/submissions/6054372
// Date: Sat, 22 Jun 2019 21:03:35 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  for (i64 i = 0; i < s.size() - 1; i++)
    if (s[i] == s[i + 1])
    {
      cout << "Bad" << endl;
      return 0;
    }
  cout << "Good" << endl;
  return 0;
}
