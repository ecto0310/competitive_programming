// URL: https://atcoder.jp/contests/abc165/submissions/12791070
// Date: Mon, 04 May 2020 01:21:26 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, M;
  cin >> N >> M;
  vector<pair<i64, i64>> ans;
  if (N % 2 == 1)
  {
    for (i64 l = 1, r = N - 1; l < r; l++, r--)
      ans.push_back({l, r});
  }
  else
  {
    bool f = false;
    for (i64 l = 1, r = N - 1; l < r; l++, r--)
    {
      if (!f && r - l <= N / 2)
      {
        l++;
        f = true;
      }
      ans.push_back({l, r});
    }
  }
  for (i64 i = 0; i < M; i++)
    cout << ans[i].first << " " << ans[i].second << endl;
  return 0;
}
