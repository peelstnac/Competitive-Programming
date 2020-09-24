#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9 + 7;

signed main()
{
    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);
    int N, M, K;
    cin >> N >> M >> K;
    int ex[N + 1];
    ex[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        ex[i] = (ex[i - 1] * M) % mod;
    }
    if (K == 1)
    {
        cout << ex[N] << "\n";
    }
    int dp[N + 1];
    for (int i = 1; i < K; i++)
    {
        dp[i] = ex[i];
    }
    dp[K] = 0;
    for (int i = 1; i < K; i++)
    {
        dp[K] += (M - 1) * ex[i];
        dp[K] %= mod;
    }
    for (int i = K + 1; i <= N; i++)
    {
        dp[i] = (dp[i - 1] + (M - 1) * (dp[i - 1] - dp[i - K])) % mod;
    }
    cout << (ex[N] - dp[N] + mod) % mod << "\n";
    return 0;
}