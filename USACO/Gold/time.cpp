#include <bits/stdc++.h>
using namespace std;

#define max(a, b) (((a) < (b)) ? (b) : (a))
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef long long ll;

int N, M, C;
typedef struct
{
    int a, b;
} edge;
vector<edge> edges;
vector<int> w;
ll dp[1005][1005];

int main()
{
#ifndef LOCAL
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
#endif
    cin >> N >> M >> C;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        w.push_back(t);
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        edge e;
        e.a = a;
        e.b = b;
        edges.push_back(e);
    }
    for (int i = 0; i < 1005; i++)
        for (int j = 0; j < 1005; j++)
        {
            dp[i][j] = -1;
        }
    dp[1][0] = 0;
    for (int t = 1; t < 1005; t++)
    {
        for (int i = 0; i < M; i++)
        {
            auto e = edges[i];
            int a = e.a, b = e.b;
            if (dp[a][t - 1] != -1)
            {
                dp[b][t] = max(dp[b][t], dp[a][t - 1] + w[b - 1]);
            }
        }
    }
    ll ret = 0;
    for (int t = 1; t < 1005; t++)
    {
        ret = max(ret, dp[1][t] - C * t * t);
    }
    cout << ret << "\n";
    return 0;
}