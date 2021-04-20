#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct node {
	int u, v, c;
};
bool operator<(node lhs, node rhs) {
	return lhs.c < rhs.c;
}
vector<node> a;
int par[2000];
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
	int n, c;
	cin >> n >> c;
	vector<pair<int, int>> p;
	for(int i = 0; i < n; i++) par[i] = i;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		p.push_back({ x, y });
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int dx = (p[i].first - p[j].first);
			int dy = (p[i].second - p[j].second);
			int r = dx * dx + dy * dy;
			if (r >= c) {
				a.push_back({ i,j,r });
			}
		}
	}	
	int ans = 0;
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) {
		int u = a[i].u;
		int v = a[i].v;
		int c = a[i].c;
		if (Union(u, v)) ans += c;
	}
	int ok = true;
	for (int i = 1; i < n; i++) {
		if (find(i) != find(i - 1)) {
			ok = false;
			break;
		}
	}
	if(ok) cout << ans << endl;
	else cout << -1 << endl;
	return 0;
}