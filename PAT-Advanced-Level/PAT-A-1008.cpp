#include <cstdio>
#include <cstring>

const int MAXN = 500 + 10;
const int MAXH = 10 + 2;
const int MOD = 1000000007;

typedef long long LL;

int main() {
	int ans = 0;
	int n, pre = 0, cur = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &cur);
		if (cur >= pre) {
			ans += (cur - pre) * 6 + 5;
		} else {
			ans += (pre - cur) * 4 + 5;
		}
		pre = cur;
	}
	printf("%d\n", ans);
	return 0;
}