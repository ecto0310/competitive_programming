// URL: https://codingcompetitions.withgoogle.com/codejam/submissions/000000000019fd74/ZWN0bzAzMTA
// Date: Sat, 11 Apr 2020 11:52:41 +0900
// Language: C++14 (G++)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 T;
  cin >> T;
  for (i64 _ = 1; _ <= T; _++)
  {
    i64 N;
    cin >> N;
    cout << "Case #" << _ << ":" << endl;
    for (i64 i = 0; i <= 31; i++)
    {
      i64 t = N - i;
      i64 last = -1;
      i64 cnt = 0;
      for (i64 j = 31; 0 <= j; j--)
      {
        if (t & (1LL << j))
        {
          last = max(last, j);
        }
        if (last != -1 && !(t & (1LL << j)))
        {
          cnt++;
        }
      }
      if (cnt <= i)
      {
        cout << "1 1" << endl;
        i64 now = 1;
        bool left = true;
        for (i64 j = 1; j <= last; j++)
        {
          if (t & (1LL << j))
          {
            for (i64 k = 0; k < j + 1; k++)
              cout << j + 1 << " " << (left ? k + 1 : j + 1 - k) << endl;
            left = !left;
            now += (1LL << j);
          }
          else
          {
            cout << j + 1 << " " << (left ? 1 : j + 1) << endl;
            now++;
          }
        }
        for (; now + 1 <= N; last++)
        {
          cout << last + 2 << " " << (left ? 1 : last + 2) << endl;
          now++;
        }
        break;
      }
    }
  }
  return 0;
}
