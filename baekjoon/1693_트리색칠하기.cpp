#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, root = 1;
vector<int> edge[100001];
vector<int> dp[100001];
pair<int, int> value[100001];
int length[100001];
bool check[100001];
void input() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		length[i] = edge[i].size() + 1;
		dp[i].resize(edge[i].size() + 2);
		for (int j = 1; j <= length[i]; j++) {
			dp[i][j] = j;
		}
	}
	return;
}
void dfs(int now) {
	check[now] = true;
	int num = edge[now].size();
	for (int i = 0; i < num; i++) {
		int next = edge[now][i];
		if (!check[next]) {
			dfs(next);
			for (int j = 1; j <= length[now]; j++) {
				if (value[next].first != j) {
					dp[now][j] += dp[next][value[next].first];
				}
				else {
					dp[now][j] += dp[next][value[next].second];
				}
			}
		}
	}
	int first = 1, second = 1;
	for (int i = 1; i <= length[now]; i++) {
		if (dp[now][first] > dp[now][i]) first = i;
	}
	if (first == 1) second = 2;
	for (int i = 1; i <= length[now]; i++) {
		if (i != first && dp[now][second] > dp[now][i]) second = i;
	}
	value[now] = { first, second };
	return;
}
void solve() {
	dfs(root);
	return;
}
void output() {
	int ans = 1111111111;
	for (int i = 1; i <= length[root]; i++) {
		ans = min(ans, dp[root][i]);
	}
	cout << ans << endl;
	return;
}
int main(void) {
	input();
	solve();
	output();
	return 0;
}