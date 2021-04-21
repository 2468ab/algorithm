#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int par[1001] = { 0, };
int find(int x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}
bool Union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;
	par[y] = x;
	return true;
}
int main(void) {
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++) par[i] = i;
		int ans = 0;
		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v;
			if (Union(u, v)) {
				ans++;
			}
		}
		cout << ans << endl;
	}
}