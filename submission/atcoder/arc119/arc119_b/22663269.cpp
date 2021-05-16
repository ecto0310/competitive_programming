// URL: https://atcoder.jp/contests/arc119/submissions/22663269
// Date: Sun, 16 May 2021 21:10:26 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 N;
    string S, T;
    cin >> N >> S >> T;
    i64 cntS[2] = {}, cntT[2] = {};
    for (i64 i = 0; i < N; i++) {
        cntS[S[i] - '0']++;
        cntT[T[i] - '0']++;
    }
    if (cntS[0] != cntT[0] || cntT[1] != cntS[1]) {
        cout << "-1" << endl;
        return 0;
    }
    vector<i64> posS, posT;
    for (i64 i = 0; i < N; i++) {
        if (S[i] == '0') {
            posS.push_back(i);
        }
        if (T[i] == '0') {
            posT.push_back(i);
        }
    }
    i64 ans = 0;
    for (i64 i = 0; i < posS.size(); i++) {
        if (posS[i] != posT[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
