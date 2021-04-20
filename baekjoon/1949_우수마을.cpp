#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 10000
int n, root = 1;
vector<int> edge[MAX + 1];
int dp[MAX + 1][3];
int cost[MAX + 1];
int check[MAX + 1];

void solve(int now) {
	check[now] = true;
	dp[now][0] = cost[now];
	int num = edge[now].size();
	int ok = false, index = 0;
	for (int i = 0; i < num; i++) {
		int next = edge[now][i];
		if (!check[next]) {
			solve(next);
			dp[now][0] += max(dp[next][1], dp[next][2]);
			dp[now][1] += dp[next][2];
			dp[now][2] += max(dp[next][0], dp[next][2]);
			if (dp[next][0] >= dp[next][2]) ok = true;
			if (dp[index][0] < dp[next][0]) index = next;
		}
	}
	if (!ok) dp[now][2] = dp[now][2] - dp[index][2] + dp[index][0];
	return;
}
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> cost[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
}
void output() {
	cout << max(max(dp[root][0], dp[root][1]), dp[root][2]) << endl;
}
int main(void) {
	input();
	solve(root);
	output();
}