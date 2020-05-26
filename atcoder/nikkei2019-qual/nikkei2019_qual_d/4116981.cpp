// URL: https://atcoder.jp/contests/nikkei2019-qual/submissions/4116981
// Date: Mon, 28 Jan 2019 21:25:36 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> edge[N], incnt(N);
  vector<bool> root(N, true);
  for (int i = 0; i < N + M - 1; i++)
  {
    int A, B;
    cin >> A >> B;
    edge[A - 1].push_back(B - 1);
    root[B - 1] = false;
    incnt[B - 1]++;
  }
  vector<long long> far(N, -1);
  vector<int> ans(N);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> que;
  for (int i = 0; i < N; i++)
    if (root[i])
    {
      que.push({0, i});
      ans[i] = 0;
      far[i] = 0;
      break;
    }
  while (que.size())
  {
    pair<long long, int> p = que.top();
    que.pop();
    for (int t : edge[p.second])
    {
      incnt[t]--;
      if (incnt[t] == 0)
      {
        far[t] = far[p.second] + 1;
        que.push({far[t], t});
        ans[t] = p.second + 1;
      }
    }
  }
  for (int t : ans)
    cout << t << endl;

  return 0;
}
