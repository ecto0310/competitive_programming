// URL: https://atcoder.jp/contests/s8pc-6/submissions/4978123
// Date: Sun, 14 Apr 2019 22:41:43 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 q;
  cin >> q;
  vector<i64> k(q);
  for (i64 i = 0; i < q; i++)
    cin >> k[i];
  for (i64 i = 0; i < q; i++)
  {
    i64 tmp = k[i], cnt = 0;
    while (tmp)
    {
      tmp /= 2;
      cnt++;
    }
    deque<i64> deq;
    i64 now = 1, t = 0;
    for (int j = cnt - 2; j >= 0; j--)
    {
      deq.push_back(t);
      now *= 2;
      t++;
      if ((now + 1) << j <= k[i])
      {
        deq.push_front(t);
        now++;
        t++;
      }
    }
    cout << deq.size() << (deq.size() == 0 ? "" : " ");
    for (i64 j = 0; j < deq.size(); j++)
      cout << deq[j] << (j + 1 == deq.size() ? "" : " ");
    cout << endl;
  }
  return 0;
}
