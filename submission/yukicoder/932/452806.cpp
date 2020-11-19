// URL: https://yukicoder.me/submissions/452806
// Date: Wed, 01 Apr 2020 17:34:17 +0900
// Language: C++14
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string S;
  cin >> S;
  string t = "AC,";
  for (i64 i = 0; i < S.size(); i++)
    if (S[i] != t[i % 3])
    {
      cout << "Failed..." << endl;
      return 0;
    }
  cout << "Done!" << endl;
  return 0;
}
