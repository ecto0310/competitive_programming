// URL: https://atcoder.jp/contests/agc024/submissions/6247551
// Date: Sat, 06 Jul 2019 01:47:33 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

struct Data
{
  vector<i64> s;
  i64 p = 0;
};

int main()
{
  i64 n;
  cin >> n;
  vector<i64> ind(n);
  for (i64 i = 0; i < n; i++)
  {
    i64 p;
    cin >> p;
    ind[p - 1] = i;
  }
  i64 ans = 0, cnt = 1;
  for (i64 i = 0; i < n - 1; i++)
    if (ind[i] < ind[i + 1])
      cnt++;
    else
    {
      ans = max(ans, cnt);
      cnt = 1;
    }
  ans = max(ans, cnt);
  cout << n - ans << endl;
  return 0;
}
