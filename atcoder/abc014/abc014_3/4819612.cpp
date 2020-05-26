// URL: https://atcoder.jp/contests/abc014/submissions/4819612
// Date: Thu, 04 Apr 2019 11:51:12 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> cnt(1e6 + 1);
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    cnt[a]++;
    cnt[b + 1]--;
  }
  int ans = 0;
  for (int i = 0; i <= 1e6; i++)
  {
    if (i != 0)
      cnt[i] += cnt[i - 1];
    ans = max(ans, cnt[i]);
  }
  cout << ans << endl;

  return 0;
}
