// URL: https://atcoder.jp/contests/apc001/submissions/4388223
// Date: Tue, 26 Feb 2019 00:13:03 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> a(N), b(N);
  for (int i = 0; i < N; i++)
    cin >> a[i];
  for (int i = 0; i < N; i++)
    cin >> b[i];
  long long cnt = 0;
  for (int i = 0; i < N; i++)
    if (a[i] < b[i])
      cnt += (b[i] - a[i]) / 2;
    else
      cnt -= a[i] - b[i];
  if (cnt < 0)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;

  return 0;
}
