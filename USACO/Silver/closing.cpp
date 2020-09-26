#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef LOCAL
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
#endif;
    int n, m;
    cin >> n >> m;
    vector<int> G[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int order[n];
    for (int i = 0; i < n; i++)
        cin >> order[i];
    int cnt = n;
    vector<int> removed;
    for (auto o : order)
    {
        int cur = 1;
        stack<int> s;
        s.push(o);
        bool vis[n + 1];
        memset(vis, 0, sizeof(vis));
        for (auto r : removed)
        {
            vis[r] = 1;
        }
        vis[o] = 1;
        while (!s.empty())
        {
            int x = s.top();
            s.pop();
            for (auto u : G[x])
            {
                if (vis[u])
                    continue;
                vis[u] = 1;
                cur++;
                s.push(u);
            }
        }
        if (cur == cnt)
            cout << "YES\n";
        else
            cout << "NO\n";
        cnt--;
        removed.push_back(o);
    }
    return 0;
}