#include <bits/stdc++.h>
using namespace std;

#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a < b) ? a : b)

int N;
vector<int> fj;

int mcmp[200][200];

int cmp(int A, int B)
{
    if (mcmp[A][B] != -1)
        return mcmp[A][B];
    int cnt = 0;
    for (int i = A; i <= B; i++)
    {
        if (fj[i] != (i - A))
            cnt++;
    }
    return mcmp[A][B] = cnt;
}

int base(int n) {
    int cnt = 0;
    for(int i=0; i<=n; i++) {
        if (fj[i] != 0) cnt++;
    }
    return cnt;
}

int dp[200][200];

int f(int n, int k)
{
    if (dp[n][k] != -1)
        return dp[n][k];
    if (k == 1) return cmp(0, n);
    int ret = 1e9;
    for (int l = n; l >= k - 1; l--)
    {
        ret = min(ret, cmp(l, n) + f(l - 1, k - 1));
    }
    return dp[n][k] = ret;
}

int main()
{
#ifndef LOCAL
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
#endif
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        fj.push_back(t);
    }
    // Base cases
    for (int i = 0; i < 105; i++)
        for (int j = 0; j < 105; j++)
            mcmp[i][j] = -1;
    for (int i = 0; i < 105; i++)
        for (int j = 0; j < 105; j++)
            dp[i][j] = -1;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            dp[i][j] = base(i);
    for (int i = 1; i <= N; i++)
    {
        cout << f(N - 1, i) << "\n";
    }
    return 0;
}