#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

vvl dp;
int k;
vl sizes;
vl psum;

ll solve(int b, int e) {
	if (b == e) {
		return 0;
	}

	if (dp[b][e] < 0) {
		dp[b][e] = numeric_limits<ll>::max();
		for (auto j = 0; j < k; ++j) {
			if (b + j == e) {
				break;
			}

			auto val = solve(b, b + j) + solve(b + j + 1, e) + psum[e];
			if (0 < b) {
				val -= psum[b - 1];
			}

			dp[b][e] = min(dp[b][e], val);
		}
	}

	return dp[b][e];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (0 < (t--)) {
		cin >> k;

		sizes = vl(k);
		psum = vl(k);
		dp = vvl(k, vl(k, -1));

		for (auto i = 0; i < k; ++i) {
			cin >> sizes[i];
			if (0 == i) {
				psum[i] = sizes[i];
			}
			else {
				psum[i] = psum[i - 1] + sizes[i];
			}
		}

		cout << solve(0, k - 1) << '\n';
	}

	return 0;
}