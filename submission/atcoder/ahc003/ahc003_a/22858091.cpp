// URL: https://atcoder.jp/contests/ahc003/submissions/22858091
// Date: Sun, 23 May 2021 16:53:16 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 N = 1000, G = 30;

struct Node {
    //0:up 1:right 2:down 3:left
    double cost[4] = {4500, 4500, 4500, 4500};
    i64 cnt[4];
};

i64 dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

Node node[G][G];

int main() {
    for (i64 turn = 1; turn <= N; turn++) {
        i64 s[2], t[2];
        cin >> s[0] >> s[1] >> t[0] >> t[1];
        vector<vector<i64>> cost(G, vector<i64>(G, 1e9));
        vector<vector<pair<i64, i64>>> bef(G, vector<pair<i64, i64>>(G, {-1, -1}));
        cost[s[0]][s[1]] = 0;
        priority_queue<tuple<i64, i64, i64>, vector<tuple<i64, i64, i64>>, greater<tuple<i64, i64, i64>>> que;
        que.push({0, s[0], s[1]});
        while (que.size()) {
            auto[c, x, y] = que.top();
            que.pop();
            if (cost[x][y] < c) {
                continue;
            }
            for (i64 i = 0; i < 4; i++) {
                i64 ddx = x + dx[i], ddy = y + dy[i];
                if (ddx < 0 || G <= ddx || ddy < 0 || G <= ddy) {
                    continue;
                }
                i64 randCost = node[x][y].cost[i] * ((double) (rand() % 20) / 100 + 0.9) * pow(((double) turn / N), 2);
                if (cost[x][y] + randCost < cost[ddx][ddy]) {
                    cost[ddx][ddy] = cost[x][y] + randCost;
                    bef[ddx][ddy] = {x, y};
                    que.push({cost[ddx][ddy], ddx, ddy});
                }
            }
        }
        string ans;
        int nowX = t[0], nowY = t[1];
        while (nowX != s[0] || nowY != s[1]) {
            if (nowX - 1 == bef[nowX][nowY].first) {
                ans += "D";
                nowX--;
            } else if (nowX + 1 == bef[nowX][nowY].first) {
                ans += "U";
                nowX++;
            } else if (nowY - 1 == bef[nowX][nowY].second) {
                ans += "R";
                nowY--;
            } else if (nowY + 1 == bef[nowX][nowY].second) {
                ans += "L";
                nowY++;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
        double length;
        cin >> length;
        length /= ans.size();
        for (char i:ans) {
            if (i == 'D') {
                node[nowX][nowY].cost[3] *= node[nowX][nowY].cnt[3];
                node[nowX][nowY].cost[3] += length;
                node[nowX][nowY].cnt[3]++;
                node[nowX][nowY].cost[3] /= node[nowX][nowY].cnt[3];
                nowX++;
                node[nowX][nowY].cost[1] *= node[nowX][nowY].cnt[1];
                node[nowX][nowY].cost[1] += length;
                node[nowX][nowY].cnt[1]++;
                node[nowX][nowY].cost[1] /= node[nowX][nowY].cnt[1];
            } else if (i == 'U') {
                node[nowX][nowY].cost[1] *= node[nowX][nowY].cnt[1];
                node[nowX][nowY].cost[1] += length;
                node[nowX][nowY].cnt[1]++;
                node[nowX][nowY].cost[1] /= node[nowX][nowY].cnt[1];
                nowX--;
                node[nowX][nowY].cost[3] *= node[nowX][nowY].cnt[3];
                node[nowX][nowY].cost[3] += length;
                node[nowX][nowY].cnt[3]++;
                node[nowX][nowY].cost[3] /= node[nowX][nowY].cnt[3];
            } else if (i == 'R') {
                node[nowX][nowY].cost[0] *= node[nowX][nowY].cnt[0];
                node[nowX][nowY].cost[0] += length;
                node[nowX][nowY].cnt[0]++;
                node[nowX][nowY].cost[0] /= node[nowX][nowY].cnt[0];
                nowY++;
                node[nowX][nowY].cost[2] *= node[nowX][nowY].cnt[2];
                node[nowX][nowY].cost[2] += length;
                node[nowX][nowY].cnt[2]++;
                node[nowX][nowY].cost[2] /= node[nowX][nowY].cnt[2];
            } else if (i == 'L') {
                node[nowX][nowY].cost[2] *= node[nowX][nowY].cnt[2];
                node[nowX][nowY].cost[2] += length;
                node[nowX][nowY].cnt[2]++;
                node[nowX][nowY].cost[2] /= node[nowX][nowY].cnt[2];
                nowY--;
                node[nowX][nowY].cost[0] *= node[nowX][nowY].cnt[0];
                node[nowX][nowY].cost[0] += length;
                node[nowX][nowY].cnt[0]++;
                node[nowX][nowY].cost[0] /= node[nowX][nowY].cnt[0];
            }
        }
    }
    return 0;
}
