// URL: https://yukicoder.me/submissions/402190
// Date: Fri, 29 Nov 2019 21:50:55 +0900
// Language: C++14
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  if (regex_match(s, regex("AC(,AC)*")))
    cout << "Done!" << endl;
  else
    cout << "Failed..." << endl;
  return 0;
}
