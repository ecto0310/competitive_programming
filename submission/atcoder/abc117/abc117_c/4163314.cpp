// URL: https://atcoder.jp/contests/abc117/submissions/4163314
// Date: Sun, 03 Feb 2019 22:08:50 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> X(M);
  for (int i = 0; i < M; i++)
    cin >> X[i];
  if (M <= N)
  {
    cout << 0 << endl;
    return 0;
  }
  sort(X.begin(), X.end());
  vector<int> dif(M - 1);
  for (int i = 0; i < M - 1; i++)
    dif[i] = X[i + 1] - X[i];
  sort(dif.begin(), dif.end());
  long long ans = 0;
  for (int i = 0; i < max(0, M - N); i++)
    ans += dif[i];
  cout << ans << endl;

  return 0;
}
