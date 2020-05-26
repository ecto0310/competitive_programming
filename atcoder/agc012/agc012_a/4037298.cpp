// URL: https://atcoder.jp/contests/agc012/submissions/4037298
// Date: Fri, 18 Jan 2019 22:28:15 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> a(N * 3);
  for (int i = 0; i < N * 3; i++)
    cin >> a[i];
  sort(a.begin(), a.end(), greater<int>());
  long long ans = 0;
  for (int i = 0; i < N; i++)
    ans += a[i * 2 + 1];
  cout << ans << endl;

  return 0;
}
