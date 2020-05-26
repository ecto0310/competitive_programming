// URL: https://atcoder.jp/contests/abc139/submissions/7291598
// Date: Sun, 01 Sep 2019 22:46:01 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  chrono::system_clock::time_point start = chrono::system_clock::now();
  i64 n;
  cin >> n;
  queue<i64> a[n];
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < n - 1; j++)
    {
      i64 t;
      cin >> t;
      a[i].push(t - 1);
    }

  i64 fin = 0;
  for (i64 i = 0;; i++)
  {
    bool match = false;
    vector<bool> use(n);
    for (i64 j = 0; j < n; j++)
      if (0 < a[j].size())
      {
        i64 jf = a[j].front();
        if (!use[j] && !use[jf] && 0 < a[jf].size() && j == a[jf].front() && jf == a[j].front())
        {
          match = true;
          use[jf] = true;
          use[j] = true;
          a[jf].pop();
          a[j].pop();
          fin++;
        }
      }
    if (!match)
    {
      cout << -1 << endl;
      return 0;
    }
    if (fin == n * (n - 1) / 2)
    {
      cout << i + 1 << endl;
      return 0;
    }
    if (1950 < chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - start).count() / 1000)
    {
      cout << n * (n - 1) / 2 << endl;
      return 0;
    }
  }
  return 0;
}
