#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    pair<int, int> pos[n + 1];
    vector<int> G[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        pos[i] = {a, b};
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int p = 1e9;
    stack<int> s;
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        int L = pos[i].first, R = pos[i].first,
            T = pos[i].second, B = pos[i].second;
        vis[i] = 1;
        s.push(i);
        while (!s.empty())
        {
            int x = s.top();
            s.pop();
            for (auto u : G[x])
            {
                if (vis[u])
                    continue;
                vis[u] = 1;
                if (pos[u].first < L)
                    L = pos[u].first;
                if (pos[u].first > R)
                    R = pos[u].first;
                if (pos[u].second < B)
                    B = pos[u].second;
                if (pos[u].second > T)
                    T = pos[u].second;
                s.push(u);
            }
        }
        int temp = 2 * (R - L + T - B);
        if (temp < p)
            p = temp;
    }
    cout << p << "\n";
    return 0;
}