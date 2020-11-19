// URL: https://codeforces.com/contest/1263/submission/65969121
// Date: Sat, 30 Nov 2019 00:05:47 +0900
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
    cin >> n;
    vector<string> p(n);
    map<string, i64> cnt;
    for (i64 i = 0; i < n; i++)
    {
      cin >> p[i];
      cnt[p[i]]++;
    }
    i64 ans = 0;
    for (pair<string, i64> i : cnt)
      ans += i.second - 1;
    cout << ans << endl;
    for (i64 i = 0; i < n; i++)
      if (1 < cnt[p[i]])
      {
        for (i64 j = 0; j <= 9; j++)
          if (cnt[p[i].substr(0, 3) + to_string(j)] == 0)
          {
            cnt[p[i]]--;
            cnt[p[i].substr(0, 3) + to_string(j)]++;
            p[i] = p[i].substr(0, 3) + to_string(j);
            break;
          }
      }
    for (i64 i = 0; i < n; i++)
      cout << p[i] << endl;
  }
  return 0;
}
