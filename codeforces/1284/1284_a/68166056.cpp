// URL: https://codeforces.com/contest/1284/submission/68166056
// Date: Sat, 04 Jan 2020 21:10:24 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<string> s(n), t(m);
  for (i64 i = 0; i < n; i++)
    cin >> s[i];
  for (i64 i = 0; i < m; i++)
    cin >> t[i];
  i64 q;
  cin >> q;
  for (i64 _ = 0; _ < q; _++)
  {
    i64 y;
    cin >> y;
    cout << s[(y - 1) % n] << t[(y - 1) % m] << "\n";
  }
  return 0;
}
