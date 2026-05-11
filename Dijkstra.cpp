#include <bits/stdc++.h>
using namespace std;

// Dijkstra 算法模板
// g是图的邻接表表示，g[u]是一个vector，里面存储了所有与u相邻的边，每条边用一个pair<int, int>表示，第一个int是相邻节点v，第二个int是边权w
// start是起点，price距离数组的初始值
vector<int> dijkstra(vector<vector<pair<int, int>>> &g, int start, int price) {
    vector<int> dis(g.size(), price); // 初始化距离数组，初始值为price
    dis[start] = 0; // 起点到自己的距离为0
    // 堆中保存
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 小根堆，堆顶是距离最小的元素，存储pair<距离, 节点>
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto [dis_x, x] = pq.top(); // 获取堆顶元素，dis_x是当前节点x的距离
        pq.pop();

        if (dis_x > dis[x]) { // 懒删除的核心判断：如果堆顶元素的距离大于当前节点x的距离，说明这个元素是过时的（之前已经有更短的路径更新了x的距离），直接跳过
            continue;
        }

        // 松弛操作：遍历x的所有邻边，尝试更新邻边的距离
        for (auto &[v, w] : g[x]) { // 遍历x的所有邻边，v是相邻节点，w是边权
            if (dis_x + w < dis[v]) { // 如果通过x到达v的距离更短
                dis[v] = dis_x + w; // 更新v的距离
                pq.emplace(dis[v], v); // 将更新后的距离和节点v加入堆中
            }
        }
    }

    return dis;
}