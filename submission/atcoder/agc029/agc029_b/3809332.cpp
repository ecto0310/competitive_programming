// URL: https://atcoder.jp/contests/agc029/submissions/3809332
// Date: Sun, 16 Dec 2018 18:31:13 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  map<int, int, greater<int>> a;
  for (int i = 0; i < n; i++)
  {
    int t;
    cin >> t;
    a[t]++;
  }
  int ans = 0;
  for (pair<int, int> i : a)
  {
    if (i.second < 1)
      continue;
    int bit = 1;
    while (bit < i.first)
      bit *= 2;
    if (bit == i.first)
      ans += i.second / 2;
    int c = min(i.second, a[bit - i.first]);
    ans += c;
    a[bit - i.first] -= c;
  }
  cout << ans << endl;

  return 0;
}
