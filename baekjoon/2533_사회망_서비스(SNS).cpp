#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 1000000
#define INF 100000000
vector<int> edge[MAX + 1];
bool check[MAX + 1] = { false, };
int dp[MAX + 1][2] = { 0, };
int n, root = 1;
void dfs(int now) {
	check[now] = true;
	int num = edge[now].size();
	for (int i = 0; i < num; i++) {
		int next = edge[now][i];
		if (!check[next]) {
			dfs(next);
 			dp[now][0] += min(dp[next][0], dp[next][1]);
			dp[now][1] += dp[next][0];
		}
	}
	return;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
	}
	dfs(root);
	cout << min(dp[root][0], dp[root][1]) << endl;
	return 0;
}