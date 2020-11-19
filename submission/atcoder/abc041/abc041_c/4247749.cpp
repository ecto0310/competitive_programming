// URL: https://atcoder.jp/contests/abc041/submissions/4247749
// Date: Wed, 13 Feb 2019 01:15:16 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<pair<int, int>> a(N);
  for (int i = 0; i < N; i++)
  {
    int tmp;
    cin >> tmp;
    a[i] = {tmp, i + 1};
  }
  sort(a.begin(), a.end(), greater<pair<int, int>>());
  for (int i = 0; i < N; i++)
    cout << a[i].second << endl;

  return 0;
}
