// URL: https://atcoder.jp/contests/tkppc3/submissions/6546446
// Date: Fri, 26 Jul 2019 23:50:38 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  string n;
  cin >> n;
  i64 sum = 0, size = n.size();
  for (i64 i = 0; i < size; i++)
    sum += n[i] - '0';
  if (sum % 3 == 0 && (n[n.size() - 1] - '0') % 2 == 0)
    cout << "yES" << endl;
  else
    cout << "nO" << endl;
  sum = 0;
  for (i64 i = 0; i < size; i++)
    sum += (n[i] - '0') * (i % 2 == 0 ? -1 : 1);
  if (sum == 0)
    cout << "yES" << endl;
  else
    cout << "nO" << endl;
  return 0;
}
