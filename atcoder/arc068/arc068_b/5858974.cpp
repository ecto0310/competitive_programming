// URL: https://atcoder.jp/contests/arc068/submissions/5858974
// Date: Sun, 09 Jun 2019 23:29:45 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  set<i64> s;
  for (i64 i = 0; i < n; i++)
  {
    i64 a;
    cin >> a;
    s.insert(a);
  }
  cout << s.size() - (s.size() + 1) % 2 << endl;
  return 0;
}
