#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  int T;
  cin >> T;
  for (i64 _ = 1; _ <= T; _++)
  {
    i64 U;
    cin >> U;
    vector<vector<char>> res(10);
    set<char> tt;
    map<char, i64> s3;
    for (i64 i = 0; i < 10000; i++)
    {
      string M, R;
      cin >> M >> R;
      for (char j : R)
        tt.insert(j);
      s3[R[0]]++;
    }
    string ans;
    set<char> use;
    vector<pair<i64, char>> list;
    for (pair<char, i64> i : s3)
    {
      list.push_back({i.second, i.first});
      use.insert(i.first);
    }
    sort(list.rbegin(), list.rend());
    for (pair<i64, char> i : list)
      ans += i.second;
    for (char j : tt)
      if (use.count(j) == 0)
      {
        ans = j + ans;
        break;
      }
    cout << "Case #" << _ << ": " << ans << endl;
  }
  return 0;
}
