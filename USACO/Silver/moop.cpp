#include <bits/stdc++.h>
using namespace std;
#define min(a, b) (a < b) ? a : b
#define max(a, b) (a < b) ? b : a

int main()
{
#ifndef LOCAL
	freopen("moop.in", "r", stdin);
	freopen("moop.out", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<pair<int, int>> p;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		p.push_back({a, b});
	}
	sort(p.begin(), p.end());
	int ans = 1;
	int maxn[n], minn[n];
	maxn[n - 1] = p[n - 1].second;
	minn[n - 1] = p[n - 1].second;
	for (int i = n - 2; i >= 0; i--)
	{
		maxn[i] = max(maxn[i + 1], p[i].second);
		minn[i] = min(minn[i + 1], p[i].second);
	}
	int cmax = -1e9 - 5, cmin = 1e9 + 5;
	for (int i = 0; i < n - 1; i++)
	{
		cmax = max(cmax, p[i].second);
		cmin = min(cmin, p[i].second);
		if (cmin > maxn[i + 1])
			ans++;
	}
	cout << ans << "\n";

	return 0;
}