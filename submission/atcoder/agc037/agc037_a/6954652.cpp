// URL: https://atcoder.jp/contests/agc037/submissions/6954652
// Date: Sat, 17 Aug 2019 21:07:01 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  i64 size = s.size();
  string last = s.substr(size - 1, 1);
  i64 ans = 1, l = size - 1;
  for (i64 i = size - 2; 0 <= i; i--)
    if (last != s.substr(i, l - i))
    {
      last = s.substr(i, l - i);
      l = i;
      ans++;
    }
  cout << ans << endl;
  return 0;
}
