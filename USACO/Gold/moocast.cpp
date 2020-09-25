// THIS IS INCORRECT
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    typedef struct
    {
        double x, y;
    } p;
    int n;
    cin >> n;
    vector<p> points;
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        p pt;
        pt.x = x;
        pt.y = y;
        points.push_back(pt);
    }
    vector<pair<double, pair<int, int>>> edges;
    vector<int> G[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            p A = points[i], B = points[j];
            double dist = sqrt((A.x - B.x) * (A.x - B.x) +
                               (A.y - B.y) * (A.y - B.y));
            G[i].push_back(j);
            G[j].push_back(i);
            edges.push_back({dist, {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    int len = edges.size();
    double ans;
    for (int i = len - 1; i >= 0; i--)
    {
        // Remove the edge
        ans = edges[i].first;
        int cmp = 0;
        pair<int, int> temp = edges[i].second;
        for (int j = 0; j < G[temp.first].size(); j++)
        {
            if (G[temp.first][j] == temp.second)
            {
                G[temp.first][j] = -1;
                break;
            }
        }
        for (int j = 0; j < G[temp.second].size(); j++)
        {
            if (G[temp.second][j] == temp.first)
            {
                G[temp.second][j] = -1;
                break;
            }
        }
        stack<int> s;
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        for (int j = 0; j < n; j++)
        {
            if (vis[j])
                continue;
            cmp++;
            if (cmp > 1)
                break;
            vis[j] = 1;
            s.push(j);
            while (!s.empty())
            {
                int x = s.top();
                s.pop();
                for (auto u : G[x])
                {
                    if (u == -1)
                        continue;
                    if (vis[u])
                        continue;
                    vis[u] = 1;
                    s.push(u);
                }
            }
        }
        if (cmp > 1)
            break;
    }
    cout << ceil(ans * ans) << "\n";
    return 0;
}