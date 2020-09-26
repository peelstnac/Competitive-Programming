#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    double x, y, p;
} point;

int dist(point A, point B)
{
    double dist = sqrt((A.x - B.x) * (A.x - B.x) +
                       (A.y - B.y) * (A.y - B.y));
    // Return if A can reach B
    if (A.p >= dist)
        return true;
    return false;
}

int main()
{
#ifndef LOCAL
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
#endif
    int n;
    cin >> n;
    point in[n];
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        point P;
        P.x = a;
        P.y = b;
        P.p = c;
        in[i] = P;
    }
    vector<int> G[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (dist(in[i], in[j]))
            {
                G[i].push_back(j);
            }
        }
    }
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        stack<int> s;
        s.push(i);
        vis[i] = 1;
        int cnt = 1;
        while (!s.empty())
        {
            int t = s.top();
            s.pop();
            for (auto u : G[t])
            {
                if (vis[u])
                    continue;
                vis[u] = 1;
                cnt++;
                s.push(u);
            }
        }
        if (m < cnt)
            m = cnt;
    }
    cout << m << "\n";
}