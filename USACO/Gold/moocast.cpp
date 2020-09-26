// THIS IS INCORRECT
#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef LOCAL
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
#endif
    typedef struct
    {
        long long x, y;
    } p;
    int n;
    cin >> n;
    vector<p> points;
    for (int i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        p pt;
        pt.x = x;
        pt.y = y;
        points.push_back(pt);
    }
    vector<pair<long long, pair<int, int>>> edges;
    vector<int> G[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            p A = points[i], B = points[j];
            long long dist = ((A.x - B.x) * (A.x - B.x) +
                               (A.y - B.y) * (A.y - B.y));
            G[i].push_back(j);
            G[j].push_back(i);
            edges.push_back({dist, {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    int len = edges.size();
    int id[n][n];
    for(int i=0; i<len; i++) {
    	auto u = edges[i].second;
    	id[u.first][u.second] = i;
    	id[u.second][u.first] = i;
    }
    int ans, L = 0, R = len - 1;
    while(L <= R) {
    	int mid = (L+R)/2;
    	int cmp = 0;
    	stack<int> s;
    	bool vis[n];
    	memset(vis, 0, sizeof(vis));
    	for(int i=0; i<n; i++) {
    		if(vis[i]) continue;
    		cmp++;
    		vis[i] = 1;
    		s.push(i);
    		while(!s.empty()) {
    			int x = s.top();
    			s.pop();
    			for(auto u : G[x]) {
    				if(vis[u] || (id[x][u] > mid)) continue;
    				vis[u] = 1;
    				s.push(u);
    			}
    		}
    	}
    	if(cmp > 1) {
    		L = mid+1;
    	} else {
    		R = mid-1;
    		ans = mid;
    	}
    }
    cout << edges[ans].first << "\n";
    return 0;
}