// URL: https://atcoder.jp/contests/agc035/submissions/10484678
// Date: Mon, 02 Mar 2020 15:15:30 +0900
// Language: C++14 (GCC 5.4.1)
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
