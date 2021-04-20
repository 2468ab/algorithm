#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int n, m; cin >> n >> m;
		vector<int> edge[1001];
		int cost[1001] = { 0, };
		int ans[1001] = { 0, };
		int inv[1001] = { 0, };
		for (int i = 1; i <= n; i++) {
			cin >> cost[i];
		}
		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v;
			edge[u].push_back(v);
			inv[v] += 1;
		}
		int e; cin >> e;
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (!inv[i]) { 
				ans[i] = cost[i];
				q.push(i); 
			}
		}
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			int num = edge[now].size();
			for (int i = 0; i < num; i++) {
				int next = edge[now][i];
				inv[next]--;
				ans[next] = max(ans[next], ans[now] + cost[next]);
				if (!inv[next]) {
					q.push(next);
				}
			}
		}
		cout << ans[e] << endl;
	}
}