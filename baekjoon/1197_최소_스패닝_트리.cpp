#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a[10001];
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		a[u].push_back({ -c, v });
		a[v].push_back({ -c, u });
	}
	int start = 1, ans = 0;
	bool check[10001] = { false, };
	priority_queue<pair<int, int>> q;
	q.push({ 0, start });
	do {
		pair<int, int> top = q.top();
		int now = top.second;
		q.pop();
		if (!check[now]) {
			ans -= top.first;
			check[now] = true;
		}
		for (int i = 0; i < a[now].size(); i++) {
			int cost = a[now][i].first;
			int next = a[now][i].second;
			if (!check[next]) {
				q.push({ cost, next });
			}
		}
	} while (!q.empty());
	cout << ans << endl;
}