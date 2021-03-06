// URL: https://atcoder.jp/contests/abc194/submissions/20716150
// Date: Sat, 06 Mar 2021 21:51:09 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 N, M;
    cin >> N >> M;
    vector<i64> A(N);
    for (i64 i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<vector<i64>> idx(N, vector<i64>{-1});
    for (i64 i = 0; i < N; i++) {
        idx[A[i]].push_back(i);
    }
    for (i64 i = 0; i < N; i++) {
        idx[i].push_back(N);
        for (i64 j = 0; j < idx[i].size() - 1; j++) {
            if (M <= idx[i][j + 1] - idx[i][j] - 1) {
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << N << endl;
    return 0;
}
