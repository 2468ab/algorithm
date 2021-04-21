#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
vector<int> arr(n);
int l = 0, r = n - 1;
int first = 0, second = n - 1, value = 2111111111;
void input() {
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
}
void solve() {
	sort(arr.begin(), arr.end());
	while (l < r) {
		int sum = arr[l] + arr[r];
		if (abs(sum) < value) {
			value = abs(sum);
			first = l, second = r;
		}
		if (sum > 0) {
			r--;
		}
		else if (sum < 0) {
			l++;
		}
		else {
			first = l, second = r;
			break;
		}
	}
}
void output() {
	cout << arr[first] << ' ' << arr[second] << endl;
}
int main(void) {
	input();
	solve();
	output();
	return 0;
}