// URL: https://atcoder.jp/contests/abc091/submissions/3828342
// Date: Thu, 20 Dec 2018 21:23:38 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  map<string, pair<int, int>> ma;
  int n;
  cin >> n;
  while (n--)
  {
    string s;
    cin >> s;
    ma[s].first++;
  }
  int m;
  cin >> m;
  while (m--)
  {
    string t;
    cin >> t;
    ma[t].second++;
  }
  int ans = 0;
  for (pair<string, pair<int, int>> t : ma)
    ans = max(ans, t.second.first - t.second.second);
  cout << ans << endl;

  return 0;
}
