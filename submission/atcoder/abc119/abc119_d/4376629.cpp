// URL: https://atcoder.jp/contests/abc119/submissions/4376629
// Date: Sun, 24 Feb 2019 22:35:40 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int A, B, Q;
  cin >> A >> B >> Q;
  vector<long long> s(A), t(B), x(Q);
  for (int i = 0; i < A; i++)
    cin >> s[i];
  for (int i = 0; i < B; i++)
    cin >> t[i];
  for (int i = 0; i < Q; i++)
    cin >> x[i];
  vector<pair<long long, long long>> start(A + B);
  for (int i = 0; i < A; i++)
  {
    int it = lower_bound(t.begin(), t.end(), s[i]) - t.begin();
    long long tmp = 1e18;
    if (0 < it)
      tmp = min(tmp, abs(s[i] - t[it - 1]));
    if (it < B)
      tmp = min(tmp, abs(s[i] - t[it]));
    start[i] = {s[i], tmp};
  }
  for (int i = 0; i < B; i++)
  {
    int it = lower_bound(s.begin(), s.end(), t[i]) - s.begin();
    long long tmp = 1e18;
    if (0 < it)
      tmp = min(tmp, abs(t[i] - s[it - 1]));
    if (it < A)
      tmp = min(tmp, abs(t[i] - s[it]));
    start[A + i] = {t[i], tmp};
  }
  sort(start.begin(), start.end());
  for (int i = 0; i < Q; i++)
  {
    int it = lower_bound(start.begin(), start.end(), pair<long long, long long>(x[i], 0)) - start.begin();
    long long ans = 1e18;
    if (0 < it)
      ans = min(ans, abs(x[i] - start[it - 1].first) + start[it - 1].second);
    if (it < A + B)
      ans = min(ans, abs(x[i] - start[it].first) + start[it].second);
    cout << ans << endl;
  }

  return 0;
}
