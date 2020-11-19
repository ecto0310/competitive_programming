// URL: https://yukicoder.me/submissions/402863
// Date: Fri, 29 Nov 2019 23:20:35 +0900
// Language: C++14
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  i64 cnt = n;
  vector<bool> use(n, true);
  for (i64 i = 0; i < n; i++)
  {
    if (cnt < 3)
      continue;
    use[i] = false;
    cnt--;
    cout << "? " << cnt << "\n";
    for (i64 j = 0; j < n; j++)
      if (use[j])
        cout << j + 1 << " ";
    cout << endl;
    i64 r;
    cin >> r;
    if (r == 0)
    {
      use[i] = true;
      cnt++;
    }
  }
  cout << "! " << cnt << "\n";
  for (i64 j = 0; j < n; j++)
    if (use[j])
      cout << j + 1 << " ";
  cout << endl;
  return 0;
}
