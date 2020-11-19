// URL: https://atcoder.jp/contests/cf17-final-open/submissions/8564744
// Date: Sat, 23 Nov 2019 11:40:59 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

string need[16] = {"AKIHABARA", "AKIHABAR", "AKIHABRA", "AKIHBARA", "KIHABARA", "AKIHABR", "AKIHBAR", "KIHABAR", "AKIHBRA", "KIHABRA", "KIHBARA", "AKIHBR", "KIHBAR", "KIHBRA", "KIHABR", "KIHBR"};

int main()
{
  string s;
  cin >> s;
  for (i64 i = 0; i < 16; i++)
    if (s == need[i])
    {
      cout << "YES" << endl;
      return 0;
    }
  cout << "NO" << endl;
  return 0;
}
