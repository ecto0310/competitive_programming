// URL: https://atcoder.jp/contests/agc035/submissions/15484159
// Date: Mon, 27 Jul 2020 15:42:57 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 N;
  cin >> N;
  vector<i64> a(N);
  for (i64 i = 0; i < N; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  if (a[N - 1] == 0)
    cout << "Yes" << endl;
  else if (N % 3 == 0)
  {
    if (a[0] == 0 && a[N / 3 - 1] == 0 && a[N / 3] == a[N - 1])
      cout << "Yes" << endl;
    else if (a[0] == a[N / 3 - 1] && a[N / 3] == a[2 * N / 3 - 1] && a[2 * N / 3] == a[N - 1] && (a[0] ^ a[N / 3] ^ a[2 * N / 3]) == 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  else
    cout << "No" << endl;
  return 0;
}
