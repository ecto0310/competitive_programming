// URL: https://atcoder.jp/contests/agc032/submissions/12864272
// Date: Tue, 05 May 2020 22:35:19 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<pair<i64, i64>> ans;
  i64 ng = N;
  if (N % 2 == 1)
    ng--;
  for (i64 i = 1; i <= N; i++)
  {
    for (i64 j = 1; j <= N; j++)
    {
      if (j <= i || j == ng)
        continue;
      ans.push_back({i, j});
    }
    ng--;
  }
  cout << ans.size() << endl;
  for (pair<i64, i64> i : ans)
    cout << i.first << " " << i.second << endl;
  return 0;
}
