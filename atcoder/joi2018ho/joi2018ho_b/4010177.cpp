// URL: https://atcoder.jp/contests/joi2018ho/submissions/4010177
// Date: Mon, 14 Jan 2019 00:21:28 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<pair<long long, long long>> vec(N);
  for (int i = 0; i < N; i++)
  {
    long long A, B;
    cin >> A >> B;
    vec[i] = {A, B};
  }
  sort(vec.begin(), vec.end());
  long long ans = 0, sum = 0, m = 0;
  for (int i = 0; i < N; i++)
  {
    m = min(m, sum - vec[i].first);
    sum += vec[i].second;
    ans = max(ans, sum - vec[i].first - m);
  }
  cout << ans << endl;

  return 0;
}
