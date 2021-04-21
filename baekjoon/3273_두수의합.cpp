#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, target, ans = 0;
vector<int> arr;
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int value; cin >> value;
		arr.push_back(value);
	}
	cin >> target;
	return;
}
void solve() {
	sort(arr.begin(), arr.end());
	int l = 0, r = arr.size() - 1;
	while (l < r) {
		int sum = arr[l] + arr[r];
		if (sum >= target) {
			if (sum == target) ans++;
			r--;
		}
		else {
			l++;
		}
	}
}
void output() {
	cout << ans << endl;
}
int main(void) {
	input();
	solve();
	output();
	return 0;
}