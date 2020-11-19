// URL: https://atcoder.jp/contests/chokudai_S002/submissions/6110433
// Date: Tue, 25 Jun 2019 00:11:27 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  set<pair<i64, i64>> s;
  for (i64 i = 0; i < n; i++)
  {
    i64 a, b;
    cin >> a >> b;
    if (b < a)
      swap(a, b);
    s.insert({a, b});
  }
  cout << s.size() << endl;
  return 0;
}
