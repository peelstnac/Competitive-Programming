#include <bits/stdc++.h>
using namespace std;

#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a < b) ? b : a)

vector<int> G[100005];
bool vis[100005];
int cc[100005];
int n;

int dfs(int x)
{
    vector<int> selection;
    vis[x] = 1;
    for (auto u : G[x])
    {
        if (vis[u])
            continue;
        selection.push_back(dfs(u));
    }
    if (selection.size() == 0)
    {
        cc[x] = n - 1;
        return 1;
    }
    int len = selection.size(), sum = 0, m = 0;
    for (int i = 0; i < len; i++)
    {
        m = max(m, selection[i]);
        sum += selection[i];
    }
    cc[x] = max(m, n - sum - 1);
    return sum + 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < 100005; i++)
            G[i].clear();
        memset(vis, 0, sizeof(vis));
        memset(cc, 0, sizeof(cc));
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        dfs(1);
        int m = 1000000;
        int a, b = -1;
        for (int i = 1; i <= n; i++)
        {
            if (m > cc[i])
            {
                m = cc[i];
                a = i;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (i == a)
                continue;
            if (cc[i] == m)
                b = i;
        }
        if (b == -1)
        {
            int x = G[a][0];
            cout << a << " " << x << "\n";
            cout << a << " " << x << "\n";
        }
        else
        {
            int x;
            for (auto u : G[b])
            {
                if (u != a)
                {
                    x = u;
                    break;
                }
            }
            cout << x << " " << b << "\n";
            cout << x << " " << a << "\n";
        }
    }
    return 0;
}