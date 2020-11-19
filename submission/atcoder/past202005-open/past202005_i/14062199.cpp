// URL: https://atcoder.jp/contests/past202005-open/submissions/14062199
// Date: Sat, 06 Jun 2020 18:05:54 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, Q;
  cin >> N >> Q;
  vector<i64> An(N), Bn(N);
  for (i64 i = 0; i < N; i++)
    An[i] = Bn[i] = i;
  bool sw = false;
  for (i64 i = 0; i < Q; i++)
  {
    i64 t;
    cin >> t;
    if (t == 1)
    {
      i64 A, B;
      cin >> A >> B;
      A--;
      B--;
      if (sw)
        swap(Bn[A], Bn[B]);
      else
        swap(An[A], An[B]);
    }
    if (t == 2)
    {
      i64 A, B;
      cin >> A >> B;
      A--;
      B--;
      if (sw)
        swap(An[A], An[B]);
      else
        swap(Bn[A], Bn[B]);
    }
    if (t == 3)
    {
      sw = !sw;
    }
    else if (t == 4)
    {
      i64 A, B;
      cin >> A >> B;
      A--;
      B--;
      if (sw)
        cout << N * An[B] + Bn[A] << endl;
      else
        cout << N * An[A] + Bn[B] << endl;
    }
  }
  return 0;
}
