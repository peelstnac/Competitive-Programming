#include <bits/stdc++.h>
using namespace std;

#define max(a, b) (((a) < (b)) ? (b) : (a))
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef long long ll;

ll dp[10005], cow[10005];
int N, K;

ll f(int x)
{
    if (x < 0)
        return 0;
    if (dp[x] != -1)
        return dp[x];
    int lim = min(x + 1, K);
    ll right[lim];
    right[0] = cow[x];
    for (int i = 1; i < lim; i++)
    {
        // Find the maximum number
        right[i] = max(right[i - 1], cow[x - i]);
    }
    ll ret = 0;
    for (int i = 0; i < lim; i++)
    {
        ret = max(ret, (i + 1) * right[i] + f(x - i - 1));
    }
    return dp[x] = ret;
}

int main()
{
#ifndef LOCAL
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
#endif
    cin >> N >> K;
    K = min(N, K);
    for (int i = 0; i < N; i++)
    {
        cin >> cow[i];
    }
    for (int i = 0; i < 10005; i++)
        dp[i] = -1;
    cout << f(N - 1) << "\n";
    return 0;
}