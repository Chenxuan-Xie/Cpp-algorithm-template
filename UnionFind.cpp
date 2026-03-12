# include <bits/stdc++.h>
using namespace std;

// 并查集模板
class UnionFind {
    vector<int> fa; // 代表元（父节点数组）

public :
    int cc; // 连通块个数

    // 1.构造函数
    UnionFind(int n) : fa(n), cc(n) { // fa(n),cc(n)表示初始化fa为长度为n的数组，cc的初始值为n（每个元素在开始的时候自成一组）
        for (int i = 0; i < n; i++) { // 给 fa 数组赋值 fa[0]=0, fa[1]=1, ..., fa[n-1]=n-1
            fa[i] = i;
        }
    }

    // 2.find方法（查找代表元+路径压缩）
    // 返回x所在集合的代表元，同时做路径压缩，即把x所在集合中的所有元素的fa都改成代表元
    int find(int x) {
        // 如果fa[x] == x，则x是代表元，不需要进行操作，直接返回fa[x]就行了
        // 否则不断向上寻找代表元（因为有可能fa[x]其实也还不是当前真实的x所在集合的代表元，需要继续找fa[x]的代表元
        if (fa[x] != x) {
            fa[x] = find(fa[x]); // 路径压缩，将fa改成代表元
        }
        return fa[x];
    }

    // 3.merge方法（合并两个集合）
    // 返回是否合并成功
    bool merge(int from, int to) {
        int x = find(from), y = find(to);
        if (x == y) { // 本身就是一个集合，不做合并
            return false;
        }
        fa[x] = y; // 合并集合
        cc--; // 成功合并，连通块数量减1
        return true;
    }
};