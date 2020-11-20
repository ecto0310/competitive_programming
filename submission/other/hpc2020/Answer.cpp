#include <vector>
#include <queue>
#include <cmath>
 
#include "Answer.hpp"
 
namespace hpc
{
    /**
     * 値を範囲内に収める
     * @param val 収める値
     * @param l 最小値
     * @param h 最大値
     * @return 収めた値
     * */
    template <typename T>
    constexpr const T &
    clamp(const T &val, const T &l, const T &h)
    {
        return (val < l) ? l : (h < val) ? h : val;
    }
 
    /**
     * Vector2用の等価演算子
     * @param l 現在のステージ
     * @param r 現在のステージ
     * @return 等価か否か
     * */
    bool equal(Vector2 l, Vector2 r)
    {
        return (l.x == r.x && l.y == r.y);
    }
 
    // 各巻物からの距離データ[scroll][y][x]
    std::vector<std::vector<std::vector<int>>> distance;
    //移動処理用変数
    const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
 
    /**
     * 巻物からの距離データ取得
     * (着地地形によって(11-10*倍率)のコスト)
     * @param aStage 現在のステージ
     * */
    void getDistance(const Stage &aStage)
    {
        distance = std::vector<std::vector<std::vector<int>>>(Parameter::MaxScrollCount, std::vector<std::vector<int>>(Parameter::StageHeight, std::vector<int>(Parameter::StageWidth, 1e9)));
        for (int _ = 0; _ < aStage.scrolls().count(); _++)
        {
            Scroll scroll = aStage.scrolls()[_];
            //{距離,{y,x}}
            std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<std::pair<int, std::pair<int, int>>>> que;
            que.push({0, {scroll.pos().y, scroll.pos().x}});
            distance[_][scroll.pos().y][scroll.pos().x] = 0;
            while (que.size())
            {
                std::pair<int, std::pair<int, int>> p = que.top();
                que.pop();
                if (distance[_][p.second.first][p.second.second] < p.first)
                    continue;
                int y = p.second.first, x = p.second.second;
                for (int d = 1; d <= aStage.rabbit().power(); d++)
                    for (int i = 0; i < 8; i++)
                    {
                        int ddy = y + dy[i] * d, ddx = x + dx[i] * d;
                        //移動可能な距離か確認
                        if (aStage.rabbit().power() < hypot(dy[i] * d, dx[i] * d))
                            continue;
                        //グリッド内か確認
                        if (ddx < 0 || 50 <= ddx || ddy < 0 || 50 <= ddy)
                            continue;
                        int cost = distance[_][y][x] + (11 - 10 * Parameter::JumpTerrianCoefficient[(int)aStage.terrain({(float)ddx, (float)ddy})]);
                        if (cost < distance[_][ddy][ddx])
                        {
                            distance[_][ddy][ddx] = cost;
                            que.push({cost, {ddy, ddx}});
                        }
                    }
            }
        }
        return;
    }
 
    /**
     * 現在地から一番近い巻物を走査
     * @param aStage 現在のステージ
     * @return 一番近い巻物のid
     * */
    int searchScroll(const Stage &aStage)
    {
        int ret = 0;
        int minDis = 1e9;
        for (int i = 0; i < aStage.scrolls().count(); i++)
        {
            if (!aStage.scrolls()[i].isGotten())
            {
                //コストが最小(周り道)
                if (distance[i][aStage.rabbit().pos().y][aStage.rabbit().pos().x] < minDis)
                {
                    minDis = distance[i][aStage.rabbit().pos().y][aStage.rabbit().pos().x];
                    ret = i;
                }
                // シュミレーションした最短(直進)
                {
                    int cnt = 0;
                    Vector2 now = aStage.rabbit().pos();
                    while (!equal(aStage.scrolls()[i].pos(), now) && cnt < 1000)
                    {
                        //移動先一覧
                        Vector2 targetLists[] = {
                            aStage.scrolls()[i].pos(),
                            Vector2(now.x, aStage.scrolls()[i].pos().y),
                            Vector2(aStage.scrolls()[i].pos().x, now.y),
                            Vector2(clamp(now.x + 6, 0.0f, 49.9f), aStage.scrolls()[i].pos().y),
                            Vector2(clamp(now.x - 6, 0.0f, 49.9f), aStage.scrolls()[i].pos().y),
                            Vector2(aStage.scrolls()[i].pos().x, clamp(now.y + 6, 0.0f, 49.9f)),
                            Vector2(aStage.scrolls()[i].pos().x, clamp(now.y - 6, 0.0f, 49.9f)),
                            Vector2(clamp(now.x + 6, 0.0f, 49.9f), clamp(now.y + 6, 0.0f, 49.9f)),
                            Vector2(clamp(now.x - 6, 0.0f, 49.9f), clamp(now.y - 6, 0.0f, 49.9f)),
                            Vector2(clamp(now.x + 6, 0.0f, 49.9f), clamp(now.y - 6, 0.0f, 49.9f)),
                            Vector2(clamp(now.x - 6, 0.0f, 49.9f), clamp(now.y + 6, 0.0f, 49.9f)),
                            Vector2(clamp(now.x + 5, 0.0f, 49.9f), aStage.scrolls()[i].pos().y),
                            Vector2(clamp(now.x - 5, 0.0f, 49.9f), aStage.scrolls()[i].pos().y),
                            Vector2(aStage.scrolls()[i].pos().x, clamp(now.y + 5, 0.0f, 49.9f)),
                            Vector2(aStage.scrolls()[i].pos().x, clamp(now.y - 5, 0.0f, 49.9f)),
                            Vector2(clamp(now.x + 5, 0.0f, 49.9f), clamp(now.y + 5, 0.0f, 49.9f)),
                            Vector2(clamp(now.x - 5, 0.0f, 49.9f), clamp(now.y - 5, 0.0f, 49.9f)),
                            Vector2(clamp(now.x + 5, 0.0f, 49.9f), clamp(now.y - 5, 0.0f, 49.9f)),
                            Vector2(clamp(now.x - 5, 0.0f, 49.9f), clamp(now.y + 5, 0.0f, 49.9f)),
                            Vector2(clamp(now.x + 2, 0.0f, 49.9f), aStage.scrolls()[i].pos().y),
                            Vector2(clamp(now.x - 2, 0.0f, 49.9f), aStage.scrolls()[i].pos().y),
                            Vector2(aStage.scrolls()[i].pos().x, clamp(now.y + 2, 0.0f, 49.9f)),
                            Vector2(aStage.scrolls()[i].pos().x, clamp(now.y - 2, 0.0f, 49.9f)),
                            Vector2(clamp(now.x + 2, 0.0f, 49.9f), clamp(now.y + 2, 0.0f, 49.9f)),
                            Vector2(clamp(now.x - 2, 0.0f, 49.9f), clamp(now.y - 2, 0.0f, 49.9f)),
                            Vector2(clamp(now.x + 2, 0.0f, 49.9f), clamp(now.y - 2, 0.0f, 49.9f)),
                            Vector2(clamp(now.x - 2, 0.0f, 49.9f), clamp(now.y + 2, 0.0f, 49.9f)),
                            Vector2(clamp(now.x + 1, 0.0f, 49.9f), aStage.scrolls()[i].pos().y),
                            Vector2(clamp(now.x - 1, 0.0f, 49.9f), aStage.scrolls()[i].pos().y),
                            Vector2(aStage.scrolls()[i].pos().x, clamp(now.y + 1, 0.0f, 49.9f)),
                            Vector2(aStage.scrolls()[i].pos().x, clamp(now.y - 1, 0.0f, 49.9f)),
                            Vector2(clamp(now.x + 1, 0.0f, 49.9f), clamp(now.y + 1, 0.0f, 49.9f)),
                            Vector2(clamp(now.x - 1, 0.0f, 49.9f), clamp(now.y - 1, 0.0f, 49.9f)),
                            Vector2(clamp(now.x + 1, 0.0f, 49.9f), clamp(now.y - 1, 0.0f, 49.9f)),
                            Vector2(clamp(now.x - 1, 0.0f, 49.9f), clamp(now.y + 1, 0.0f, 49.9f)),
                        };
                        double fmm = 1e9;
                        Vector2 tnow = targetLists[0];
                        for (int j = 0; j < 35; j++)
                        {
                            Vector2 nt = aStage.getNextPos(now, aStage.rabbit().power(), targetLists[j]);
                            if (nt.x == now.x && nt.y == now.y)
                                continue;
                            double dbx = aStage.scrolls()[i].pos().x - now.x, dby = aStage.scrolls()[i].pos().y - now.y;
                            double ddx = nt.x - aStage.scrolls()[i].pos().x, ddy = nt.y - aStage.scrolls()[i].pos().y;
                            if (std::sqrt(dbx * dbx + dby * dby) < std::sqrt(ddx * ddx + ddy * ddy))
                                continue;
                            double far = std::sqrt(ddx * ddx + ddy * ddy) * (1.5 - Parameter::JumpTerrianCoefficient[(int)aStage.terrain(nt)]);
                            if (far < fmm)
                            {
                                fmm = far;
                                tnow = nt;
                            }
                        }
                        now = tnow;
                        cnt++;
                    }
                    if (cnt * 1.1 <= minDis)
                    {
                        minDis = cnt;
                        ret = i;
                    }
                }
            }
        }
        return ret;
    }
 
    /**
     * 特定の巻物への移動に最適な次手順を走査
     * @param target 目標の巻物のid
     * @param aStage 現在のステージ
     * @return 次の移動手順
     * */
    Vector2 searchMove(int target, const Stage &aStage)
    {
        Vector2 ret = aStage.scrolls()[target].pos();
        int minDis = distance[target][aStage.rabbit().pos().y][aStage.rabbit().pos().x];
        int y = aStage.rabbit().pos().y, x = aStage.rabbit().pos().x;
        //コストの減少が最大(周り道)
        for (int d = 1; d <= aStage.rabbit().power(); d++)
            for (int i = 0; i < 8; i++)
            {
                int targetY = y + dy[i] * d, targetX = x + dx[i] * d;
                if (targetX < 0 || 50 <= targetX || targetY < 0 || 50 <= targetY)
                    continue;
                Vector2 dd = aStage.getNextPos({aStage.rabbit().pos().x, aStage.rabbit().pos().y}, aStage.rabbit().power(), {(float)targetX, (float)targetY});
                if (dd.x < 0 || 50 <= dd.x || dd.y < 0 || 50 <= dd.y)
                    continue;
                int dis = distance[target][targetY][targetX];
                if (dis < minDis)
                {
                    minDis = dis;
                    ret = {(float)targetX + 0.5f, (float)targetY + 0.5f};
                }
            }
        // シュミレーションした最短(直進)
        {
            int cnt = 0;
            Vector2 aNext = aStage.scrolls()[target].pos();
            Vector2 now = aStage.rabbit().pos();
            while (!equal(aStage.scrolls()[target].pos(), now) && cnt < 1000)
            {
                //移動先一覧
                Vector2 targetLists[] = {
                    aStage.scrolls()[target].pos(),
                    Vector2(now.x, aStage.scrolls()[target].pos().y),
                    Vector2(aStage.scrolls()[target].pos().x, now.y),
                    Vector2(clamp(now.x + 6, 0.0f, 49.9f), aStage.scrolls()[target].pos().y),
                    Vector2(clamp(now.x - 6, 0.0f, 49.9f), aStage.scrolls()[target].pos().y),
                    Vector2(aStage.scrolls()[target].pos().x, clamp(now.y + 6, 0.0f, 49.9f)),
                    Vector2(aStage.scrolls()[target].pos().x, clamp(now.y - 6, 0.0f, 49.9f)),
                    Vector2(clamp(now.x + 6, 0.0f, 49.9f), clamp(now.y + 6, 0.0f, 49.9f)),
                    Vector2(clamp(now.x - 6, 0.0f, 49.9f), clamp(now.y - 6, 0.0f, 49.9f)),
                    Vector2(clamp(now.x + 6, 0.0f, 49.9f), clamp(now.y - 6, 0.0f, 49.9f)),
                    Vector2(clamp(now.x - 6, 0.0f, 49.9f), clamp(now.y + 6, 0.0f, 49.9f)),
                    Vector2(clamp(now.x + 5, 0.0f, 49.9f), aStage.scrolls()[target].pos().y),
                    Vector2(clamp(now.x - 5, 0.0f, 49.9f), aStage.scrolls()[target].pos().y),
                    Vector2(aStage.scrolls()[target].pos().x, clamp(now.y + 5, 0.0f, 49.9f)),
                    Vector2(aStage.scrolls()[target].pos().x, clamp(now.y - 5, 0.0f, 49.9f)),
                    Vector2(clamp(now.x + 5, 0.0f, 49.9f), clamp(now.y + 5, 0.0f, 49.9f)),
                    Vector2(clamp(now.x - 5, 0.0f, 49.9f), clamp(now.y - 5, 0.0f, 49.9f)),
                    Vector2(clamp(now.x + 5, 0.0f, 49.9f), clamp(now.y - 5, 0.0f, 49.9f)),
                    Vector2(clamp(now.x - 5, 0.0f, 49.9f), clamp(now.y + 5, 0.0f, 49.9f)),
                    Vector2(clamp(now.x + 2, 0.0f, 49.9f), aStage.scrolls()[target].pos().y),
                    Vector2(clamp(now.x - 2, 0.0f, 49.9f), aStage.scrolls()[target].pos().y),
                    Vector2(aStage.scrolls()[target].pos().x, clamp(now.y + 2, 0.0f, 49.9f)),
                    Vector2(aStage.scrolls()[target].pos().x, clamp(now.y - 2, 0.0f, 49.9f)),
                    Vector2(clamp(now.x + 2, 0.0f, 49.9f), clamp(now.y + 2, 0.0f, 49.9f)),
                    Vector2(clamp(now.x - 2, 0.0f, 49.9f), clamp(now.y - 2, 0.0f, 49.9f)),
                    Vector2(clamp(now.x + 2, 0.0f, 49.9f), clamp(now.y - 2, 0.0f, 49.9f)),
                    Vector2(clamp(now.x - 2, 0.0f, 49.9f), clamp(now.y + 2, 0.0f, 49.9f)),
                    Vector2(clamp(now.x + 1, 0.0f, 49.9f), aStage.scrolls()[target].pos().y),
                    Vector2(clamp(now.x - 1, 0.0f, 49.9f), aStage.scrolls()[target].pos().y),
                    Vector2(aStage.scrolls()[target].pos().x, clamp(now.y + 1, 0.0f, 49.9f)),
                    Vector2(aStage.scrolls()[target].pos().x, clamp(now.y - 1, 0.0f, 49.9f)),
                    Vector2(clamp(now.x + 1, 0.0f, 49.9f), clamp(now.y + 1, 0.0f, 49.9f)),
                    Vector2(clamp(now.x - 1, 0.0f, 49.9f), clamp(now.y - 1, 0.0f, 49.9f)),
                    Vector2(clamp(now.x + 1, 0.0f, 49.9f), clamp(now.y - 1, 0.0f, 49.9f)),
                    Vector2(clamp(now.x - 1, 0.0f, 49.9f), clamp(now.y + 1, 0.0f, 49.9f)),
                };
                double fmm = 1e9;
                Vector2 tnow = targetLists[0];
                for (int j = 0; j < 35; j++)
                {
                    Vector2 nt = aStage.getNextPos(now, aStage.rabbit().power(), targetLists[j]);
                    if (nt.x == now.x && nt.y == now.y)
                        continue;
                    double dbx = aStage.scrolls()[target].pos().x - now.x, dby = aStage.scrolls()[target].pos().y - now.y;
                    double ddx = nt.x - aStage.scrolls()[target].pos().x, ddy = nt.y - aStage.scrolls()[target].pos().y;
                    if (std::sqrt(dbx * dbx + dby * dby) < std::sqrt(ddx * ddx + ddy * ddy))
                        continue;
                    double far = std::sqrt(ddx * ddx + ddy * ddy) * (1.5 - Parameter::JumpTerrianCoefficient[(int)aStage.terrain(nt)]);
                    if (far < fmm)
                    {
                        fmm = far;
                        tnow = nt;
                    }
                }
                now = tnow;
                if (cnt == 0)
                    aNext = now;
                cnt++;
            }
            if (cnt * 1.1 <= distance[target][aStage.rabbit().pos().y][aStage.rabbit().pos().x])
                ret = aNext;
        }
        return ret;
    }
 
    /**
     * 最初のステージ開始前の処理
     * */
    Answer::Answer()
    {
    }
 
    /**
     * 最後のステージ終了後の処理
     * */
    Answer::~Answer()
    {
    }
 
    /**
     * 各ステージ開始前の処理
     * @param aStage 現在のステージ
     * */
    void Answer::initialize(const Stage &aStage)
    {
        getDistance(aStage);
    }
 
    /**
     * 毎ターンの処理
     * @param aStage 現在のステージ
     * @return 移動の目標座標
     * */
    Vector2 Answer::getTargetPos(const Stage &aStage)
    {
        int nextTarget = searchScroll(aStage);
        Vector2 targetPos = searchMove(nextTarget, aStage);
        return targetPos;
    }
 
    /**
     * 各ステージ終了後の処理
     * @param aStage 現在のステージ
     * */
    void Answer::finalize(const Stage &aStage)
    {
    }
 
} // namespace hpc
