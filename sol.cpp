#include <bits/stdc++.h>
using namespace std;

void test_case(int tc) {
	int n;
	cin >> n;
	vector<int> u(n), s(n);
	for(int i = 0; i < n; i++) {
		cin >> u[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	vector<vector<int>> vec(n);
	for(int i = 0; i < n; i++) {
		vec[u[i]-1].push_back(s[i]);
	}
	vector<long long> res(n, 0);
	for(int i = 0; i < n; i++) {
		int sz = vec[i].size();
		if(sz == 0) {
			continue;
		}
		sort(vec[i].rbegin(), vec[i].rend());
		vector<long long> pref(sz);
		pref[0] = vec[i][0];
		for(int j = 1; j < sz; j++) {
			pref[j] = pref[j-1] + vec[i][j];
		}
		for(int k = 1; k <= n; k++) {
			if (sz < k) {
				break;
			}
			//form valid groups
			int counted = k * (sz / k);
			res[k-1] += pref[counted-1];
		}
	}
	for(long long x : res) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T = 1;
	cin >> T;
	for(int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
