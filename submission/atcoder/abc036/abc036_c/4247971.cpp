// URL: https://atcoder.jp/contests/abc036/submissions/4247971
// Date: Wed, 13 Feb 2019 02:01:15 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++)
    cin >> a[i];
  vector<int> v = a;
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  map<int, int> key;
  for (int i = 0; i < v.size(); i++)
    key[v[i]] = i;
  for (int i = 0; i < N; i++)
    cout << key[a[i]] << endl;

  return 0;
}
