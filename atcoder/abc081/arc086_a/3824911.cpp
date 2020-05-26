// URL: https://atcoder.jp/contests/abc081/submissions/3824911
// Date: Thu, 20 Dec 2018 01:03:44 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> cnt(200001);
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    cnt[a]++;
  }
  int ans = 0;
  sort(cnt.begin(), cnt.end(), greater<int>());
  for (int i = k; i < n + 1; i++)
    ans += cnt[i];
  cout << ans << endl;

  return 0;
}
