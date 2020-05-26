// URL: https://atcoder.jp/contests/agc014/submissions/11442173
// Date: Thu, 02 Apr 2020 22:04:00 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, M;
  cin >> N >> M;
  vector<i64> a(M), b(M);
  for (i64 i = 0; i < M; i++)
    cin >> a[i] >> b[i];
  map<i64, i64> m;
  for (i64 i = 0; i < M; i++)
  {
    m[a[i]]++;
    m[b[i]]++;
  }
  for (pair<i64, i64> i : m)
    if (i.second % 2 == 1)
    {
      cout << "NO" << endl;
      return 0;
    }
  cout << "YES" << endl;
  return 0;
}
