// URL: https://atcoder.jp/contests/abc094/submissions/4632710
// Date: Tue, 19 Mar 2019 20:38:04 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++)
    cin >> x[i];
  vector<int> s = x;
  sort(s.begin(), s.end());
  for (int i = 0; i < n; i++)
    if (x[i] < s[(n + 1) / 2])
      cout << s[(n + 1) / 2] << endl;
    else
      cout << s[(n + 1) / 2 - 1] << endl;

  return 0;
}
