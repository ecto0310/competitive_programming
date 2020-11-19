// URL: https://atcoder.jp/contests/abc159/submissions/11101731
// Date: Sun, 22 Mar 2020 21:20:46 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string S;
  cin >> S;
  i64 size = S.size();
  for (i64 i = 0; i < size / 2; i++)
    if (S[i] != S[size - i - 1])
    {
      cout << "No" << endl;
      return 0;
    }
  for (i64 i = 0; i < size / 4; i++)
    if (S[i] != S[size / 2 - i - 1])
    {
      cout << "No" << endl;
      return 0;
    }
  for (i64 i = 0; i < size / 4; i++)
    if (S[i + size / 2 + 1] != S[size - i - 1])
    {
      cout << "No" << endl;
      return 0;
    }
  cout << "Yes" << endl;
  return 0;
}
