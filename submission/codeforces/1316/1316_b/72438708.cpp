// URL: https://codeforces.com/contest/1316/submission/72438708
// Date: Thu, 05 Mar 2020 00:16:51 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 t;
  cin >> t;
  for (i64 _ = 0; _ < t; _++)
  {
    i64 n;
    string s;
    cin >> n >> s;
    vector<pair<string, i64>> ans;
    for (i64 i = 1; i <= n; i++)
    {
      string tmp = s.substr(0, i);
      if ((n - i) % 2 == 1)
        reverse(tmp.begin(), tmp.end());
      ans.push_back({s.substr(i, n - i) + tmp, i % n + 1});
      cerr << s.substr(i, n - i) + tmp << endl;
    }
    sort(ans.begin(), ans.end());
    cout << ans[0].first << "\n"
         << ans[0].second << "\n";
  }
  return 0;
}
