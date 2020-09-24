#include <bits/stdc++.h>
using namespace std;

int main()
{
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
    stack<int> s;
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    vector<int> cmp;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = 1;
        s.push(i);
        cmp.push_back(i);
        while (!s.empty())
        {
            int x = s.top();
            s.pop();
            for (auto u : G[x])
            {
                if (vis[u])
                    continue;
                vis[u] = 1;
                s.push(u);
            }
        }
    }
    cout << cmp.size() - 1 << "\n";
    for (int i = 0; i < cmp.size() - 1; i++)
    {
        cout << cmp[i] << " " << cmp[i + 1] << "\n";
    }
    return 0;
}