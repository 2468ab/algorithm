#include <string>
#include <vector>
using namespace std;
vector<int> edge[200000];
bool check[200000];
int before[200000];
int after[200000];
int root = 0;
void dfs(int now) {
	check[now] = true;
	if (after[now] != -1) {
		if (!check[after[now]]) {
			dfs(after[now]);
		}
	}
	int num = edge[now].size();
	for (int i = 0; i < num; i++) {
		int next = edge[now][i];
		if (!check[next]) {
			if (check[before[next]]) {
				dfs(next);
			}
			else {
				after[before[next]] = next;
			}
		}
	}
	return;
}
bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
	bool answer = true;
	int m = path.size();
	for (int i = 0; i < m; i++) {
		int u = path[i][0];
		int v = path[i][1];
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (auto elem : order) {
		before[elem[1]] = elem[0];
	}
	if (before[root] != 0) return false;
	dfs(root);
	for (int i = 0; i < n; i++) {
		if (!check[i]) answer = false;
	}
	return answer;
}