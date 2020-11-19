// URL: https://atcoder.jp/contests/abc178/submissions/16727714
// Date: Mon, 14 Sep 2020 00:07:55 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

const i64 timeLimit = 1900;

unsigned long xor128()
{
  static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
  unsigned long t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

int main()
{
  i64 N;
  cin >> N;
  vector<i64> A(N), B(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  for (i64 i = 0; i < N; i++)
    cin >> B[i];
  reverse(B.begin(), B.end());
  i64 cnt = 0;
  for (i64 i = 0; i < N; i++)
    if (A[i] == B[i])
      cnt++;
  chrono::system_clock::time_point start = chrono::system_clock::now();
  while (chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - start).count() / 1000 < timeLimit)
  {
    i64 x = xor128() % N, y = xor128() % N;
    if (A[x] == B[y] || A[y] == B[x])
      continue;
    if (A[x] == B[x])
      cnt--;
    if (A[y] == B[y])
      cnt--;
    swap(B[x], B[y]);
    if (cnt == 0)
    {
      cout << "Yes" << endl;
      for (i64 i = 0; i < N; i++)
        cout << B[i] << " "[i + 1 == N];
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
