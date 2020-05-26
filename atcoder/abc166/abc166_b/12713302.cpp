// URL: https://atcoder.jp/contests/abc166/submissions/12713302
// Date: Sun, 03 May 2020 21:02:28 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, K;
  cin >> N >> K;
  set<i64> s;
  for (i64 i = 0; i < K; i++)
  {
    i64 d;
    cin >> d;
    for (i64 j = 0; j < d; j++)
    {
      i64 A;
      cin >> A;
      s.insert(A);
    }
  }
  cout << N - s.size() << endl;
  return 0;
}
