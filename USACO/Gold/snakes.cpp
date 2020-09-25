#include <bits/stdc++.h>
using namespace std;

#define max(a, b) (((a) < (b)) ? (b) : (a))
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef long long ll;

ll dp[500][500], line[500], psa[500];

int N, K;

ll f(int x, int k)
{
    if (x <= 0)
        return 0;
    if (dp[x][k] != -1)
        return dp[x][k];
    int right[x + 1];
    right[x] = line[x];
    for (int i = x - 1; i >= 0; i--)
    {
        right[i] = max(right[i + 1], line[i]);
    }
    if (k == 0)
    {
        return dp[x][k] = right[0] * (x + 1) - psa[x + 1];
    }
    ll ret = 1e15;
    for (int i = x; i >= 0; i--)
    {
        ret = min(ret, f(i - 1, k - 1) + right[i] * (x - i + 1) - (psa[x + 1] - psa[i]));
    }
    return dp[x][k] = ret;
}

int main()
{
#ifndef LOCAL
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
#endif
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> line[i];
    for (int i = 0; i < 500; i++)
        for (int j = 0; j < 500; j++)
            dp[i][j] = -1;
    for (int i = 1; i <= N; i++)
        psa[i] = line[i - 1] + psa[i - 1];
    cout << f(N - 1, K) << "\n";
    return 0;
}