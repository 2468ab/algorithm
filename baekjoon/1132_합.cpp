#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<long long, bool>> cnt(10);
long long ans = 0;
int main(void) {
	long long n; cin >> n;
	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		int num = input.size();
		long long d = 1;
		for (int j = num - 1; j >= 0; j--) {
			cnt[input[j] - 'A'].first += d;
			d *= 10;
		}
		cnt[input[0] - 'A'].second = true;
	}
	sort(cnt.begin(), cnt.end());
	for (int i = 0; i <= 9; i++) {
		if (!cnt[i].second) {
			pair<long long, bool> tmp = cnt[i];
			for (int j = i - 1; j >= 0; j--) {
				cnt[j + 1] = cnt[j];
			}
			cnt[0] = tmp;
			break;
		}
	}
	for (int i = 9; i >= 0; i--) {
		ans += i * cnt[i].first;
	}
	cout << ans << endl;
	return 0;
}