#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

const int MAXN = 1000 + 10;
const int INF = 1000000000 + 7;

struct Edge {
	int v, next;
};

int head[MAXN];
int tot;
Edge list[MAXN * MAXN];
bool vis[MAXN];
int level[MAXN], numChild[MAXN];

void init() {
	std::fill(head, head + MAXN, -1);
	tot = 0;
}


void addEdge(int s, int t) {
	list[tot].v = t;
	list[tot].next = head[s];
	head[s] = tot ++;
}

void dfs(int cur, int step) {
	level[cur] = step;

	for (int i = head[cur]; i != -1; i = list[i].next) {
		int t = list[i].v;
		dfs(t, step + 1);
	}
}

void work(int n) {
	dfs(1, 0);
	int ans[MAXN];
	memset(ans, 0, sizeof(ans));

	int maxLevel = 0;
	for (int i = 1; i <= n; ++ i) {
		if (!numChild[i]) {
			++ ans[level[i]];
			maxLevel = level[i] > maxLevel ? level[i] : maxLevel;
		}
	}

	for(int i = 0; i < maxLevel; ++ i) {
		printf("%d ", ans[i]);
	}
	printf("%d\n", ans[maxLevel]);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	init();
	for(int i = 0; i < m; ++ i) {
		int id, k;
		scanf("%d%d", &id, &k);
		numChild[id] = k;
		for (int j = 0; j < k; ++ j) {
			int x;
			scanf("%d", &x);
			addEdge(id, x);
		}
	}
	work(n);
	return 0;
}