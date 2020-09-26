#include <bits/stdc++.h>
using namespace std;

#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a < b) ? a : b)

// [index][K(i)][H/P/S -> 0/1/2]
int dp[100005][50][3];
string fj[100005];

// Returns 1 if A wins, 0 otherwise
int eval(int A, string B)
{
    if (A == 0 && B == "S")
        return 1;
    if (A == 1 && B == "H")
        return 1;
    if (A == 2 && B == "P")
        return 1;
    return 0;
}

int f(int i, int k, int choice)
{
    if (dp[i][k][choice] != -1)
        return dp[i][k][choice];

    // Base case
    if (i == 0)
    {
        return eval(choice, fj[0]);
    }
    // When k=0
    if (k == 0)
    {
        // cout << choice << " " << fj[i] << endl;
        return dp[i][k][choice] = eval(choice, fj[i]) + f(i - 1, k, choice);
    }
    // Other cases
    int ret = 0;
    for (int next = 0; next < 3; next++)
    {
        int sub = 1;
        if (next == choice)
            sub = 0;
        ret = max(ret, f(i - 1, k - sub, next));
    }
    ret += eval(choice, fj[i]);
    return dp[i][k][choice] = ret;
}

int main()
{
#ifndef LOCAL
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
#endif
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        cin >> fj[i];
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= K; j++)
            for (int k = 0; k < 3; k++)
                dp[i][j][k] = -1;
    int ans = 0;
    for (int next = 0; next < 3; next++)
    {
        ans = max(ans, f(N - 1, K, next));
    }
    printf("%d\n", ans);
    return 0;
}