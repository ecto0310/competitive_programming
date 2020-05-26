// URL: https://atcoder.jp/contests/arc073/submissions/3872695
// Date: Tue, 25 Dec 2018 22:38:25 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  long long N, W;
  cin >> N >> W;
  vector<long long> o[4];
  int cnt = 0;
  map<long long, long long> m1, m2;
  for (int i = 0; i < N; i++)
  {
    int w, v;
    cin >> w >> v;
    if (m1.count(w) == 0)
    {
      o[cnt].push_back(v);
      m1[w] = cnt;
      m2[cnt] = w;
      cnt++;
    }
    else
      o[m1[w]].push_back(v);
  }
  sort(o[0].begin(), o[0].end(), greater<long long>());
  sort(o[1].begin(), o[1].end(), greater<long long>());
  sort(o[2].begin(), o[2].end(), greater<long long>());
  sort(o[3].begin(), o[3].end(), greater<long long>());
  long long ans = 0;
  for (int i = 0; i <= o[0].size(); i++)
    for (int j = 0; j <= o[1].size(); j++)
      for (int k = 0; k <= o[2].size(); k++)
        for (int l = 0; l <= o[3].size(); l++)
        {
          if (W < m2[0] * i + m2[1] * j + m2[2] * k + m2[3] * l)
            continue;
          long long tmp = 0;
          for (int t = 0; t < i; t++)
            tmp += o[0][t];
          for (int t = 0; t < j; t++)
            tmp += o[1][t];
          for (int t = 0; t < k; t++)
            tmp += o[2][t];
          for (int t = 0; t < l; t++)
            tmp += o[3][t];
          ans = max(ans, tmp);
        }
  cout << ans << endl;

  return 0;
}
