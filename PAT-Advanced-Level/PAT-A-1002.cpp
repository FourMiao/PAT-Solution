#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 1111;

int main () {
	double n[MAXN];
	int k1, k2;

	fill(n, n + MAXN, 0);
	scanf("%d", &k1);
	for (int i = 0; i < k1; ++i) {
		int x;
		double c;
		scanf("%d%lf", &x, &c);
		n[x] += c;
	}
	scanf("%d", &k2);
	for (int i=0; i < k2; ++i) {
		int x; 
		double c;
		scanf("%d%lf", &x, &c);
		n[x] += c;
	}
	int k = k1 > k2 ? k1 : k2;

	int cnt = 0;
	for(int i = 0; i < MAXN; ++i) {
		if (n[i]) {
			cnt++;
		}
	}
	printf("%d", cnt);

	for(int i = MAXN - 1; i >= 0; --i) {
		if(n[i]) {
			printf(" %d %.1lf", i, n[i]);
		}
	}
	printf("\n");
	return 0;
}