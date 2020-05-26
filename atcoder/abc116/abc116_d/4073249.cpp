// URL: https://atcoder.jp/contests/abc116/submissions/4073249
// Date: Wed, 23 Jan 2019 17:38:04 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<pair<int, int>> v;
  for (int i = 0; i < N; i++)
  {
    int t, d;
    cin >> t >> d;
    v.push_back({d, t});
  }
  sort(v.begin(), v.end(), greater<pair<int, int>>());
  map<int, bool> type;
  priority_queue<int, vector<int>, greater<int>> pq;
  long long base = 0;
  for (int i = 0; i < K; i++)
  {
    if (type[v[i].second])
      pq.push(v[i].first);
    base += v[i].first;
    type[v[i].second] = true;
  }
  long long ans = base + (long long)type.size() * (long long)type.size();
  for (int i = K; i < N && pq.size() != 0; i++)
    if (!type[v[i].second])
    {
      base -= pq.top();
      pq.pop();
      type[v[i].second] = true;
      base += v[i].first;
      ans = max(ans, base + (long long)type.size() * (long long)type.size());
    }
  cout << ans << endl;

  return 0;
}
