// URL: https://codingcompetitions.withgoogle.com/codejam/submissions/000000000019fd27/ZWN0bzAzMTA
// Date: Sat, 04 Apr 2020 12:35:36 +0900
// Language: C++14 (G++)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

struct Time
{
  i64 S, E, ind;
  bool operator<(const Time &r) const
  {
    return S < r.S;
  }
};

int main()
{
  i64 T;
  cin >> T;
  for (i64 _ = 1; _ <= T; _++)
  {
    i64 N;
    cin >> N;
    vector<Time> time(N);
    for (i64 i = 0; i < N; i++)
    {
      i64 S, E;
      cin >> S >> E;
      time[i] = {S, E, i};
    }
    sort(time.begin(), time.end());
    string ans = string(N, '-');
    bool imp = false;
    i64 t[2] = {};
    char c[2] = {'C', 'J'};
    for (i64 i = 0; i < N; i++)
    {
      if (t[2] < t[1])
      {
        swap(t[0], t[1]);
        swap(c[0], c[1]);
      }
      for (i64 j = 0; j < 2; j++)
      {
        if (t[j] <= time[i].S)
        {
          t[j] = time[i].E;
          ans[time[i].ind] = c[j];
          break;
        }
      }
      if (ans[time[i].ind] == '-')
        imp = true;
    }
    if (imp)
      cout << "Case #" << _ << ": "
           << "IMPOSSIBLE" << endl;
    else
      cout << "Case #" << _ << ": " << ans << endl;
  }
  return 0;
}
