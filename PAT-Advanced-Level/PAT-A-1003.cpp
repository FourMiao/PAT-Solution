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
	int v, next, w;
};

int head[MAXN];
int tot;
Edge list[MAXN * MAXN];
bool vis[MAXN];
int dis[MAXN], num[MAXN];
int cnt[MAXN], team[MAXN];

void init() {
	std::fill(head, head + MAXN, -1);
	tot = 0;
}


void addEdge(int s, int t, int w) {
	list[tot].v = t;
	list[tot].w = w;
	list[tot].next = head[s];
	head[s] = tot ++;
}

void dijkstra(int s, int n) {
	std::fill(dis, dis + MAXN, INF);
	std::fill(num, num + MAXN, 0);
	std::fill(cnt, cnt + MAXN, 0);
	dis[s] = 0;
	cnt[s] = 1;
	num[s] = team[s];

	for (int i = 0; i < n - 1; ++ i) {
		int min = INF, u = -1;
		for (int j = 0; j < n; ++ j) {
			if (!vis[j] && dis[j] < min) {
				u = j;
				min = dis[j];
			}
		}
		if (u == -1) {
			break;
		}
		vis[u] = 1;

		for (int j = head[u]; j != -1; j = list[j].next) {
			int v = list[j].v,
				w = list[j].w,
				c = team[v];
			if (dis[v] > min + w) {
				dis[v] = min + w;
				cnt[v] = cnt[u];
				num[v] = num[u] + c;
			} else if (dis[v] == min + w) {
				cnt[v] += cnt[u];
				num[v] = std::max(num[v], num[u] + c);
			}
		}
	}
}

int main() {
	int n, m, s, t;
	init();
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for(int i = 0; i < n; ++ i) {
		scanf("%d", &team[i]);
	}
	for(int i = 0; i < m; ++ i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		addEdge(u, v, w);
		addEdge(v, u, w);
	}
	dijkstra(s, n);
	printf("%d %d\n", cnt[t], num[t]);
	return 0;
}