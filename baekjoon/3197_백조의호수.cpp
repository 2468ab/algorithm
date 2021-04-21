#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct Point {
	int y, x, round;
};
queue<Point> q;
int n, m;
int round_number, area_number;
int map[1500][1500];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> pos;
vector<int> par;
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char value; cin >> value;
			if (value == 'X') map[i][j] = -1;
			if (value == 'L') pos.push_back({ i,j });
		}
	}
}
void output() {
	cout << round_number << endl;
}
void bfs(int area_number, int y, int x) {
	queue<pair<int, int>> q2;
	q2.push({ y,x });
	map[y][x] = area_number;
	while (!q2.empty()) {
		pair<int, int> now = q2.front();
		q2.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = now.first + dy[i];
			int next_x = now.second + dx[i];
			if (0 <= next_y && next_y < n && 0 <= next_x && next_x < m) {
				if (!map[next_y][next_x]) {
					map[next_y][next_x] = area_number;
					q2.push({ next_y, next_x });
				}
				if (map[next_y][next_x] == -1) {
					q.push({ now.first, now.second ,round_number });
				}
			}
		}
	}
}
void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!map[i][j]) {
				bfs(++area_number, i, j);
			}
		}
	}
	par.resize(area_number + 1);
	for (int i = 0; i <= area_number; i++) par[i] = i;
}
int find(int x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}
void Union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	par[y] = x;
	return;
}
void solve() {
	init();
	while (find(map[pos[0].first][pos[0].second]) != find(map[pos[1].first][pos[1].second])) {
		round_number++;
		while (!q.empty() && q.front().round < round_number) {
			Point now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int next_y = now.y + dy[i];
				int next_x = now.x + dx[i];
				if (0 <= next_y && next_y < n && 0 <= next_x && next_x < m) {
					if (map[next_y][next_x] == -1) {
						map[next_y][next_x] = map[now.y][now.x];
						q.push({ next_y, next_x ,round_number });
						for (int j = 0; j < 4; j++) {
							int y = next_y + dy[j];
							int x = next_x + dx[j];
							if (0 <= y && y < n && 0 <= x && x < m) {
								if (map[y][x] > 0) {
									Union(map[next_y][next_x], map[y][x]);
								}
							} 
						}
					}
				}
			}
		}
	}
}
int main(void) {
	input();
	solve();
	output();
}