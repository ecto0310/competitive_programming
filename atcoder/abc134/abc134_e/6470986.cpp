// URL: https://atcoder.jp/contests/abc134/submissions/6470986
// Date: Sat, 20 Jul 2019 22:15:18 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  deque<i64> ans;
  for (i64 i = 0; i < n; i++)
  {
    if (i == 0 || a[i] <= *ans.begin())
      ans.push_front(a[i]);
    else
    {
      i64 it = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
      ans.erase(0 <= it - 1 ? ans.begin() + it - 1 : ans.begin());
      ans.insert(upper_bound(ans.begin(), ans.end(), a[i]), a[i]);
    }
  }
  cout << ans.size() << endl;
  return 0;
}
