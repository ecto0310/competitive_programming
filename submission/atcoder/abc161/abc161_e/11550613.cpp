// URL: https://atcoder.jp/contests/abc161/submissions/11550613
// Date: Sat, 04 Apr 2020 23:16:21 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, K, C;
  string S;
  cin >> N >> K >> C >> S;
  vector<i64> w;
  for (i64 i = N - 1; 0 <= i; i--)
    if (w.size() < K && S[i] == 'o')
    {
      w.push_back(i);
      i -= C;
    }
  i64 cnt = 0;
  for (i64 i = 0; i < N; i++)
    if (cnt < K && S[i] == 'o')
    {
      if (w[K - cnt - 1] == i)
        cout << i + 1 << endl;
      cnt++;
      i += C;
    }
  return 0;
}
