#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> G[100005];
bool vis[100005];
int cc[100005];
int n;

map<pair<int, int>, int> edge_id;
map<int, pair<int, int>> reverse_id;

int mod = 1e9 + 7;

int dfs(int x)
{
    vis[x] = 1;
    int sum = 0;
    for (auto u : G[x])
    {
        if (vis[u])
            continue;
        vis[u] = 1;
        int v = dfs(u);
        sum += v;
        cc[edge_id[{x, u}]] = ((n - v) * v);
    }
    return sum + 1;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 100005; i++)
        {
            G[i].clear();
        }
        memset(vis, 0, sizeof(vis));
        cin >> n;
        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            cnt++;
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
            edge_id[{a, b}] = cnt;
            edge_id[{b, a}] = cnt;
            reverse_id[cnt] = {a, b};
        }
        dfs(1);
        vector<pair<int, int>> sorted;
        for (int i = 1; i < n; i++)
        {
            sorted.push_back({cc[i], i});
        }
        sort(sorted.rbegin(), sorted.rend());
        int m;
        cin >> m;
        vector<int> input;
        for (int i = 0; i < m; i++)
        {
            int temp;
            cin >> temp;
            input.push_back(temp);
        }
        if (m <= n - 1)
        {
            int diff = n - 1 - m;
            while (diff--)
            {
                input.push_back(1);
            }
            sort(input.rbegin(), input.rend());

            int sol = 0;
            for (int i = 0; i < n - 1; i++)
            {
                sol = (sol + (input[i] * sorted[i].first) % mod) % mod;
            }
            cout << sol << "\n";
        }
        else
        {
            int diff = m - n + 1;
            sort(input.rbegin(), input.rend());
            vector<int> new_input;
            int x = 1;
            for (int i = 0; i <= diff; i++)
            {
                x = (x * input[i]) % mod;
            }
            new_input.push_back(x);
            for (int i = diff + 1; i < m; i++)
            {
                new_input.push_back(input[i]);
            }

            int sol = 0;
            for (int i = 0; i < n - 1; i++)
            {
                sol = (sol + (new_input[i] * sorted[i].first) % mod) % mod;
            }
            cout << sol << "\n";
        }
    }
}