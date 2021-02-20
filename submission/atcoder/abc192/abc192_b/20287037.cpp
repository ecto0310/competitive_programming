// URL: https://atcoder.jp/contests/abc192/submissions/20287037
// Date: Sat, 20 Feb 2021 21:03:01 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    string S;
    cin >> S;
    bool ans = true;
    for (i64 i = 0; i < S.size(); i++)
        if ((i % 2 != 0 && 'a' <= S[i] && S[i] <= 'z') || (i % 2 != 1 && 'A' <= S[i] && S[i] <= 'Z'))
            ans = false;
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
