#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

const int MAXN = 10000 + 10;
const int INF = 1000000000 + 7;

int num[MAXN], dp[MAXN];

int main() {
	int n;
	int lnum, rnum, l, r;
	int maxnum = 0;
	int sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &num[i]);
		if (num[i] < 0) sum ++;
		if (!i) {
			dp[i] = num[i];
			maxnum = num[i];
			lnum = i; rnum = i;
			l = i; r = i;
		} else if (dp[i - 1] + num[i] >= num[i]) {
			dp[i] = dp[i - 1] + num[i];
			r = i;
			if (dp[i] > maxnum) {
				maxnum = dp[i];
				lnum = l;
				rnum = r;
			}
		} else {
			dp[i] = num[i];
			l = i;
			r = i;
			if (dp[i] > maxnum) {
				maxnum = dp[i];
				lnum = l;
				rnum = r;
			}
		}
	}
	if (sum == n) {
		printf("%d %d %d\n", 0, num[0], num[n-1]);
	} else {
		printf("%d %d %d\n", maxnum, num[lnum], num[rnum]);
	}

	return 0;
}