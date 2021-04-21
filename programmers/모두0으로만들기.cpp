#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;
vector<int> edge[300000];
vector<long long> cost;
int inv[300000];
bool check[300000];
long long answer = 0;
void dfs(int now) {
	check[now] = true;
	int num = edge[now].size();
	for (int i = 0; i < num; i++) {
		int next = edge[now][i];
		if (!check[next]) {
			dfs(next);
			cost[now] += cost[next];
			answer += abs(cost[next]);
			cost[next] = 0;
		}
	}
}
long long solution(vector<int> a, vector<vector<int>> edges) {
	int n = a.size();
	int m = edges.size();
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		cost.push_back(a[i]);
	}
	if (sum) return -1;
	for (int i = 0; i < m; i++) {
		int u = edges[i][0];
		int v = edges[i][1];
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(0);
	return answer;
}