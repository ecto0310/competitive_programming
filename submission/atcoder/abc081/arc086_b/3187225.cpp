// URL: https://atcoder.jp/contests/abc081/submissions/3187225
// Date: Fri, 14 Sep 2018 02:58:12 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cout << 2 * n - 1 << endl;
  if (abs(*max_element(a.begin(), a.end())) < abs(*min_element(a.begin(), a.end())))
  {
    int pos = min_element(a.begin(), a.end()) - a.begin() + 1;
    for (int i = 1; i <= n; i++)
      cout << pos << " " << i << endl;
    for (int i = n; i > 1; i--)
      cout << i << " " << i - 1 << endl;
  }
  else
  {
    int pos = max_element(a.begin(), a.end()) - a.begin() + 1;
    for (int i = 1; i <= n; i++)
      cout << pos << " " << i << endl;
    for (int i = 1; i < n; i++)
      cout << i << " " << i+1 << endl;
  }

  return 0;
}
