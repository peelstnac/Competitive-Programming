#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, pair<int, int>>> edges;

vector<vector<int>> make_adj(int L, int R)
{
    vector<vector<int>> adj(n + 1);
    for (int i = L; i <= R; i++)
    {
        auto u = edges[i].second;
        adj[u.first].push_back(u.second);
        adj[u.second].push_back(u.first);
    }
    return adj;
}

int main()
{
#ifndef LOCAL
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
#endif;
    cin >> n >> m;
    int pi[n + 1];
    bool in_order = true;
    for (int i = 1; i <= n; i++)
    {
        cin >> pi[i];
        if (pi[i] != i)
        {
            in_order = false;
        }
    }
    if (in_order)
    {
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }
    sort(edges.begin(), edges.end());
    int ans, L = 0, R = m - 1;
    while (L <= R)
    {
        int mid = (L + R) / 2, cmp = 0;
        int id[n + 1];
        stack<int> s;
        bool vis[n + 1];
        memset(vis, 0, sizeof(vis));
        vector<vector<int>> G = make_adj(mid, m - 1);
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
                continue;
            cmp++;
            s.push(i);
            id[i] = cmp;
            vis[i] = 1;
            while (!s.empty())
            {
                int x = s.top();
                s.pop();
                for (auto u : G[x])
                {
                    if (vis[u])
                        continue;
                    id[u] = cmp;
                    vis[u] = 1;
                    s.push(u);
                }
            }
        }
        bool can = true;
        for (int i = 1; i <= n; i++)
        {
            if (id[i] != id[pi[i]])
            {
                can = false;
            }
        }
        if (can)
        {
            L = mid + 1;
            ans = mid;
        }
        else
        {
            R = mid - 1;
        }
    }
    cout << edges[ans].first << endl;
    return 0;
}
