# include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> p(n);
        vector<bool> marked(n, false);
        for (int j = 0; j < j; j++) {
            int cur;
            cin >> cur;
            p[j] = cur;
        }

        // 其实每次就只选“安全”的座位就可以了
        // 假设我们在第k个座位处停下来了，那么假设前面有i个安全座位，那么剩余的一定都是“危险座位”
        // 它们每一个都对应k后面的一把椅子
        // 换句话说，这些k后的椅子反而一定是安全椅子了！所以只要贪心的只选安全的椅子就可以拿到最大值了
        int ans = 0;
        for (int j = 0; j < n; j++) {
            if (p[j] <= j + 1) {
                ans++;
            }
        }

        cout << ans << endl;
    }
}