#include <cstdio>
#include <cstring>

const int MAXN = 2000 + 10;
const int MOD = 1000000007;

typedef long long LL;

struct PP {
	int n;
	double a;
}p1[MAXN], p2[MAXN];

double ans[MAXN];

int main() {
	int n1, n2;
	scanf("%d", &n1);
	for (int i = 0; i < n1; ++ i) {
		scanf("%d%lf", &p1[i].n, &p1[i].a);
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; ++ i) {
		scanf("%d%lf", &p2[i].n, &p2[i].a);
	}

	memset(ans, 0, sizeof(ans));
	int maxNum = 0;
	for (int i = 0; i < n1; ++ i) {
		for (int j = 0; j < n2; ++ j) {
			ans[p1[i].n + p2[j].n] += p1[i].a * p2[j].a;
			maxNum = p1[i].n + p2[j].n > maxNum ? p1[i].n + p2[j].n : maxNum;
		}
	}

	int cnt = 0;
	for (int i = maxNum; i >= 0; -- i) {
		if (ans[i]) {
			cnt ++;
		}
	}

	printf("%d", cnt);
	for (int i = maxNum; i >= 0; -- i) {
		if (ans[i]) {
			printf(" %d %.1lf", i, ans[i]);
		}
	}
	puts("");

	return 0;
}